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
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '!'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '>'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* '.'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_48_ = 48,                       /* '%'  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
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
  YYSYMBOL_Block = 69,                     /* Block  */
  YYSYMBOL_BlockStmtsOpt = 70,             /* BlockStmtsOpt  */
  YYSYMBOL_BlockStmts = 71,                /* BlockStmts  */
  YYSYMBOL_BlockStmt = 72,                 /* BlockStmt  */
  YYSYMBOL_LocalVarDeclStmt = 73,          /* LocalVarDeclStmt  */
  YYSYMBOL_LocalVarDecl = 74,              /* LocalVarDecl  */
  YYSYMBOL_Stmt = 75,                      /* Stmt  */
  YYSYMBOL_ExprStmt = 76,                  /* ExprStmt  */
  YYSYMBOL_StmtExpr = 77,                  /* StmtExpr  */
  YYSYMBOL_IfThenStmt = 78,                /* IfThenStmt  */
  YYSYMBOL_IfThenElseStmt = 79,            /* IfThenElseStmt  */
  YYSYMBOL_IfThenElseIfStmt = 80,          /* IfThenElseIfStmt  */
  YYSYMBOL_ElseIfSequence = 81,            /* ElseIfSequence  */
  YYSYMBOL_ElseIfStmt = 82,                /* ElseIfStmt  */
  YYSYMBOL_WhileStmt = 83,                 /* WhileStmt  */
  YYSYMBOL_ForStmt = 84,                   /* ForStmt  */
  YYSYMBOL_ForInit = 85,                   /* ForInit  */
  YYSYMBOL_ExprOpt = 86,                   /* ExprOpt  */
  YYSYMBOL_ForUpdate = 87,                 /* ForUpdate  */
  YYSYMBOL_StmtExprList = 88,              /* StmtExprList  */
  YYSYMBOL_BreakStmt = 89,                 /* BreakStmt  */
  YYSYMBOL_ReturnStmt = 90,                /* ReturnStmt  */
  YYSYMBOL_Primary = 91,                   /* Primary  */
  YYSYMBOL_Literal = 92,                   /* Literal  */
  YYSYMBOL_ArgList = 93,                   /* ArgList  */
  YYSYMBOL_FieldAccess = 94,               /* FieldAccess  */
  YYSYMBOL_ArgListOpt = 95,                /* ArgListOpt  */
  YYSYMBOL_MethodCall = 96,                /* MethodCall  */
  YYSYMBOL_PostFixExpr = 97,               /* PostFixExpr  */
  YYSYMBOL_UnaryExpr = 98,                 /* UnaryExpr  */
  YYSYMBOL_MulExpr = 99,                   /* MulExpr  */
  YYSYMBOL_AddExpr = 100,                  /* AddExpr  */
  YYSYMBOL_RelOp = 101,                    /* RelOp  */
  YYSYMBOL_RelExpr = 102,                  /* RelExpr  */
  YYSYMBOL_EqExpr = 103,                   /* EqExpr  */
  YYSYMBOL_CondAndExpr = 104,              /* CondAndExpr  */
  YYSYMBOL_CondOrExpr = 105,               /* CondOrExpr  */
  YYSYMBOL_Expr = 106,                     /* Expr  */
  YYSYMBOL_Assignment = 107,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 108,             /* LeftHandSide  */
  YYSYMBOL_AssignOp = 109                  /* AssignOp  */
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
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

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
       2,     2,     2,    33,     2,     2,     2,    48,     2,     2,
      44,    45,    46,    49,    41,    32,    40,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      34,    36,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
