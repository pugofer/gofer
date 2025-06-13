/* --------------------------------------------------------------------------
 * machdep.c:   Copyright (c) Mark P Jones 1991-1994.   All rights reserved.
 *              See goferite.h for details and conditions of use etc...
 *              Gofer version 2.30 March 1994
 *
 * Machine dependent code
 * RISCOS specific code provided by Bryan Scatergood, JBS
 * ------------------------------------------------------------------------*/

#if UNIX
#include <signal.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif

#if (TURBOC | BCC | _WIN32)
#include <dos.h>
#include <conio.h>
#include <io.h>
#include <stdlib.h>
#include <mem.h>
#include <sys/stat.h>
#include <time.h>
#endif

#if (TURBOC | BCC)
extern unsigned _stklen = 8000;		/* Allocate an 8k stack segment	   */
#endif

/* --------------------------------------------------------------------------
 * Machine dependent code is used in each of:
 *	- The gofer interpreter		MACHDEP_GOFER
 *	- The gofer compiler		MACHDEP_GOFC
 *	- The compiler runtime system	MACHDEP_RUNTIME
 * In many cases, the the same code is used in each part.  The following
 * sections of code are enclosed in suitable #if ... #endif directives to
 * indicate which sections require particular parts of the code.  Each of
 * the three systems above defines one of the three symbols on the right
 * above as 1 and then #includes this file.  The following directives make
 * sure that the other macros are set to the correct defaults.
 * ------------------------------------------------------------------------*/

#ifndef MACHDEP_GOFER
#define MACHDEP_GOFER   0
#endif
#ifndef MACHDEP_GOFC
#define MACHDEP_GOFC    0
#endif
#ifndef MACHDEP_RUNTIME
#define MACHDEP_RUNTIME 0
#endif

/* --------------------------------------------------------------------------
 * Find information about a file:
 * ------------------------------------------------------------------------*/

#if (MACHDEP_GOFER | MACHDEP_GOFC)
typedef time_t Time;
#define timeChanged(now,thn)	(now!=thn)
#define timeSet(var,tm)		var = tm

static Void local getFileInfo	Args((String, Time *, Long *));

static Void local getFileInfo(s,tm,sz)	/* find time stamp and size of file*/
String s;
Time   *tm;
Long   *sz; {
    static struct stat scbuf;
    stat(s,&scbuf);
    *tm = scbuf.st_mtime;
    *sz = (Long)(scbuf.st_size);
}
#endif


/* --------------------------------------------------------------------------
 * Get time/date stamp for inclusion in compiled files:
 * ------------------------------------------------------------------------*/

#if MACHDEP_GOFC
#include <time.h>
String timeString() {			/* return time&date string	   */
    time_t clock;			/* must end with '\n' character	   */
    time(&clock);
    return(ctime(&clock));
}
#endif

/* --------------------------------------------------------------------------
 * Garbage collection notification:
 * ------------------------------------------------------------------------*/

#if  (MACHDEP_GOFER | MACHDEP_GOFC)
Bool gcMessages = FALSE;		/* TRUE => print GC messages	   */

Void gcStarted() {			/* notify garbage collector start  */
    if (gcMessages) {
	printf("{{Gc");
	fflush(stdout);
    }
}

Void gcScanning() {			/* notify garbage collector scans  */
    if (gcMessages) {
	putchar(':');
	fflush(stdout);
    }
}

Void gcRecovered(recovered)		/* notify garbage collection done  */
Int recovered; {
    if (gcMessages) {
	printf("%d}}",recovered);
	fflush(stdout);
    }
}

Cell *CStackBase;			/* Retain start of C control stack */


Void gcCStack() {			/* Garbage collect elements off    */
    Cell stackTop = NIL;		/* C stack			   */
    Cell *ptr = &stackTop;
#if SMALL_GOFER
    if (((long)(ptr) - (long)(CStackBase))&1)
	fatal("gcCStack");
#elif _WIN32
    if (((uintptr_t)(ptr) - (uintptr_t)(CStackBase))&3)
	fatal("gcCStack");
#else 
    if (((long)(ptr) - (long)(CStackBase))&3)
	fatal("gcCStack");
#endif

#define StackGrowsDown	while (ptr<=CStackBase) markWithoutMove(*ptr++)
#define StackGrowsUp	while (ptr>=CStackBase) markWithoutMove(*ptr--)
#define GuessDirection	if (ptr>CStackBase) StackGrowsUp; else StackGrowsDown
    StackGrowsDown;
#undef  StackGrowsDown
#undef  StackGrowsUp
#undef  GuessDirection
}
#endif

/* --------------------------------------------------------------------------
 * Terminal dependent stuff:
 * ------------------------------------------------------------------------*/

#if   (TERMIO_IO | SGTTY_IO | TERMIOS_IO)

