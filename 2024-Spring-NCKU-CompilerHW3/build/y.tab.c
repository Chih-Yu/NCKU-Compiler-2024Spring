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
#line 2 "./compiler.y"

    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    int arrayCount;

    char* identName;
    char* identNameX;

    int noLoad = 0;

#line 84 "./build/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COUT = 3,                       /* COUT  */
  YYSYMBOL_ENDL = 4,                       /* ENDL  */
  YYSYMBOL_SHR = 5,                        /* SHR  */
  YYSYMBOL_SHL = 6,                        /* SHL  */
  YYSYMBOL_BAN = 7,                        /* BAN  */
  YYSYMBOL_BOR = 8,                        /* BOR  */
  YYSYMBOL_BNT = 9,                        /* BNT  */
  YYSYMBOL_BXO = 10,                       /* BXO  */
  YYSYMBOL_ADD = 11,                       /* ADD  */
  YYSYMBOL_SUB = 12,                       /* SUB  */
  YYSYMBOL_MUL = 13,                       /* MUL  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_REM = 15,                       /* REM  */
  YYSYMBOL_NOT = 16,                       /* NOT  */
  YYSYMBOL_GTR = 17,                       /* GTR  */
  YYSYMBOL_LES = 18,                       /* LES  */
  YYSYMBOL_GEQ = 19,                       /* GEQ  */
  YYSYMBOL_LEQ = 20,                       /* LEQ  */
  YYSYMBOL_EQL = 21,                       /* EQL  */
  YYSYMBOL_NEQ = 22,                       /* NEQ  */
  YYSYMBOL_LAN = 23,                       /* LAN  */
  YYSYMBOL_LOR = 24,                       /* LOR  */
  YYSYMBOL_VAL_ASSIGN = 25,                /* VAL_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 26,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 27,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 28,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 29,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 30,                /* REM_ASSIGN  */
  YYSYMBOL_BAN_ASSIGN = 31,                /* BAN_ASSIGN  */
  YYSYMBOL_BOR_ASSIGN = 32,                /* BOR_ASSIGN  */
  YYSYMBOL_BXO_ASSIGN = 33,                /* BXO_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 34,                /* SHR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 35,                /* SHL_ASSIGN  */
  YYSYMBOL_INC_ASSIGN = 36,                /* INC_ASSIGN  */
  YYSYMBOL_DEC_ASSIGN = 37,                /* DEC_ASSIGN  */
  YYSYMBOL_IF = 38,                        /* IF  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_FOR = 40,                       /* FOR  */
  YYSYMBOL_WHILE = 41,                     /* WHILE  */
  YYSYMBOL_RETURN = 42,                    /* RETURN  */
  YYSYMBOL_BREAK = 43,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 44,                  /* CONTINUE  */
  YYSYMBOL_VARIABLE_T = 45,                /* VARIABLE_T  */
  YYSYMBOL_BOOL_LIT = 46,                  /* BOOL_LIT  */
  YYSYMBOL_CHAR_LIT = 47,                  /* CHAR_LIT  */
  YYSYMBOL_INT_LIT = 48,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 49,                 /* FLOAT_LIT  */
  YYSYMBOL_STR_LIT = 50,                   /* STR_LIT  */
  YYSYMBOL_IDENT = 51,                     /* IDENT  */
  YYSYMBOL_THEN = 52,                      /* THEN  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* '('  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_Program = 63,                   /* Program  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 65,            /* GlobalStmtList  */
  YYSYMBOL_GlobalStmt = 66,                /* GlobalStmt  */
  YYSYMBOL_DefineVariableStmt = 67,        /* DefineVariableStmt  */
  YYSYMBOL_DefineVariableList = 68,        /* DefineVariableList  */
  YYSYMBOL_DefineVariable = 69,            /* DefineVariable  */
  YYSYMBOL_70_2 = 70,                      /* $@2  */
  YYSYMBOL_FunctionDefStmt = 71,           /* FunctionDefStmt  */
  YYSYMBOL_72_3 = 72,                      /* $@3  */
  YYSYMBOL_73_4 = 73,                      /* $@4  */
  YYSYMBOL_FunctionParameterStmtList = 74, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 75,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 76,                  /* StmtList  */
  YYSYMBOL_Stmt = 77,                      /* Stmt  */
  YYSYMBOL_CoutParmListStmt = 78,          /* CoutParmListStmt  */
  YYSYMBOL_IfStmt = 79,                    /* IfStmt  */
  YYSYMBOL_80_5 = 80,                      /* $@5  */
  YYSYMBOL_81_6 = 81,                      /* $@6  */
  YYSYMBOL_82_7 = 82,                      /* $@7  */
  YYSYMBOL_ElseStmt = 83,                  /* ElseStmt  */
  YYSYMBOL_84_8 = 84,                      /* $@8  */
  YYSYMBOL_ForStmt = 85,                   /* ForStmt  */
  YYSYMBOL_86_9 = 86,                      /* $@9  */
  YYSYMBOL_ForInitStmt = 87,               /* ForInitStmt  */
  YYSYMBOL_ForCondStmt = 88,               /* ForCondStmt  */
  YYSYMBOL_ForUpdateStmt = 89,             /* ForUpdateStmt  */
  YYSYMBOL_WhileStmt = 90,                 /* WhileStmt  */
  YYSYMBOL_91_10 = 91,                     /* $@10  */
  YYSYMBOL_92_11 = 92,                     /* $@11  */
  YYSYMBOL_AssignStmt = 93,                /* AssignStmt  */
  YYSYMBOL_94_12 = 94,                     /* $@12  */
  YYSYMBOL_95_13 = 95,                     /* $@13  */
  YYSYMBOL_96_14 = 96,                     /* $@14  */
  YYSYMBOL_97_15 = 97,                     /* $@15  */
  YYSYMBOL_98_16 = 98,                     /* $@16  */
  YYSYMBOL_99_17 = 99,                     /* $@17  */
  YYSYMBOL_100_18 = 100,                   /* $@18  */
  YYSYMBOL_101_19 = 101,                   /* $@19  */
  YYSYMBOL_102_20 = 102,                   /* $@20  */
  YYSYMBOL_103_21 = 103,                   /* $@21  */
  YYSYMBOL_104_22 = 104,                   /* $@22  */
  YYSYMBOL_ExpList = 105,                  /* ExpList  */
  YYSYMBOL_Expression = 106,               /* Expression  */
  YYSYMBOL_ExpHierarchy = 107,             /* ExpHierarchy  */
  YYSYMBOL_LORExp = 108,                   /* LORExp  */
  YYSYMBOL_LANExp = 109,                   /* LANExp  */
  YYSYMBOL_BORExp = 110,                   /* BORExp  */
  YYSYMBOL_BXOExp = 111,                   /* BXOExp  */
  YYSYMBOL_BANExp = 112,                   /* BANExp  */
  YYSYMBOL_EQUExp = 113,                   /* EQUExp  */
  YYSYMBOL_CompareExp = 114,               /* CompareExp  */
  YYSYMBOL_ShiftExp = 115,                 /* ShiftExp  */
  YYSYMBOL_AddSubExp = 116,                /* AddSubExp  */
  YYSYMBOL_MulExp = 117,                   /* MulExp  */
  YYSYMBOL_UnaryExp = 118,                 /* UnaryExp  */
  YYSYMBOL_FuncCallStmt = 119,             /* FuncCallStmt  */
  YYSYMBOL_Literal = 120,                  /* Literal  */
  YYSYMBOL_IdentExp = 121                  /* IdentExp  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   343

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      59,    60,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    68,    69,    73,    74,    78,    79,    83,
      87,    88,    92,    93,    94,    95,    95,    97,   102,   103,
     102,   107,   108,   109,   112,   113,   118,   119,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     138,   139,   140,   144,   144,   144,   145,   145,   149,   149,
     150,   154,   154,   158,   159,   162,   163,   164,   168,   169,
     173,   173,   173,   177,   177,   178,   178,   179,   179,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   186,   186,   187,   187,   188,   189,   193,   194,   195,
     199,   204,   208,   209,   213,   214,   218,   219,   223,   224,
     228,   229,   233,   234,   235,   239,   240,   241,   242,   243,
     247,   248,   252,   253,   254,   258,   259,   260,   261,   265,
     266,   267,   268,   270,   271,   275,   283,   285,   286,   287,
     291,   292,   293,   297,   301,   302
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
  "\"end of file\"", "error", "\"invalid token\"", "COUT", "ENDL", "SHR",
  "SHL", "BAN", "BOR", "BNT", "BXO", "ADD", "SUB", "MUL", "DIV", "REM",
  "NOT", "GTR", "LES", "GEQ", "LEQ", "EQL", "NEQ", "LAN", "LOR",
  "VAL_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "REM_ASSIGN", "BAN_ASSIGN", "BOR_ASSIGN", "BXO_ASSIGN", "SHR_ASSIGN",
  "SHL_ASSIGN", "INC_ASSIGN", "DEC_ASSIGN", "IF", "ELSE", "FOR", "WHILE",
  "RETURN", "BREAK", "CONTINUE", "VARIABLE_T", "BOOL_LIT", "CHAR_LIT",
  "INT_LIT", "FLOAT_LIT", "STR_LIT", "IDENT", "THEN", "';'", "','", "'['",
  "']'", "'{'", "'}'", "'('", "')'", "':'", "$accept", "Program", "$@1",
  "GlobalStmtList", "GlobalStmt", "DefineVariableStmt",
  "DefineVariableList", "DefineVariable", "$@2", "FunctionDefStmt", "$@3",
  "$@4", "FunctionParameterStmtList", "FunctionParameterStmt", "StmtList",
  "Stmt", "CoutParmListStmt", "IfStmt", "$@5", "$@6", "$@7", "ElseStmt",
  "$@8", "ForStmt", "$@9", "ForInitStmt", "ForCondStmt", "ForUpdateStmt",
  "WhileStmt", "$@10", "$@11", "AssignStmt", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22",
  "ExpList", "Expression", "ExpHierarchy", "LORExp", "LANExp", "BORExp",
  "BXOExp", "BANExp", "EQUExp", "CompareExp", "ShiftExp", "AddSubExp",
  "MulExp", "UnaryExp", "FuncCallStmt", "Literal", "IdentExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-195)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,    30,    -1,  -195,   -15,    -1,  -195,   -20,  -195,   -18,
      -4,  -195,  -195,  -195,   271,   151,  -195,    26,   271,   271,
     271,  -195,  -195,  -195,  -195,  -195,   -13,    36,  -195,  -195,
      23,    65,    83,    86,    91,    -6,    51,    96,    54,   112,
    -195,  -195,  -195,  -195,    56,   271,    58,    78,   -24,  -195,
    -195,  -195,  -195,   271,   271,    71,    72,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   -12,    82,   -31,  -195,    81,   -28,
    -195,   271,  -195,    65,    83,    86,    91,    -6,    51,    51,
      96,    96,    96,    96,    54,   112,   112,  -195,  -195,  -195,
     151,   109,    84,    78,  -195,    87,   271,  -195,  -195,    85,
      88,    97,  -195,    95,   271,  -195,  -195,   271,  -195,   106,
      98,    -5,   132,    99,  -195,  -195,   252,    90,   102,    26,
    -195,   108,   137,  -195,  -195,  -195,  -195,   123,   130,   306,
    -195,  -195,   271,    -2,   271,   125,   126,  -195,   133,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
       8,  -195,   127,   -17,   271,  -195,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,  -195,  -195,   134,
     128,   143,   139,  -195,   144,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,   148,   106,   271,   149,
     271,  -195,   106,  -195,  -195,   106,   154,   161,   171,   190,
     157,   106,  -195,  -195,  -195,  -195,   214,   180,  -195,  -195,
    -195,   163,   106,   233,  -195
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     0,     8,    12,
       9,    11,     5,     7,     0,     0,    18,     0,     0,     0,
       0,   129,   130,   127,   128,   126,   133,     0,    13,    90,
      91,    93,    95,    97,    99,   101,   104,   109,   111,   114,
     118,   123,   124,   132,   133,     0,     0,    23,    12,    10,
     120,   121,   119,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,    22,     0,     0,
      88,     0,   131,    92,    94,    96,    98,   100,   102,   103,
     105,   106,   107,   108,   110,   112,   113,   115,   116,   117,
       0,     0,    24,     0,    19,   134,     0,   125,   122,     0,
       0,     0,    21,     0,     0,    87,    17,    89,    25,     0,
       0,     0,     0,     0,    51,    60,     0,     0,     0,     0,
      28,     0,     0,    27,    37,    38,    39,     0,     0,     0,
     135,    16,     0,     0,     0,     0,     0,    31,     0,    32,
      33,    34,    20,    26,    35,    36,    63,    65,    67,    69,
      71,    73,    79,    81,    83,    75,    77,    85,    86,    42,
       0,    29,     0,    57,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    41,    46,
      55,     0,     0,    56,     0,    64,    66,    68,    70,    72,
      74,    80,    82,    84,    76,    78,     0,     0,     0,     0,
       0,    61,     0,    47,    53,     0,     0,     0,     0,     0,
      59,     0,    44,    52,    54,    58,     0,    50,    62,    48,
      45,     0,     0,     0,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,  -195,  -195,   216,     0,  -195,   206,  -195,  -195,
    -195,  -195,  -195,   122,  -194,  -129,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -159,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,   110,   -14,  -195,  -195,   169,   179,   181,
     178,   183,    17,     9,   174,    47,    -9,   -97,    -7,  -113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,   131,    10,    11,   101,     8,
      47,   113,    76,    77,   132,   133,   143,   134,   206,   227,
     207,   230,   231,   135,   145,   191,   192,   224,   136,   146,
     217,   137,   176,   177,   178,   179,   180,   181,   185,   186,
     182,   183,   184,    79,    56,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    14,     7,   153,   170,     7,   139,    14,    46,    50,
      51,    52,   187,   -15,   193,    62,    63,    18,   218,   139,
      19,   219,   138,   103,    20,    -4,   106,   226,   129,   104,
       3,    15,   107,    13,    44,   138,     9,    15,   233,    78,
      80,    16,    53,   100,     4,    18,    54,    57,    19,   106,
      17,   171,    20,   141,    21,    22,    23,    24,    25,    26,
     139,   225,    97,    98,    99,    69,    70,    27,    64,    65,
      66,    67,   108,    90,    91,    92,    93,    48,   213,    88,
      89,    55,    21,    22,    23,    24,    25,    26,    58,   153,
     153,    59,   115,   109,   139,    27,    60,   153,    61,   139,
     120,    68,   139,    80,   153,   139,   139,   139,   139,   122,
     138,    53,   148,   139,    74,   138,    95,    96,   138,   139,
     139,   138,   138,    75,   138,    71,    72,    73,   169,   138,
     172,    81,    82,   102,   110,   138,   138,   105,   142,   111,
     122,   116,   114,   149,   123,   117,   124,   125,   126,   127,
     128,   129,   119,   118,   140,   150,   188,    26,   144,   130,
     194,   151,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   190,   122,   123,   154,   124,   125,   126,
     127,   128,   129,   155,   173,   174,   175,   189,    26,   208,
     130,   -43,   210,   122,   214,   152,   216,    21,    22,    23,
      24,    25,    44,   209,   211,   212,   215,   220,    44,   123,
      45,   124,   125,   126,   127,   128,   129,   122,   221,   229,
     232,    12,    26,    49,   130,   112,    83,   121,   123,   222,
     124,   125,   126,   127,   128,   129,   122,    84,    86,     0,
      85,    26,    94,   130,    87,     0,     0,     0,   223,     0,
       0,     0,   123,     0,   124,   125,   126,   127,   128,   129,
       0,    18,     0,     0,    19,    26,     0,   130,    20,     0,
       0,   123,   228,   124,   125,   126,   127,   128,   129,     0,
      18,     0,     0,    19,    26,     0,   130,    20,     0,     0,
       0,   234,     0,     0,     0,     0,     0,     0,    21,    22,
      23,    24,    25,    26,     0,   147,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
      27,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168
};

static const yytype_int16 yycheck[] =
{
      14,    25,     2,   132,     6,     5,   119,    25,    15,    18,
      19,    20,     4,    25,   173,    21,    22,     9,   212,   132,
      12,   215,   119,    54,    16,     0,    54,   221,    45,    60,
       0,    55,    60,    53,    51,   132,    51,    55,   232,    53,
      54,    59,    55,    55,    45,     9,    59,    24,    12,    54,
      54,    53,    16,    58,    46,    47,    48,    49,    50,    51,
     173,   220,    71,    72,    73,    11,    12,    59,    17,    18,
      19,    20,    81,    64,    65,    66,    67,    51,   207,    62,
      63,    45,    46,    47,    48,    49,    50,    51,    23,   218,
     219,     8,   106,   100,   207,    59,    10,   226,     7,   212,
     114,     5,   215,   117,   233,   218,   219,   220,   221,     3,
     207,    55,   126,   226,    56,   212,    69,    70,   215,   232,
     233,   218,   219,    45,   221,    13,    14,    15,   142,   226,
     144,    60,    60,    51,    25,   232,   233,    56,     6,    55,
       3,    56,    55,    53,    38,    57,    40,    41,    42,    43,
      44,    45,    57,    56,    56,    53,   170,    51,    59,    53,
     174,    53,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   173,     3,    38,    53,    40,    41,    42,
      43,    44,    45,    53,    59,    59,    53,    60,    51,    61,
      53,    57,    53,     3,   208,    58,   210,    46,    47,    48,
      49,    50,    51,    60,    60,    57,    57,    53,    51,    38,
      59,    40,    41,    42,    43,    44,    45,     3,    57,    39,
      57,     5,    51,    17,    53,   103,    57,   117,    38,    58,
      40,    41,    42,    43,    44,    45,     3,    58,    60,    -1,
      59,    51,    68,    53,    61,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    43,    44,    45,
      -1,     9,    -1,    -1,    12,    51,    -1,    53,    16,    -1,
      -1,    38,    58,    40,    41,    42,    43,    44,    45,    -1,
       9,    -1,    -1,    12,    51,    -1,    53,    16,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,    64,     0,    45,    65,    66,    67,    71,    51,
      68,    69,    66,    53,    25,    55,    59,    54,     9,    12,
      16,    46,    47,    48,    49,    50,    51,    59,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    51,    59,   120,    72,    51,    69,
     118,   118,   118,    55,    59,    45,   106,    24,    23,     8,
      10,     7,    21,    22,    17,    18,    19,    20,     5,    11,
      12,    13,    14,    15,    56,    45,    74,    75,   106,   105,
     106,    60,    60,   109,   110,   111,   112,   113,   114,   114,
     115,   115,   115,   115,   116,   117,   117,   118,   118,   118,
      55,    70,    51,    54,    60,    56,    54,    60,   118,   120,
      25,    55,    75,    73,    55,   106,    56,    57,    56,    57,
     106,   105,     3,    38,    40,    41,    42,    43,    44,    45,
      53,    67,    76,    77,    79,    85,    90,    93,   119,   121,
      56,    58,     6,    78,    59,    86,    91,    53,   106,    53,
      53,    53,    58,    77,    53,    53,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   106,
       6,    53,   106,    59,    59,    53,    94,    95,    96,    97,
      98,    99,   102,   103,   104,   100,   101,     4,   106,    60,
      67,    87,    88,    93,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,    80,    82,    61,    60,
      53,    60,    57,    77,   106,    57,   106,    92,    76,    76,
      53,    57,    58,    58,    89,    93,    76,    81,    58,    39,
      83,    84,    57,    76,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    64,    63,    63,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    69,    70,    69,    69,    72,    73,
      71,    74,    74,    74,    75,    75,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    78,    80,    81,    79,    82,    79,    84,    83,
      83,    86,    85,    87,    87,    88,    88,    88,    89,    89,
      91,    92,    90,    94,    93,    95,    93,    96,    93,    97,
      93,    98,    93,    99,    93,   100,    93,   101,    93,   102,
      93,   103,    93,   104,    93,    93,    93,   105,   105,   105,
     106,   107,   108,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   114,
     115,   115,   116,   116,   116,   117,   117,   117,   117,   118,
     118,   118,   118,   118,   118,   119,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     2,     1,     2,
       3,     1,     1,     3,     4,     0,     9,     7,     0,     0,
      10,     3,     1,     0,     2,     4,     2,     1,     1,     3,
       3,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       3,     3,     2,     0,     0,    10,     0,     6,     0,     5,
       0,     0,     8,     3,     5,     1,     1,     0,     1,     0,
       0,     0,     9,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     2,     2,     3,     1,     0,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     4,     1,     1,     4,     1,     1,     1,     1,
       1,     3,     1,     1,     4,     7
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
  case 2: /* $@1: %empty  */
