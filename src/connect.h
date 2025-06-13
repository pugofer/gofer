/* --------------------------------------------------------------------------
 * connect.h:	Copyright (c) Mark P Jones 1991-1994.   All rights reserved.
 *		See goferite.h for details and conditions of use etc...
 *		Gofer version 2.30 March 1994
 *
 * Connections between components of the Gofer system
 * ------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------
 * Standard data:
 * ------------------------------------------------------------------------*/

extern Name  nameFalse,   nameTrue;	/* primitive constructor functions */
extern Name  nameNil,     nameCons;
extern Name  nameFatbar,  nameFail;	/* primitives reqd for translation */
extern Name  nameIf,      nameSel;
extern Name  nameMinus,	  nameDivide;
extern Name  nameUndefMem;	 	/* undefined member primitive	   */
extern Name  nameError;			/* for runtime error messages	   */
extern Name  nameBlackHole;		/* for GC-detected black hole	   */
extern Name  nameAnd,	  nameOr;	/* for optimisation of && and ||   */
extern Name  nameOtherwise;

extern Name  nameResult,  nameBind;	/* for translation of monad comps  */
extern Name  nameZero;

extern Name  namePrint;			/* printing primitive		   */

#if IO_DIALOGUE
extern Name  nameReadFile,   nameWriteFile;/* I/O name primitives	   */
extern Name  nameAppendFile, nameReadChan;
extern Name  nameAppendChan, nameEcho;
extern Name  nameGetArgs,    nameGetProgName;
extern Name  nameGetEnv;
extern Name  nameSuccess,    nameStr;
extern Name  nameFailure,    nameStrList;
extern Name  nameWriteError;
extern Name  nameReadError,  nameSearchError;
extern Name  nameFormatError,nameOtherError;
#endif
#if    IO_MONAD
extern Type   typeIO, typeProgIO;	/* for the IO monad, IO and IO ()  */
extern Type   typeWorld, typeST;	/* built on top of IO = ST World   */
extern void   ioExecute Args((Cell));	/* IO monad executor		   */
extern Name   nameSTRun;		/* encapsulator			   */
extern Type   typeMutVar;		/* type constr for mutable vars	   */
#if    HASKELL_ARRAYS
extern Type   typeMutArr;		/* type constr for mutable arrays  */
#endif
#endif
#ifdef LAMBDAVAR
extern Name  nameVar;			/* internal lambda var constructor */
extern Type  typeProg;			/* type of a lambda var program	   */
extern void  lvExecute	Args((Cell));	/* lambda var executor		   */
#endif
#ifdef LAMBDANU
extern Name nameTag;			/* internal lambda nu constructor  */
extern Type typeLnProg;			/* type of a lambda nu prog	   */
extern void lnExecute   Args((Cell));	/* Lambda nu executor		   */
#endif
#if    HASKELL_ARRAYS
extern Type typeArray;			/* type constr for arrays	   */
#endif

extern Text  textPlus,    textMult;	/* used to recognise n+k/c*n pats  */

extern String repeatStr;		/* repeat last command string	   */

extern Type  typeString;		/* String  == [Char]		   */
extern Type  typeDialogue;		/* Dialogue== [Response]->[Request]*/
extern Type  typeBool;
extern Type  typeInt;
extern Type  typeFloat;
extern Type  typeChar;		

extern Cell  *CStackBase;		/* pointer to base of C stack	   */

extern List  tyconDefns;		/* list of type constructor defns  */
extern List  typeInDefns;		/* list of synonym restrictions	   */
extern List  valDefns;			/* list of value definitions       */
extern List  opDefns;			/* list of operator definitions    */
extern List  classDefns;		/* list of class definitions       */
extern List  instDefns;			/* list of instance definitions    */
extern List  overDefns;			/* list of overloaded member defns */
extern List  primDefns;			/* list of primitive definitions   */
extern Cell  inputExpr;			/* evaluator input expression      */
extern Addr  inputCode;			/* Code for compiled input expr    */

extern Int   whnfArgs;			/* number of args of term in whnf  */
extern Cell  whnfHead;			/* head of term in whnf            */
extern Int   whnfInt;			/* integer value of term in whnf   */
extern Float whnfFloat;			/* float value of term in whnf	   */
extern Long  numReductions;		/* number of reductions used       */
extern Long  numCells;			/* number of cells allocated       */
extern Int   numberGcs;			/* number of garbage collections   */
extern Int   cellsRecovered;		/* cells recovered by last gc	   */

extern Bool  gcMessages;		/* TRUE => print GC messages	   */
extern Bool  literateScripts;		/* TRUE => default lit scripts     */
extern Bool  literateErrors;		/* TRUE => report errs in lit scrs */
extern Bool  useConformality;		/* TRUE => check patbind conform'ty*/
extern Bool  anyEvidence;		/* TRUE => don't search for best ev*/
extern Bool  coerceNumLiterals;		/* TRUE => insert fromInteger calls*/
					/*	   etc for numeric literals*/
