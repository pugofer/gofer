/* --------------------------------------------------------------------------
 * errors.h:    Copyright (c) Mark P Jones 1991-1994.   All rights reserved.
 *              See goferite.h for details and conditions of use etc...
 *              Gofer version 2.30 March 1994
 *
 * Error handling support functions
 * ------------------------------------------------------------------------*/

#define errorStream	 stdout
#define ERROR(l)         errHead(l);fprintf(errorStream,
#define EEND       	 ); errFail()
#define ETHEN		 );
#define ERRTEXT		 fprintf(errorStream,
#define ERREXPR(e)	 printExp(errorStream,e)
#define ERRTYPE(e)	 printType(errorStream,e)
#define ERRCONTEXT(qs)   printContext(errorStream,qs)
#define ERRPRED(pi)      printPred(errorStream,pi)
#define ERRKIND(k)	 printKind(errorStream,k)
#define ERRSIG(sig)	 printSig(errorStream,sig)

extern void errHead      Args((Int));              /* in main.c            */
extern void errFail      Args((void));
extern void errAbort	 Args((void));

extern sigProto(breakHandler);

extern Bool breakOn      Args((Bool));		   /* in machdep.c	   */

extern void printExp     Args((FILE *,Cell));      /* in output.c          */
extern void printType    Args((FILE *,Cell));
extern void printContext Args((FILE *,List));
extern void printPred    Args((FILE *,Cell));
extern void printKind	 Args((FILE *,Kind));
extern void printSig	 Args((FILE *,Cell));

/*-------------------------------------------------------------------------*/