#line 68 "./compiler.y"
      { pushScope(); }
#line 1386 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 68 "./compiler.y"
                                      { dumpScope(); }
#line 1392 "./build/y.tab.c"
    break;

  case 9: /* DefineVariableStmt: VARIABLE_T DefineVariableList  */
#line 83 "./compiler.y"
                                    { defineType((yyvsp[-1].var_type)); /* 改type*/ }
#line 1398 "./build/y.tab.c"
    break;

  case 12: /* DefineVariable: IDENT  */
#line 92 "./compiler.y"
            { createVariable(OBJECT_TYPE_UNDEFINED, (yyvsp[0].s_var), 0); codeRaw("ldc 0"); createVariableJ((yyvsp[0].s_var)); }
#line 1404 "./build/y.tab.c"
    break;

  case 13: /* DefineVariable: IDENT VAL_ASSIGN Expression  */
#line 93 "./compiler.y"
                                  { createVariable((yyvsp[0].object_val).type, (yyvsp[-2].s_var), 0); createVariableJ((yyvsp[-2].s_var)); }
#line 1410 "./build/y.tab.c"
    break;

  case 14: /* DefineVariable: IDENT '[' Literal ']'  */
#line 94 "./compiler.y"
                            { createVariable(OBJECT_TYPE_UNDEFINED, (yyvsp[-3].s_var), VAR_FLAG_ARRAY); }
