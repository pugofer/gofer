/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 18 "parser.y"

#ifndef lint
#define lint
#endif
#define defTycon(n,l,lhs,rhs,w)	 tyconDefn(intOf(l),lhs,rhs,w); sp-=n
#define sigdecl(l,vs,t)		 ap(SIGDECL,triple(l,vs,t))
#define grded(gs)		 ap(GUARDED,gs)
#define letrec(bs,e)		 (nonNull(bs) ? ap(LETREC,pair(bs,e)) : e)
#define yyerror(s)		 /* errors handled elsewhere */
#define YYSTYPE			 Cell

static Cell   local gcShadow     Args((Int,Cell));
static Void   local syntaxError  Args((String));
static String local unexpected   Args((Void));
static Cell   local checkPrec    Args((Cell));
static Void   local fixDefn      Args((Syntax,Cell,Cell,List));
static Void   local setSyntax    Args((Int,Syntax,Cell));
static Cell   local buildTuple   Args((List));
static Cell   local checkClass   Args((Cell));
static List   local checkContext Args((List));
static Pair   local checkDo	 Args((List));
static Cell   local checkTyLhs	 Args((Cell));
static Cell   local tidyInfix    Args((Cell));

/* For the purposes of reasonably portable garbage collection, it is
 * necessary to simulate the YACC stack on the Gofer stack to keep
 * track of all intermediate constructs.  The lexical analyser
 * pushes a token onto the stack for each token that is found, with
 * these elements being removed as reduce actions are performed,
 * taking account of look-ahead tokens as described by gcShadow()
 * below.
 *
 * Of the non-terminals used below, only start, topDecl & begin do not leave
 * any values on the Gofer stack.  The same is true for the terminals
 * EVALEX and SCRIPT.  At the end of a successful parse, there should only
 * be one element left on the stack, containing the result of the parse.
 */

#define gc0(e)			 gcShadow(0,e)
#define gc1(e)			 gcShadow(1,e)
#define gc2(e)			 gcShadow(2,e)
#define gc3(e)			 gcShadow(3,e)
#define gc4(e)			 gcShadow(4,e)
#define gc5(e)			 gcShadow(5,e)
#define gc6(e)			 gcShadow(6,e)
#define gc7(e)			 gcShadow(7,e)