#if TERMIO_IO
#include <termio.h>
typedef  struct termio   TermParams;
#define  getTerminal(tp) ioctl(fileno(stdin),TCGETA,&tp)
#define  setTerminal(tp) ioctl(fileno(stdin),TCSETAF,&tp)
#define  noEcho(tp)      tp.c_lflag    &= ~(ICANON | ECHO); \
			 tp.c_cc[VMIN]  = 1;		    \
			 tp.c_cc[VTIME] = 0;
#endif

#if SGTTY_IO
#include <sgtty.h>
typedef  struct sgttyb   TermParams;
#define  getTerminal(tp) ioctl(fileno(stdin),TIOCGETP,&tp)
#define  setTerminal(tp) ioctl(fileno(stdin),TIOCSETP,&tp)
#define  noEcho(tp)      tp.sg_flags |= CBREAK; tp.sg_flags &= (~ECHO);
#endif

#if TERMIOS_IO
#include <termios.h>
typedef  struct termios  TermParams;
#define  getTerminal(tp) tcgetattr(fileno(stdin), &tp)
#define  setTerminal(tp) tcsetattr(fileno(stdin), TCSAFLUSH, &tp)
#define  noEcho(tp)      tp.c_lflag    &= ~(ICANON | ECHO); \
			 tp.c_cc[VMIN]  = 1;                \
			 tp.c_cc[VTIME] = 0;
#endif

static Bool messedWithTerminal = FALSE;
static TermParams originalSettings;

Void normalTerminal() {			/* restore terminal initial state  */
    if (messedWithTerminal)
	setTerminal(originalSettings);
}

Void noechoTerminal() {			/* set terminal into noecho mode   */
    TermParams settings;

    if (!messedWithTerminal) {
	getTerminal(originalSettings);
	messedWithTerminal = TRUE;
    }
    getTerminal(settings);
    noEcho(settings);
    setTerminal(settings);
}

#if (MACHDEP_GOFER | MACHDEP_GOFC)
Int getTerminalWidth() {		/* determine width of terminal	   */
#ifdef TIOCGWINSZ
#ifdef _M_UNIX				/* SCO Unix 3.2.4 defines TIOCGWINSZ*/
#include <sys/stream.h>			/* Required by sys/ptem.h	   */
#include <sys/ptem.h>			/* Required to declare winsize	   */
#endif
    static struct winsize terminalSize;
    ioctl(fileno(stdout),TIOCGWINSZ,&terminalSize);
    return (terminalSize.ws_col==0)? 80 : terminalSize.ws_col;
#else
    return 80;
#endif
}
#endif

Int readTerminalChar() {		/* read character from terminal	   */
    return getchar();			/* without echo, assuming that	   */
}					/* noechoTerminal() is active...   */
#endif

#if DOS_IO
static Bool terminalEchoReqd = TRUE;

#if (MACHDEP_GOFER | MACHDEP_GOFC)
Int getTerminalWidth() {		/* PC screen is fixed 80 chars	   */
    return 80;
}
#endif

Void normalTerminal() {			/* restore terminal initial state  */
    terminalEchoReqd = TRUE;
}

Void noechoTerminal() {			/* turn terminal echo on/off	   */
    terminalEchoReqd = FALSE;
}

Int readTerminalChar() {		/* read character from terminal	   */
    if (terminalEchoReqd)
	return getchar();
    else {
	Int c = getch();
	return c=='\r' ? '\n' : c;
    }
}
#endif


/* --------------------------------------------------------------------------
 * Interrupt handling:
 * ------------------------------------------------------------------------*/

#if (MACHDEP_GOFER | MACHDEP_GOFC)	/* runtime.c provides own version  */
static  Bool broken    = FALSE;
static  Bool breakReqd = FALSE;
static  sigProto(ignoreBreak);

Bool breakOn(reqd)			/* set break trapping on if reqd,  */
Bool reqd; {				/* or off otherwise, returning old */
    Bool old  = breakReqd;

    breakReqd = reqd;
    if (reqd) {
	if (broken) {			/* repond to break signal received */
	    broken = FALSE;		/* whilst break trap disabled	   */
	    sigRaise(breakHandler);
	}
	ctrlbrk(breakHandler);
    }
    else
	ctrlbrk(ignoreBreak);

    return old;
}

static sigHandler(ignoreBreak) {	/* record but don't respond to break*/
    ctrlbrk(ignoreBreak);
    broken = TRUE;
    sigResume;
}
#endif

/* --------------------------------------------------------------------------
 * Shell escapes:
 * ------------------------------------------------------------------------*/

#if MACHDEP_GOFER
Int shellEsc(s)				/* run a shell command (or shell)  */
String s; {
#if UNIX
    if (s[0]=='\0')
	s = fromEnv("SHELL","/bin/sh");
#endif
    return system(s);
}

