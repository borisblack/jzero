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
  YYSYMBOL_BOOLEAN = 16,                   /* BOOLEAN  */
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
  YYSYMBOL_NEW = 32,                       /* NEW  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '!'  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* '>'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '.'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ')'  */
  YYSYMBOL_47_ = 47,                       /* '*'  */
  YYSYMBOL_48_ = 48,                       /* '/'  */
  YYSYMBOL_49_ = 49,                       /* '%'  */
  YYSYMBOL_50_ = 50,                       /* '+'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_ClassDecl = 52,                 /* ClassDecl  */
  YYSYMBOL_ClassBody = 53,                 /* ClassBody  */
  YYSYMBOL_ClassBodyDecls = 54,            /* ClassBodyDecls  */
  YYSYMBOL_ClassBodyDecl = 55,             /* ClassBodyDecl  */
  YYSYMBOL_FieldDecl = 56,                 /* FieldDecl  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_Name = 58,                      /* Name  */
  YYSYMBOL_QualifiedName = 59,             /* QualifiedName  */
  YYSYMBOL_VarDecls = 60,                  /* VarDecls  */
  YYSYMBOL_VarDeclarator = 61,             /* VarDeclarator  */
  YYSYMBOL_MethodReturnVal = 62,           /* MethodReturnVal  */
  YYSYMBOL_MethodDecl = 63,                /* MethodDecl  */
  YYSYMBOL_MethodHeader = 64,              /* MethodHeader  */
  YYSYMBOL_MethodDeclarator = 65,          /* MethodDeclarator  */
  YYSYMBOL_FormalParmListOpt = 66,         /* FormalParmListOpt  */
  YYSYMBOL_FormalParmList = 67,            /* FormalParmList  */
  YYSYMBOL_FormalParm = 68,                /* FormalParm  */
  YYSYMBOL_ConstructorDecl = 69,           /* ConstructorDecl  */
  YYSYMBOL_Block = 70,                     /* Block  */
  YYSYMBOL_BlockStmtsOpt = 71,             /* BlockStmtsOpt  */
  YYSYMBOL_BlockStmts = 72,                /* BlockStmts  */
  YYSYMBOL_BlockStmt = 73,                 /* BlockStmt  */
  YYSYMBOL_LocalVarDeclStmt = 74,          /* LocalVarDeclStmt  */
  YYSYMBOL_LocalVarDecl = 75,              /* LocalVarDecl  */
  YYSYMBOL_Stmt = 76,                      /* Stmt  */
  YYSYMBOL_ExprStmt = 77,                  /* ExprStmt  */
  YYSYMBOL_StmtExpr = 78,                  /* StmtExpr  */
  YYSYMBOL_IfThenStmt = 79,                /* IfThenStmt  */
  YYSYMBOL_IfThenElseStmt = 80,            /* IfThenElseStmt  */
  YYSYMBOL_IfThenElseIfStmt = 81,          /* IfThenElseIfStmt  */
  YYSYMBOL_ElseIfSequence = 82,            /* ElseIfSequence  */
  YYSYMBOL_ElseIfStmt = 83,                /* ElseIfStmt  */
  YYSYMBOL_WhileStmt = 84,                 /* WhileStmt  */
  YYSYMBOL_ForStmt = 85,                   /* ForStmt  */
  YYSYMBOL_ForInit = 86,                   /* ForInit  */
  YYSYMBOL_ExprOpt = 87,                   /* ExprOpt  */
  YYSYMBOL_ForUpdate = 88,                 /* ForUpdate  */
  YYSYMBOL_StmtExprList = 89,              /* StmtExprList  */
  YYSYMBOL_BreakStmt = 90,                 /* BreakStmt  */
  YYSYMBOL_ReturnStmt = 91,                /* ReturnStmt  */
  YYSYMBOL_Primary = 92,                   /* Primary  */
  YYSYMBOL_InstanceCreation = 93,          /* InstanceCreation  */
  YYSYMBOL_ArrayCreation = 94,             /* ArrayCreation  */
  YYSYMBOL_Literal = 95,                   /* Literal  */
  YYSYMBOL_ArgList = 96,                   /* ArgList  */
  YYSYMBOL_FieldAccess = 97,               /* FieldAccess  */
  YYSYMBOL_ArgListOpt = 98,                /* ArgListOpt  */
  YYSYMBOL_MethodCall = 99,                /* MethodCall  */
  YYSYMBOL_PostFixExpr = 100,              /* PostFixExpr  */
  YYSYMBOL_UnaryExpr = 101,                /* UnaryExpr  */
  YYSYMBOL_MulExpr = 102,                  /* MulExpr  */
  YYSYMBOL_AddExpr = 103,                  /* AddExpr  */
  YYSYMBOL_RelOp = 104,                    /* RelOp  */
  YYSYMBOL_RelExpr = 105,                  /* RelExpr  */
  YYSYMBOL_EqExpr = 106,                   /* EqExpr  */
  YYSYMBOL_CondAndExpr = 107,              /* CondAndExpr  */
  YYSYMBOL_CondOrExpr = 108,               /* CondOrExpr  */
  YYSYMBOL_ArrayAccess = 109,              /* ArrayAccess  */
  YYSYMBOL_Expr = 110,                     /* Expr  */
  YYSYMBOL_Assignment = 111,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 112,             /* LeftHandSide  */
  YYSYMBOL_AssignOp = 113                  /* AssignOp  */
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
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  216

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
       2,     2,     2,    34,     2,     2,     2,    49,     2,     2,
      45,    46,    47,    50,    42,    33,    41,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      35,    37,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    25,    25,    30,    31,    32,    33,    35,    35,    35,
      36,    40,    40,    40,    40,    40,    42,    42,    43,    46,
      46,    48,    48,    51,    51,    52,    55,    59,    62,    62,
      63,    63,    65,    70,    73,    74,    74,    75,    75,    77,
      77,    79,    80,    85,    85,    85,    85,    85,    86,    86,
      86,    87,    87,    89,    91,    91,    93,    95,    97,    99,
     102,   102,   104,   106,   109,   111,   111,   111,   112,   112,
     113,   113,   115,   115,   118,   118,   120,   123,   123,   123,
     123,   124,   124,   124,   125,   127,   129,   129,   129,   129,
     129,   131,   131,   133,   136,   136,   137,   139,   143,   143,
     144,   146,   148,   149,   150,   152,   154,   156,   157,   159,
     161,   161,   161,   161,   162,   162,   165,   166,   168,   170,
     170,   172,   172,   175,   177,   177,   178,   180,   180,   180,
     181,   181,   181
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
  "CLASSNAME", "CLASS", "STRING", "BOOLEAN", "INTLIT", "DOUBLELIT",
  "STRINGLIT", "BOOLLIT", "NULLVAL", "LESSTHANOREQUAL",
  "GREATERTHANOREQUAL", "ISEQUALTO", "NOTEQUALTO", "LOGICALAND",
  "LOGICALOR", "INCREMENT", "DECREMENT", "PUBLIC", "STATIC", "NEW", "'-'",
  "'!'", "'<'", "'>'", "'='", "';'", "'{'", "'}'", "'.'", "','", "'['",
  "']'", "'('", "')'", "'*'", "'/'", "'%'", "'+'", "$accept", "ClassDecl",
  "ClassBody", "ClassBodyDecls", "ClassBodyDecl", "FieldDecl", "Type",
  "Name", "QualifiedName", "VarDecls", "VarDeclarator", "MethodReturnVal",
  "MethodDecl", "MethodHeader", "MethodDeclarator", "FormalParmListOpt",
  "FormalParmList", "FormalParm", "ConstructorDecl", "Block",
  "BlockStmtsOpt", "BlockStmts", "BlockStmt", "LocalVarDeclStmt",
  "LocalVarDecl", "Stmt", "ExprStmt", "StmtExpr", "IfThenStmt",
  "IfThenElseStmt", "IfThenElseIfStmt", "ElseIfSequence", "ElseIfStmt",
  "WhileStmt", "ForStmt", "ForInit", "ExprOpt", "ForUpdate",
  "StmtExprList", "BreakStmt", "ReturnStmt", "Primary", "InstanceCreation",
  "ArrayCreation", "Literal", "ArgList", "FieldAccess", "ArgListOpt",
  "MethodCall", "PostFixExpr", "UnaryExpr", "MulExpr", "AddExpr", "RelOp",
  "RelExpr", "EqExpr", "CondAndExpr", "CondOrExpr", "ArrayAccess", "Expr",
  "Assignment", "LeftHandSide", "AssignOp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-130)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,     1,    62,    28,  -173,     9,     4,  -173,  -173,  -173,
      24,  -173,  -173,    15,  -173,   212,  -173,  -173,    64,    51,
    -173,  -173,    58,    58,  -173,   210,   246,  -173,  -173,  -173,
      30,    44,    88,   191,  -173,  -173,  -173,    64,    75,    81,
    -173,  -173,  -173,   107,  -173,    64,    95,  -173,    19,   114,
     117,   270,   118,  -173,  -173,  -173,  -173,  -173,   210,  -173,
     270,    64,     2,  -173,    92,   191,  -173,  -173,   129,  -173,
    -173,   130,  -173,  -173,  -173,  -173,  -173,  -173,  -173,   128,
    -173,  -173,  -173,    -1,   134,    61,  -173,    73,    44,  -173,
     210,    24,  -173,    44,  -173,   132,  -173,   260,   270,   270,
     270,   143,   140,   128,  -173,  -173,  -173,    82,     5,    48,
      87,   153,   154,  -173,  -173,   270,   147,    40,   137,   149,
     270,   270,  -173,  -173,  -173,  -173,   184,  -173,  -173,  -173,
     270,  -173,  -173,  -173,  -173,   163,   162,   159,    77,  -173,
    -173,  -173,  -173,  -173,   270,   270,   270,   270,   270,  -173,
    -173,  -173,  -173,   270,   270,   270,   270,   270,   167,   270,
     270,  -173,   171,   175,   173,  -173,   176,  -173,   270,    46,
      58,  -173,  -173,  -173,    82,    82,     5,    48,    48,    87,
     153,   228,   188,   187,  -173,   270,  -173,   270,   200,    77,
    -173,   236,  -173,  -173,  -173,  -173,   197,    46,    10,   239,
    -173,  -173,   205,   162,   208,  -173,  -173,    10,  -173,    58,
     270,  -173,  -173,   209,    58,  -173
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,    12,    11,
      16,    14,    13,     0,     4,     0,     5,     7,     0,    15,
      17,     8,     0,     0,     9,    29,     0,     3,     6,    21,
       0,    19,     0,    36,    25,    33,    16,     0,     0,    28,
      30,    24,    23,     0,    10,     0,     0,    18,     0,     0,
       0,    69,     0,    86,    87,    89,    88,    90,     0,    44,
       0,     0,   127,    43,     0,    35,    37,    39,     0,    40,
      45,     0,    48,    49,    50,    51,    52,    46,    47,     0,
      83,    82,    77,    78,    55,    80,    54,     0,    32,    27,
       0,     0,    26,    20,    22,     0,    74,    67,     0,     0,
       0,    99,     0,    98,    79,   102,   103,   107,   114,   116,
     119,   121,   124,    68,   125,     0,     0,    15,     0,    42,
       0,    95,    34,    38,    41,    53,     0,   131,   132,   130,
       0,    31,    75,    66,    72,     0,    65,     0,    99,    78,
     100,    80,   101,    76,     0,     0,     0,     0,     0,   110,
     111,   112,   113,     0,     0,     0,     0,     0,     0,     0,
      95,    81,     0,    94,     0,    91,    93,   126,    69,     0,
       0,   104,   105,   106,   109,   108,   115,   117,   118,   120,
     122,     0,     0,     0,   123,     0,    96,    95,     0,   127,
      73,    56,    63,    85,    84,    92,     0,    71,     0,    58,
      60,    97,     0,    70,     0,    57,    62,     0,    61,     0,
       0,    59,    64,     0,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,  -173,  -173,   242,  -173,    -2,    -4,  -173,   198,
     -12,  -173,  -173,  -173,   220,  -173,  -173,   179,  -173,   -22,
    -173,  -173,   206,  -173,   168,    89,  -173,   -94,  -172,  -173,
    -173,  -173,    84,  -173,  -173,  -173,   106,  -173,    96,  -173,
    -173,   -24,  -173,  -173,  -173,  -173,   -40,  -155,   -23,  -173,
     -93,     8,   131,  -173,     6,   138,   139,  -173,   -20,   -21,
     -15,  -173,  -173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,    15,    16,    17,    61,   101,    20,    30,
      31,    43,    21,    22,    23,    38,    39,    40,    24,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   199,   200,    75,    76,   135,   102,   202,   136,    77,
      78,   103,    80,    81,    82,   163,    83,   164,   104,   105,
     106,   107,   108,   153,   109,   110,   111,   112,    85,   165,
     114,    87,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    35,    19,   134,    18,   183,   140,   142,     8,    79,
      84,    19,     9,    18,   -15,     3,    10,   204,    86,    11,
      12,    19,    19,    37,    42,    88,   206,  -128,  -128,    62,
     113,    95,   196,    93,    13,   206,  -128,     1,   147,   118,
       5,    79,    84,    32,    14,   120,    26,   121,     6,    33,
      86,   171,   172,   173,   117,   148,   116,    96,    36,   139,
     139,    62,     4,    53,    54,    55,    56,    57,    44,    25,
     149,   150,    45,    79,    84,   190,    29,   137,    58,   141,
     141,    32,    86,   151,   152,   160,    19,    46,    37,  -129,
    -129,    60,    32,    62,   158,   138,   138,    33,  -129,   162,
      47,   127,   128,   134,   139,   139,   139,   139,   139,   167,
     129,   154,   155,   139,   139,   139,   139,   139,    32,    91,
     120,    89,   121,    90,   141,   141,   141,   141,   141,   144,
     145,   146,   122,   141,   141,   141,   141,   141,   182,    94,
     138,   138,   138,   138,   138,    79,    84,   113,   191,   138,
     138,   138,   138,   138,    86,   174,   175,    79,    84,    97,
     177,   178,    98,   115,   195,   189,    86,   124,   125,   126,
     132,  -127,  -127,    79,    84,   -79,   205,   189,   143,   156,
    -127,   157,    86,   161,    32,   211,   120,   212,   121,   213,
     159,    45,   215,   189,    48,     8,   166,    49,    50,     9,
      51,   168,    52,    36,   169,   170,    11,    12,    53,    54,
      55,    56,    57,   181,     8,   184,     8,   185,     9,   186,
       9,   187,    36,    58,    10,    11,    12,    11,    12,    59,
      33,    48,   193,   194,    49,    50,    60,    51,   197,    52,
      36,   198,    13,   201,   207,    53,    54,    55,    56,    57,
       8,   209,    27,   210,     9,   214,    41,    28,    36,   119,
      58,    11,    12,    92,     8,   133,    59,    33,     9,   131,
     192,   123,    36,    60,   188,    11,    12,    53,    54,    55,
      56,    57,    36,   208,   176,     0,     0,    53,    54,    55,
      56,    57,    58,   203,   179,     0,   180,     0,     0,     0,
       0,     0,    58,    99,   100,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    60
};