#line 1416 "./build/y.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 95 "./compiler.y"
                            { arrayCount = 0; }
#line 1422 "./build/y.tab.c"
    break;

  case 16: /* DefineVariable: IDENT '[' Literal ']' $@2 VAL_ASSIGN '{' ExpList '}'  */
#line 95 "./compiler.y"
                                                                           { 
        printf("create array: %d\n", arrayCount); createVariable(OBJECT_TYPE_UNDEFINED, (yyvsp[-8].s_var), VAR_FLAG_ARRAY); }
#line 1429 "./build/y.tab.c"
    break;

  case 17: /* DefineVariable: IDENT '[' Literal ']' '[' Literal ']'  */
#line 97 "./compiler.y"
                                            { createVariable(OBJECT_TYPE_UNDEFINED, (yyvsp[-6].s_var), VAR_FLAG_ARRAY); }
#line 1435 "./build/y.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 102 "./compiler.y"
                           { createFunction((yyvsp[-2].var_type), (yyvsp[-1].s_var)); pushScope();}
#line 1441 "./build/y.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 103 "./compiler.y"
                                      { markFuncSig(); }
#line 1447 "./build/y.tab.c"
    break;

  case 20: /* FunctionDefStmt: VARIABLE_T IDENT '(' $@3 FunctionParameterStmtList ')' $@4 '{' StmtList '}'  */