#line 120 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EVALEX = 258,                  /* EVALEX  */
    SCRIPT = 259,                  /* SCRIPT  */
    COCO = 260,                    /* COCO  */
    INFIXL = 261,                  /* INFIXL  */
    INFIXR = 262,                  /* INFIXR  */
    INFIX = 263,                   /* INFIX  */
    FUNARROW = 264,                /* FUNARROW  */
    UPTO = 265,                    /* UPTO  */
    CASEXP = 266,                  /* CASEXP  */
    OF = 267,                      /* OF  */
    IF = 268,                      /* IF  */
    THEN = 269,                    /* THEN  */
    ELSE = 270,                    /* ELSE  */
    WHERE = 271,                   /* WHERE  */
    TYPE = 272,                    /* TYPE  */
    DATA = 273,                    /* DATA  */
    FROM = 274,                    /* FROM  */
    LET = 275,                     /* LET  */
    IN = 276,                      /* IN  */
    VAROP = 277,                   /* VAROP  */
    VARID = 278,                   /* VARID  */
    NUMLIT = 279,                  /* NUMLIT  */
    CHARLIT = 280,                 /* CHARLIT  */
    STRINGLIT = 281,               /* STRINGLIT  */
    REPEAT = 282,                  /* REPEAT  */
    CONOP = 283,                   /* CONOP  */
    CONID = 284,                   /* CONID  */
    TCLASS = 285,                  /* TCLASS  */
    IMPLIES = 286,                 /* IMPLIES  */
    TINSTANCE = 287,               /* TINSTANCE  */
    DO = 288,                      /* DO  */
    TRUNST = 289,                  /* TRUNST  */
    PRIMITIVE = 290,               /* PRIMITIVE  */
    DEFAULT = 291,                 /* DEFAULT  */
    DERIVING = 292,                /* DERIVING  */
    HIDING = 293,                  /* HIDING  */
    IMPORT = 294,                  /* IMPORT  */
    INTERFACE = 295,               /* INTERFACE  */
    MODULE = 296,                  /* MODULE  */
    RENAMING = 297,                /* RENAMING  */
    TO = 298                       /* TO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define EVALEX 258
#define SCRIPT 259
#define COCO 260
#define INFIXL 261
#define INFIXR 262
#define INFIX 263
#define FUNARROW 264
#define UPTO 265
#define CASEXP 266
#define OF 267
#define IF 268
#define THEN 269
#define ELSE 270
#define WHERE 271
#define TYPE 272
#define DATA 273
#define FROM 274
#define LET 275
#define IN 276
#define VAROP 277
#define VARID 278
#define NUMLIT 279
#define CHARLIT 280
#define STRINGLIT 281
#define REPEAT 282
#define CONOP 283
#define CONID 284
#define TCLASS 285
#define IMPLIES 286
#define TINSTANCE 287
#define DO 288
#define TRUNST 289
#define PRIMITIVE 290
#define DEFAULT 291
#define DERIVING 292
#define HIDING 293
#define IMPORT 294
#define INTERFACE 295
#define MODULE 296
#define RENAMING 297
#define TO 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EVALEX = 3,                     /* EVALEX  */
  YYSYMBOL_SCRIPT = 4,                     /* SCRIPT  */
  YYSYMBOL_5_ = 5,                         /* '='  */
  YYSYMBOL_COCO = 6,                       /* COCO  */
  YYSYMBOL_INFIXL = 7,                     /* INFIXL  */
  YYSYMBOL_INFIXR = 8,                     /* INFIXR  */
  YYSYMBOL_INFIX = 9,                      /* INFIX  */
  YYSYMBOL_FUNARROW = 10,                  /* FUNARROW  */
  YYSYMBOL_11_ = 11,                       /* '-'  */
  YYSYMBOL_12_ = 12,                       /* ','  */
  YYSYMBOL_13_ = 13,                       /* '@'  */
  YYSYMBOL_14_ = 14,                       /* '('  */
  YYSYMBOL_15_ = 15,                       /* ')'  */
  YYSYMBOL_16_ = 16,                       /* '|'  */
  YYSYMBOL_17_ = 17,                       /* ';'  */
  YYSYMBOL_UPTO = 18,                      /* UPTO  */
  YYSYMBOL_19_ = 19,                       /* '['  */
  YYSYMBOL_20_ = 20,                       /* ']'  */
  YYSYMBOL_CASEXP = 21,                    /* CASEXP  */
  YYSYMBOL_OF = 22,                        /* OF  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_THEN = 24,                      /* THEN  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_WHERE = 26,                     /* WHERE  */
  YYSYMBOL_TYPE = 27,                      /* TYPE  */
  YYSYMBOL_DATA = 28,                      /* DATA  */
  YYSYMBOL_FROM = 29,                      /* FROM  */
  YYSYMBOL_30_ = 30,                       /* '\\'  */
  YYSYMBOL_31_ = 31,                       /* '~'  */
  YYSYMBOL_LET = 32,                       /* LET  */
  YYSYMBOL_IN = 33,                        /* IN  */
  YYSYMBOL_34_ = 34,                       /* '`'  */
  YYSYMBOL_VAROP = 35,                     /* VAROP  */
  YYSYMBOL_VARID = 36,                     /* VARID  */
  YYSYMBOL_NUMLIT = 37,                    /* NUMLIT  */
  YYSYMBOL_CHARLIT = 38,                   /* CHARLIT  */
  YYSYMBOL_STRINGLIT = 39,                 /* STRINGLIT  */
  YYSYMBOL_REPEAT = 40,                    /* REPEAT  */
  YYSYMBOL_CONOP = 41,                     /* CONOP  */
  YYSYMBOL_CONID = 42,                     /* CONID  */
  YYSYMBOL_TCLASS = 43,                    /* TCLASS  */
  YYSYMBOL_IMPLIES = 44,                   /* IMPLIES  */
  YYSYMBOL_TINSTANCE = 45,                 /* TINSTANCE  */
  YYSYMBOL_DO = 46,                        /* DO  */
  YYSYMBOL_TRUNST = 47,                    /* TRUNST  */
  YYSYMBOL_PRIMITIVE = 48,                 /* PRIMITIVE  */
  YYSYMBOL_DEFAULT = 49,                   /* DEFAULT  */
  YYSYMBOL_DERIVING = 50,                  /* DERIVING  */
  YYSYMBOL_HIDING = 51,                    /* HIDING  */
  YYSYMBOL_IMPORT = 52,                    /* IMPORT  */
  YYSYMBOL_INTERFACE = 53,                 /* INTERFACE  */
  YYSYMBOL_MODULE = 54,                    /* MODULE  */
  YYSYMBOL_RENAMING = 55,                  /* RENAMING  */
  YYSYMBOL_TO = 56,                        /* TO  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58___ = 58,                     /* '_'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_start = 61,                     /* start  */
  YYSYMBOL_topModule = 62,                 /* topModule  */
  YYSYMBOL_begin = 63,                     /* begin  */
  YYSYMBOL_topDecls = 64,                  /* topDecls  */
  YYSYMBOL_modules = 65,                   /* modules  */
  YYSYMBOL_module = 66,                    /* module  */
  YYSYMBOL_topDecl = 67,                   /* topDecl  */
  YYSYMBOL_modid = 68,                     /* modid  */
  YYSYMBOL_expspec = 69,                   /* expspec  */
  YYSYMBOL_exports = 70,                   /* exports  */
  YYSYMBOL_export = 71,                    /* export  */
  YYSYMBOL_impspec = 72,                   /* impspec  */
  YYSYMBOL_imports0 = 73,                  /* imports0  */
  YYSYMBOL_imports = 74,                   /* imports  */
  YYSYMBOL_rename = 75,                    /* rename  */
  YYSYMBOL_renamings = 76,                 /* renamings  */
  YYSYMBOL_renaming = 77,                  /* renaming  */
  YYSYMBOL_entity = 78,                    /* entity  */
  YYSYMBOL_conids = 79,                    /* conids  */
  YYSYMBOL_vars0 = 80,                     /* vars0  */
  YYSYMBOL_tyLhs = 81,                     /* tyLhs  */
  YYSYMBOL_invars = 82,                    /* invars  */
  YYSYMBOL_rsvars = 83,                    /* rsvars  */
  YYSYMBOL_rsvar = 84,                     /* rsvar  */
  YYSYMBOL_constrs = 85,                   /* constrs  */
  YYSYMBOL_constr = 86,                    /* constr  */
  YYSYMBOL_deriving = 87,                  /* deriving  */
  YYSYMBOL_derivs0 = 88,                   /* derivs0  */
  YYSYMBOL_derivs = 89,                    /* derivs  */
  YYSYMBOL_sigType = 90,                   /* sigType  */
  YYSYMBOL_context = 91,                   /* context  */
  YYSYMBOL_type = 92,                      /* type  */
  YYSYMBOL_ctype = 93,                     /* ctype  */
  YYSYMBOL_atype = 94,                     /* atype  */
  YYSYMBOL_tupCommas = 95,                 /* tupCommas  */
  YYSYMBOL_typeTuple = 96,                 /* typeTuple  */
  YYSYMBOL_optdigit = 97,                  /* optdigit  */
  YYSYMBOL_ops = 98,                       /* ops  */
  YYSYMBOL_op = 99,                        /* op  */
  YYSYMBOL_varop = 100,                    /* varop  */
  YYSYMBOL_conop = 101,                    /* conop  */
  YYSYMBOL_prims = 102,                    /* prims  */
  YYSYMBOL_prim = 103,                     /* prim  */
  YYSYMBOL_classHead = 104,                /* classHead  */
  YYSYMBOL_classBody = 105,                /* classBody  */
  YYSYMBOL_instBody = 106,                 /* instBody  */
  YYSYMBOL_csigdecls = 107,                /* csigdecls  */
  YYSYMBOL_csigdecl = 108,                 /* csigdecl  */
  YYSYMBOL_decl = 109,                     /* decl  */
  YYSYMBOL_decls = 110,                    /* decls  */
  YYSYMBOL_rhs = 111,                      /* rhs  */
  YYSYMBOL_rhs1 = 112,                     /* rhs1  */
  YYSYMBOL_wherePart = 113,                /* wherePart  */
  YYSYMBOL_gdefs = 114,                    /* gdefs  */
  YYSYMBOL_gdef = 115,                     /* gdef  */
  YYSYMBOL_vars = 116,                     /* vars  */
  YYSYMBOL_var = 117,                      /* var  */
  YYSYMBOL_varid = 118,                    /* varid  */
  YYSYMBOL_conid = 119,                    /* conid  */
  YYSYMBOL_exp = 120,                      /* exp  */
  YYSYMBOL_opExp = 121,                    /* opExp  */
  YYSYMBOL_opExp0 = 122,                   /* opExp0  */
  YYSYMBOL_pfxExp = 123,                   /* pfxExp  */
  YYSYMBOL_pats = 124,                     /* pats  */
  YYSYMBOL_appExp = 125,                   /* appExp  */
  YYSYMBOL_atomic = 126,                   /* atomic  */
  YYSYMBOL_exps2 = 127,                    /* exps2  */
  YYSYMBOL_alts = 128,                     /* alts  */
  YYSYMBOL_alt = 129,                      /* alt  */
  YYSYMBOL_altRhs = 130,                   /* altRhs  */
  YYSYMBOL_altRhs1 = 131,                  /* altRhs1  */
  YYSYMBOL_guardAlts = 132,                /* guardAlts  */
  YYSYMBOL_guardAlt = 133,                 /* guardAlt  */
  YYSYMBOL_list = 134,                     /* list  */
  YYSYMBOL_quals = 135,                    /* quals  */
  YYSYMBOL_qual = 136,                     /* qual  */
  YYSYMBOL_close = 137,                    /* close  */
  YYSYMBOL_close1 = 138                    /* close1  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   881

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  390

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      14,    15,     2,     2,    12,    11,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    17,
       2,     5,     2,     2,    13,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,    30,    20,     2,    58,    34,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,    16,    59,    31,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       6,     7,     8,     9,    10,    18,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    32,    33,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    87,    88,    89,   102,   103,   105,   107,
     108,   109,   110,   111,   113,   114,   116,   118,   120,   121,
     123,   124,   126,   127,   129,   130,   132,   133,   135,   136,
     137,   139,   140,   142,   143,   145,   146,   148,   149,   151,
     152,   154,   155,   156,   157,   158,   160,   161,   163,   164,
     169,   170,   173,   178,   179,   180,   182,   183,   185,   186,
     188,   190,   192,   193,   195,   196,   199,   201,   202,   203,
     205,   206,   208,   209,   220,   221,   223,   225,   226,   227,
     229,   230,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   243,   244,   246,   247,   252,   253,   254,   256,
     257,   259,   260,   262,   263,   264,   266,   267,   269,   270,
     275,   277,   278,   279,   281,   286,   287,   288,   290,   291,
     293,   294,   296,   297,   299,   300,   302,   303,   308,   309,
     311,   312,   314,   315,   316,   318,   319,   321,   323,   324,
     326,   333,   334,   336,   337,   339,   340,   342,   343,   345,
     346,   351,   352,   353,   355,   356,   357,   359,   360,   364,
     369,   372,   373,   374,   375,   377,   378,   380,   381,   382,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   401,   402,   404,   405,
     407,   409,   410,   412,   413,   414,   416,   417,   419,   424,
     425,   426,   427,   428,   429,   430,   431,   434,   435,   437,
     438,   442,   443,   469,   470,   472,   473
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EVALEX", "SCRIPT",
  "'='", "COCO", "INFIXL", "INFIXR", "INFIX", "FUNARROW", "'-'", "','",
  "'@'", "'('", "')'", "'|'", "';'", "UPTO", "'['", "']'", "CASEXP", "OF",
  "IF", "THEN", "ELSE", "WHERE", "TYPE", "DATA", "FROM", "'\\\\'", "'~'",
  "LET", "IN", "'`'", "VAROP", "VARID", "NUMLIT", "CHARLIT", "STRINGLIT",
  "REPEAT", "CONOP", "CONID", "TCLASS", "IMPLIES", "TINSTANCE", "DO",
  "TRUNST", "PRIMITIVE", "DEFAULT", "DERIVING", "HIDING", "IMPORT",
  "INTERFACE", "MODULE", "RENAMING", "TO", "'{'", "'_'", "'}'", "$accept",
  "start", "topModule", "begin", "topDecls", "modules", "module",
  "topDecl", "modid", "expspec", "exports", "export", "impspec",
  "imports0", "imports", "rename", "renamings", "renaming", "entity",
  "conids", "vars0", "tyLhs", "invars", "rsvars", "rsvar", "constrs",
  "constr", "deriving", "derivs0", "derivs", "sigType", "context", "type",
  "ctype", "atype", "tupCommas", "typeTuple", "optdigit", "ops", "op",
  "varop", "conop", "prims", "prim", "classHead", "classBody", "instBody",
  "csigdecls", "csigdecl", "decl", "decls", "rhs", "rhs1", "wherePart",
  "gdefs", "gdef", "vars", "var", "varid", "conid", "exp", "opExp",
  "opExp0", "pfxExp", "pats", "appExp", "atomic", "exps2", "alts", "alt",
  "altRhs", "altRhs1", "guardAlts", "guardAlt", "list", "quals", "qual",
  "close", "close1", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-243)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-206)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     263,  -243,   593,    13,    33,  -243,   780,   465,   497,   593,
     593,   823,   823,   -22,  -243,  -243,  -243,  -243,  -243,  -243,
     823,  -243,    24,  -243,  -243,    43,    98,    14,    14,   823,
    -243,  -243,    20,  -243,   425,    53,  -243,  -243,   823,   794,
    -243,   105,   112,   125,   823,   823,   177,    14,   204,   148,
     113,   181,   146,   185,   703,  -243,  -243,   765,  -243,   823,
     151,  -243,    75,  -243,  -243,  -243,   765,  -243,  -243,   765,
    -243,  -243,  -243,  -243,   209,  -243,   193,   193,   193,    26,
      75,    75,    75,   115,    75,    46,    19,  -243,  -243,    44,
     215,   179,  -243,  -243,   197,   225,  -243,  -243,   223,   234,
     593,  -243,   735,   593,  -243,   593,   625,   529,  -243,   230,
     593,   593,  -243,  -243,    22,  -243,   765,  -243,   171,    51,
    -243,  -243,  -243,   217,   249,   258,  -243,  -243,    14,   140,
     252,  -243,    14,    14,    14,  -243,  -243,    41,   265,   305,
     270,   249,   300,   302,  -243,   110,   138,  -243,   291,  -243,
    -243,    40,  -243,   340,  -243,  -243,  -243,    75,    82,  -243,
     593,   593,  -243,    43,    90,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,   315,   279,    29,   322,  -243,  -243,   765,
     313,  -243,   285,   307,    22,   327,  -243,  -243,   236,   293,
     259,   261,  -243,   325,    75,    75,  -243,   765,   143,   328,
     273,  -243,  -243,  -243,   296,   343,  -243,   343,   343,    75,
    -243,    26,   239,    75,   299,  -243,   308,  -243,   342,   112,
      75,    82,  -243,   157,   348,   311,  -243,  -243,  -243,  -243,
    -243,   357,   368,  -243,   593,  -243,   561,   765,   593,   593,
     625,   190,    23,  -243,   593,  -243,   593,  -243,  -243,    75,
    -243,   210,  -243,  -243,    75,  -243,  -243,  -243,  -243,  -243,
     221,  -243,   140,  -243,   425,    14,   341,    56,    81,    10,
    -243,    92,  -243,   657,   765,  -243,  -243,   361,   366,   374,
    -243,   157,   376,  -243,   689,   593,   357,  -243,    22,  -243,
    -243,  -243,  -243,   593,   765,  -243,    43,   375,  -243,   285,
    -243,  -243,  -243,  -243,  -243,  -243,    89,   378,   277,   380,
     384,  -243,  -243,  -243,    19,  -243,    82,  -243,   239,   239,
      15,  -243,   358,    75,  -243,    27,  -243,  -243,    22,  -243,
     157,   286,   184,   593,  -243,  -243,   307,  -243,   391,  -243,
    -243,  -243,   125,  -243,   100,  -243,  -243,  -243,   393,  -243,
     397,    10,  -243,   365,  -243,  -243,   383,  -243,  -243,  -243,
    -243,   290,  -243,   352,   353,   185,   593,   369,  -243,    82,
      75,  -243,  -243,   396,   400,  -243,  -243,   184,  -243,    82,
     100,  -243,  -243,  -243,  -243,   382,  -243,  -243,  -243,  -243
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,   153,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   176,   177,   178,   179,   149,
       0,   173,   170,   145,   174,     2,   152,   156,   154,   164,
     169,     8,     0,     4,     0,     7,    15,     1,   159,     0,
     175,     0,   106,   108,     0,     0,     0,   154,     0,   200,
     201,     0,     0,     0,     0,   166,   172,     0,   168,     0,
       0,     3,     0,   105,   106,   108,     0,   103,   104,     0,
     167,    17,    21,    20,    22,    13,   100,   100,   100,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     0,
     170,     0,    14,   146,     0,     0,   148,   150,     0,     0,
       0,   180,     0,     0,   181,     0,     0,     0,   182,     0,
       0,     0,   165,   131,     0,   171,     0,    79,     0,     0,
      82,    83,   151,     0,    75,    77,    81,   157,   155,     0,
       0,    99,     0,     0,     0,    55,    54,     0,     0,    76,
       0,   119,   121,   123,   113,     0,     0,   112,     0,   117,
      19,    28,   216,     0,   215,     6,   214,     0,     0,   134,
       0,     0,   129,   133,   136,   139,   107,   109,   184,   185,
     187,   183,   186,   187,     0,   211,   202,   208,   203,     0,
       0,   160,     0,     0,     0,     0,    93,    84,     0,    77,
       0,     0,    91,     0,     0,     0,    80,     0,    42,     0,
       0,    25,    26,    41,     0,    96,   102,    97,    98,     0,
      53,     0,     0,     0,     0,   115,     0,   116,     0,     0,
       0,     0,   114,    31,     0,    35,     9,    10,   213,   128,
     143,   135,     0,   132,     0,   138,     0,     0,     0,     0,
       0,     0,     0,   189,     0,   130,     0,   137,    85,     0,
      86,     0,    92,    88,     0,    89,    90,    74,    78,   158,
      48,    27,     0,    23,     0,     0,    57,     0,    66,    67,
      63,    65,   118,     0,     0,   110,   111,    42,     0,    32,
      34,     0,     0,    18,     0,     0,     0,   206,     0,   210,
     209,   207,   195,     0,     0,   190,   192,   193,   197,     0,
     163,   162,   161,    95,    87,    94,     0,     0,     0,     0,
      49,   144,    47,    24,     0,   101,     0,    50,     0,     0,
       0,    51,     0,     0,   127,     0,   125,   126,     0,    30,
       0,     0,     0,     0,   142,   140,   212,   194,     0,   191,
     196,   188,     0,    43,     0,    44,    45,    16,    56,    59,
      61,    67,    62,    70,    68,    64,     0,   120,   122,    33,
      29,     0,    38,     0,     0,   141,     0,     0,    46,     0,
       0,    52,    73,     0,    71,   127,   124,     0,    36,     0,
       0,   198,    58,    60,    69,     0,    37,    39,    40,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -243,  -243,  -243,  -243,   152,  -243,   392,   264,   -10,  -243,
    -243,   156,  -243,  -243,   147,  -243,  -243,    52,  -207,  -243,
    -243,   220,  -243,  -243,    66,   120,   118,    94,  -243,  -243,
    -148,   238,   -39,   329,  -106,  -243,  -243,   119,    54,   -15,
     433,    -6,  -243,   222,   367,  -243,  -243,  -243,    95,   -17,
    -105,  -243,  -243,  -153,  -243,   294,   194,   -19,  -243,  -242,
      -2,    -4,  -243,    -3,  -243,    45,   108,   442,  -243,   160,
    -243,  -243,  -243,   163,  -243,  -243,   229,  -111,  -151
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,    33,    34,    86,    35,    36,    87,   199,   130,
     200,   201,   225,   278,   279,   283,   361,   362,   202,   308,
     309,   137,   317,   348,   349,   269,   270,   321,   373,   374,
     122,   123,   124,   125,   126,   190,   191,   132,   205,   206,
      67,    68,   146,   147,   142,   215,   217,   325,   326,   113,
     114,   162,   163,    61,   164,   165,    89,    22,    23,    24,
     175,    26,    27,    28,    54,    29,    30,    48,   242,   243,
     295,   296,   297,   298,    51,   176,   177,   155,   156
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    45,   228,   183,    47,    46,    49,    52,    53,   229,
     233,   184,    66,    69,    31,    90,   280,    88,   312,   196,
     152,    71,    74,   152,   152,    63,   319,   135,   152,   353,
      91,   228,   102,    37,   238,    57,   153,    59,    90,   182,
     299,   139,   141,   141,   356,   149,   209,   150,    41,    64,
     157,    38,   117,    91,   223,    65,   158,   354,   239,    72,
     320,   318,    73,   127,   148,   118,   128,    32,   136,    60,
     119,   192,   275,   247,   280,   151,   117,   210,   154,   188,
     193,   154,   154,   196,    38,    72,   154,   120,    73,   118,
     364,   224,   210,   121,   119,   234,   145,    90,   170,   128,
     218,   172,   368,   173,    62,   178,   161,    32,   180,   181,
     203,   120,    91,   197,   367,   -79,   144,   121,    14,    55,
      56,   218,   -79,   359,   219,   103,   322,    96,    58,   145,
     342,   300,   288,    65,    90,   364,   227,    70,   388,   230,
      97,    94,    19,   339,   220,   219,    70,    95,   228,    91,
     221,    14,    98,    99,   145,   257,   258,   260,   231,   232,
     105,   -20,   112,    90,   106,   245,   107,   115,   109,   328,
     266,   145,   117,   271,   272,   241,    14,   336,    91,    72,
     159,   185,   198,   186,   160,   118,   187,   207,   208,   100,
     119,   292,   101,    14,   259,   161,   133,   134,   306,   277,
     293,   108,   148,   347,   203,   228,   294,   120,   116,   110,
     303,   117,   258,   121,   357,   305,   103,   358,    90,   104,
      14,  -144,   383,   129,   118,   304,    19,  -144,    59,   119,
     131,   166,   286,    91,   287,   306,   289,   290,   168,   307,
     268,   311,   301,   203,   302,    90,   120,    88,   249,   169,
     315,   250,   121,   118,    90,    90,   327,    14,   119,   167,
      91,   194,   203,    19,     1,   323,     2,     3,   195,    91,
      91,   252,   118,   254,   253,   120,   255,   119,   204,   271,
     271,   121,   334,   335,   355,   262,   152,   179,   263,   344,
     338,   337,   345,   -76,   120,   241,     6,   350,   330,     7,
     121,   360,   377,   251,     8,   378,     9,   118,    10,   211,
     212,   203,   119,   363,   213,    11,    12,    13,   138,   140,
     140,    14,    15,    16,    17,    18,   214,    19,   216,   120,
     222,   365,    20,   236,   240,   121,   237,    90,   244,   327,
     246,   152,   248,    21,   154,   256,   261,    76,    77,    78,
     350,     6,    91,   264,     7,   265,   273,    93,   363,     8,
     387,     9,   281,    10,   381,   274,   282,    79,    80,   284,
      11,    12,    13,   285,   316,   260,    14,    15,    16,    17,
      18,   329,    19,    81,   375,    82,   330,    20,    83,    84,
     332,   294,    85,   343,     6,   346,   158,     7,    21,   154,
      95,   366,     8,   370,     9,   369,    10,   372,   379,   380,
     342,   384,   385,    11,    12,    13,   314,   226,   313,    14,
      15,    16,    17,    18,   389,    19,    75,    92,   331,   386,
      20,   267,    76,    77,    78,   382,     6,   352,   351,     7,
      44,    21,   154,   276,     8,   371,     9,   189,    10,   143,
      50,   376,    79,    80,   310,    11,    12,    13,   235,   341,
     340,    14,    15,    16,    17,    18,     5,    19,    81,   291,
      82,     0,    20,    83,    84,     0,    39,    85,     0,     7,
      40,     0,     0,    21,     8,     0,     9,     0,    10,     0,
       0,     0,     0,     0,     0,    11,    12,    13,     5,    41,
      42,    14,    15,    16,    17,    18,    43,    19,     6,     0,
       0,     7,    20,     0,     0,     0,     8,  -199,     9,     0,
      10,     0,     0,    21,     0,     0,     0,    11,    12,    13,
       5,     0,     0,    14,    15,    16,    17,    18,     0,    19,
       6,     0,     0,     7,    20,     0,     0,     0,     8,  -205,
       9,     0,    10,     0,     0,    21,     0,     0,     0,    11,
      12,    13,     5,     0,     0,    14,    15,    16,    17,    18,
       0,    19,     6,     0,     0,     7,    20,     0,     0,     0,
       8,  -204,     9,     0,    10,     0,     0,    21,     0,     0,
       0,    11,    12,    13,     5,     0,     0,    14,    15,    16,
      17,    18,     0,    19,     6,     0,     0,     7,    20,     0,
       0,     0,     8,     0,     9,     0,    10,     0,     0,    21,
       0,     0,     0,    11,    12,    13,     5,     0,     0,    14,
      15,    16,    17,    18,     0,    19,     6,     0,     0,     7,
      20,     0,     0,     0,     8,     0,     9,     0,    10,     0,
       0,    21,     0,     0,     0,    11,    12,   174,   324,     0,
       0,    14,    15,    16,    17,    18,     0,    19,     6,     0,
       0,     7,    20,     0,     0,     0,     8,     0,     9,     0,
      10,     0,     0,    21,     0,     0,     0,    11,    12,    13,
       5,     0,     0,    14,    15,    16,    17,    18,     0,    19,
       6,     0,     0,     7,    20,     0,     0,     0,     8,     0,
       9,     0,   333,   111,     0,    21,     0,     7,     0,    11,
      12,    13,     8,     0,     0,    14,    15,    16,    17,    18,
       0,    19,     0,     0,    12,     0,    20,     0,     0,    14,
      15,    16,    17,    18,     0,    19,     6,    21,     0,     7,
     171,     0,     0,     0,     8,     0,     9,     0,    10,     0,
       0,    21,     0,     0,     0,    11,    12,    13,     0,     0,
       0,    14,    15,    16,    17,    18,     6,    19,     0,     7,
       0,     0,    20,     0,     8,     0,     9,     0,    10,     0,
       0,     0,     0,    21,     7,    11,    12,    13,     0,     8,
       0,    14,    15,    16,    17,    18,     0,    19,     7,    93,
       0,    12,    20,     8,     0,     0,    14,    15,    16,    17,
      18,     0,    19,    21,     0,    12,     0,    20,     0,     0,
      14,    15,    16,    17,    18,     0,    19,     7,    21,     0,
       0,    20,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,    12,     0,     0,     0,     0,    14,
      15,    16,    17,    18,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21
};

static const yytype_int16 yycheck[] =
{
       2,     7,   153,   114,     7,     7,     8,     9,    10,   157,
     163,   116,    27,    28,     1,    34,   223,    34,   260,   125,
       1,     1,    32,     1,     1,    11,    16,     1,     1,    14,
      34,   182,    47,     0,     5,    57,    17,    13,    57,    17,
      17,    80,    81,    82,    17,    84,     5,     1,    34,    35,
       6,     6,     1,    57,    14,    41,    12,    42,    29,    39,
      50,     5,    42,    66,    83,    14,    69,    54,    42,    26,
      19,    20,   220,   184,   281,    85,     1,    36,    59,   118,
     119,    59,    59,   189,    39,    39,    59,    36,    42,    14,
     332,    51,    36,    42,    19,     5,    14,   116,   100,   102,
      11,   103,   344,   105,     6,   107,    16,    54,   110,   111,
     129,    36,   116,   128,    14,    34,     1,    42,    36,    11,
      12,    11,    41,   330,    35,    12,    34,    15,    20,    14,
      41,   242,   237,    41,   153,   377,   153,    29,   380,   158,
      15,    36,    42,   296,     6,    35,    38,    42,   299,   153,
      12,    36,    44,    45,    14,   194,   195,    14,   160,   161,
      12,    18,    54,   182,    16,   182,    18,    59,    22,   274,
     209,    14,     1,   212,   213,   179,    36,   288,   182,    39,
       1,    10,    42,    12,     5,    14,    15,   133,   134,    12,
      19,     1,    15,    36,   197,    16,    77,    78,    14,    42,
      10,    20,   221,   314,   223,   356,    16,    36,    57,    24,
     249,     1,   251,    42,   325,   254,    12,   328,   237,    15,
      36,     6,   370,    14,    14,    15,    42,    12,    13,    19,
      37,    34,   234,   237,   236,    14,   238,   239,    15,    18,
       1,   260,   244,   262,   246,   264,    36,   264,    12,    15,
     265,    15,    42,    14,   273,   274,   273,    36,    19,    34,
     264,    44,   281,    42,     1,   271,     3,     4,    10,   273,
     274,    12,    14,    12,    15,    36,    15,    19,    26,   318,
     319,    42,   284,   285,   323,    12,     1,    57,    15,    12,
     294,   293,    15,    44,    36,   299,    11,   316,    12,    14,
      42,    15,    12,    10,    19,    15,    21,    14,    23,    44,
       5,   330,    19,   332,    44,    30,    31,    32,    80,    81,
      82,    36,    37,    38,    39,    40,    26,    42,    26,    36,
      39,   333,    47,    18,    12,    42,    57,   356,    25,   356,
      33,     1,    15,    58,    59,    20,    18,     7,     8,     9,
     369,    11,   356,    57,    14,    12,    57,    15,   377,    19,
     379,    21,    14,    23,   366,    57,    55,    27,    28,    12,
      30,    31,    32,     5,    33,    14,    36,    37,    38,    39,
      40,    15,    42,    43,     1,    45,    12,    47,    48,    49,
      14,    16,    52,    15,    11,    15,    12,    14,    58,    59,
      42,    10,    19,     6,    21,    12,    23,    42,    56,    56,
      41,    15,    12,    30,    31,    32,   264,   153,   262,    36,
      37,    38,    39,    40,    42,    42,     1,    35,   281,   377,
      47,   211,     7,     8,     9,   369,    11,   319,   318,    14,
       7,    58,    59,   221,    19,   351,    21,   118,    23,    82,
       8,   356,    27,    28,   260,    30,    31,    32,   164,   299,
     297,    36,    37,    38,    39,    40,     1,    42,    43,   240,
      45,    -1,    47,    48,    49,    -1,    11,    52,    -1,    14,
      15,    -1,    -1,    58,    19,    -1,    21,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,     1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    11,    -1,
      -1,    14,    47,    -1,    -1,    -1,    19,    20,    21,    -1,
      23,    -1,    -1,    58,    -1,    -1,    -1,    30,    31,    32,
       1,    -1,    -1,    36,    37,    38,    39,    40,    -1,    42,
      11,    -1,    -1,    14,    47,    -1,    -1,    -1,    19,    20,
      21,    -1,    23,    -1,    -1,    58,    -1,    -1,    -1,    30,
      31,    32,     1,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    42,    11,    -1,    -1,    14,    47,    -1,    -1,    -1,
      19,    20,    21,    -1,    23,    -1,    -1,    58,    -1,    -1,
      -1,    30,    31,    32,     1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    42,    11,    -1,    -1,    14,    47,    -1,
      -1,    -1,    19,    -1,    21,    -1,    23,    -1,    -1,    58,
      -1,    -1,    -1,    30,    31,    32,     1,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    42,    11,    -1,    -1,    14,
      47,    -1,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,
      -1,    58,    -1,    -1,    -1,    30,    31,    32,     1,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    42,    11,    -1,
      -1,    14,    47,    -1,    -1,    -1,    19,    -1,    21,    -1,
      23,    -1,    -1,    58,    -1,    -1,    -1,    30,    31,    32,
       1,    -1,    -1,    36,    37,    38,    39,    40,    -1,    42,
      11,    -1,    -1,    14,    47,    -1,    -1,    -1,    19,    -1,
      21,    -1,    23,    10,    -1,    58,    -1,    14,    -1,    30,
      31,    32,    19,    -1,    -1,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    31,    -1,    47,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    42,    11,    58,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    21,    -1,    23,    -1,
      -1,    58,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    11,    42,    -1,    14,
      -1,    -1,    47,    -1,    19,    -1,    21,    -1,    23,    -1,
      -1,    -1,    -1,    58,    14,    30,    31,    32,    -1,    19,
      -1,    36,    37,    38,    39,    40,    -1,    42,    14,    15,
      -1,    31,    47,    19,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    42,    58,    -1,    31,    -1,    47,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    42,    14,    58,    -1,
      -1,    47,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    31,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,    61,     1,    11,    14,    19,    21,
      23,    30,    31,    32,    36,    37,    38,    39,    40,    42,
      47,    58,   117,   118,   119,   120,   121,   122,   123,   125,
     126,     1,    54,    62,    63,    65,    66,     0,   125,    11,
      15,    34,    35,    41,   100,   101,   120,   123,   127,   120,
     127,   134,   120,   120,   124,   126,   126,    57,   126,    13,
      26,   113,     6,    11,    35,    41,    99,   100,   101,    99,
     126,     1,    39,    42,    68,     1,     7,     8,     9,    27,
      28,    43,    45,    48,    49,    52,    64,    67,   109,   116,
     117,   121,    66,    15,    36,    42,    15,    15,   126,   126,
      12,    15,    99,    12,    15,    12,    16,    18,    20,    22,
      24,    10,   126,   109,   110,   126,    57,     1,    14,    19,
      36,    42,    90,    91,    92,    93,    94,   123,   123,    14,
      69,    37,    97,    97,    97,     1,    42,    81,    91,    92,
      91,    92,   104,   104,     1,    14,   102,   103,   117,    92,
       1,    68,     1,    17,    59,   137,   138,     6,    12,     1,
       5,    16,   111,   112,   114,   115,    34,    34,    15,    15,
     120,    15,   120,   120,    32,   120,   135,   136,   120,    57,
     120,   120,    17,   137,   110,    10,    12,    15,    92,    93,
      95,    96,    20,    92,    44,    10,    94,    99,    42,    68,
      70,    71,    78,   117,    26,    98,    99,    98,    98,     5,
      36,    44,     5,    44,    26,   105,    26,   106,    11,    35,
       6,    12,    39,    14,    51,    72,    67,   109,   138,    90,
     117,   120,   120,   113,     5,   115,    18,    57,     5,    29,
      12,   121,   128,   129,    25,   109,    33,   137,    15,    12,
      15,    10,    12,    15,    12,    15,    20,    92,    92,   123,
      14,    18,    12,    15,    57,    12,    92,    81,     1,    85,
      86,    92,    92,    57,    57,    90,   103,    42,    73,    74,
      78,    14,    55,    75,    12,     5,   120,   120,   110,   120,
     120,   136,     1,    10,    16,   130,   131,   132,   133,    17,
     137,   120,   120,    92,    15,    92,    14,    18,    79,    80,
     116,   117,   119,    71,    64,    99,    33,    82,     5,    16,
      50,    87,    34,   101,     1,   107,   108,   109,   110,    15,
      12,    74,    14,    23,   120,   120,   137,   120,   121,   113,
     133,   129,    41,    15,    12,    15,    15,   137,    83,    84,
     117,    85,    86,    14,    42,    92,    17,   137,   137,    78,
      15,    76,    77,   117,   119,   120,    10,    14,   119,    12,
       6,    87,    42,    88,    89,     1,   108,    12,    15,    56,
      56,   120,    84,    90,    15,    12,    77,   117,   119,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    62,    62,    63,    64,
      64,    64,    64,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      67,    67,    67,    81,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    87,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    95,    95,    96,    96,    67,    67,    67,    97,
      97,    98,    98,    99,    99,    99,   100,   100,   101,   101,
      67,   102,   102,   102,   103,    67,    67,    67,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   111,   112,   112,   113,   114,   114,
     115,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   120,   120,   121,   121,   121,   122,   122,   123,
     123,   123,   123,   123,   123,   124,   124,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   127,   127,   128,   128,
     129,   130,   130,   131,   131,   131,   132,   132,   133,   134,
     134,   134,   134,   134,   134,   134,   134,   135,   135,   136,
     136,   136,   136,   137,   137,   138,   138
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     3,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     7,     2,     4,     2,
       1,     1,     0,     3,     3,     1,     1,     2,     0,     4,
       3,     0,     1,     3,     1,     0,     4,     3,     1,     3,
       3,     1,     1,     4,     4,     4,     3,     1,     0,     1,
       5,     5,     7,     2,     1,     1,     2,     0,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     0,     2,     4,
       0,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     2,     3,     3,     4,     3,     3,
       3,     2,     2,     1,     3,     3,     3,     3,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       4,     3,     1,     1,     2,     3,     3,     2,     3,     1,
       4,     0,     4,     0,     3,     1,     1,     1,     3,     2,
       3,     1,     2,     1,     1,     2,     1,     4,     2,     1,
       4,     5,     4,     3,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     1,     1,     3,     1,     3,     5,     2,
       4,     6,     6,     6,     1,     2,     1,     2,     2,     1,
       1,     3,     2,     1,     1,     2,     1,     1,     1,     1,
       3,     3,     3,     4,     4,     4,     3,     3,     3,     1,
       2,     2,     1,     1,     2,     1,     2,     1,     4,     0,
       1,     1,     3,     3,     4,     2,     5,     3,     1,     3,
       3,     1,     4,     2,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: EVALEX exp  */
