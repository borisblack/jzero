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
#line 1 "j0gram.y"

#include "j0.h"

#line 75 "j0gram.tab.c"

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

#include "j0gram.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BREAK = 3,                      /* BREAK  */
  YYSYMBOL_DOUBLE = 4,                     /* DOUBLE  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_IDENTIFIER = 12,                /* IDENTIFIER  */
  YYSYMBOL_CLASSNAME = 13,                 /* CLASSNAME  */
  YYSYMBOL_CLASS = 14,                     /* CLASS  */
  YYSYMBOL_STRING = 15,                    /* STRING  */
  YYSYMBOL_BOOL = 16,                      /* BOOL  */
  YYSYMBOL_INTLIT = 17,                    /* INTLIT  */
  YYSYMBOL_DOUBLELIT = 18,                 /* DOUBLELIT  */
  YYSYMBOL_STRINGLIT = 19,                 /* STRINGLIT  */
  YYSYMBOL_BOOLLIT = 20,                   /* BOOLLIT  */
  YYSYMBOL_NULLVAL = 21,                   /* NULLVAL  */
  YYSYMBOL_LESSTHANOREQUAL = 22,           /* LESSTHANOREQUAL  */
  YYSYMBOL_GREATERTHANOREQUAL = 23,        /* GREATERTHANOREQUAL  */
  YYSYMBOL_ISEQUALTO = 24,                 /* ISEQUALTO  */
  YYSYMBOL_NOTEQUALTO = 25,                /* NOTEQUALTO  */
  YYSYMBOL_LOGICALAND = 26,                /* LOGICALAND  */
  YYSYMBOL_LOGICALOR = 27,                 /* LOGICALOR  */
  YYSYMBOL_INCREMENT = 28,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 29,                 /* DECREMENT  */
  YYSYMBOL_PUBLIC = 30,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '.'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '!'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '%'  */
  YYSYMBOL_46_ = 46,                       /* '+'  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_ClassDecl = 51,                 /* ClassDecl  */
  YYSYMBOL_ClassBody = 52,                 /* ClassBody  */
  YYSYMBOL_ClassBodyDecls = 53,            /* ClassBodyDecls  */
  YYSYMBOL_ClassBodyDecl = 54,             /* ClassBodyDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_Type = 56,                      /* Type  */
  YYSYMBOL_Name = 57,                      /* Name  */
  YYSYMBOL_QualifiedName = 58,             /* QualifiedName  */
  YYSYMBOL_VarDecls = 59,                  /* VarDecls  */
  YYSYMBOL_VarDeclarator = 60,             /* VarDeclarator  */
  YYSYMBOL_MethodReturnVal = 61,           /* MethodReturnVal  */
  YYSYMBOL_MethodDecl = 62,                /* MethodDecl  */
  YYSYMBOL_MethodHeader = 63,              /* MethodHeader  */
  YYSYMBOL_MethodDeclarator = 64,          /* MethodDeclarator  */
  YYSYMBOL_FormalParmListOpt = 65,         /* FormalParmListOpt  */
  YYSYMBOL_FormalParmList = 66,            /* FormalParmList  */
  YYSYMBOL_FormalParm = 67,                /* FormalParm  */
  YYSYMBOL_ConstructorDecl = 68,           /* ConstructorDecl  */
  YYSYMBOL_ConstructorDeclarator = 69,     /* ConstructorDeclarator  */
  YYSYMBOL_ArgListOpt = 70,                /* ArgListOpt  */
  YYSYMBOL_Block = 71,                     /* Block  */
  YYSYMBOL_BlockStmtsOpt = 72,             /* BlockStmtsOpt  */
  YYSYMBOL_BlockStmts = 73,                /* BlockStmts  */
  YYSYMBOL_BlockStmt = 74,                 /* BlockStmt  */
  YYSYMBOL_LocalVarDeclStmt = 75,          /* LocalVarDeclStmt  */
  YYSYMBOL_LocalVarDecl = 76,              /* LocalVarDecl  */
  YYSYMBOL_Stmt = 77,                      /* Stmt  */
  YYSYMBOL_ExprStmt = 78,                  /* ExprStmt  */
  YYSYMBOL_StmtExpr = 79,                  /* StmtExpr  */
  YYSYMBOL_IfThenStmt = 80,                /* IfThenStmt  */
  YYSYMBOL_IfThenElseStmt = 81,            /* IfThenElseStmt  */
  YYSYMBOL_IfThenElseIfStmt = 82,          /* IfThenElseIfStmt  */
  YYSYMBOL_ElseIfSequence = 83,            /* ElseIfSequence  */
  YYSYMBOL_ElseIfStmt = 84,                /* ElseIfStmt  */
  YYSYMBOL_WhileStmt = 85,                 /* WhileStmt  */
  YYSYMBOL_ForStmt = 86,                   /* ForStmt  */
  YYSYMBOL_ForInit = 87,                   /* ForInit  */
  YYSYMBOL_ExprOpt = 88,                   /* ExprOpt  */
  YYSYMBOL_ForUpdate = 89,                 /* ForUpdate  */
  YYSYMBOL_StmtExprList = 90,              /* StmtExprList  */
  YYSYMBOL_BreakStmt = 91,                 /* BreakStmt  */
  YYSYMBOL_ReturnStmt = 92,                /* ReturnStmt  */
  YYSYMBOL_Primary = 93,                   /* Primary  */
  YYSYMBOL_Literal = 94,                   /* Literal  */
  YYSYMBOL_InstantiationExpr = 95,         /* InstantiationExpr  */
  YYSYMBOL_ArgList = 96,                   /* ArgList  */
  YYSYMBOL_FieldAccess = 97,               /* FieldAccess  */
  YYSYMBOL_MethodCall = 98,                /* MethodCall  */
  YYSYMBOL_PostFixExpr = 99,               /* PostFixExpr  */
  YYSYMBOL_UnaryExpr = 100,                /* UnaryExpr  */
  YYSYMBOL_MulExpr = 101,                  /* MulExpr  */
  YYSYMBOL_AddExpr = 102,                  /* AddExpr  */
  YYSYMBOL_RelOp = 103,                    /* RelOp  */
  YYSYMBOL_RelExpr = 104,                  /* RelExpr  */
  YYSYMBOL_EqExpr = 105,                   /* EqExpr  */
  YYSYMBOL_CondAndExpr = 106,              /* CondAndExpr  */
  YYSYMBOL_CondOrExpr = 107,               /* CondOrExpr  */
  YYSYMBOL_Expr = 108,                     /* Expr  */
  YYSYMBOL_Assignment = 109,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 110,             /* LeftHandSide  */
  YYSYMBOL_AssignOp = 111                  /* AssignOp  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
       2,     2,     2,    42,     2,     2,     2,    45,     2,     2,
      39,    40,    43,    46,    36,    41,    35,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      47,    49,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    20,    20,    21,    21,    22,    22,    23,    23,    23,
      24,    25,    25,    25,    25,    25,    27,    27,    28,    30,
      30,    31,    31,    33,    33,    34,    35,    36,    37,    37,
      38,    38,    39,    41,    42,    43,    43,    45,    46,    46,
      47,    47,    48,    48,    50,    51,    53,    53,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    59,    61,    61,
      61,    63,    64,    65,    66,    68,    68,    69,    70,    72,
      73,    73,    73,    74,    74,    75,    75,    77,    77,    79,
      79,    80,    82,    82,    82,    82,    83,    83,    83,    83,
      83,    85,    86,    86,    87,    89,    90,    91,    92,    94,
      94,    95,    95,    95,    96,    96,    97,    97,    98,    98,
      98,    99,    99,    99,    99,   100,   100,   102,   102,   102,
     103,   103,   104,   104,   106,   106,   107,   108,   108,   109,
     109,   109
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
  "\"end of file\"", "error", "\"invalid token\"", "BREAK", "DOUBLE",
  "ELSE", "FOR", "IF", "INT", "RETURN", "VOID", "WHILE", "IDENTIFIER",
  "CLASSNAME", "CLASS", "STRING", "BOOL", "INTLIT", "DOUBLELIT",
  "STRINGLIT", "BOOLLIT", "NULLVAL", "LESSTHANOREQUAL",
  "GREATERTHANOREQUAL", "ISEQUALTO", "NOTEQUALTO", "LOGICALAND",
  "LOGICALOR", "INCREMENT", "DECREMENT", "PUBLIC", "STATIC", "'{'", "'}'",
  "';'", "'.'", "','", "'['", "']'", "'('", "')'", "'-'", "'!'", "'*'",
  "'/'", "'%'", "'+'", "'<'", "'>'", "'='", "$accept", "ClassDecl",
  "ClassBody", "ClassBodyDecls", "ClassBodyDecl", "FieldDecl", "Type",
  "Name", "QualifiedName", "VarDecls", "VarDeclarator", "MethodReturnVal",
  "MethodDecl", "MethodHeader", "MethodDeclarator", "FormalParmListOpt",
  "FormalParmList", "FormalParm", "ConstructorDecl",
  "ConstructorDeclarator", "ArgListOpt", "Block", "BlockStmtsOpt",
  "BlockStmts", "BlockStmt", "LocalVarDeclStmt", "LocalVarDecl", "Stmt",
  "ExprStmt", "StmtExpr", "IfThenStmt", "IfThenElseStmt",
  "IfThenElseIfStmt", "ElseIfSequence", "ElseIfStmt", "WhileStmt",
  "ForStmt", "ForInit", "ExprOpt", "ForUpdate", "StmtExprList",
  "BreakStmt", "ReturnStmt", "Primary", "Literal", "InstantiationExpr",
  "ArgList", "FieldAccess", "MethodCall", "PostFixExpr", "UnaryExpr",
  "MulExpr", "AddExpr", "RelOp", "RelExpr", "EqExpr", "CondAndExpr",
  "CondOrExpr", "Expr", "Assignment", "LeftHandSide", "AssignOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -11,    -6,    25,    87,  -190,    77,   155,  -190,  -190,  -190,
     -10,  -190,  -190,     0,  -190,   241,  -190,  -190,   104,    82,
    -190,  -190,    88,  -190,    88,   171,   111,  -190,  -190,  -190,
      39,    93,   120,   188,  -190,  -190,  -190,   104,   102,    97,
    -190,  -190,  -190,   124,  -190,   104,   107,  -190,    -1,   115,
     116,   222,   117,  -190,  -190,  -190,  -190,  -190,  -190,   222,
     104,    44,  -190,   127,   188,  -190,  -190,   132,  -190,  -190,
     134,  -190,  -190,  -190,  -190,  -190,  -190,  -190,   141,  -190,
    -190,    17,   142,  -190,    49,    93,  -190,   171,   130,  -190,
      93,  -190,   144,  -190,    20,   222,   222,   222,    57,   159,
     141,  -190,  -190,  -190,    19,   112,    -5,    24,   172,   174,
    -190,  -190,   222,   162,   175,   222,   222,  -190,  -190,  -190,
    -190,   198,  -190,  -190,  -190,   222,  -190,   171,  -190,  -190,
    -190,   178,   177,   176,    90,  -190,  -190,  -190,   222,  -190,
     222,   222,   222,   222,   222,  -190,  -190,  -190,  -190,   222,
     222,   222,   222,   222,   185,  -190,   181,   190,  -190,   195,
      58,  -190,   196,   222,   248,    88,   197,  -190,  -190,  -190,
      19,    19,   112,    -5,    -5,    24,   172,   212,  -190,   222,
     182,   222,   222,  -190,   194,    96,  -190,   233,  -190,  -190,
    -190,   214,   208,   248,    40,   245,  -190,  -190,  -190,   215,
     177,   213,  -190,  -190,    40,  -190,    88,   222,  -190,  -190,
     218,    88,  -190
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,    12,    11,
      16,    14,    13,     0,     4,     0,     5,     7,     0,    15,
      17,     8,     0,     9,     0,    29,     0,     3,     6,    21,
       0,    19,     0,    39,    25,    33,    16,     0,     0,    28,
      30,    24,    23,     0,    10,     0,     0,    18,     0,     0,
       0,    74,     0,    86,    87,    89,    88,    90,    47,     0,
       0,   127,    46,     0,    38,    40,    42,     0,    43,    48,
       0,    52,    53,    54,    55,    56,    49,    50,     0,    82,
      60,    84,    59,    58,     0,    32,    34,     0,     0,    26,
      20,    22,     0,    79,    72,     0,     0,     0,   100,     0,
      99,    85,   103,   104,   108,   115,   117,   120,   122,   124,
      73,   125,     0,     0,    45,    36,    36,    37,    41,    44,
      57,     0,   130,   131,   129,     0,    31,    29,    80,    71,
      77,     0,    70,     0,   100,    84,   101,   102,    36,    81,
       0,     0,     0,     0,     0,   111,   112,   113,   114,     0,
       0,     0,     0,     0,     0,    83,     0,    35,    92,     0,
      94,   126,     0,    74,     0,     0,     0,   105,   106,   107,
     110,   109,   116,   118,   119,   121,   123,    51,    96,     0,
      91,    36,    36,    27,     0,   127,    78,    61,    95,    68,
      93,     0,     0,    76,     0,    63,    65,    98,    97,     0,
      75,     0,    62,    67,     0,    66,     0,     0,    64,    69,
       0,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,  -190,   239,  -190,     1,    -3,  -190,   199,
      23,  -190,  -190,  -190,  -190,   135,  -190,   183,  -190,  -190,
    -112,   -22,  -190,  -190,   209,  -190,   184,    95,  -190,   -93,
    -189,  -190,  -190,  -190,    80,  -190,  -190,  -190,   113,  -190,
      84,  -190,  -190,   -20,  -190,  -190,  -190,   -39,   -13,  -190,
     -87,   -56,   131,  -190,   -43,   129,   126,  -190,   -45,   -12,
    -190,  -190
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,    15,    16,    17,    37,    98,    20,    30,
      31,    43,    21,    22,    89,    38,    39,    40,    23,    24,
     156,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,   195,   196,    74,    75,   131,    99,   199,
     132,    76,    77,   100,    79,    80,   157,    81,   101,   102,
     103,   104,   105,   149,   106,   107,   108,   109,   158,   111,
      84,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   130,    35,    19,   159,   203,   110,    18,     3,   136,
     137,    92,    19,    78,   113,   203,    18,   145,   146,     1,
      82,    83,    19,    19,     8,     4,   166,    42,     9,    25,
      61,    26,    36,    93,    60,    11,    12,    53,    54,    55,
      56,    57,   147,   148,    78,  -128,  -128,   201,   150,   151,
     133,    82,    83,   167,   168,   169,   -15,   135,   135,    59,
      85,    61,   140,   141,   142,    60,  -128,   154,    90,   191,
     192,   186,    33,    44,    78,    45,   115,   122,   123,    32,
     161,    82,    83,   116,    19,  -127,  -127,   170,   171,   115,
     181,    61,    32,   134,   134,    60,   138,   182,   124,     5,
     130,   135,   135,   135,   135,   135,  -127,   173,   174,     6,
     135,   135,   135,   135,   135,     8,    29,    32,   110,     9,
      33,    41,   115,    36,    19,    32,    11,    12,   115,   138,
      46,    32,    47,    87,   190,   116,    88,   134,   134,   134,
     134,   134,    86,   187,    78,    91,   134,   134,   134,   134,
     134,    82,    83,   143,    94,    95,   112,    78,   144,     8,
     117,   185,   210,     9,    82,    83,   119,    10,   120,   127,
      11,    12,   202,    78,   185,     8,   121,   -85,   128,     9,
      82,    83,   208,    36,   209,    13,    11,    12,    14,   212,
     185,    48,     8,   139,    49,    50,     9,    51,   152,    52,
      36,   153,   155,    11,    12,    53,    54,    55,    56,    57,
     160,    45,   163,   164,   178,    48,   165,   -95,    49,    50,
      33,    51,    58,    52,    36,   177,   179,    59,   193,    53,
      54,    55,    56,    57,    36,   180,   183,   188,   194,    53,
      54,    55,    56,    57,    33,     8,    58,   197,   198,     9,
     204,    59,   207,    10,    28,   206,    11,    12,   211,   114,
      36,    59,   162,    96,    97,    53,    54,    55,    56,    57,
     126,    13,   189,   118,    27,   205,   184,   200,   129,   176,
     172,   175,     0,     0,     0,     0,     0,    59
};

static const yytype_int16 yycheck[] =
{
      22,    94,    24,     6,   116,   194,    51,     6,    14,    96,
      97,    12,    15,    33,    59,   204,    15,    22,    23,    30,
      33,    33,    25,    26,     4,     0,   138,    26,     8,    39,
      33,    31,    12,    34,    33,    15,    16,    17,    18,    19,
      20,    21,    47,    48,    64,    28,    29,     7,    24,    25,
      95,    64,    64,   140,   141,   142,    12,    96,    97,    39,
      37,    64,    43,    44,    45,    64,    49,   112,    45,   181,
     182,   164,    32,    34,    94,    36,    32,    28,    29,    35,
     125,    94,    94,    39,    87,    28,    29,   143,   144,    32,
      32,    94,    35,    96,    97,    94,    39,    39,    49,    12,
     193,   140,   141,   142,   143,   144,    49,   150,   151,    32,
     149,   150,   151,   152,   153,     4,    12,    35,   163,     8,
      32,    10,    32,    12,   127,    35,    15,    16,    32,    39,
      37,    35,    12,    36,   179,    39,    12,   140,   141,   142,
     143,   144,    40,   165,   164,    38,   149,   150,   151,   152,
     153,   164,   164,    41,    39,    39,    39,   177,    46,     4,
      33,   164,   207,     8,   177,   177,    34,    12,    34,    39,
      15,    16,   194,   193,   177,     4,    35,    35,    34,     8,
     193,   193,   204,    12,   206,    30,    15,    16,    33,   211,
     193,     3,     4,    34,     6,     7,     8,     9,    26,    11,
      12,    27,    40,    15,    16,    17,    18,    19,    20,    21,
      12,    36,    34,    36,    33,     3,    40,    35,     6,     7,
      32,     9,    34,    11,    12,    40,    36,    39,    34,    17,
      18,    19,    20,    21,    12,    40,    40,    40,     5,    17,
      18,    19,    20,    21,    32,     4,    34,    33,    40,     8,
       5,    39,    39,    12,    15,    40,    15,    16,    40,    60,
      12,    39,   127,    41,    42,    17,    18,    19,    20,    21,
      87,    30,   177,    64,    33,   195,   163,   193,    94,   153,
     149,   152,    -1,    -1,    -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    51,    14,     0,    12,    32,    52,     4,     8,
      12,    15,    16,    30,    33,    53,    54,    55,    56,    57,
      58,    62,    63,    68,    69,    39,    31,    33,    54,    12,
      59,    60,    35,    32,    71,    71,    12,    56,    65,    66,
      67,    10,    56,    61,    34,    36,    37,    12,     3,     6,
       7,     9,    11,    17,    18,    19,    20,    21,    34,    39,
      56,    57,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    85,    86,    91,    92,    93,    94,
      95,    97,    98,   109,   110,    60,    40,    36,    12,    64,
      60,    38,    12,    34,    39,    39,    41,    42,    57,    88,
      93,    98,    99,   100,   101,   102,   104,   105,   106,   107,
     108,   109,    39,   108,    59,    32,    39,    33,    74,    34,
      34,    35,    28,    29,    49,   111,    67,    39,    34,    76,
      79,    87,    90,   108,    57,    97,   100,   100,    39,    34,
      43,    44,    45,    41,    46,    22,    23,    47,    48,   103,
      24,    25,    26,    27,   108,    40,    70,    96,   108,    70,
      12,   108,    65,    34,    36,    40,    70,   100,   100,   100,
     101,   101,   102,   104,   104,   105,   106,    40,    33,    36,
      40,    32,    39,    40,    88,    57,    79,    71,    40,    77,
     108,    70,    70,    34,     5,    83,    84,    33,    40,    89,
      90,     7,    71,    80,     5,    84,    40,    39,    71,    71,
     108,    40,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      55,    56,    56,    56,    56,    56,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    66,    67,    68,    69,    70,    70,    71,    72,    72,
      73,    73,    74,    74,    75,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    79,    79,
      79,    80,    81,    82,    82,    83,    83,    84,    85,    86,
      87,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    93,    93,    93,    93,    94,    94,    94,    94,
      94,    95,    96,    96,    97,    98,    98,    98,    98,    99,
      99,   100,   100,   100,   101,   101,   101,   101,   102,   102,
     102,   103,   103,   103,   103,   104,   104,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   110,   110,   111,
     111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     2,     4,     4,     1,     0,
       1,     3,     2,     2,     4,     1,     0,     3,     1,     0,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     5,     7,     6,     8,     1,     2,     2,     5,     9,
       1,     1,     0,     1,     0,     1,     0,     1,     3,     2,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     4,     4,     6,     6,     1,
       1,     2,     2,     1,     1,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1
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

#line 1349 "j0gram.tab.c"

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