extern Bool  andorOptimise;		/* TRUE => optimise uses of &&, || */
extern Bool  showDicts;			/* TRUE => show dictionary params  */
					/*	   in output expressions   */
extern Bool  catchAmbigs;		/* TRUE => functions with ambig.   */
					/*	   types produce error	   */
extern Bool  failOnError;		/* TRUE => error produces immediate*/
					/*	   termination		   */

extern Int   maxEvidLevel;		/* maximum no of selects in evid   */
extern Bool  silentEvFail;		/* TRUE => keep quiet if maxEvidLev*/
					/* 	   is exceeded.		   */

extern Bool  kindExpert;		/* TRUE => display kind errors in  */
					/* 	   full detail		   */
extern Bool  overSingleton;		/* TRUE => overload singleton list */
					/*	   notation, [x]	   */

/* --------------------------------------------------------------------------
 * Function prototypes etc...
 * ------------------------------------------------------------------------*/

extern void   everybody        Args((Int));

#define RESET   1		/* reset subsystem                         */
#define MARK    2		/* mark parts of graph in use by subsystem */
#define INSTALL 3		/* install subsystem (executed once only)  */
#define EXIT	4		/* Take action immediately before exit()   */
#define BREAK   5		/* Take action after program break	   */
#define PRELUDE 6		/* Init. once prelude Tycons/Classes known */

typedef long   Target;
extern  void   setGoal          Args((String, Target));
extern  void   soFar            Args((Target));
extern  void   done             Args((void));
extern  String fromEnv		Args((String,String));

extern  void   storage          Args((Int));
extern  void   setLastExpr	Args((Cell));
extern  Cell   getLastExpr	Args((void));
extern	List   addNamesMatching Args((String,List));

extern  void   input            Args((Int));
extern  void   consoleInput     Args((String));
extern  void   projInput	Args((String));
extern  void   parseScript      Args((String,Long));
extern  void   parseExp         Args((void));
extern  String readFilename     Args((void));
extern  String readLine		Args((void));
extern  Syntax defaultSyntax    Args((Text));
extern  String unlexChar        Args((Char,Char));

extern  void   staticAnalysis	Args((Int));
extern  void   tyconDefn	Args((Int,Cell,Cell,Cell));
extern  void   setTypeIns	Args((List));
extern  void   clearTypeIns	Args((void));
extern  Bool   isAmbiguous	Args((Type));
extern  void   ambigError	Args((Int,String,Cell,Type));
extern  void   classDefn	Args((Int,Cell,Cell));
extern  void   instDefn		Args((Int,Cell,Cell));
extern  void   primDefn		Args((Cell,List,Cell));
extern  void   checkExp		Args((void));
extern  void   checkDefns	Args((void));

extern  void   typeChecker	Args((Int));
extern  Type   typeCheckExp	Args((void));
extern  void   typeCheckDefns	Args((void));
extern  void   insertInst	Args((Int,Class,Inst));
extern  Cell   rhsExpr		Args((Cell));
extern  Int    rhsLine		Args((Cell));
extern  Bool   typeMatches	Args((Type,Type));
extern  Bool   typeInstOf	Args((Type,Type));
extern  Dict   listMonadDict	Args((void));

extern  void   kindTCGroup	Args((List));
extern  void   kindSigType	Args((Int,Type));
extern  void   kindInst		Args((Inst,Int));

extern  void   compiler         Args((Cell));
extern  void   compileDefns     Args((void));
extern  void   compileExp       Args((void));
extern  Bool   refutable	Args((Cell));
extern  Int    discrArity       Args((Cell));

extern  void   machine          Args((Int));
extern  Addr   codeGen          Args((Name,Int,Cell));
extern  void   externalPrim	Args((Name,String));
extern  void   unwind           Args((Cell));
extern  void   eval             Args((Cell));
extern  Cell   evalWithNoError  Args((Cell));
extern  void   evalFails        Args((StackPtr));
extern  Cell   graphForExp	Args((void));

extern  void   builtIn          Args((Int));
extern  void   abandon		Args((String,Cell));
extern  Cell   outputString	Args((FILE *,Cell));
extern  void   dialogue		Args((Cell));
extern  Cell   consChar		Args((Char));

extern  void   machdep          Args((Int));
extern  String timeString	Args((void));
extern  Int    shellEsc		Args((String));
extern  Int    getTerminalWidth Args((void));
extern  void   normalTerminal	Args((void));
extern  void   noechoTerminal	Args((void));
extern  Int    readTerminalChar Args((void));
extern  void   gcStarted	Args((void));
extern  void   gcScanning	Args((void));
extern  void   gcRecovered	Args((Int));
extern  void   gcCStack		Args((void));

/*-------------------------------------------------------------------------*/