#line 86 "parser.y"
                                        {inputExpr = yyvsp[0];	    sp-=1;}
#line 1743 "y.tab.c"
    break;

  case 3: /* start: EVALEX exp wherePart  */
#line 87 "parser.y"
                                        {inputExpr = letrec(yyvsp[0],yyvsp[-1]); sp-=2;}
#line 1749 "y.tab.c"
    break;

  case 4: /* start: SCRIPT topModule  */
#line 88 "parser.y"
                                        {valDefns  = yyvsp[0];	    sp-=1;}
#line 1755 "y.tab.c"
    break;

  case 5: /* start: error  */
#line 89 "parser.y"
                                        {syntaxError("input");}
#line 1761 "y.tab.c"
    break;

  case 6: /* topModule: begin topDecls close  */
#line 102 "parser.y"
                                        {yyval = gc2(yyvsp[-1]);}
#line 1767 "y.tab.c"
    break;

  case 7: /* topModule: modules  */
#line 103 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1773 "y.tab.c"
    break;

  case 8: /* begin: error  */
#line 105 "parser.y"
                                        {yyerrok; goOffside(startColumn);}
#line 1779 "y.tab.c"
    break;

  case 9: /* topDecls: topDecls ';' topDecl  */
#line 107 "parser.y"
                                        {yyval = gc2(yyvsp[-2]);}