static const yytype_uint8 yyrline[] =
{
       0,    24,    24,    28,    29,    30,    31,    33,    33,    33,
      34,    36,    36,    36,    36,    36,    38,    38,    39,    42,
      42,    44,    44,    47,    47,    48,    51,    53,    56,    56,
      57,    57,    59,    63,    66,    67,    67,    68,    68,    70,
      70,    72,    73,    76,    76,    76,    76,    76,    77,    77,
      77,    78,    78,    80,    82,    82,    84,    86,    88,    90,
      93,    93,    95,    97,   100,   102,   102,   102,   103,   103,
     104,   104,   106,   106,   109,   109,   111,   114,   114,   114,
     114,   116,   116,   116,   116,   116,   118,   118,   120,   123,
     123,   124,   126,   130,   130,   131,   133,   135,   136,   137,
     139,   141,   143,   144,   146,   148,   148,   148,   148,   149,
     149,   152,   153,   155,   157,   157,   159,   159,   162,   162,
     163,   165,   165,   166,   166,   166
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
  "LOGICALOR", "INCREMENT", "DECREMENT", "PUBLIC", "STATIC", "'-'", "'!'",
  "'<'", "'>'", "'='", "';'", "'{'", "'}'", "'.'", "','", "'['", "']'",
  "'('", "')'", "'*'", "'/'", "'%'", "'+'", "$accept", "ClassDecl",
  "ClassBody", "ClassBodyDecls", "ClassBodyDecl", "FieldDecl", "Type",
  "Name", "QualifiedName", "VarDecls", "VarDeclarator", "MethodReturnVal",
  "MethodDecl", "MethodHeader", "MethodDeclarator", "FormalParmListOpt",
  "FormalParmList", "FormalParm", "ConstructorDecl", "Block",
  "BlockStmtsOpt", "BlockStmts", "BlockStmt", "LocalVarDeclStmt",
  "LocalVarDecl", "Stmt", "ExprStmt", "StmtExpr", "IfThenStmt",
  "IfThenElseStmt", "IfThenElseIfStmt", "ElseIfSequence", "ElseIfStmt",
  "WhileStmt", "ForStmt", "ForInit", "ExprOpt", "ForUpdate",
  "StmtExprList", "BreakStmt", "ReturnStmt", "Primary", "Literal",
  "ArgList", "FieldAccess", "ArgListOpt", "MethodCall", "PostFixExpr",
  "UnaryExpr", "MulExpr", "AddExpr", "RelOp", "RelExpr", "EqExpr",
  "CondAndExpr", "CondOrExpr", "Expr", "Assignment", "LeftHandSide",
  "AssignOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-168)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-123)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,    21,    26,    40,  -168,     9,   224,  -168,  -168,  -168,
      -4,  -168,  -168,    41,  -168,   226,  -168,  -168,    69,    57,
    -168,  -168,    81,    81,  -168,    70,   193,  -168,  -168,  -168,
      23,    65,   101,   175,  -168,  -168,  -168,    69,    84,   104,
    -168,  -168,  -168,   134,  -168,    69,   107,  -168,     6,   112,
     113,   116,   114,  -168,  -168,  -168,  -168,  -168,  -168,   116,
      69,     2,  -168,   120,   175,  -168,  -168,   125,  -168,  -168,
     126,  -168,  -168,  -168,  -168,  -168,  -168,  -168,   128,  -168,
      48,   129,  -168,    75,    65,  -168,    70,    -4,  -168,    65,
    -168,   136,  -168,   206,   116,   116,   116,   171,   137,   128,
    -168,  -168,  -168,    79,    12,    28,    -8,   140,   144,  -168,
    -168,   116,   131,   139,   116,  -168,  -168,  -168,  -168,   173,
    -168,  -168,  -168,   116,  -168,  -168,  -168,  -168,   152,   157,
     159,    35,  -168,  -168,  -168,  -168,   116,   116,   116,   116,
     116,  -168,  -168,  -168,  -168,   116,   116,   116,   116,   116,
     161,  -168,   176,   184,  -168,   158,  -168,   116,    13,    81,
    -168,  -168,  -168,    79,    79,    12,    28,    28,    -8,   140,
     103,   116,  -168,   116,   179,    35,  -168,   215,  -168,  -168,
     186,    13,     3,   228,  -168,  -168,   190,   157,   199,  -168,
    -168,     3,  -168,    81,   116,  -168,  -168,   192,    81,  -168
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,    12,    11,
      16,    14,    13,     0,     4,     0,     5,     7,     0,    15,
      17,     8,     0,     0,     9,    29,     0,     3,     6,    21,
       0,    19,     0,    36,    25,    33,    16,     0,     0,    28,
      30,    24,    23,     0,    10,     0,     0,    18,     0,     0,
       0,    69,     0,    81,    82,    84,    83,    85,    44,     0,
       0,   121,    43,     0,    35,    37,    39,     0,    40,    45,
       0,    48,    49,    50,    51,    52,    46,    47,     0,    77,
      78,    55,    54,     0,    32,    27,     0,     0,    26,    20,
      22,     0,    74,    67,     0,     0,     0,    94,     0,    93,
      79,    97,    98,   102,   109,   111,   114,   116,   118,    68,
     119,     0,     0,    42,    90,    34,    38,    41,    53,     0,
     124,   125,   123,     0,    31,    75,    66,    72,     0,    65,
       0,    94,    78,    95,    96,    76,     0,     0,     0,     0,
       0,   105,   106,   107,   108,     0,     0,     0,     0,     0,
       0,    80,    89,     0,    86,    88,   120,    69,     0,     0,
      99,   100,   101,   104,   103,   110,   112,   113,   115,   117,
       0,     0,    91,    90,     0,   121,    73,    56,    63,    87,
       0,    71,     0,    58,    60,    92,     0,    70,     0,    57,
      62,     0,    61,     0,     0,    59,    64,     0,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,  -168,  -168,   229,  -168,    -3,    -6,  -168,   185,
     -24,  -168,  -168,  -168,   203,  -168,  -168,   162,  -168,   -21,
    -168,  -168,   183,  -168,   156,    82,  -168,   -85,  -167,  -168,
    -168,  -168,    68,  -168,  -168,  -168,    96,  -168,    74,  -168,
    -168,   -28,  -168,  -168,   -47,    85,   -27,  -168,   -67,   -45,
     115,  -168,   -92,   109,   110,  -168,   -55,   -26,  -168,  -168
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,    15,    16,    17,    60,   131,    20,    30,
      31,    43,    21,    22,    23,    38,    39,    40,    24,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   183,   184,    74,    75,   128,    98,   186,   129,    76,
      77,    99,    79,   152,    80,   153,   100,   101,   102,   103,
     104,   145,   105,   106,   107,   108,   109,   110,    83,   123
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    34,    35,    18,   112,    78,    81,    82,   127,    19,
     188,     1,    18,    84,   -15,   190,   146,   147,    91,    19,
      19,    89,    37,    42,   190,    36,     4,    61,   133,   134,
      53,    54,    55,    56,    57,     3,    78,    81,    82,   130,
      25,    33,    32,    92,   139,    97,   114,     6,   132,   132,
     141,   142,     5,    97,   166,   167,   150,    59,    61,   154,
      44,   140,   143,   144,    45,    78,    81,    82,   156,   160,
     161,   162,    26,   176,     8,    32,  -122,  -122,     9,   114,
      19,    29,    36,    37,  -122,    11,    12,    61,    97,   132,
     132,   132,   132,   132,   163,   164,   127,    32,   132,   132,
     132,   132,   132,   120,   121,    97,    48,    46,    97,    49,
      50,   122,    51,    47,    52,    36,   179,    97,   154,    33,
      53,    54,    55,    56,    57,   136,   137,   138,    36,    85,
      78,    81,    82,    53,    54,    55,    56,    57,   177,   197,
      58,    33,    78,    81,    82,    86,    87,    59,    95,    96,
      90,    97,   175,    78,    81,    82,    93,    94,   111,   115,
      59,   189,   117,   118,   175,    97,   148,    97,   119,   -79,
     195,   149,   196,   125,   135,   175,   151,   199,    48,     8,
      45,    49,    50,     9,    51,   155,    52,    36,    97,   157,
      11,    12,    53,    54,    55,    56,    57,     8,   158,  -121,
    -121,     9,   173,    41,   159,    36,   170,  -121,    11,    12,
       8,    32,    58,    33,     9,   114,   181,   171,    36,    59,
     182,    11,    12,    53,    54,    55,    56,    57,     8,   172,
       8,   185,     9,   191,     9,   193,    10,   198,    10,    11,
      12,    11,    12,   194,    28,   113,    88,   116,   124,   126,
      59,   192,   178,   174,    13,   187,    13,   168,   180,   169,
     165,     0,     0,    14,     0,    27
};