#line 104 "./compiler.y"
                         { dumpScope(); codeRaw("return"); codeRaw(".end method"); }
#line 1453 "./build/y.tab.c"
    break;

  case 24: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 112 "./compiler.y"
                       { pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), VAR_FLAG_DEFAULT); }
#line 1459 "./build/y.tab.c"
    break;

  case 25: /* FunctionParameterStmt: VARIABLE_T IDENT '[' ']'  */
#line 113 "./compiler.y"
                               { pushFunParm((yyvsp[-3].var_type), (yyvsp[-2].s_var), VAR_FLAG_ARRAY); }
#line 1465 "./build/y.tab.c"
    break;

  case 29: /* Stmt: COUT CoutParmListStmt ';'  */
#line 124 "./compiler.y"
                                { stdoutPrint(); }
#line 1471 "./build/y.tab.c"
    break;

  case 30: /* Stmt: RETURN Expression ';'  */
#line 125 "./compiler.y"
                            { printf("RETURN\n"); /*codeRaw("return");*/ }
#line 1477 "./build/y.tab.c"
    break;

  case 31: /* Stmt: RETURN ';'  */
#line 126 "./compiler.y"
                 { printf("RETURN\n"); }
#line 1483 "./build/y.tab.c"
    break;

  case 32: /* Stmt: BREAK ';'  */