#line 1785 "y.tab.c"
    break;

  case 10: /* topDecls: topDecls ';' decl  */
#line 108 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 1791 "y.tab.c"
    break;

  case 11: /* topDecls: topDecl  */
#line 109 "parser.y"
                                        {yyval = gc0(NIL);}
#line 1797 "y.tab.c"
    break;

  case 12: /* topDecls: decl  */
#line 110 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 1803 "y.tab.c"
    break;

  case 13: /* topDecls: error  */
#line 111 "parser.y"
                                        {syntaxError("definition");}
#line 1809 "y.tab.c"
    break;

  case 14: /* modules: modules module  */
#line 113 "parser.y"
                                        {yyval = gc2(appendOnto(yyvsp[0],yyvsp[-1]));}
#line 1815 "y.tab.c"
    break;

  case 15: /* modules: module  */
#line 114 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1821 "y.tab.c"
    break;

  case 16: /* module: MODULE modid expspec WHERE '{' topDecls close  */
#line 117 "parser.y"
                                        {yyval = gc7(yyvsp[-1]);}
#line 1827 "y.tab.c"
    break;

  case 17: /* module: MODULE error  */
#line 118 "parser.y"
                                        {syntaxError("module definition");}
#line 1833 "y.tab.c"
    break;

  case 18: /* topDecl: IMPORT modid impspec rename  */
#line 120 "parser.y"
                                        {sp-=4;}
#line 1839 "y.tab.c"
    break;

  case 19: /* topDecl: IMPORT error  */
#line 121 "parser.y"
                                        {syntaxError("import declaration");}