static const yytype_int16 yycheck[] =
{
       6,    22,    23,     6,    59,    33,    33,    33,    93,    15,
       7,    30,    15,    37,    12,   182,    24,    25,    12,    25,
      26,    45,    25,    26,   191,    12,     0,    33,    95,    96,
      17,    18,    19,    20,    21,    14,    64,    64,    64,    94,
      44,    38,    40,    37,    32,    51,    44,    38,    95,    96,
      22,    23,    12,    59,   146,   147,   111,    44,    64,   114,
      37,    49,    34,    35,    41,    93,    93,    93,   123,   136,
     137,   138,    31,   158,     4,    40,    28,    29,     8,    44,
      86,    12,    12,    86,    36,    15,    16,    93,    94,   136,
     137,   138,   139,   140,   139,   140,   181,    40,   145,   146,
     147,   148,   149,    28,    29,   111,     3,    42,   114,     6,
       7,    36,     9,    12,    11,    12,   171,   123,   173,    38,
      17,    18,    19,    20,    21,    46,    47,    48,    12,    45,
     158,   158,   158,    17,    18,    19,    20,    21,   159,   194,
      37,    38,   170,   170,   170,    41,    12,    44,    32,    33,
      43,   157,   158,   181,   181,   181,    44,    44,    44,    39,
      44,   182,    37,    37,   170,   171,    26,   173,    40,    40,
     191,    27,   193,    37,    37,   181,    45,   198,     3,     4,
      41,     6,     7,     8,     9,    12,    11,    12,   194,    37,
      15,    16,    17,    18,    19,    20,    21,     4,    41,    28,
      29,     8,    44,    10,    45,    12,    45,    36,    15,    16,
       4,    40,    37,    38,     8,    44,    37,    41,    12,    44,
       5,    15,    16,    17,    18,    19,    20,    21,     4,    45,
       4,    45,     8,     5,     8,    45,    12,    45,    12,    15,
      16,    15,    16,    44,    15,    60,    43,    64,    86,    93,
      44,   183,   170,   157,    30,   181,    30,   148,   173,   149,
     145,    -1,    -1,    39,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    51,    14,     0,    12,    38,    52,     4,     8,
      12,    15,    16,    30,    39,    53,    54,    55,    56,    57,
      58,    62,    63,    64,    68,    44,    31,    39,    54,    12,
      59,    60,    40,    38,    69,    69,    12,    56,    65,    66,
      67,    10,    56,    61,    37,    41,    42,    12,     3,     6,
       7,     9,    11,    17,    18,    19,    20,    21,    37,    44,
      56,    57,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    83,    84,    89,    90,    91,    92,
      94,    96,   107,   108,    60,    45,    41,    12,    64,    60,
      43,    12,    37,    44,    44,    32,    33,    57,    86,    91,
      96,    97,    98,    99,   100,   102,   103,   104,   105,   106,
     107,    44,   106,    59,    44,    39,    72,    37,    37,    40,
      28,    29,    36,   109,    67,    37,    74,    77,    85,    88,
     106,    57,    94,    98,    98,    37,    46,    47,    48,    32,
      49,    22,    23,    34,    35,   101,    24,    25,    26,    27,
     106,    45,    93,    95,   106,    12,   106,    37,    41,    45,
      98,    98,    98,    99,    99,   100,   102,   102,   103,   104,
      45,    41,    45,    44,    86,    57,    77,    69,    75,   106,
      95,    37,     5,    81,    82,    45,    87,    88,     7,    69,
      78,     5,    82,    45,    44,    69,    69,   106,    45,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      55,    56,    56,    56,    56,    56,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    66,    67,    68,    69,    70,    70,    71,    71,    72,
      72,    73,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    76,    77,    77,    78,    79,    80,    80,
      81,    81,    82,    83,    84,    85,    85,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    91,    91,    91,
      91,    92,    92,    92,    92,    92,    93,    93,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    98,    99,    99,
      99,    99,   100,   100,   100,   101,   101,   101,   101,   102,
     102,   103,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   108,   108,   109,   109,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     2,     4,     4,     1,     0,
       1,     3,     2,     2,     3,     1,     0,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     5,     7,     6,     8,
       1,     2,     2,     5,     9,     1,     1,     0,     1,     0,
       1,     0,     1,     3,     2,     3,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       0,     4,     6,     1,     1,     2,     2,     1,     1,     3,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     1
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
  case 2: /* ClassDecl: PUBLIC CLASS IDENTIFIER ClassBody  */
#line 24 "j0gram.y"
                                             {
  (yyval.t)=node("ClassDecl",1000,2,(yyvsp[-1].t),(yyvsp[0].t));
  printRoot((yyval.t));
 }
#line 1337 "j0gram.tab.c"
    break;

  case 3: /* ClassBody: '{' ClassBodyDecls '}'  */
#line 28 "j0gram.y"
                                  { (yyval.t)=node("ClassBody",1010,1,(yyvsp[-1].t)); }
#line 1343 "j0gram.tab.c"
    break;

  case 4: /* ClassBody: '{' '}'  */
#line 29 "j0gram.y"
                   { (yyval.t)=node("ClassBody",1011,0); }
#line 1349 "j0gram.tab.c"
    break;

  case 6: /* ClassBodyDecls: ClassBodyDecls ClassBodyDecl  */
#line 31 "j0gram.y"
                               {
  (yyval.t)=node("ClassBodyDecls",1020,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1356 "j0gram.tab.c"
    break;

  case 10: /* FieldDecl: Type VarDecls ';'  */
#line 34 "j0gram.y"
                             {
  (yyval.t)=node("FieldDecl",1030,2,(yyvsp[-2].t),(yyvsp[-1].t)); }
#line 1363 "j0gram.tab.c"
    break;

  case 18: /* QualifiedName: Name '.' IDENTIFIER  */
#line 39 "j0gram.y"
                                   {
  (yyval.t)=node("QualifiedName",1040,2,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1370 "j0gram.tab.c"
    break;

  case 20: /* VarDecls: VarDecls ',' VarDeclarator  */
#line 42 "j0gram.y"
                                                     {
  (yyval.t)=node("VarDecls",1050,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1377 "j0gram.tab.c"
    break;

  case 22: /* VarDeclarator: VarDeclarator '[' ']'  */
#line 44 "j0gram.y"
                                                  {
  (yyval.t)=node("VarDeclarator",1060,1,(yyvsp[-2].t)); }
#line 1384 "j0gram.tab.c"
    break;

  case 25: /* MethodDecl: MethodHeader Block  */
#line 48 "j0gram.y"
                               {
  (yyval.t)=node("MethodDecl",1380,2,(yyvsp[-1].t),(yyvsp[0].t));
 }
#line 1392 "j0gram.tab.c"
    break;

  case 26: /* MethodHeader: PUBLIC STATIC MethodReturnVal MethodDeclarator  */
#line 51 "j0gram.y"
                                                             {
  (yyval.t)=node("MethodHeader",1070,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1399 "j0gram.tab.c"
    break;

  case 27: /* MethodDeclarator: IDENTIFIER '(' FormalParmListOpt ')'  */
#line 53 "j0gram.y"
                                                       {
  (yyval.t)=node("MethodDeclarator",1080,2,(yyvsp[-3].t),(yyvsp[-1].t)); }
#line 1406 "j0gram.tab.c"
    break;

  case 29: /* FormalParmListOpt: %empty  */
#line 56 "j0gram.y"
                                    {(yyval.t)=node("FormalParmListOpt",1081,0);}
#line 1412 "j0gram.tab.c"
    break;

  case 31: /* FormalParmList: FormalParmList ',' FormalParm  */
#line 57 "j0gram.y"
                                                           {
  (yyval.t)=node("FormalParmList",1090,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1419 "j0gram.tab.c"
    break;

  case 32: /* FormalParm: Type VarDeclarator  */
#line 59 "j0gram.y"
                               {
  (yyval.t)=node("FormalParm",1100,2,(yyvsp[-1].t),(yyvsp[0].t));
 }
#line 1427 "j0gram.tab.c"
    break;

  case 33: /* ConstructorDecl: MethodDeclarator Block  */
#line 63 "j0gram.y"
                                        {
  (yyval.t)=node("ConstructorDecl",1110,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1434 "j0gram.tab.c"
    break;

  case 34: /* Block: '{' BlockStmtsOpt '}'  */
#line 66 "j0gram.y"
                             {(yyval.t)=node("Block",1200,1,(yyvsp[-1].t));}
#line 1440 "j0gram.tab.c"
    break;

  case 36: /* BlockStmtsOpt: %empty  */
#line 67 "j0gram.y"
                            {(yyval.t)=node("BlockStmtsOpt",1201,0);}
#line 1446 "j0gram.tab.c"
    break;

  case 38: /* BlockStmts: BlockStmts BlockStmt  */
#line 68 "j0gram.y"
                                              {
  (yyval.t)=node("BlockStmts",1130,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1453 "j0gram.tab.c"
    break;

  case 42: /* LocalVarDecl: Type VarDecls  */
#line 73 "j0gram.y"
                            {
  (yyval.t)=node("LocalVarDecl",1140,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1460 "j0gram.tab.c"
    break;

  case 56: /* IfThenStmt: IF '(' Expr ')' Block  */
#line 84 "j0gram.y"
                                  {
  (yyval.t)=node("IfThenStmt",1150,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1467 "j0gram.tab.c"
    break;

  case 57: /* IfThenElseStmt: IF '(' Expr ')' Block ELSE Block  */
#line 86 "j0gram.y"
                                                 {
  (yyval.t)=node("IfThenElseStmt",1160,3,(yyvsp[-4].t),(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1474 "j0gram.tab.c"
    break;

  case 58: /* IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence  */
#line 88 "j0gram.y"
                                                       {
  (yyval.t)=node("IfThenElseIfStmt",1170,3,(yyvsp[-3].t),(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1481 "j0gram.tab.c"
    break;

  case 59: /* IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence ELSE Block  */
#line 90 "j0gram.y"
                                                   {
  (yyval.t)=node("IfThenElseIfStmt",1171,3,(yyvsp[-5].t),(yyvsp[-3].t),(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1488 "j0gram.tab.c"
    break;

  case 61: /* ElseIfSequence: ElseIfSequence ElseIfStmt  */
#line 93 "j0gram.y"
                                                       {
  (yyval.t)=node("ElseIfSequence",1180,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1495 "j0gram.tab.c"
    break;

  case 62: /* ElseIfStmt: ELSE IfThenStmt  */
#line 95 "j0gram.y"
                            {
  (yyval.t)=node("ElseIfStmt",1190,1,(yyvsp[0].t)); }
#line 1502 "j0gram.tab.c"
    break;

  case 63: /* WhileStmt: WHILE '(' Expr ')' Stmt  */
#line 97 "j0gram.y"
                                   {
  (yyval.t)=node("WhileStmt",1210,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1509 "j0gram.tab.c"
    break;

  case 64: /* ForStmt: FOR '(' ForInit ';' ExprOpt ';' ForUpdate ')' Block  */
#line 100 "j0gram.y"
                                                             {
  (yyval.t)=node("ForStmt",1220,4,(yyvsp[-6].t),(yyvsp[-4].t),(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1516 "j0gram.tab.c"
    break;

  case 67: /* ForInit: %empty  */
#line 102 "j0gram.y"
                                       {(yyval.t)=node("ForInit",1221,0);}
#line 1522 "j0gram.tab.c"
    break;

  case 69: /* ExprOpt: %empty  */
#line 103 "j0gram.y"
                {(yyval.t)=node("ExprOpt",1222,0);}
#line 1528 "j0gram.tab.c"
    break;

  case 71: /* ForUpdate: %empty  */
#line 104 "j0gram.y"
                          {(yyval.t)=node("ForUpdate",1223,0);}
#line 1534 "j0gram.tab.c"
    break;

  case 73: /* StmtExprList: StmtExprList ',' StmtExpr  */
#line 106 "j0gram.y"
                                                   {
  (yyval.t)=node("StmtExprList",1230,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1541 "j0gram.tab.c"
    break;

  case 75: /* BreakStmt: BREAK IDENTIFIER ';'  */
#line 109 "j0gram.y"
                                            {
  (yyval.t)=node("BreakStmt",1240,1,(yyvsp[-1].t)); }
#line 1548 "j0gram.tab.c"
    break;

  case 76: /* ReturnStmt: RETURN ExprOpt ';'  */
#line 111 "j0gram.y"
                               {
  (yyval.t)=node("ReturnStmt",1250,1,(yyvsp[-1].t)); }
#line 1555 "j0gram.tab.c"
    break;

  case 80: /* Primary: '(' Expr ')'  */
#line 114 "j0gram.y"
                                                            {
  (yyval.t)=(yyvsp[-1].t);}
#line 1562 "j0gram.tab.c"
    break;

  case 87: /* ArgList: ArgList ',' Expr  */
#line 118 "j0gram.y"
                                 {
  (yyval.t)=node("ArgList",1270,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1569 "j0gram.tab.c"
    break;

  case 88: /* FieldAccess: Primary '.' IDENTIFIER  */
#line 120 "j0gram.y"
                                    {
  (yyval.t)=node("FieldAccess",1280,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1576 "j0gram.tab.c"
    break;

  case 90: /* ArgListOpt: %empty  */
#line 123 "j0gram.y"
                       {(yyval.t)=node("ArgListOpt",1281,0);}
#line 1582 "j0gram.tab.c"
    break;

  case 91: /* MethodCall: Name '(' ArgListOpt ')'  */
#line 124 "j0gram.y"
                                    {
  (yyval.t)=node("MethodCall",1290,2,(yyvsp[-3].t),(yyvsp[-1].t)); }
#line 1589 "j0gram.tab.c"
    break;

  case 92: /* MethodCall: Primary '.' IDENTIFIER '(' ArgListOpt ')'  */
#line 126 "j0gram.y"
                                              {
    (yyval.t)=node("MethodCall",1291,3,(yyvsp[-5].t),(yyvsp[-3].t),(yyvsp[-1].t)); }
#line 1596 "j0gram.tab.c"
    break;

  case 95: /* UnaryExpr: '-' UnaryExpr  */
#line 131 "j0gram.y"
                          {
  (yyval.t)=node("UnaryExpr",1300,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1603 "j0gram.tab.c"
    break;

  case 96: /* UnaryExpr: '!' UnaryExpr  */
#line 133 "j0gram.y"
                    {
  (yyval.t)=node("UnaryExpr",1301,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1610 "j0gram.tab.c"
    break;

  case 99: /* MulExpr: MulExpr '*' UnaryExpr  */
#line 137 "j0gram.y"
                            {
      (yyval.t)=node("MulExpr",1310,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1617 "j0gram.tab.c"
    break;

  case 100: /* MulExpr: MulExpr '/' UnaryExpr  */
#line 139 "j0gram.y"
                            {
      (yyval.t)=node("MulExpr",1311,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1624 "j0gram.tab.c"
    break;

  case 101: /* MulExpr: MulExpr '%' UnaryExpr  */
#line 141 "j0gram.y"
                            {
      (yyval.t)=node("MulExpr",1312,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1631 "j0gram.tab.c"
    break;

  case 103: /* AddExpr: AddExpr '+' MulExpr  */
#line 144 "j0gram.y"
                          {
      (yyval.t)=node("AddExpr",1320,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1638 "j0gram.tab.c"
    break;

  case 104: /* AddExpr: AddExpr '-' MulExpr  */
#line 146 "j0gram.y"
                          {
      (yyval.t)=node("AddExpr",1321,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1645 "j0gram.tab.c"
    break;

  case 110: /* RelExpr: RelExpr RelOp AddExpr  */
#line 149 "j0gram.y"
                                         {
  (yyval.t)=node("RelExpr",1330,3,(yyvsp[-2].t),(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1652 "j0gram.tab.c"
    break;

  case 112: /* EqExpr: EqExpr ISEQUALTO RelExpr  */
#line 153 "j0gram.y"
                               {
  (yyval.t)=node("EqExpr",1340,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1659 "j0gram.tab.c"
    break;

  case 113: /* EqExpr: EqExpr NOTEQUALTO RelExpr  */
#line 155 "j0gram.y"
                            {
  (yyval.t)=node("EqExpr",1341,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1666 "j0gram.tab.c"
    break;

  case 115: /* CondAndExpr: CondAndExpr LOGICALAND EqExpr  */
#line 157 "j0gram.y"
                                                    {
  (yyval.t)=node("CondAndExpr", 1350, 2, (yyvsp[-2].t), (yyvsp[0].t)); }
#line 1673 "j0gram.tab.c"
    break;

  case 117: /* CondOrExpr: CondOrExpr LOGICALOR CondAndExpr  */
#line 159 "j0gram.y"
                                                           {
  (yyval.t)=node("CondOrExpr", 1360, 2, (yyvsp[-2].t), (yyvsp[0].t)); }
#line 1680 "j0gram.tab.c"
    break;

  case 120: /* Assignment: LeftHandSide AssignOp Expr  */
#line 163 "j0gram.y"
                                       {
(yyval.t)=node("Assignment",1370, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1687 "j0gram.tab.c"
    break;


#line 1691 "j0gram.tab.c"

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

#line 167 "j0gram.y"


const char* token_Name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}