static const yytype_int16 yycheck[] =
{
      22,    23,     6,    97,     6,   160,    99,   100,     4,    33,
      33,    15,     8,    15,    12,    14,    12,     7,    33,    15,
      16,    25,    26,    25,    26,    37,   198,    28,    29,    33,
      51,    12,   187,    45,    30,   207,    37,    30,    33,    60,
      12,    65,    65,    41,    40,    43,    31,    45,    39,    39,
      65,   144,   145,   146,    58,    50,    58,    38,    12,    99,
     100,    65,     0,    17,    18,    19,    20,    21,    38,    45,
      22,    23,    42,    97,    97,   169,    12,    98,    32,    99,
     100,    41,    97,    35,    36,    45,    90,    43,    90,    28,
      29,    45,    41,    97,   115,    99,   100,    39,    37,   120,
      12,    28,    29,   197,   144,   145,   146,   147,   148,   130,
      37,    24,    25,   153,   154,   155,   156,   157,    41,    12,
      43,    46,    45,    42,   144,   145,   146,   147,   148,    47,
      48,    49,    40,   153,   154,   155,   156,   157,   159,    44,
     144,   145,   146,   147,   148,   169,   169,   168,   170,   153,
     154,   155,   156,   157,   169,   147,   148,   181,   181,    45,
     154,   155,    45,    45,   185,   169,   181,    38,    38,    41,
      38,    28,    29,   197,   197,    41,   198,   181,    38,    26,
      37,    27,   197,    46,    41,   207,    43,   209,    45,   210,
      43,    42,   214,   197,     3,     4,    12,     6,     7,     8,
       9,    38,    11,    12,    42,    46,    15,    16,    17,    18,
      19,    20,    21,    46,     4,    44,     4,    42,     8,    46,
       8,    45,    12,    32,    12,    15,    16,    15,    16,    38,
      39,     3,    44,    46,     6,     7,    45,     9,    38,    11,
      12,     5,    30,    46,     5,    17,    18,    19,    20,    21,
       4,    46,    40,    45,     8,    46,    10,    15,    12,    61,
      32,    15,    16,    43,     4,    97,    38,    39,     8,    90,
     181,    65,    12,    45,   168,    15,    16,    17,    18,    19,
      20,    21,    12,   199,   153,    -1,    -1,    17,    18,    19,
      20,    21,    32,   197,   156,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    52,    14,     0,    12,    39,    53,     4,     8,
      12,    15,    16,    30,    40,    54,    55,    56,    57,    58,
      59,    63,    64,    65,    69,    45,    31,    40,    55,    12,
      60,    61,    41,    39,    70,    70,    12,    57,    66,    67,
      68,    10,    57,    62,    38,    42,    43,    12,     3,     6,
       7,     9,    11,    17,    18,    19,    20,    21,    32,    38,
      45,    57,    58,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    84,    85,    90,    91,    92,
      93,    94,    95,    97,    99,   109,   111,   112,    61,    46,
      42,    12,    65,    61,    44,    12,    38,    45,    45,    33,
      34,    58,    87,    92,    99,   100,   101,   102,   103,   105,
     106,   107,   108,   110,   111,    45,    57,    58,   110,    60,
      43,    45,    40,    73,    38,    38,    41,    28,    29,    37,
     113,    68,    38,    75,    78,    86,    89,   110,    58,    97,
     101,   109,   101,    38,    47,    48,    49,    33,    50,    22,
      23,    35,    36,   104,    24,    25,    26,    27,   110,    43,
      45,    46,   110,    96,    98,   110,    12,   110,    38,    42,
      46,   101,   101,   101,   102,   102,   103,   105,   105,   106,
     107,    46,   110,    98,    44,    42,    46,    45,    87,    58,
      78,    70,    76,    44,    46,   110,    98,    38,     5,    82,
      83,    46,    88,    89,     7,    70,    79,     5,    83,    46,
      45,    70,    70,   110,    46,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    55,
      56,    57,    57,    57,    57,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    62,    63,    64,    65,    66,    66,
      67,    67,    68,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    78,    78,    79,    80,    81,    81,
      82,    82,    83,    84,    85,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    92,    92,    92,
      92,    92,    92,    92,    93,    94,    95,    95,    95,    95,
      95,    96,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   102,   102,   102,   102,   103,   103,   103,
     104,   104,   104,   104,   105,   105,   106,   106,   106,   107,
     107,   108,   108,   109,   110,   110,   111,   112,   112,   112,
     113,   113,   113
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
       1,     3,     1,     1,     5,     5,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     0,     4,     6,     1,     1,
       2,     2,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     3,     1,     3,     3,     1,
       3,     1,     3,     4,     1,     1,     3,     1,     1,     1,
       1,     1,     1
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
#line 25 "j0gram.y"
                                             {
  (yyval.t)=node("ClassDecl",1000,2,(yyvsp[-1].t),(yyvsp[0].t));
  semantic((yyval.t));
  gencode((yyval.t));
 }
#line 1363 "j0gram.tab.c"
    break;

  case 3: /* ClassBody: '{' ClassBodyDecls '}'  */
#line 30 "j0gram.y"
                                  { (yyval.t)=node("ClassBody",1010,1,(yyvsp[-1].t)); }
#line 1369 "j0gram.tab.c"
    break;

  case 4: /* ClassBody: '{' '}'  */
#line 31 "j0gram.y"
                   { (yyval.t)=node("ClassBody",1011,0); }
#line 1375 "j0gram.tab.c"
    break;

  case 6: /* ClassBodyDecls: ClassBodyDecls ClassBodyDecl  */
#line 33 "j0gram.y"
                               {
  (yyval.t)=node("ClassBodyDecls",1020,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1382 "j0gram.tab.c"
    break;

  case 10: /* FieldDecl: Type VarDecls ';'  */
#line 36 "j0gram.y"
                             {
  (yyval.t)=node("FieldDecl",1030,2,(yyvsp[-2].t),(yyvsp[-1].t));
  calcType((yyval.t));
 }
#line 1391 "j0gram.tab.c"
    break;

  case 18: /* QualifiedName: Name '.' IDENTIFIER  */
#line 43 "j0gram.y"
                                   {
  (yyval.t)=node("QualifiedName",1040,2,(yyvsp[-2].t),(yyvsp[0].t));}
#line 1398 "j0gram.tab.c"
    break;

  case 20: /* VarDecls: VarDecls ',' VarDeclarator  */
#line 46 "j0gram.y"
                                                     {
  (yyval.t)=node("VarDecls",1050,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1405 "j0gram.tab.c"
    break;

  case 22: /* VarDeclarator: VarDeclarator '[' ']'  */
#line 48 "j0gram.y"
                                                  {
  (yyval.t)=node("VarDeclarator",1060,1,(yyvsp[-2].t)); }
#line 1412 "j0gram.tab.c"
    break;

  case 25: /* MethodDecl: MethodHeader Block  */
#line 52 "j0gram.y"
                               {
  (yyval.t)=node("MethodDecl",1380,2,(yyvsp[-1].t),(yyvsp[0].t));
 }
#line 1420 "j0gram.tab.c"
    break;

  case 26: /* MethodHeader: PUBLIC STATIC MethodReturnVal MethodDeclarator  */
#line 55 "j0gram.y"
                                                             {
  (yyval.t)=node("MethodHeader",1070,2,(yyvsp[-1].t),(yyvsp[0].t));
  calcType((yyval.t));
 }
#line 1429 "j0gram.tab.c"
    break;

  case 27: /* MethodDeclarator: IDENTIFIER '(' FormalParmListOpt ')'  */
#line 59 "j0gram.y"
                                                       {
  (yyval.t)=node("MethodDeclarator",1080,2,(yyvsp[-3].t),(yyvsp[-1].t)); }
#line 1436 "j0gram.tab.c"
    break;

  case 29: /* FormalParmListOpt: %empty  */
#line 62 "j0gram.y"
                                    {(yyval.t)=node("FormalParmListOpt",1081,0);}
#line 1442 "j0gram.tab.c"
    break;

  case 31: /* FormalParmList: FormalParmList ',' FormalParm  */
#line 63 "j0gram.y"
                                                           {
  (yyval.t)=node("FormalParmList",1090,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1449 "j0gram.tab.c"
    break;

  case 32: /* FormalParm: Type VarDeclarator  */
#line 65 "j0gram.y"
                               {
  (yyval.t)=node("FormalParm",1100,2,(yyvsp[-1].t),(yyvsp[0].t));
  calcType((yyval.t));
 }
#line 1458 "j0gram.tab.c"
    break;

  case 33: /* ConstructorDecl: MethodDeclarator Block  */
#line 70 "j0gram.y"
                                        {
  (yyval.t)=node("ConstructorDecl",1110,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1465 "j0gram.tab.c"
    break;

  case 34: /* Block: '{' BlockStmtsOpt '}'  */
#line 73 "j0gram.y"
                             {(yyval.t)=node("Block",1200,1,(yyvsp[-1].t));}
#line 1471 "j0gram.tab.c"
    break;

  case 36: /* BlockStmtsOpt: %empty  */
#line 74 "j0gram.y"
                            {(yyval.t)=node("BlockStmtsOpt",1201,0);}
#line 1477 "j0gram.tab.c"
    break;

  case 38: /* BlockStmts: BlockStmts BlockStmt  */
#line 75 "j0gram.y"
                                              {
  (yyval.t)=node("BlockStmts",1130,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1484 "j0gram.tab.c"
    break;

  case 42: /* LocalVarDecl: Type VarDecls  */
#line 80 "j0gram.y"
                            {
  (yyval.t)=node("LocalVarDecl",1140,2,(yyvsp[-1].t),(yyvsp[0].t));
  calcType((yyval.t));
 }
#line 1493 "j0gram.tab.c"
    break;

  case 56: /* IfThenStmt: IF '(' Expr ')' Block  */
#line 93 "j0gram.y"
                                  {
  (yyval.t)=node("IfThenStmt",1150,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1500 "j0gram.tab.c"
    break;

  case 57: /* IfThenElseStmt: IF '(' Expr ')' Block ELSE Block  */
#line 95 "j0gram.y"
                                                 {
  (yyval.t)=node("IfThenElseStmt",1160,3,(yyvsp[-4].t),(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1507 "j0gram.tab.c"
    break;

  case 58: /* IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence  */
#line 97 "j0gram.y"
                                                       {
  (yyval.t)=node("IfThenElseIfStmt",1170,3,(yyvsp[-3].t),(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1514 "j0gram.tab.c"
    break;

  case 59: /* IfThenElseIfStmt: IF '(' Expr ')' Block ElseIfSequence ELSE Block  */
#line 99 "j0gram.y"
                                                   {
  (yyval.t)=node("IfThenElseIfStmt",1171,3,(yyvsp[-5].t),(yyvsp[-3].t),(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1521 "j0gram.tab.c"
    break;

  case 61: /* ElseIfSequence: ElseIfSequence ElseIfStmt  */
#line 102 "j0gram.y"
                                                       {
  (yyval.t)=node("ElseIfSequence",1180,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1528 "j0gram.tab.c"
    break;

  case 62: /* ElseIfStmt: ELSE IfThenStmt  */
#line 104 "j0gram.y"
                            {
  (yyval.t)=node("ElseIfStmt",1190,1,(yyvsp[0].t)); }
#line 1535 "j0gram.tab.c"
    break;

  case 63: /* WhileStmt: WHILE '(' Expr ')' Stmt  */
#line 106 "j0gram.y"
                                   {
  (yyval.t)=node("WhileStmt",1210,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1542 "j0gram.tab.c"
    break;

  case 64: /* ForStmt: FOR '(' ForInit ';' ExprOpt ';' ForUpdate ')' Block  */
#line 109 "j0gram.y"
                                                             {
  (yyval.t)=node("ForStmt",1220,4,(yyvsp[-6].t),(yyvsp[-4].t),(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1549 "j0gram.tab.c"
    break;

  case 67: /* ForInit: %empty  */
#line 111 "j0gram.y"
                                       {(yyval.t)=node("ForInit",1221,0);}
#line 1555 "j0gram.tab.c"
    break;

  case 69: /* ExprOpt: %empty  */
#line 112 "j0gram.y"
                {(yyval.t)=node("ExprOpt",1222,0);}
#line 1561 "j0gram.tab.c"
    break;

  case 71: /* ForUpdate: %empty  */
#line 113 "j0gram.y"
                          {(yyval.t)=node("ForUpdate",1223,0);}
#line 1567 "j0gram.tab.c"
    break;

  case 73: /* StmtExprList: StmtExprList ',' StmtExpr  */
#line 115 "j0gram.y"
                                                   {
  (yyval.t)=node("StmtExprList",1230,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1574 "j0gram.tab.c"
    break;

  case 75: /* BreakStmt: BREAK IDENTIFIER ';'  */
#line 118 "j0gram.y"
                                            {
  (yyval.t)=node("BreakStmt",1240,1,(yyvsp[-1].t)); }
#line 1581 "j0gram.tab.c"
    break;

  case 76: /* ReturnStmt: RETURN ExprOpt ';'  */
#line 120 "j0gram.y"
                               {
  (yyval.t)=node("ReturnStmt",1250,1,(yyvsp[-1].t)); }
#line 1588 "j0gram.tab.c"
    break;

  case 81: /* Primary: '(' Expr ')'  */
#line 124 "j0gram.y"
                      { (yyval.t)=(yyvsp[-1].t);}
#line 1594 "j0gram.tab.c"
    break;

  case 84: /* InstanceCreation: NEW Name '(' ArgListOpt ')'  */
#line 125 "j0gram.y"
                                              {
  (yyval.t)=node("InstanceCreation", 1261, 2, (yyvsp[-3].t), (yyvsp[-1].t)); }
#line 1601 "j0gram.tab.c"
    break;

  case 85: /* ArrayCreation: NEW Type '[' Expr ']'  */
#line 127 "j0gram.y"
                                     {
  (yyval.t)=node("ArrayCreation", 1260, 2, (yyvsp[-3].t), (yyvsp[-1].t)); }
#line 1608 "j0gram.tab.c"
    break;

  case 92: /* ArgList: ArgList ',' Expr  */
#line 131 "j0gram.y"
                                 {
  (yyval.t)=node("ArgList",1270,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1615 "j0gram.tab.c"
    break;

  case 93: /* FieldAccess: Primary '.' IDENTIFIER  */
#line 133 "j0gram.y"
                                    {
  (yyval.t)=node("FieldAccess",1280,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1622 "j0gram.tab.c"
    break;

  case 95: /* ArgListOpt: %empty  */
#line 136 "j0gram.y"
                       {(yyval.t)=node("ArgListOpt",1281,0);}
#line 1628 "j0gram.tab.c"
    break;

  case 96: /* MethodCall: Name '(' ArgListOpt ')'  */
#line 137 "j0gram.y"
                                    {
  (yyval.t)=node("MethodCall",1290,2,(yyvsp[-3].t),(yyvsp[-1].t)); }
#line 1635 "j0gram.tab.c"
    break;

  case 97: /* MethodCall: Primary '.' IDENTIFIER '(' ArgListOpt ')'  */
#line 139 "j0gram.y"
                                              {
    (yyval.t)=node("MethodCall",1291,3,(yyvsp[-5].t),(yyvsp[-3].t),(yyvsp[-1].t)); }
#line 1642 "j0gram.tab.c"
    break;

  case 100: /* UnaryExpr: '-' UnaryExpr  */
#line 144 "j0gram.y"
                          {
  (yyval.t)=node("UnaryExpr",1300,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1649 "j0gram.tab.c"
    break;

  case 101: /* UnaryExpr: '!' UnaryExpr  */
#line 146 "j0gram.y"
                    {
  (yyval.t)=node("UnaryExpr",1301,2,(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1656 "j0gram.tab.c"
    break;

  case 104: /* MulExpr: MulExpr '*' UnaryExpr  */
#line 150 "j0gram.y"
                            {
      (yyval.t)=node("MulExpr",1310,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1663 "j0gram.tab.c"
    break;

  case 105: /* MulExpr: MulExpr '/' UnaryExpr  */
#line 152 "j0gram.y"
                            {
      (yyval.t)=node("MulExpr",1311,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1670 "j0gram.tab.c"
    break;

  case 106: /* MulExpr: MulExpr '%' UnaryExpr  */
#line 154 "j0gram.y"
                            {
      (yyval.t)=node("MulExpr",1312,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1677 "j0gram.tab.c"
    break;

  case 108: /* AddExpr: AddExpr '+' MulExpr  */
#line 157 "j0gram.y"
                          {
      (yyval.t)=node("AddExpr",1320,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1684 "j0gram.tab.c"
    break;

  case 109: /* AddExpr: AddExpr '-' MulExpr  */
#line 159 "j0gram.y"
                          {
      (yyval.t)=node("AddExpr",1321,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1691 "j0gram.tab.c"
    break;

  case 115: /* RelExpr: RelExpr RelOp AddExpr  */
#line 162 "j0gram.y"
                                         {
  (yyval.t)=node("RelExpr",1330,3,(yyvsp[-2].t),(yyvsp[-1].t),(yyvsp[0].t)); }
#line 1698 "j0gram.tab.c"
    break;

  case 117: /* EqExpr: EqExpr ISEQUALTO RelExpr  */
#line 166 "j0gram.y"
                               {
  (yyval.t)=node("EqExpr",1340,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1705 "j0gram.tab.c"
    break;

  case 118: /* EqExpr: EqExpr NOTEQUALTO RelExpr  */
#line 168 "j0gram.y"
                            {
  (yyval.t)=node("EqExpr",1341,2,(yyvsp[-2].t),(yyvsp[0].t)); }
#line 1712 "j0gram.tab.c"
    break;

  case 120: /* CondAndExpr: CondAndExpr LOGICALAND EqExpr  */
#line 170 "j0gram.y"
                                                    {
  (yyval.t)=node("CondAndExpr", 1350, 2, (yyvsp[-2].t), (yyvsp[0].t)); }
#line 1719 "j0gram.tab.c"
    break;

  case 122: /* CondOrExpr: CondOrExpr LOGICALOR CondAndExpr  */
#line 172 "j0gram.y"
                                                           {
  (yyval.t)=node("CondOrExpr", 1360, 2, (yyvsp[-2].t), (yyvsp[0].t)); }
#line 1726 "j0gram.tab.c"
    break;

  case 123: /* ArrayAccess: Name '[' Expr ']'  */
#line 175 "j0gram.y"
                               { (yyval.t)=node("ArrayAccess",1390,2, (yyvsp[-3].t),(yyvsp[-1].t)); }
#line 1732 "j0gram.tab.c"
    break;

  case 126: /* Assignment: LeftHandSide AssignOp Expr  */
#line 178 "j0gram.y"
                                       {
  (yyval.t)=node("Assignment",1370, 3, (yyvsp[-2].t), (yyvsp[-1].t), (yyvsp[0].t)); }
#line 1739 "j0gram.tab.c"
    break;


#line 1743 "j0gram.tab.c"

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

#line 182 "j0gram.y"


const char* token_Name(int t) {
    return yysymbol_name(YYTRANSLATE(t));
}