#line 1845 "y.tab.c"
    break;

  case 20: /* modid: CONID  */
#line 123 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1851 "y.tab.c"
    break;

  case 21: /* modid: STRINGLIT  */
#line 124 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1857 "y.tab.c"
    break;

  case 22: /* expspec: %empty  */
#line 126 "parser.y"
                                        {yyval = gc0(NIL);}
#line 1863 "y.tab.c"
    break;

  case 23: /* expspec: '(' exports ')'  */
#line 127 "parser.y"
                                        {yyval = gc3(NIL);}
#line 1869 "y.tab.c"
    break;

  case 24: /* exports: exports ',' export  */
#line 129 "parser.y"
                                        {yyval = gc3(NIL);}
#line 1875 "y.tab.c"
    break;

  case 25: /* exports: export  */
#line 130 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1881 "y.tab.c"
    break;

  case 26: /* export: entity  */
#line 132 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1887 "y.tab.c"
    break;

  case 27: /* export: modid UPTO  */
#line 133 "parser.y"
                                        {yyval = gc2(NIL);}
#line 1893 "y.tab.c"
    break;

  case 28: /* impspec: %empty  */
#line 135 "parser.y"
                                        {yyval = gc0(NIL);}
#line 1899 "y.tab.c"
    break;

  case 29: /* impspec: HIDING '(' imports ')'  */
#line 136 "parser.y"
                                        {yyval = gc4(NIL);}
#line 1905 "y.tab.c"
    break;

  case 30: /* impspec: '(' imports0 ')'  */
#line 137 "parser.y"
                                        {yyval = gc3(NIL);}
#line 1911 "y.tab.c"
    break;

  case 31: /* imports0: %empty  */
#line 139 "parser.y"
                                        {yyval = gc0(NIL);}
#line 1917 "y.tab.c"
    break;

  case 32: /* imports0: imports  */
#line 140 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1923 "y.tab.c"
    break;

  case 33: /* imports: imports ',' entity  */
#line 142 "parser.y"
                                        {yyval = gc3(NIL);}
#line 1929 "y.tab.c"
    break;

  case 34: /* imports: entity  */
#line 143 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1935 "y.tab.c"
    break;

  case 35: /* rename: %empty  */
#line 145 "parser.y"
                                        {yyval = gc0(NIL);}
#line 1941 "y.tab.c"
    break;

  case 36: /* rename: RENAMING '(' renamings ')'  */
#line 146 "parser.y"
                                        {yyval = gc4(NIL);}
#line 1947 "y.tab.c"
    break;

  case 37: /* renamings: renamings ',' renaming  */
#line 148 "parser.y"
                                        {yyval = gc3(NIL);}
#line 1953 "y.tab.c"
    break;

  case 38: /* renamings: renaming  */
#line 149 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1959 "y.tab.c"
    break;

  case 39: /* renaming: var TO var  */
#line 151 "parser.y"
                                        {yyval = gc3(NIL);}
#line 1965 "y.tab.c"
    break;

  case 40: /* renaming: conid TO conid  */
#line 152 "parser.y"
                                        {yyval = gc3(NIL);}
#line 1971 "y.tab.c"
    break;

  case 41: /* entity: var  */
#line 154 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1977 "y.tab.c"
    break;

  case 42: /* entity: CONID  */
#line 155 "parser.y"
                                        {yyval = yyvsp[0];}
#line 1983 "y.tab.c"
    break;

  case 43: /* entity: CONID '(' UPTO ')'  */
#line 156 "parser.y"
                                        {yyval = gc4(NIL);}
#line 1989 "y.tab.c"
    break;

  case 44: /* entity: CONID '(' conids ')'  */
#line 157 "parser.y"
                                        {yyval = gc4(NIL);}
#line 1995 "y.tab.c"
    break;

  case 45: /* entity: CONID '(' vars0 ')'  */
#line 158 "parser.y"
                                        {yyval = gc4(NIL);}
#line 2001 "y.tab.c"
    break;

  case 46: /* conids: conids ',' conid  */
#line 160 "parser.y"
                                        {yyval = gc3(NIL);}
#line 2007 "y.tab.c"
    break;

  case 47: /* conids: conid  */
#line 161 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2013 "y.tab.c"
    break;

  case 48: /* vars0: %empty  */
#line 163 "parser.y"
                                        {yyval = gc0(NIL);}
#line 2019 "y.tab.c"
    break;

  case 49: /* vars0: vars  */
#line 164 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2025 "y.tab.c"
    break;

  case 50: /* topDecl: TYPE tyLhs '=' type invars  */
#line 169 "parser.y"
                                        {defTycon(5,yyvsp[-2],yyvsp[-3],yyvsp[-1],yyvsp[0]);}
#line 2031 "y.tab.c"
    break;

  case 51: /* topDecl: DATA type '=' constrs deriving  */
#line 171 "parser.y"
                                        {defTycon(5,yyvsp[-2],checkTyLhs(yyvsp[-3]),
							rev(yyvsp[-1]),DATATYPE);}
#line 2038 "y.tab.c"
    break;

  case 52: /* topDecl: DATA context IMPLIES tyLhs '=' constrs deriving  */
#line 174 "parser.y"
                                        {defTycon(7,yyvsp[-2],yyvsp[-3],
						  ap(QUAL,pair(yyvsp[-5],rev(yyvsp[-1]))),
						  DATATYPE);}
#line 2046 "y.tab.c"
    break;

  case 53: /* tyLhs: tyLhs VARID  */
#line 178 "parser.y"
                                        {yyval = gc2(ap(yyvsp[-1],yyvsp[0]));}
#line 2052 "y.tab.c"
    break;

  case 54: /* tyLhs: CONID  */
#line 179 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2058 "y.tab.c"
    break;

  case 55: /* tyLhs: error  */
#line 180 "parser.y"
                                        {syntaxError("type defn lhs");}
#line 2064 "y.tab.c"
    break;

  case 56: /* invars: IN rsvars  */
#line 182 "parser.y"
                                        {yyval = gc2(yyvsp[0]);}
#line 2070 "y.tab.c"
    break;

  case 57: /* invars: %empty  */
#line 183 "parser.y"
                                        {yyval = gc0(SYNONYM);}
#line 2076 "y.tab.c"
    break;

  case 58: /* rsvars: rsvars ',' rsvar  */
#line 185 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2082 "y.tab.c"
    break;

  case 59: /* rsvars: rsvar  */
#line 186 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2088 "y.tab.c"
    break;

  case 60: /* rsvar: var COCO sigType  */
#line 188 "parser.y"
                                        {yyval = gc3(sigdecl(yyvsp[-1],singleton(yyvsp[-2]),
							     yyvsp[0]));}
#line 2095 "y.tab.c"
    break;

  case 61: /* rsvar: var  */
#line 190 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2101 "y.tab.c"
    break;

  case 62: /* constrs: constrs '|' constr  */
#line 192 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2107 "y.tab.c"
    break;

  case 63: /* constrs: constr  */
#line 193 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2113 "y.tab.c"
    break;

  case 64: /* constr: type conop type  */
#line 195 "parser.y"
                                        {yyval = gc3(ap(ap(yyvsp[-1],yyvsp[-2]),yyvsp[0]));}
#line 2119 "y.tab.c"
    break;

  case 65: /* constr: type  */
#line 196 "parser.y"
                                        {if (!isCon(getHead(yyvsp[0])))
					     syntaxError("data constructor");
					 yyval = yyvsp[0];}
#line 2127 "y.tab.c"
    break;

  case 66: /* constr: error  */
#line 199 "parser.y"
                                        {syntaxError("data type definition");}
#line 2133 "y.tab.c"
    break;

  case 67: /* deriving: %empty  */
#line 201 "parser.y"
                                        {yyval = gc0(NIL);}
#line 2139 "y.tab.c"
    break;

  case 68: /* deriving: DERIVING CONID  */
#line 202 "parser.y"
                                        {yyval = gc2(singleton(yyvsp[0]));}
#line 2145 "y.tab.c"
    break;

  case 69: /* deriving: DERIVING '(' derivs0 ')'  */
#line 203 "parser.y"
                                        {yyval = gc4(yyvsp[-1]);}
#line 2151 "y.tab.c"
    break;

  case 70: /* derivs0: %empty  */
#line 205 "parser.y"
                                        {yyval = gc0(NIL);}
#line 2157 "y.tab.c"
    break;

  case 71: /* derivs0: derivs  */
#line 206 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2163 "y.tab.c"
    break;

  case 72: /* derivs: derivs ',' CONID  */
#line 208 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2169 "y.tab.c"
    break;

  case 73: /* derivs: CONID  */
#line 209 "parser.y"
                                        {yyval = gc1(singleton(yyvsp[0]));}
#line 2175 "y.tab.c"
    break;

  case 74: /* sigType: context IMPLIES type  */
#line 220 "parser.y"
                                        {yyval = gc3(ap(QUAL,pair(yyvsp[-2],yyvsp[0])));}
#line 2181 "y.tab.c"
    break;

  case 75: /* sigType: type  */
#line 221 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2187 "y.tab.c"
    break;

  case 76: /* context: type  */
#line 223 "parser.y"
                                        {yyval = gc1(checkContext(yyvsp[0]));}
#line 2193 "y.tab.c"
    break;

  case 77: /* type: ctype  */
#line 225 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2199 "y.tab.c"
    break;

  case 78: /* type: ctype FUNARROW type  */
#line 226 "parser.y"
                                        {yyval = gc3(ap(ap(ARROW,yyvsp[-2]),yyvsp[0]));}
#line 2205 "y.tab.c"
    break;

  case 79: /* type: error  */
#line 227 "parser.y"
                                        {syntaxError("type expression");}
#line 2211 "y.tab.c"
    break;

  case 80: /* ctype: ctype atype  */
#line 229 "parser.y"
                                        {yyval = gc2(ap(yyvsp[-1],yyvsp[0]));}
#line 2217 "y.tab.c"
    break;

  case 81: /* ctype: atype  */
#line 230 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2223 "y.tab.c"
    break;

  case 82: /* atype: VARID  */
#line 232 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2229 "y.tab.c"
    break;

  case 83: /* atype: CONID  */
#line 233 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2235 "y.tab.c"
    break;

  case 84: /* atype: '(' ')'  */
#line 234 "parser.y"
                                        {yyval = gc2(UNIT);}
#line 2241 "y.tab.c"
    break;

  case 85: /* atype: '(' FUNARROW ')'  */
#line 235 "parser.y"
                                        {yyval = gc3(ARROW);}
#line 2247 "y.tab.c"
    break;

  case 86: /* atype: '(' type ')'  */
#line 236 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2253 "y.tab.c"
    break;

  case 87: /* atype: '(' ctype FUNARROW ')'  */
#line 237 "parser.y"
                                        {yyval = gc4(ap(ARROW,yyvsp[-2]));}
#line 2259 "y.tab.c"
    break;

  case 88: /* atype: '(' tupCommas ')'  */
#line 238 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2265 "y.tab.c"
    break;

  case 89: /* atype: '(' typeTuple ')'  */
#line 239 "parser.y"
                                        {yyval = gc3(buildTuple(yyvsp[-1]));}
#line 2271 "y.tab.c"
    break;

  case 90: /* atype: '[' type ']'  */