#endif

/* --------------------------------------------------------------------------
 * Floating point support:
 * ------------------------------------------------------------------------*/

#if HAS_FLOATS
#if BREAK_FLOATS
static union {
    Float  flVal;
    struct {
	Cell flPart1,flPart2;
    }	   clVal;
} fudgeCoerce;

Cell part1Float(fl)
FloatPro fl; {
    fudgeCoerce.flVal = fl;
    return fudgeCoerce.clVal.flPart1;
}

Cell part2Float(fl)
FloatPro fl; {
    fudgeCoerce.flVal = fl;
    return fudgeCoerce.clVal.flPart2;
}

FloatPro floatFromParts(c1,c2)
Cell c1, c2; {
    fudgeCoerce.clVal.flPart1 = c1;
    fudgeCoerce.clVal.flPart2 = c2;
    return fudgeCoerce.flVal;
}

Cell mkFloat(fl)
FloatPro fl; {
    Cell p1,p2;
    fudgeCoerce.flVal = fl;
    p1 = mkInt(fudgeCoerce.clVal.flPart1);
    p2 = mkInt(fudgeCoerce.clVal.flPart2);
    return pair(FLOATCELL,pair(p1,p2));
}

FloatPro floatOf(c)
Cell c; {
    fudgeCoerce.clVal.flPart1 = intOf(fst(snd(c)));
    fudgeCoerce.clVal.flPart2 = intOf(snd(snd(c)));
    return fudgeCoerce.flVal;
}

#if MACHDEP_RUNTIME & BREAK_FLOATS
Cell safeMkFloat(fl)
FloatPro fl; {
    fudgeCoerce.flVal = fl;
    needStack(2);
    pushInt(fudgeCoerce.clVal.flPart2);
    pushInt(fudgeCoerce.clVal.flPart1);
    heap(2);
    mkap();
    topfun(FLOATCELL);
    return pop();
}
#endif

#else /* !BREAK_FLOATS */
static union {
    Float flVal;
    Cell  clVal;
} fudgeCoerce;

Cell mkFloat(fl)
FloatPro fl; {
    fudgeCoerce.flVal = fl;
    return pair(FLOATCELL,fudgeCoerce.clVal);
}

FloatPro floatOf(c)
Cell c; {
    fudgeCoerce.clVal = snd(c);
    return fudgeCoerce.flVal;
}
#endif

String floatToString(fl)			/* Make sure that floating   */
FloatPro fl; {					/* point values print out in */
    static char buffer1[32];			/* a form in which they could*/
    static char buffer2[32];			/* also be entered as floats */
    Int i=0, j=0;

    sprintf(buffer1,FloatFMT,fl);
    while (buffer1[i] && strchr("eE.",buffer1[i])==0)
	buffer2[j++] = buffer1[i++];
    if (buffer1[i]!='.') {
        buffer2[j++] = '.';
	buffer2[j++] = '0';
    }
    while (buffer2[j++]=buffer1[i++])
	;
    return buffer2;
}

FloatPro stringToFloat(s)
String s; {
    return atof(s);
}
#else
Cell mkFloat(fl)
FloatPro fl; {
    internal("mkFloat");
    return 0;/*NOTREACHED*/
}

FloatPro floatOf(c)
Cell c; {
    internal("floatOf");
    return 0;/*NOTREACHED*/
}

String floatToString(fl)
FloatPro fl; {
    internal("floatToString");
    return "";/*NOTREACHED*/
}

FloatPro stringToFloat(s)
String s; {
    internal("stringToFloat");
    return 0;
}
#endif

/* --------------------------------------------------------------------------
 * Machine dependent control:
 * ------------------------------------------------------------------------*/

#if (MACHDEP_GOFER | MACHDEP_GOFC)
#if UNIX
static sigHandler(panic) {		/* exit in a panic, on receipt of  */
    everybody(EXIT);			/* an unexpected signal		   */
    fprintf(stderr,"Unexpected signal\n");
    exit(1);
    sigResume;/*NOTREACHED*/
}
#endif

Void machdep(Int what) {
    switch (what) {
        case MARK:
            break;

#if UNIX
        case INSTALL:
            signal(SIGHUP,  panic);
            signal(SIGQUIT, panic);
            signal(SIGTERM, panic);
            signal(SIGSEGV, panic);
            signal(SIGBUS,  panic);
            break;
#endif

#if (_WIN32)
        case INSTALL:
            /* Windows: optional handling via SetConsoleCtrlHandler */
            break;
#endif

        case RESET:
        case BREAK:
        case EXIT:
            normalTerminal();
            break;
    }
}
#endif

/*-------------------------------------------------------------------------*/