#line 127 "./compiler.y"
                 { printf("BREAK\n"); }
#line 1489 "./build/y.tab.c"
    break;

  case 33: /* Stmt: CONTINUE ';'  */
#line 128 "./compiler.y"
                    { printf("CONTINUE\n"); }
#line 1495 "./build/y.tab.c"
    break;

  case 40: /* CoutParmListStmt: CoutParmListStmt SHL ENDL  */
#line 138 "./compiler.y"
                                { codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;"); codeRaw("invokevirtual java/io/PrintStream/println()V"); fprintf(yyout, "\n");}
#line 1501 "./build/y.tab.c"
    break;

  case 41: /* CoutParmListStmt: CoutParmListStmt SHL Expression  */
#line 139 "./compiler.y"
                                      { printExpJ((yyvsp[0].object_val).type); pushFunInParm(&(yyvsp[0].object_val)); }
#line 1507 "./build/y.tab.c"
    break;

  case 42: /* CoutParmListStmt: SHL Expression  */
#line 140 "./compiler.y"
                     { printExpJ((yyvsp[0].object_val).type); pushFunInParm(&(yyvsp[0].object_val)); }
#line 1513 "./build/y.tab.c"
    break;

  case 43: /* $@5: %empty  */
#line 144 "./compiler.y"
                            { printf("IF\n"); pushScope(); }
#line 1519 "./build/y.tab.c"
    break;

  case 44: /* $@6: %empty  */
#line 144 "./compiler.y"
                                                                              { dumpScope(); }
#line 1525 "./build/y.tab.c"
    break;

  case 46: /* $@7: %empty  */
#line 145 "./compiler.y"
                            { printf("IF\n"); }
#line 1531 "./build/y.tab.c"
    break;

  case 48: /* $@8: %empty  */
#line 149 "./compiler.y"
           { printf("ELSE\n"); pushScope(); }
#line 1537 "./build/y.tab.c"
    break;

  case 49: /* ElseStmt: ELSE $@8 '{' StmtList '}'  */
#line 149 "./compiler.y"
                                                               { dumpScope();}
#line 1543 "./build/y.tab.c"
    break;

  case 51: /* $@9: %empty  */
#line 154 "./compiler.y"
          { printf("FOR\n"); pushScope(); }
#line 1549 "./build/y.tab.c"
    break;

  case 52: /* ForStmt: FOR $@9 '(' ForInitStmt ')' '{' StmtList '}'  */
#line 154 "./compiler.y"
                                                                                 { dumpScope(); }
#line 1555 "./build/y.tab.c"
    break;

  case 53: /* ForInitStmt: DefineVariableStmt ':' Expression  */
#line 158 "./compiler.y"
                                        { defineType((yyvsp[0].object_val).type); }
#line 1561 "./build/y.tab.c"
    break;

  case 60: /* $@10: %empty  */
#line 173 "./compiler.y"
            { printf("WHILE\n"); }
#line 1567 "./build/y.tab.c"
    break;

  case 61: /* $@11: %empty  */
#line 173 "./compiler.y"
                                                      { pushScope(); }
#line 1573 "./build/y.tab.c"
    break;

  case 62: /* WhileStmt: WHILE $@10 '(' Expression ')' $@11 '{' StmtList '}'  */
#line 173 "./compiler.y"
                                                                                        { dumpScope();}
#line 1579 "./build/y.tab.c"
    break;

  case 63: /* $@12: %empty  */
#line 177 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1585 "./build/y.tab.c"
    break;

  case 64: /* AssignStmt: IdentExp VAL_ASSIGN $@12 Expression  */
#line 177 "./compiler.y"
                                                                         { printf("EQL_ASSIGN\n"); createVariableJ(identNameX);}
#line 1591 "./build/y.tab.c"
    break;

  case 65: /* $@13: %empty  */
#line 178 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1597 "./build/y.tab.c"
    break;

  case 66: /* AssignStmt: IdentExp ADD_ASSIGN $@13 Expression  */
#line 178 "./compiler.y"
                                                                         { printf("ADD_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("iadd");}else{codeRaw("fadd");} createVariableJ(identNameX);}
#line 1603 "./build/y.tab.c"
    break;

  case 67: /* $@14: %empty  */
#line 179 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1609 "./build/y.tab.c"
    break;

  case 68: /* AssignStmt: IdentExp SUB_ASSIGN $@14 Expression  */
#line 179 "./compiler.y"
                                                                         { printf("SUB_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("isub");}else{codeRaw("fsub");} createVariableJ(identNameX);}
#line 1615 "./build/y.tab.c"
    break;

  case 69: /* $@15: %empty  */
#line 180 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1621 "./build/y.tab.c"
    break;

  case 70: /* AssignStmt: IdentExp MUL_ASSIGN $@15 Expression  */
#line 180 "./compiler.y"
                                                                         { printf("MUL_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("imul");}else{codeRaw("fmul");} createVariableJ(identNameX);}
#line 1627 "./build/y.tab.c"
    break;

  case 71: /* $@16: %empty  */
#line 181 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1633 "./build/y.tab.c"
    break;

  case 72: /* AssignStmt: IdentExp DIV_ASSIGN $@16 Expression  */
#line 181 "./compiler.y"
                                                                         { printf("DIV_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("idiv");}else{codeRaw("fdiv");} createVariableJ(identNameX);}
#line 1639 "./build/y.tab.c"
    break;

  case 73: /* $@17: %empty  */
#line 182 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1645 "./build/y.tab.c"
    break;

  case 74: /* AssignStmt: IdentExp REM_ASSIGN $@17 Expression  */
#line 182 "./compiler.y"
                                                                         { printf("REM_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("irem");}else{codeRaw("frem");} createVariableJ(identNameX);}
#line 1651 "./build/y.tab.c"
    break;

  case 75: /* $@18: %empty  */
#line 183 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1657 "./build/y.tab.c"
    break;

  case 76: /* AssignStmt: IdentExp SHR_ASSIGN $@18 Expression  */
#line 183 "./compiler.y"
                                                                         { printf("SHR_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("ishr");}else{codeRaw("fshr");} createVariableJ(identNameX);}
#line 1663 "./build/y.tab.c"
    break;

  case 77: /* $@19: %empty  */
#line 184 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1669 "./build/y.tab.c"
    break;

  case 78: /* AssignStmt: IdentExp SHL_ASSIGN $@19 Expression  */
#line 184 "./compiler.y"
                                                                         { printf("SHL_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("ishl");}else{codeRaw("fshl");} createVariableJ(identNameX);}
#line 1675 "./build/y.tab.c"
    break;

  case 79: /* $@20: %empty  */
#line 185 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1681 "./build/y.tab.c"
    break;

  case 80: /* AssignStmt: IdentExp BAN_ASSIGN $@20 Expression  */
#line 185 "./compiler.y"
                                                                         { printf("BAN_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("iand");}else{codeRaw("fand");} createVariableJ(identNameX);}
#line 1687 "./build/y.tab.c"
    break;

  case 81: /* $@21: %empty  */
#line 186 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1693 "./build/y.tab.c"
    break;

  case 82: /* AssignStmt: IdentExp BOR_ASSIGN $@21 Expression  */
#line 186 "./compiler.y"
                                                                         { printf("BOR_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("ior");}else{codeRaw("for");} createVariableJ(identNameX);}
#line 1699 "./build/y.tab.c"
    break;

  case 83: /* $@22: %empty  */
#line 187 "./compiler.y"
                          { identNameX = strdup(identName); }
#line 1705 "./build/y.tab.c"
    break;

  case 84: /* AssignStmt: IdentExp BXO_ASSIGN $@22 Expression  */
#line 187 "./compiler.y"
                                                                         { printf("BXO_ASSIGN\n"); if((yyvsp[-3].object_val).type == OBJECT_TYPE_INT){codeRaw("ixor");}else{codeRaw("fxor");} createVariableJ(identNameX);}
#line 1711 "./build/y.tab.c"
    break;

  case 85: /* AssignStmt: IdentExp INC_ASSIGN  */
#line 188 "./compiler.y"
                          { printf("INC_ASSIGN\n"); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("INC");}else{compareFloatJ("INC");}}
#line 1717 "./build/y.tab.c"
    break;

  case 86: /* AssignStmt: IdentExp DEC_ASSIGN  */
#line 189 "./compiler.y"
                          { printf("DEC_ASSIGN\n"); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("DEC");}else{compareFloatJ("DEC");}}
#line 1723 "./build/y.tab.c"
    break;

  case 87: /* ExpList: ExpList ',' Expression  */
#line 193 "./compiler.y"
                             { arrayCount++; }
#line 1729 "./build/y.tab.c"
    break;

  case 88: /* ExpList: Expression  */
#line 194 "./compiler.y"
                 { arrayCount++; }
#line 1735 "./build/y.tab.c"
    break;

  case 90: /* Expression: ExpHierarchy  */
#line 199 "./compiler.y"
                   { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1741 "./build/y.tab.c"
    break;

  case 91: /* ExpHierarchy: LORExp  */
#line 204 "./compiler.y"
             { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1747 "./build/y.tab.c"
    break;

  case 92: /* LORExp: LORExp LOR LANExp  */
#line 208 "./compiler.y"
                        { printf("LOR\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("ior");}else{codeRaw("ior");}}
#line 1753 "./build/y.tab.c"
    break;

  case 93: /* LORExp: LANExp  */
#line 209 "./compiler.y"
             { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1759 "./build/y.tab.c"
    break;

  case 94: /* LANExp: LANExp LAN BORExp  */
#line 213 "./compiler.y"
                        { printf("LAN\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("iand");}else{codeRaw("iand");} }
#line 1765 "./build/y.tab.c"
    break;

  case 95: /* LANExp: BORExp  */
#line 214 "./compiler.y"
             { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1771 "./build/y.tab.c"
    break;

  case 96: /* BORExp: BORExp BOR BXOExp  */
#line 218 "./compiler.y"
                        { printf("BOR\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("ior");}else{codeRaw("ior");}}
#line 1777 "./build/y.tab.c"
    break;

  case 97: /* BORExp: BXOExp  */
#line 219 "./compiler.y"
             { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1783 "./build/y.tab.c"
    break;

  case 98: /* BXOExp: BXOExp BXO BANExp  */
#line 223 "./compiler.y"
                        { printf("BXO\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("ixor");}else{codeRaw("ixor");}}
#line 1789 "./build/y.tab.c"
    break;

  case 99: /* BXOExp: BANExp  */
#line 224 "./compiler.y"
             { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1795 "./build/y.tab.c"
    break;

  case 100: /* BANExp: BANExp BAN EQUExp  */
#line 228 "./compiler.y"
                        { printf("BAN\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("iand");}else{codeRaw("iand");}}
#line 1801 "./build/y.tab.c"
    break;

  case 101: /* BANExp: EQUExp  */
#line 229 "./compiler.y"
             { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1807 "./build/y.tab.c"
    break;

  case 102: /* EQUExp: EQUExp EQL CompareExp  */
#line 233 "./compiler.y"
                            { printf("EQL\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("EQL");}else{compareFloatJ("EQL");}}
#line 1813 "./build/y.tab.c"
    break;

  case 103: /* EQUExp: EQUExp NEQ CompareExp  */
#line 234 "./compiler.y"
                            { printf("NEQ\n"); (yyval.object_val) = (yyvsp[0].object_val); compareIntJ("NEQ"); }
#line 1819 "./build/y.tab.c"
    break;

  case 104: /* EQUExp: CompareExp  */
#line 235 "./compiler.y"
                 { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1825 "./build/y.tab.c"
    break;

  case 105: /* CompareExp: CompareExp GTR ShiftExp  */
#line 239 "./compiler.y"
                              { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("GTR");}else{compareFloatJ("GTR");}}
#line 1831 "./build/y.tab.c"
    break;

  case 106: /* CompareExp: CompareExp LES ShiftExp  */
#line 240 "./compiler.y"
                              { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("LES");}else{compareFloatJ("LES");}}
#line 1837 "./build/y.tab.c"
    break;

  case 107: /* CompareExp: CompareExp GEQ ShiftExp  */
#line 241 "./compiler.y"
                              { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("GEQ");}else{compareFloatJ("GEQ");}}
#line 1843 "./build/y.tab.c"
    break;

  case 108: /* CompareExp: CompareExp LEQ ShiftExp  */
#line 242 "./compiler.y"
                              { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("LEQ");}else{compareFloatJ("LEQ");}}
#line 1849 "./build/y.tab.c"
    break;

  case 109: /* CompareExp: ShiftExp  */
#line 243 "./compiler.y"
               { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1855 "./build/y.tab.c"
    break;

  case 110: /* ShiftExp: ShiftExp SHR AddSubExp  */
#line 247 "./compiler.y"
                             { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("ishr");}else{codeRaw("fshr");}}
#line 1861 "./build/y.tab.c"
    break;

  case 111: /* ShiftExp: AddSubExp  */
#line 248 "./compiler.y"
                { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1867 "./build/y.tab.c"
    break;

  case 112: /* AddSubExp: AddSubExp ADD MulExp  */
#line 252 "./compiler.y"
                           { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("iadd");}else{codeRaw("fadd");}}
#line 1873 "./build/y.tab.c"
    break;

  case 113: /* AddSubExp: AddSubExp SUB MulExp  */
#line 253 "./compiler.y"
                           { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("isub");}else{codeRaw("fsub");}}
#line 1879 "./build/y.tab.c"
    break;

  case 114: /* AddSubExp: MulExp  */
#line 254 "./compiler.y"
             { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1885 "./build/y.tab.c"
    break;

  case 115: /* MulExp: MulExp MUL UnaryExp  */
#line 258 "./compiler.y"
                          { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("imul");}else{codeRaw("fmul");}}
#line 1891 "./build/y.tab.c"
    break;

  case 116: /* MulExp: MulExp DIV UnaryExp  */
#line 259 "./compiler.y"
                          { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("idiv");}else{codeRaw("fdiv");}}
#line 1897 "./build/y.tab.c"
    break;

  case 117: /* MulExp: MulExp REM UnaryExp  */
#line 260 "./compiler.y"
                          { (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("irem");}else{codeRaw("frem");}}
#line 1903 "./build/y.tab.c"
    break;

  case 118: /* MulExp: UnaryExp  */
#line 261 "./compiler.y"
               { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1909 "./build/y.tab.c"
    break;

  case 119: /* UnaryExp: NOT UnaryExp  */
#line 265 "./compiler.y"
                   { printf("NOT\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("NOT");}else{compareFloatJ("NOT");}}
#line 1915 "./build/y.tab.c"
    break;

  case 120: /* UnaryExp: BNT UnaryExp  */
#line 266 "./compiler.y"
                   { printf("BNT\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){compareIntJ("NOT");}else{compareFloatJ("NOT");}}
#line 1921 "./build/y.tab.c"
    break;

  case 121: /* UnaryExp: SUB UnaryExp  */
#line 267 "./compiler.y"
                   { printf("NEG\n"); (yyval.object_val) = (yyvsp[0].object_val); if((yyval.object_val).type == OBJECT_TYPE_INT){codeRaw("ineg");}else{codeRaw("fneg");}}
#line 1927 "./build/y.tab.c"
    break;

  case 122: /* UnaryExp: '(' VARIABLE_T ')' UnaryExp  */
#line 268 "./compiler.y"
                                  { (yyval.object_val).type = (yyvsp[-2].var_type); objectCast((yyval.object_val).type, NULL, NULL);
                                    if((yyvsp[-2].var_type)==OBJECT_TYPE_INT){codeRaw("i2f");}else{codeRaw("f2i");}}
#line 1934 "./build/y.tab.c"
    break;

  case 123: /* UnaryExp: FuncCallStmt  */
#line 270 "./compiler.y"
                   { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1940 "./build/y.tab.c"
    break;

  case 124: /* UnaryExp: Literal  */
#line 271 "./compiler.y"
              { (yyval.object_val) = (yyvsp[0].object_val); }
#line 1946 "./build/y.tab.c"
    break;

  case 125: /* FuncCallStmt: IDENT '(' ExpList ')'  */
#line 275 "./compiler.y"
                            {
     Object *obj = findVariable((yyvsp[-3].s_var)); 
     (yyval.object_val).type = obj->returnType;
     printf("IDENT (name=%s, address=%ld)\n", (yyvsp[-3].s_var), obj->symbol->addr); 
     printf("call: %s%s\n", obj->symbol->name, obj->symbol->func_sig);}
#line 1956 "./build/y.tab.c"
    break;

  case 126: /* Literal: STR_LIT  */
#line 283 "./compiler.y"
                { 
        printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var)); (yyval.object_val).type = OBJECT_TYPE_STR; code("ldc \"%s\";", (yyvsp[0].s_var)); }
#line 1963 "./build/y.tab.c"
    break;

  case 127: /* Literal: INT_LIT  */
#line 285 "./compiler.y"
                { printf("INT_LIT %d\n", (yyvsp[0].i_var)); (yyval.object_val).value = (yyvsp[0].i_var); (yyval.object_val).type = OBJECT_TYPE_INT; code("ldc %d", (yyvsp[0].i_var));}
#line 1969 "./build/y.tab.c"
    break;

  case 128: /* Literal: FLOAT_LIT  */
#line 286 "./compiler.y"
                { printf("FLOAT_LIT %f\n", (yyvsp[0].f_var)); (yyval.object_val).value = (yyvsp[0].f_var); (yyval.object_val).type = OBJECT_TYPE_FLOAT; code("ldc %f", (yyvsp[0].f_var)); }
#line 1975 "./build/y.tab.c"
    break;

  case 129: /* Literal: BOOL_LIT  */
#line 287 "./compiler.y"
                { if((yyvsp[0].b_var)==true){ printf("BOOL_LIT TRUE\n"); codeRaw("iconst_1")}
                  else{ printf("BOOL_LIT FALSE\n"); codeRaw("iconst_0")} 
                  (yyval.object_val).value = (yyvsp[0].b_var); (yyval.object_val).type = OBJECT_TYPE_BOOL; 
                }
#line 1984 "./build/y.tab.c"
    break;

  case 130: /* Literal: CHAR_LIT  */
#line 291 "./compiler.y"
               { (yyval.object_val).type = OBJECT_TYPE_CHAR; code("ldc \"%c\";", (yyvsp[0].c_var)); }
#line 1990 "./build/y.tab.c"
    break;

  case 131: /* Literal: '(' Expression ')'  */
#line 292 "./compiler.y"
                         { (yyval.object_val) = (yyvsp[-1].object_val); }
#line 1996 "./build/y.tab.c"
    break;

  case 133: /* IdentExp: IDENT  */
#line 297 "./compiler.y"
            {
	     Object *obj = findVariable((yyvsp[0].s_var)); printf("IDENT (name=%s, address=%ld)\n", (yyvsp[0].s_var), obj->symbol->addr); 
         (yyval.object_val).type = obj->type; loadVariableJ((yyvsp[0].s_var)); identName = strdup((yyvsp[0].s_var));
        }
#line 2005 "./build/y.tab.c"
    break;

  case 134: /* IdentExp: IDENT '[' Expression ']'  */
#line 301 "./compiler.y"
                               { Object *obj = findVariable((yyvsp[-3].s_var)); printf("IDENT (name=%s, address=%ld)\n", (yyvsp[-3].s_var), obj->symbol->addr); (yyval.object_val).type = obj->type; }
#line 2011 "./build/y.tab.c"
    break;

  case 135: /* IdentExp: IDENT '[' Expression ']' '[' Expression ']'  */
#line 302 "./compiler.y"
                                                  { Object *obj = findVariable((yyvsp[-6].s_var)); printf("IDENT (name=%s, address=%ld)\n", (yyvsp[-6].s_var), obj->symbol->addr); (yyval.object_val).type = obj->type; }
#line 2017 "./build/y.tab.c"
    break;


#line 2021 "./build/y.tab.c"

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

#line 307 "./compiler.y"

/* C code section */