#line 240 "parser.y"
                                        {yyval = gc3(ap(LIST,yyvsp[-1]));}
#line 2277 "y.tab.c"
    break;

  case 91: /* atype: '[' ']'  */
#line 241 "parser.y"
                                        {yyval = gc2(LIST);}
#line 2283 "y.tab.c"
    break;

  case 92: /* tupCommas: tupCommas ','  */
#line 243 "parser.y"
                                        {yyval = gc2(mkTuple(tupleOf(yyvsp[-1])+1));}
#line 2289 "y.tab.c"
    break;

  case 93: /* tupCommas: ','  */
#line 244 "parser.y"
                                        {yyval = gc1(mkTuple(2));}
#line 2295 "y.tab.c"
    break;

  case 94: /* typeTuple: typeTuple ',' type  */
#line 246 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2301 "y.tab.c"
    break;

  case 95: /* typeTuple: type ',' type  */
#line 247 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],cons(yyvsp[-2],NIL)));}
#line 2307 "y.tab.c"
    break;

  case 96: /* topDecl: INFIXL optdigit ops  */
#line 252 "parser.y"
                                        {fixDefn(LEFT_ASS,yyvsp[-2],yyvsp[-1],yyvsp[0]); sp-=3;}
#line 2313 "y.tab.c"
    break;

  case 97: /* topDecl: INFIXR optdigit ops  */
#line 253 "parser.y"
                                        {fixDefn(RIGHT_ASS,yyvsp[-2],yyvsp[-1],yyvsp[0]);sp-=3;}
#line 2319 "y.tab.c"
    break;

  case 98: /* topDecl: INFIX optdigit ops  */
#line 254 "parser.y"
                                        {fixDefn(NON_ASS,yyvsp[-2],yyvsp[-1],yyvsp[0]);  sp-=3;}
#line 2325 "y.tab.c"
    break;

  case 99: /* optdigit: NUMLIT  */
#line 256 "parser.y"
                                        {yyval = gc1(checkPrec(yyvsp[0]));}
#line 2331 "y.tab.c"
    break;

  case 100: /* optdigit: %empty  */
#line 257 "parser.y"
                                        {yyval = gc0(mkInt(DEF_PREC));}
#line 2337 "y.tab.c"
    break;

  case 101: /* ops: ops ',' op  */
#line 259 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2343 "y.tab.c"
    break;

  case 102: /* ops: op  */
#line 260 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2349 "y.tab.c"
    break;

  case 103: /* op: varop  */
#line 262 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2355 "y.tab.c"
    break;

  case 104: /* op: conop  */
#line 263 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2361 "y.tab.c"
    break;

  case 105: /* op: '-'  */
#line 264 "parser.y"
                                        {yyval = gc1(varMinus);}
#line 2367 "y.tab.c"
    break;

  case 106: /* varop: VAROP  */
#line 266 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2373 "y.tab.c"
    break;

  case 107: /* varop: '`' VARID '`'  */
#line 267 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2379 "y.tab.c"
    break;

  case 108: /* conop: CONOP  */
#line 269 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2385 "y.tab.c"
    break;

  case 109: /* conop: '`' CONID '`'  */
#line 270 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2391 "y.tab.c"
    break;

  case 110: /* topDecl: PRIMITIVE prims COCO sigType  */
#line 275 "parser.y"
                                        {primDefn(yyvsp[-3],yyvsp[-2],yyvsp[0]); sp-=4;}
#line 2397 "y.tab.c"
    break;

  case 111: /* prims: prims ',' prim  */
#line 277 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2403 "y.tab.c"
    break;

  case 112: /* prims: prim  */
#line 278 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2409 "y.tab.c"
    break;

  case 113: /* prims: error  */
#line 279 "parser.y"
                                        {syntaxError("primitive defn");}
#line 2415 "y.tab.c"
    break;

  case 114: /* prim: var STRINGLIT  */
#line 281 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2421 "y.tab.c"
    break;

  case 115: /* topDecl: TCLASS classHead classBody  */
#line 286 "parser.y"
                                        {classDefn(intOf(yyvsp[-2]),yyvsp[-1],yyvsp[0]); sp-=3;}
#line 2427 "y.tab.c"
    break;

  case 116: /* topDecl: TINSTANCE classHead instBody  */
#line 287 "parser.y"
                                        {instDefn(intOf(yyvsp[-2]),yyvsp[-1],yyvsp[0]);  sp-=3;}
#line 2433 "y.tab.c"
    break;

  case 117: /* topDecl: DEFAULT type  */
#line 288 "parser.y"
                                        {sp-=2;}
#line 2439 "y.tab.c"
    break;

  case 118: /* classHead: context IMPLIES type  */
#line 290 "parser.y"
                                        {yyval = gc3(pair(yyvsp[-2],checkClass(yyvsp[0])));}
#line 2445 "y.tab.c"
    break;

  case 119: /* classHead: type  */
#line 291 "parser.y"
                                        {yyval = gc1(pair(NIL,checkClass(yyvsp[0])));}
#line 2451 "y.tab.c"
    break;

  case 120: /* classBody: WHERE '{' csigdecls close  */
#line 293 "parser.y"
                                        {yyval = gc4(yyvsp[-1]);}
#line 2457 "y.tab.c"
    break;

  case 121: /* classBody: %empty  */
#line 294 "parser.y"
                                        {yyval = gc0(NIL);}
#line 2463 "y.tab.c"
    break;

  case 122: /* instBody: WHERE '{' decls close  */
#line 296 "parser.y"
                                        {yyval = gc4(yyvsp[-1]);}
#line 2469 "y.tab.c"
    break;

  case 123: /* instBody: %empty  */
#line 297 "parser.y"
                                        {yyval = gc0(NIL);}
#line 2475 "y.tab.c"
    break;

  case 124: /* csigdecls: csigdecls ';' csigdecl  */
#line 299 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2481 "y.tab.c"
    break;

  case 125: /* csigdecls: csigdecl  */
#line 300 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2487 "y.tab.c"
    break;

  case 126: /* csigdecl: decl  */
#line 302 "parser.y"
                                        {yyval = gc1(yyvsp[0]);}
#line 2493 "y.tab.c"
    break;

  case 127: /* csigdecl: error  */
#line 303 "parser.y"
                                        {syntaxError("class body");}
#line 2499 "y.tab.c"
    break;

  case 128: /* decl: vars COCO sigType  */
#line 308 "parser.y"
                                        {yyval = gc3(sigdecl(yyvsp[-1],yyvsp[-2],yyvsp[0]));}
#line 2505 "y.tab.c"
    break;

  case 129: /* decl: opExp rhs  */
#line 309 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2511 "y.tab.c"
    break;

  case 130: /* decls: decls ';' decl  */
#line 311 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2517 "y.tab.c"
    break;

  case 131: /* decls: decl  */
#line 312 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2523 "y.tab.c"
    break;

  case 132: /* rhs: rhs1 wherePart  */
#line 314 "parser.y"
                                        {yyval = gc2(letrec(yyvsp[0],yyvsp[-1]));}
#line 2529 "y.tab.c"
    break;

  case 133: /* rhs: rhs1  */
#line 315 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2535 "y.tab.c"
    break;

  case 134: /* rhs: error  */
#line 316 "parser.y"
                                        {syntaxError("declaration");}
#line 2541 "y.tab.c"
    break;

  case 135: /* rhs1: '=' exp  */
#line 318 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2547 "y.tab.c"
    break;

  case 136: /* rhs1: gdefs  */
#line 319 "parser.y"
                                        {yyval = gc1(grded(rev(yyvsp[0])));}
#line 2553 "y.tab.c"
    break;

  case 137: /* wherePart: WHERE '{' decls close  */
#line 321 "parser.y"
                                        {yyval = gc4(yyvsp[-1]);}
#line 2559 "y.tab.c"
    break;

  case 138: /* gdefs: gdefs gdef  */
#line 323 "parser.y"
                                        {yyval = gc2(cons(yyvsp[0],yyvsp[-1]));}
#line 2565 "y.tab.c"
    break;

  case 139: /* gdefs: gdef  */
#line 324 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2571 "y.tab.c"
    break;

  case 140: /* gdef: '|' exp '=' exp  */
#line 326 "parser.y"
                                        {yyval = gc4(pair(yyvsp[-1],pair(yyvsp[-2],yyvsp[0])));}
#line 2577 "y.tab.c"
    break;

  case 141: /* gdef: '=' exp ',' IF exp  */
#line 333 "parser.y"
                                        {yyval = gc5(pair(yyvsp[-4],pair(yyvsp[0],yyvsp[-3])));}
#line 2583 "y.tab.c"
    break;

  case 142: /* gdef: '=' exp ',' exp  */
#line 334 "parser.y"
                                        {yyval = gc4(pair(yyvsp[-3],pair(yyvsp[0],yyvsp[-2])));}
#line 2589 "y.tab.c"
    break;

  case 143: /* vars: vars ',' var  */
#line 336 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2595 "y.tab.c"
    break;

  case 144: /* vars: var  */
#line 337 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2601 "y.tab.c"
    break;

  case 145: /* var: varid  */
#line 339 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2607 "y.tab.c"
    break;

  case 146: /* var: '(' '-' ')'  */
#line 340 "parser.y"
                                        {yyval = gc3(varMinus);}
#line 2613 "y.tab.c"
    break;

  case 147: /* varid: VARID  */
#line 342 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2619 "y.tab.c"
    break;

  case 148: /* varid: '(' VAROP ')'  */
#line 343 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2625 "y.tab.c"
    break;

  case 149: /* conid: CONID  */
#line 345 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2631 "y.tab.c"
    break;

  case 150: /* conid: '(' CONOP ')'  */
#line 346 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2637 "y.tab.c"
    break;

  case 151: /* exp: opExp COCO sigType  */
#line 351 "parser.y"
                                        {yyval = gc3(ap(ESIGN,pair(yyvsp[-2],yyvsp[0])));}
#line 2643 "y.tab.c"
    break;

  case 152: /* exp: opExp  */
#line 352 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2649 "y.tab.c"
    break;

  case 153: /* exp: error  */
#line 353 "parser.y"
                                        {syntaxError("expression");}
#line 2655 "y.tab.c"
    break;

  case 154: /* opExp: pfxExp  */
#line 355 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2661 "y.tab.c"
    break;

  case 155: /* opExp: pfxExp op pfxExp  */
#line 356 "parser.y"
                                        {yyval = gc3(ap(ap(yyvsp[-1],yyvsp[-2]),yyvsp[0]));}
#line 2667 "y.tab.c"
    break;

  case 156: /* opExp: opExp0  */
#line 357 "parser.y"
                                        {yyval = gc1(tidyInfix(yyvsp[0]));}
#line 2673 "y.tab.c"
    break;

  case 157: /* opExp0: opExp0 op pfxExp  */
#line 359 "parser.y"
                                        {yyval = gc3(ap(ap(yyvsp[-1],yyvsp[-2]),yyvsp[0]));}
#line 2679 "y.tab.c"
    break;

  case 158: /* opExp0: pfxExp op pfxExp op pfxExp  */
#line 360 "parser.y"
                                        {yyval = gc5(ap(ap(yyvsp[-1],
							ap(ap(yyvsp[-3],singleton(yyvsp[-4])),
                                                           yyvsp[-2])),yyvsp[0]));}
#line 2687 "y.tab.c"
    break;

  case 159: /* pfxExp: '-' appExp  */
#line 364 "parser.y"
                                        {if (isInt(yyvsp[0]))
					     yyval = gc2(mkInt(-intOf(yyvsp[0])));
					 else
					     yyval = gc2(ap(varNegate,yyvsp[0]));
					}
#line 2697 "y.tab.c"
    break;

  case 160: /* pfxExp: '\\' pats FUNARROW exp  */
#line 369 "parser.y"
                                        {yyval = gc4(ap(LAMBDA,
						     pair(rev(yyvsp[-2]),
						          pair(yyvsp[-1],yyvsp[0]))));}
#line 2705 "y.tab.c"
    break;

  case 161: /* pfxExp: LET '{' decls close IN exp  */
#line 372 "parser.y"
                                        {yyval = gc6(letrec(yyvsp[-3],yyvsp[0]));}
#line 2711 "y.tab.c"
    break;

  case 162: /* pfxExp: IF exp THEN exp ELSE exp  */
#line 373 "parser.y"
                                        {yyval = gc6(ap(COND,triple(yyvsp[-4],yyvsp[-2],yyvsp[0])));}
#line 2717 "y.tab.c"
    break;

  case 163: /* pfxExp: CASEXP exp OF '{' alts close  */
#line 374 "parser.y"
                                        {yyval = gc6(ap(CASE,pair(yyvsp[-4],rev(yyvsp[-1]))));}
#line 2723 "y.tab.c"
    break;

  case 164: /* pfxExp: appExp  */
#line 375 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2729 "y.tab.c"
    break;

  case 165: /* pats: pats atomic  */
#line 377 "parser.y"
                                        {yyval = gc2(cons(yyvsp[0],yyvsp[-1]));}
#line 2735 "y.tab.c"
    break;

  case 166: /* pats: atomic  */
#line 378 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2741 "y.tab.c"
    break;

  case 167: /* appExp: appExp atomic  */
#line 380 "parser.y"
                                        {yyval = gc2(ap(yyvsp[-1],yyvsp[0]));}
#line 2747 "y.tab.c"
    break;

  case 168: /* appExp: TRUNST atomic  */
#line 381 "parser.y"
                                        {yyval = gc2(ap(RUNST,yyvsp[0]));}
#line 2753 "y.tab.c"
    break;

  case 169: /* appExp: atomic  */
#line 382 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2759 "y.tab.c"
    break;

  case 170: /* atomic: var  */
#line 384 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2765 "y.tab.c"
    break;

  case 171: /* atomic: var '@' atomic  */
#line 385 "parser.y"
                                        {yyval = gc3(ap(ASPAT,pair(yyvsp[-2],yyvsp[0])));}
#line 2771 "y.tab.c"
    break;

  case 172: /* atomic: '~' atomic  */
#line 386 "parser.y"
                                        {yyval = gc2(ap(LAZYPAT,yyvsp[0]));}
#line 2777 "y.tab.c"
    break;

  case 173: /* atomic: '_'  */
#line 387 "parser.y"
                                        {yyval = gc1(WILDCARD);}
#line 2783 "y.tab.c"
    break;

  case 174: /* atomic: conid  */
#line 388 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2789 "y.tab.c"
    break;

  case 175: /* atomic: '(' ')'  */
#line 389 "parser.y"
                                        {yyval = gc2(UNIT);}
#line 2795 "y.tab.c"
    break;

  case 176: /* atomic: NUMLIT  */
#line 390 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2801 "y.tab.c"
    break;

  case 177: /* atomic: CHARLIT  */
#line 391 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2807 "y.tab.c"
    break;

  case 178: /* atomic: STRINGLIT  */
#line 392 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2813 "y.tab.c"
    break;

  case 179: /* atomic: REPEAT  */
#line 393 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2819 "y.tab.c"
    break;

  case 180: /* atomic: '(' exp ')'  */
#line 394 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2825 "y.tab.c"
    break;

  case 181: /* atomic: '(' exps2 ')'  */
#line 395 "parser.y"
                                        {yyval = gc3(buildTuple(yyvsp[-1]));}
#line 2831 "y.tab.c"
    break;

  case 182: /* atomic: '[' list ']'  */
#line 396 "parser.y"
                                        {yyval = gc3(yyvsp[-1]);}
#line 2837 "y.tab.c"
    break;

  case 183: /* atomic: '(' pfxExp op ')'  */
#line 397 "parser.y"
                                        {yyval = gc4(ap(yyvsp[-1],yyvsp[-2]));}
#line 2843 "y.tab.c"
    break;

  case 184: /* atomic: '(' varop atomic ')'  */
#line 398 "parser.y"
                                        {yyval = gc4(ap(ap(varFlip,yyvsp[-2]),yyvsp[-1]));}
#line 2849 "y.tab.c"
    break;

  case 185: /* atomic: '(' conop atomic ')'  */
#line 399 "parser.y"
                                        {yyval = gc4(ap(ap(varFlip,yyvsp[-2]),yyvsp[-1]));}
#line 2855 "y.tab.c"
    break;

  case 186: /* exps2: exps2 ',' exp  */
#line 401 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2861 "y.tab.c"
    break;

  case 187: /* exps2: exp ',' exp  */
#line 402 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],cons(yyvsp[-2],NIL)));}
#line 2867 "y.tab.c"
    break;

  case 188: /* alts: alts ';' alt  */
#line 404 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2873 "y.tab.c"
    break;

  case 189: /* alts: alt  */
#line 405 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2879 "y.tab.c"
    break;

  case 190: /* alt: opExp altRhs  */
#line 407 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2885 "y.tab.c"
    break;

  case 191: /* altRhs: altRhs1 wherePart  */
#line 409 "parser.y"
                                        {yyval = gc2(letrec(yyvsp[0],yyvsp[-1]));}
#line 2891 "y.tab.c"
    break;

  case 192: /* altRhs: altRhs1  */
#line 410 "parser.y"
                                        {yyval = yyvsp[0];}
#line 2897 "y.tab.c"
    break;

  case 193: /* altRhs1: guardAlts  */
#line 412 "parser.y"
                                        {yyval = gc1(grded(rev(yyvsp[0])));}
#line 2903 "y.tab.c"
    break;

  case 194: /* altRhs1: FUNARROW exp  */
#line 413 "parser.y"
                                        {yyval = gc2(pair(yyvsp[-1],yyvsp[0]));}
#line 2909 "y.tab.c"
    break;

  case 195: /* altRhs1: error  */
#line 414 "parser.y"
                                        {syntaxError("case expression");}
#line 2915 "y.tab.c"
    break;

  case 196: /* guardAlts: guardAlts guardAlt  */
#line 416 "parser.y"
                                        {yyval = gc2(cons(yyvsp[0],yyvsp[-1]));}
#line 2921 "y.tab.c"
    break;

  case 197: /* guardAlts: guardAlt  */
#line 417 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2927 "y.tab.c"
    break;

  case 198: /* guardAlt: '|' opExp FUNARROW exp  */
#line 419 "parser.y"
                                        {yyval = gc4(pair(yyvsp[-1],pair(yyvsp[-2],yyvsp[0])));}
#line 2933 "y.tab.c"
    break;

  case 199: /* list: %empty  */
#line 424 "parser.y"
                                        {yyval = gc0(nameNil);}
#line 2939 "y.tab.c"
    break;

  case 200: /* list: exp  */
#line 425 "parser.y"
                                        {yyval = gc1(ap(FINLIST,cons(yyvsp[0],NIL)));}
#line 2945 "y.tab.c"
    break;

  case 201: /* list: exps2  */
#line 426 "parser.y"
                                        {yyval = gc1(ap(FINLIST,rev(yyvsp[0])));}
#line 2951 "y.tab.c"
    break;

  case 202: /* list: exp '|' quals  */
#line 427 "parser.y"
                                        {yyval = gc3(ap(COMP,pair(yyvsp[-2],rev(yyvsp[0]))));}
#line 2957 "y.tab.c"
    break;

  case 203: /* list: exp UPTO exp  */
#line 428 "parser.y"
                                        {yyval = gc3(ap(ap(varFromTo,yyvsp[-2]),yyvsp[0]));}
#line 2963 "y.tab.c"
    break;

  case 204: /* list: exp ',' exp UPTO  */
#line 429 "parser.y"
                                        {yyval = gc4(ap(ap(varFromThen,yyvsp[-3]),yyvsp[-1]));}
#line 2969 "y.tab.c"
    break;

  case 205: /* list: exp UPTO  */
#line 430 "parser.y"
                                        {yyval = gc2(ap(varFrom,yyvsp[-1]));}
#line 2975 "y.tab.c"
    break;

  case 206: /* list: exp ',' exp UPTO exp  */
#line 431 "parser.y"
                                        {yyval = gc5(ap(ap(ap(varFromThenTo,
                                                               yyvsp[-4]),yyvsp[-2]),yyvsp[0]));}
#line 2982 "y.tab.c"
    break;

  case 207: /* quals: quals ',' qual  */
#line 434 "parser.y"
                                        {yyval = gc3(cons(yyvsp[0],yyvsp[-2]));}
#line 2988 "y.tab.c"
    break;

  case 208: /* quals: qual  */
#line 435 "parser.y"
                                        {yyval = gc1(cons(yyvsp[0],NIL));}
#line 2994 "y.tab.c"
    break;

  case 209: /* qual: exp FROM exp  */
#line 437 "parser.y"
                                        {yyval = gc3(ap(FROMQUAL,pair(yyvsp[-2],yyvsp[0])));}
#line 3000 "y.tab.c"
    break;

  case 210: /* qual: exp '=' exp  */
#line 438 "parser.y"
                                        {yyval = gc3(ap(QWHERE,
						     singleton(
							pair(yyvsp[-2],pair(yyvsp[-1],
								     yyvsp[0])))));}
#line 3009 "y.tab.c"
    break;

  case 211: /* qual: exp  */
#line 442 "parser.y"
                                        {yyval = gc1(ap(BOOLQUAL,yyvsp[0]));}
#line 3015 "y.tab.c"
    break;

  case 212: /* qual: LET '{' decls close  */
#line 443 "parser.y"
                                        {yyval = gc4(ap(QWHERE,yyvsp[-1]));}
#line 3021 "y.tab.c"
    break;

  case 213: /* close: ';' close1  */
#line 469 "parser.y"
                                        {yyval = gc2(yyvsp[0]);}
#line 3027 "y.tab.c"
    break;

  case 214: /* close: close1  */
#line 470 "parser.y"
                                        {yyval = yyvsp[0];}
#line 3033 "y.tab.c"
    break;

  case 215: /* close1: '}'  */
#line 472 "parser.y"
                                        {yyval = yyvsp[0];}
#line 3039 "y.tab.c"
    break;

  case 216: /* close1: error  */
#line 473 "parser.y"
                                        {yyerrok;
                                         if (canUnOffside()) {
                                             unOffside();
					     /* insert extra token on stack*/
					     push(NIL);
					     pushed(0) = pushed(1);
					     pushed(1) = mkInt(column);
					 }
                                         else
                                             syntaxError("definition");
                                        }
#line 3055 "y.tab.c"
    break;


#line 3059 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 488 "parser.y"


static Cell local gcShadow(n,e)		/* keep parsed fragments on stack  */
Int  n;
Cell e; {
    /* If a look ahead token is held then the required stack transformation
     * is:
     *   pushed: n               1     0          1     0
     *           x1  |  ...  |  xn  |  la   ===>  e  |  la
     *                                top()            top()
     *
     * Othwerwise, the transformation is:
     *   pushed: n-1             0        0
     *           x1  |  ...  |  xn  ===>  e
     *                         top()     top()
     */
    if (yychar>=0) {
	pushed(n-1) = top();
        pushed(n)   = e;
    }
    else
	pushed(n-1) = e;
    sp -= (n-1);
    return e;
}

static Void local syntaxError(s)       /* report on syntax error           */
String s; {
    ERROR(row) "Syntax error in %s (unexpected %s)", s, unexpected()
    EEND;
}

static String local unexpected() {	/* find name for unexpected token  */
    static char buffer[100];
    static char *fmt = "%s \"%s\"";
    static char *kwd = "keyword";
    static char *hkw = "(Haskell) keyword";

    switch (yychar) {
	case 0	       : return "end of input";

#define keyword(kw) sprintf(buffer,fmt,kwd,kw); return buffer;
	case INFIXL    : keyword("infixl");
	case INFIXR    : keyword("infixr");
	case INFIX     : keyword("infix");
	case TINSTANCE : keyword("instance");
	case TCLASS    : keyword("class");
	case PRIMITIVE : keyword("primitive");
	case CASEXP    : keyword("case");
	case OF        : keyword("of");
	case IF        : keyword("if");
	case DO	       : keyword("do");
	case TRUNST    : keyword("runST");
	case THEN      : keyword("then");
	case ELSE      : keyword("else");
	case WHERE     : keyword("where");
	case TYPE      : keyword("type");
	case DATA      : keyword("data");
	case LET       : keyword("let");
	case IN        : keyword("in");
#undef keyword

#define hasword(kw) sprintf(buffer,fmt,hkw,kw); return buffer;
	case DEFAULT   : hasword("default");
	case DERIVING  : hasword("deriving");
	case HIDING    : hasword("hiding");
	case IMPORT    : hasword("import");
	case INTERFACE : hasword("interface");
	case MODULE    : hasword("module");
	case RENAMING  : hasword("renaming");
	case TO	       : hasword("to");
#undef hasword

	case FUNARROW  : return "`->'";
	case '='       : return "`='";
	case COCO      : return "`::'";
	case '-'       : return "`-'";
	case ','       : return "comma";
	case '@'       : return "`@'";
	case '('       : return "`('";
	case ')'       : return "`)'";
	case '|'       : return "`|'";
	case ';'       : return "`;'";
	case UPTO      : return "`..'";
	case '['       : return "`['";
	case ']'       : return "`]'";
	case FROM      : return "`<-'";
	case '\\'      : return "backslash (lambda)";
	case '~'       : return "tilde";
	case '`'       : return "backquote";
	case VAROP     :
	case VARID     :
	case CONOP     :
	case CONID     : sprintf(buffer,"symbol \"%s\"",
				 textToStr(textOf(yylval)));
			 return buffer;
	case NUMLIT    : return "numeric literal";
	case CHARLIT   : return "character literal";
	case STRINGLIT : return "string literal";
	case IMPLIES   : return "`=>";
	default	       : return "token";
    }
}

static Cell local checkPrec(p)         /* Check for valid precedence value */
Cell p; {
    if (!isInt(p) || intOf(p)<MIN_PREC || intOf(p)>MAX_PREC) {
        ERROR(row) "Precedence value must be an integer in the range [%d..%d]",
                   MIN_PREC, MAX_PREC
        EEND;
    }
    return p;
}

static Void local fixDefn(a,line,p,ops)/* Declare syntax of operators      */
Syntax a;
Cell   line;
Cell   p;
List   ops; {
    Int l = intOf(line);
    a     = mkSyntax(a,intOf(p));
    map2Proc(setSyntax,l,a,ops);
}

static Void local setSyntax(line,sy,op)/* set syntax of individ. operator  */
Int    line;
Syntax sy;
Cell   op; {
    addSyntax(line,textOf(op),sy);
    opDefns = cons(op,opDefns);
}

static Cell local buildTuple(tup)      /* build tuple (x1,...,xn) from list*/
List tup; {                            /* [xn,...,x1]                      */
    Int  n = 0;
    Cell t = tup;
    Cell x;

    do {                               /*     .                    .       */
        x      = fst(t);               /*    / \                  / \      */
        fst(t) = snd(t);               /*   xn  .                .   xn    */
        snd(t) = x;                    /*        .    ===>      .          */
        x      = t;                    /*         .            .           */
        t      = fun(x);               /*          .          .            */
        n++;                           /*         / \        / \           */
    } while (nonNull(t));              /*        x1  NIL   (n)  x1         */
    fst(x) = mkTuple(n);
    return tup;
}

/* The yacc parser presented above is not sufficiently powerful to
 * determine whether a tuple at the front of a sigType is part of a
 * context:    e.g. (Eq a, Num a) => a -> a -> a
 * or a type:  e.g.  (Tree a, Tree a) -> Tree a
 *
 * Rather than complicate the grammar, both are parsed as tuples of types,
 * using the following checks afterwards to ensure that the correct syntax
 * is used in the case of a tupled context.
 */

static List local checkContext(con)	/* validate type class context	   */
Type con; {
    if (con==UNIT)			/* allows empty context ()	   */
	return NIL;
    else if (whatIs(getHead(con))==TUPLE) {
	List qs = NIL;

	while (isAp(con)) {		/* undo work of buildTuple  :-(    */
	    Cell temp = fun(con);
	    fun(con)  = arg(con);
	    arg(con)  = qs;
	    qs	      = con;
	    con       = temp;
	    checkClass(hd(qs));
	}
	return qs;
    }
    else				/* single context expression	   */
	return singleton(checkClass(con));
}

static Cell local checkClass(c)		/* check that type expr is a class */
Cell c; {				/* constrnt of the form C t1 .. tn */
    Cell cn = getHead(c);

    if (!isCon(cn))
	syntaxError("class expression");
    else if (argCount<1) {
	ERROR(row) "Class \"%s\" must have at least one argument",
		   textToStr(textOf(cn))
	EEND;
    }
    return c;
}

static Pair local checkDo(dqs)		/* convert reversed list of dquals */
List dqs; {				/* to a (expr,quals) pair	   */
#if DO_COMPS
    if (isNull(dqs) || whatIs(hd(dqs))!=DOQUAL) {
	ERROR(row) "Last generator in do {...} must be an expression"
	EEND;
    }
    fst(dqs) = snd(fst(dqs));		/* put expression in fst of pair   */
    snd(dqs) = rev(snd(dqs));		/* & reversed list of quals in snd */
#endif
    return dqs;
}

static Cell local checkTyLhs(c)		/* check that lhs is of the form   */
Cell c; {				/* T a1 ... a			   */
    Cell tlhs = c;
    while (isAp(tlhs) && whatIs(arg(tlhs))==VARIDCELL)
	tlhs = fun(tlhs);
    if (whatIs(tlhs)!=CONIDCELL) {
	ERROR(row) "Illegal left hand side in datatype definition"
	EEND;
    }
    return c;
}

/* expressions involving a sequence of two or more infix operator symbols
 * are parsed as elements of type:
 *    InfixExpr ::= [Expr]
 *		 |  ap(ap(Operator,InfixExpr),Expr)
 *
 * thus x0 +1 x1 ... +n xn is parsed as: +n (....(+1 [x0] x1)....) xn
 *
 * Once the expression has been completely parsed, this parsed form is
 * `tidied' according to the precedences and associativities declared for
 * each operator symbol.
 *
 * The tidy process uses a `stack' of type:
 *    TidyStack ::= ap(ap(Operator,TidyStack),Expr)
 *		 |  NIL
 * when the ith layer of an InfixExpr has been transferred to the stack, the
 * stack is of the form: +i (....(+n NIL xn)....) xi
 *
 * The tidy function is based on a simple shift-reduce parser:
 *
 *  tidy                :: InfixExpr -> TidyStack -> Expr
 *  tidy [m]   ss        = foldl (\x f-> f x) m ss
 *  tidy (m*n) []        = tidy m [(*n)]
 *  tidy (m*n) ((+o):ss)
 *	       | amb     = error "Ambiguous"
 *	       | shift   = tidy m ((*n):(+o):ss)
 *	       | reduce  = tidy (m*(n+o)) ss
 *			   where sye     = syntaxOf (*)
 *				 (ae,pe) = sye
 *				 sys     = syntaxOf (+)
 *				 (as,ps) = sys
 *				 amb     = pe==ps && (ae/=as || ae==NON_ASS)
 *				 shift   = pe>ps || (ps==pe && ae==LEFT_ASS)
 *				 reduce  = otherwise
 *
 * N.B. the conditions amb, shift, reduce are NOT mutually exclusive and
 * must be tested in that order.
 *
 * As a concession to efficiency, we lower the number of calls to syntaxOf
 * by keeping track of the values of sye, sys throughout the process.  The
 * value APPLIC is used to indicate that the syntax value is unknown.
 */

static Cell local tidyInfix(e)         /* convert InfixExpr to Expr        */
Cell e; {                              /* :: InfixExpr                     */
    Cell   s   = NIL;                  /* :: TidyStack                     */
    Syntax sye = APPLIC;               /* Syntax of op in e (init unknown) */
    Syntax sys = APPLIC;               /* Syntax of op in s (init unknown) */
    Cell   temp;

    while (nonNull(tl(e))) {
        if (isNull(s)) {
            s           = e;
            e           = arg(fun(s));
            arg(fun(s)) = NIL;
            sys         = sye;
            sye         = APPLIC;
        }
        else {
            if (sye==APPLIC) {         /* calculate sye (if unknown)       */
                sye = syntaxOf(textOf(fun(fun(e))));
                if (sye==APPLIC) sye=DEF_OPSYNTAX;
            }
            if (sys==APPLIC) {         /* calculate sys (if unknown)       */
                sys = syntaxOf(textOf(fun(fun(s))));
                if (sys==APPLIC) sys=DEF_OPSYNTAX;
            }

            if (precOf(sye)==precOf(sys) &&                      /* amb    */
                   (assocOf(sye)!=assocOf(sys) || assocOf(sye)==NON_ASS)) {
                ERROR(row) "Ambiguous use of operator \"%s\" with \"%s\"",
                           textToStr(textOf(fun(fun(e)))),
                           textToStr(textOf(fun(fun(s))))
                EEND;
            }
            else if (precOf(sye)>precOf(sys) ||                  /* shift  */
                       (precOf(sye)==precOf(sys) && assocOf(sye)==LEFT_ASS)) {
                temp        = arg(fun(e));
                arg(fun(e)) = s;
                s           = e;
                e           = temp;
                sys         = sye;
                sye         = APPLIC;
            }
            else {                                               /* reduce */
                temp        = arg(fun(s));
                arg(fun(s)) = arg(e);
                arg(e)      = s;
                s           = temp;
                sys         = APPLIC;
                /* sye unchanged */
            }
        }
    }

    e = hd(e);
    while (nonNull(s)) {
        temp        = arg(fun(s));
        arg(fun(s)) = e;
        e           = s;
        s           = temp;
    }

    return e;
}

/*-------------------------------------------------------------------------*/
