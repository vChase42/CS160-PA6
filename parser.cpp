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
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    #include "ast.hpp"
    
    #define YYDEBUG 1
    #define YYINITDEPTH 10000
    int yylex(void);
    void yyerror(const char *);
    
    extern ASTNode* astRoot;

#line 86 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PRINT = 3,                    /* T_PRINT  */
  YYSYMBOL_T_RETURN = 4,                   /* T_RETURN  */
  YYSYMBOL_T_IF = 5,                       /* T_IF  */
  YYSYMBOL_T_ELSE = 6,                     /* T_ELSE  */
  YYSYMBOL_T_WHILE = 7,                    /* T_WHILE  */
  YYSYMBOL_T_NEW = 8,                      /* T_NEW  */
  YYSYMBOL_T_NONE = 9,                     /* T_NONE  */
  YYSYMBOL_T_EXTENDS = 10,                 /* T_EXTENDS  */
  YYSYMBOL_T_DO = 11,                      /* T_DO  */
  YYSYMBOL_T_ARROW = 12,                   /* T_ARROW  */
  YYSYMBOL_T_DOT = 13,                     /* T_DOT  */
  YYSYMBOL_T_COMMA = 14,                   /* T_COMMA  */
  YYSYMBOL_T_METHODNAME = 15,              /* T_METHODNAME  */
  YYSYMBOL_T_LBRACKET = 16,                /* T_LBRACKET  */
  YYSYMBOL_T_RBRACKET = 17,                /* T_RBRACKET  */
  YYSYMBOL_T_QMARK = 18,                   /* T_QMARK  */
  YYSYMBOL_T_COLON = 19,                   /* T_COLON  */
  YYSYMBOL_T_SEMICOLON = 20,               /* T_SEMICOLON  */
  YYSYMBOL_T_OR = 21,                      /* T_OR  */
  YYSYMBOL_T_AND = 22,                     /* T_AND  */
  YYSYMBOL_T_EQUALTO = 23,                 /* T_EQUALTO  */
  YYSYMBOL_T_GT = 24,                      /* T_GT  */
  YYSYMBOL_T_GTE = 25,                     /* T_GTE  */
  YYSYMBOL_T_ADD = 26,                     /* T_ADD  */
  YYSYMBOL_T_SUB = 27,                     /* T_SUB  */
  YYSYMBOL_T_DIV = 28,                     /* T_DIV  */
  YYSYMBOL_T_MUL = 29,                     /* T_MUL  */
  YYSYMBOL_T_UNARYMINUS = 30,              /* T_UNARYMINUS  */
  YYSYMBOL_T_NOT = 31,                     /* T_NOT  */
  YYSYMBOL_T_LPAREN = 32,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 33,                  /* T_RPAREN  */
  YYSYMBOL_T_ID = 34,                      /* T_ID  */
  YYSYMBOL_T_INT = 35,                     /* T_INT  */
  YYSYMBOL_T_TRUE = 36,                    /* T_TRUE  */
  YYSYMBOL_T_FALSE = 37,                   /* T_FALSE  */
  YYSYMBOL_T_NUM = 38,                     /* T_NUM  */
  YYSYMBOL_T_BOOL = 39,                    /* T_BOOL  */
  YYSYMBOL_T_EQ = 40,                      /* T_EQ  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Start = 42,                     /* Start  */
  YYSYMBOL_classes = 43,                   /* classes  */
  YYSYMBOL_class_ = 44,                    /* class_  */
  YYSYMBOL_class = 45,                     /* class  */
  YYSYMBOL_superclass = 46,                /* superclass  */
  YYSYMBOL_members = 47,                   /* members  */
  YYSYMBOL_methods = 48,                   /* methods  */
  YYSYMBOL_method_decl = 49,               /* method_decl  */
  YYSYMBOL_body = 50,                      /* body  */
  YYSYMBOL_declarations = 51,              /* declarations  */
  YYSYMBOL_declaration = 52,               /* declaration  */
  YYSYMBOL_names = 53,                     /* names  */
  YYSYMBOL_return_ = 54,                   /* return_  */
  YYSYMBOL_statements = 55,                /* statements  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_assignment = 57,                /* assignment  */
  YYSYMBOL_if_else = 58,                   /* if_else  */
  YYSYMBOL_while_ = 59,                    /* while_  */
  YYSYMBOL_do_while = 60,                  /* do_while  */
  YYSYMBOL_print = 61,                     /* print  */
  YYSYMBOL_name = 62,                      /* name  */
  YYSYMBOL_params = 63,                    /* params  */
  YYSYMBOL_params_ = 64,                   /* params_  */
  YYSYMBOL_param = 65,                     /* param  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_expression = 67,                /* expression  */
  YYSYMBOL_new = 68,                       /* new  */
  YYSYMBOL_method_call = 69,               /* method_call  */
  YYSYMBOL_arguments = 70,                 /* arguments  */
  YYSYMBOL_arguments_ = 71                 /* arguments_  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    80,    81,    84,    85,    88,    89,    90,
      91,    94,    95,    96,    97,   100,   101,   104,   105,   108,
     109,   114,   115,   116,   117,   118,   119,   120,   121,   124,
     125,   128,   131,   132,   134,   136,   137,   140,   141,   142,
     143,   144,   145,   149,   150,   153,   154,   156,   158,   161,
     164,   168,   169,   171,   172,   175,   178,   179,   180,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   205,
     206,   210,   211,   214,   215,   218,   219
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_PRINT", "T_RETURN",
  "T_IF", "T_ELSE", "T_WHILE", "T_NEW", "T_NONE", "T_EXTENDS", "T_DO",
  "T_ARROW", "T_DOT", "T_COMMA", "T_METHODNAME", "T_LBRACKET",
  "T_RBRACKET", "T_QMARK", "T_COLON", "T_SEMICOLON", "T_OR", "T_AND",
  "T_EQUALTO", "T_GT", "T_GTE", "T_ADD", "T_SUB", "T_DIV", "T_MUL",
  "T_UNARYMINUS", "T_NOT", "T_LPAREN", "T_RPAREN", "T_ID", "T_INT",
  "T_TRUE", "T_FALSE", "T_NUM", "T_BOOL", "T_EQ", "$accept", "Start",
  "classes", "class_", "class", "superclass", "members", "methods",
  "method_decl", "body", "declarations", "declaration", "names", "return_",
  "statements", "statement", "assignment", "if_else", "while_", "do_while",
  "print", "name", "params", "params_", "param", "type", "expression",
  "new", "method_call", "arguments", "arguments_", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,   -93,    38,    -9,   -93,    29,   -93,   -93,   -93,   -93,
     104,   106,    -9,   -93,   -93,   -93,   189,    33,   -93,    21,
      -9,    48,   -93,    54,    -9,   -93,   -93,    21,   142,    55,
     191,   -93,    57,   -93,    41,    68,   -93,    -9,   -93,   -93,
     201,    61,   -93,    88,   142,   -93,   -93,    72,   -93,    17,
     -93,   -93,    86,    93,   100,   100,   183,   183,   183,   183,
     116,    67,   100,   -93,   -93,    76,   -93,   117,   -93,   -93,
     122,   124,    -5,    -9,   127,   105,    -9,   183,   183,   183,
     -93,   -93,   -93,    26,   297,   -93,   -93,   273,   247,   261,
     198,   -93,   -93,   -93,    76,   -93,   -93,    -5,   -93,   -93,
     -93,    -9,   183,   183,   107,   -93,   -93,   -93,   118,   -93,
     -93,   220,    -9,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   -93,   198,   198,     2,   -93,   -22,   297,
     119,   153,   297,    -9,   -93,   183,   -93,   138,   285,   305,
     312,   102,   102,   102,   -14,   -14,   -93,   -93,   161,   182,
     166,   183,   183,   -93,   183,   -93,   141,   183,   174,   -93,
     150,   155,   297,   297,   -93,   297,   167,   183,   -93,   198,
     233,   193,   -93,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    50,     0,     2,     4,     0,     1,     3,     6,     5,
       0,     0,     0,    10,    57,    56,     0,     0,    18,    58,
       0,     0,     8,     0,     0,     9,    17,     0,    52,     0,
       0,     7,     0,    58,     0,    51,    54,     0,    16,    14,
       0,     0,    15,     0,     0,    55,    12,     0,    13,     0,
      53,    11,     0,     0,    28,    28,     0,     0,     0,     0,
       0,     0,    24,    30,    27,    26,    36,     0,    39,    40,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    72,    74,    49,    78,    75,     0,     0,     0,
       0,    20,    29,    23,    22,    25,    35,     0,    37,    41,
      42,     0,    84,     0,     0,    32,    38,    19,    79,    70,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,    21,     0,    86,
       0,    83,    43,     0,    31,    84,    71,    73,     0,    67,
      66,    65,    63,    64,    59,    60,    62,    61,     0,     0,
       0,    84,     0,    81,     0,    33,     0,     0,    45,    47,
       0,     0,    44,    85,    80,    69,     0,     0,    82,     0,
       0,     0,    48,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   -93,   187,   -93,   156,    30,    25,   147,
     -93,   149,   -93,   -61,   -56,   -63,   -93,   -93,   -93,   -93,
     -93,     0,   -93,   -93,   168,   135,    40,   -93,   -33,   -92,
     -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     7,     4,     9,    16,    17,    18,    61,
      62,    63,   104,    64,    65,    66,    67,    68,    69,    70,
      71,    83,    34,    35,    36,    73,   129,    85,    86,   130,
     131
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       5,    93,    96,    10,    95,    56,    94,    58,   101,    59,
     151,    19,    21,    60,   121,   122,    19,    27,   152,   150,
      29,    74,    74,    27,    32,     1,    52,   102,    33,    74,
      19,    96,    74,   127,   126,   103,     1,    45,     6,   112,
      19,    27,    26,   156,    33,    11,    23,    27,    26,    33,
      25,     1,    14,    28,    72,    72,    15,    74,   102,   161,
      41,    74,    72,    96,    30,    97,    26,     1,   148,   149,
      47,    31,    26,   105,    43,    38,   108,    42,    48,    56,
      57,    58,    44,    59,    91,    96,    96,    60,     1,    51,
      97,    74,    74,    74,    97,     1,    84,    87,    88,    89,
      49,   128,    54,    56,    57,    58,     1,    59,    96,    55,
       1,    60,   137,   171,    12,    74,    74,   109,   110,   111,
      11,   133,   107,    13,    97,    97,    97,   134,   119,   120,
     121,   122,    90,   155,     1,    14,    74,    98,    74,    15,
       1,    14,    99,   132,   100,    15,    20,   106,    97,    97,
     135,    24,   153,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,    37,    56,    20,    58,   154,    59,    97,
     151,    97,    60,   160,   164,    24,     1,    14,   158,    37,
     166,    15,   167,   169,    53,    56,    40,    58,   168,    59,
       8,    76,   162,    60,   163,     1,    56,   165,    58,   159,
      59,    56,    75,    58,    60,    59,    22,   170,    39,    60,
     173,    92,    50,    77,    78,    79,     1,     1,    46,    80,
      81,    82,     0,     1,    14,     1,    14,     1,    15,     0,
      15,     0,     1,     0,     0,     1,    14,     0,   113,     0,
      15,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   113,     0,   136,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   124,     0,   113,   172,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   125,     0,   113,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   113,     0,   123,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   113,   157,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   113,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   115,   116,   117,
     118,   119,   120,   121,   122,   116,   117,   118,   119,   120,
     121,   122
};

static const yytype_int16 yycheck[] =
{
       0,    62,    65,     3,    65,     3,    62,     5,    13,     7,
      32,    11,    12,    11,    28,    29,    16,    17,    40,    17,
      20,    54,    55,    23,    24,    34,     9,    32,    28,    62,
      30,    94,    65,    94,    90,    40,    34,    37,     0,    13,
      40,    41,    17,   135,    44,    16,    16,    47,    23,    49,
      17,    34,    35,    32,    54,    55,    39,    90,    32,   151,
      30,    94,    62,   126,    16,    65,    41,    34,   124,   125,
      40,    17,    47,    73,    33,    20,    76,    20,    17,     3,
       4,     5,    14,     7,    17,   148,   149,    11,    34,    17,
      90,   124,   125,   126,    94,    34,    56,    57,    58,    59,
      12,   101,    16,     3,     4,     5,    34,     7,   171,    16,
      34,    11,   112,   169,    10,   148,   149,    77,    78,    79,
      16,    14,    17,    17,   124,   125,   126,    20,    26,    27,
      28,    29,    16,   133,    34,    35,   169,    20,   171,    39,
      34,    35,    20,   103,    20,    39,    11,    20,   148,   149,
      32,    16,    33,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    28,     3,    30,     5,    14,     7,   169,
      32,   171,    11,     7,    33,    40,    34,    35,    17,    44,
       6,    39,    32,    16,    49,     3,    30,     5,    33,     7,
       3,     8,   152,    11,   154,    34,     3,   157,     5,    17,
       7,     3,    55,     5,    11,     7,    17,   167,    17,    11,
      17,    62,    44,    30,    31,    32,    34,    34,    17,    36,
      37,    38,    -1,    34,    35,    34,    35,    34,    39,    -1,
      39,    -1,    34,    -1,    -1,    34,    35,    -1,    18,    -1,
      39,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    18,    -1,    33,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    16,    -1,    18,    33,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    16,    -1,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    22,    23,    24,
      25,    26,    27,    28,    29,    23,    24,    25,    26,    27,
      28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    42,    43,    45,    62,     0,    44,    45,    46,
      62,    16,    10,    17,    35,    39,    47,    48,    49,    62,
      66,    62,    17,    48,    66,    17,    49,    62,    32,    62,
      16,    17,    62,    62,    63,    64,    65,    66,    20,    17,
      47,    48,    20,    33,    14,    62,    17,    48,    17,    12,
      65,    17,     9,    66,    16,    16,     3,     4,     5,     7,
      11,    50,    51,    52,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    66,    69,    50,     8,    30,    31,    32,
      36,    37,    38,    62,    67,    68,    69,    67,    67,    67,
      16,    17,    52,    54,    55,    54,    56,    62,    20,    20,
      20,    13,    32,    40,    53,    62,    20,    17,    62,    67,
      67,    67,    13,    18,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    20,    16,    16,    55,    54,    62,    67,
      70,    71,    67,    14,    20,    32,    33,    62,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    55,    55,
      17,    32,    40,    33,    14,    62,    70,    19,    17,    17,
       7,    70,    67,    67,    33,    67,     6,    32,    33,    16,
      67,    55,    33,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    45,    45,
      45,    46,    46,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    50,    50,    50,    50,    50,    51,
      51,    52,    53,    53,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    58,    59,    60,    61,
      62,    63,    63,    64,    64,    65,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     5,     4,     4,
       3,     7,     6,     6,     5,     4,     3,     2,     1,     9,
       9,     3,     2,     2,     1,     2,     1,     1,     0,     2,
       1,     3,     1,     3,     3,     2,     1,     2,     2,     1,
       1,     2,     2,     3,     5,     5,     9,     5,     8,     2,
       1,     1,     0,     3,     1,     2,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     5,
       2,     3,     1,     3,     1,     1,     1,     1,     1,     2,
       5,     4,     6,     1,     0,     3,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* Start: classes  */
#line 76 "parser.y"
                  {astRoot = new ProgramNode((yyvsp[0].class_list_ptr));}
#line 1563 "parser.cpp"
    break;

  case 3: /* classes: classes class_  */
#line 80 "parser.y"
                         {(yyval.class_list_ptr) = (yyvsp[-1].class_list_ptr); (yyval.class_list_ptr)->push_back((yyvsp[0].class_ptr));}
#line 1569 "parser.cpp"
    break;

  case 4: /* classes: class  */
#line 81 "parser.y"
               {(yyval.class_list_ptr) = new std::list<ClassNode*>(); (yyval.class_list_ptr)->push_back((yyvsp[0].class_ptr));}
#line 1575 "parser.cpp"
    break;

  case 5: /* class_: superclass  */
#line 84 "parser.y"
                     {(yyval.class_ptr) = (yyvsp[0].class_ptr);}
#line 1581 "parser.cpp"
    break;

  case 6: /* class_: class  */
#line 85 "parser.y"
                {(yyval.class_ptr) = (yyvsp[0].class_ptr);}
#line 1587 "parser.cpp"
    break;

  case 7: /* class: name T_LBRACKET members methods T_RBRACKET  */
#line 88 "parser.y"
                                                      {(yyval.class_ptr) = new ClassNode((yyvsp[-4].identifier_ptr),NULL,(yyvsp[-2].declaration_list_ptr),(yyvsp[-1].method_list_ptr));}
#line 1593 "parser.cpp"
    break;

  case 8: /* class: name T_LBRACKET members T_RBRACKET  */
#line 89 "parser.y"
                                                      {(yyval.class_ptr) = new ClassNode((yyvsp[-3].identifier_ptr),NULL,(yyvsp[-1].declaration_list_ptr),NULL);}
#line 1599 "parser.cpp"
    break;

  case 9: /* class: name T_LBRACKET methods T_RBRACKET  */
#line 90 "parser.y"
                                                      {(yyval.class_ptr) = new ClassNode((yyvsp[-3].identifier_ptr),NULL,NULL,(yyvsp[-1].method_list_ptr));}
#line 1605 "parser.cpp"
    break;

  case 10: /* class: name T_LBRACKET T_RBRACKET  */
#line 91 "parser.y"
                                                      {(yyval.class_ptr) = new ClassNode((yyvsp[-2].identifier_ptr),NULL,NULL,NULL);}
#line 1611 "parser.cpp"
    break;

  case 11: /* superclass: name T_EXTENDS name T_LBRACKET members methods T_RBRACKET  */
#line 94 "parser.y"
                                                                        {(yyval.class_ptr) = new ClassNode((yyvsp[-6].identifier_ptr),(yyvsp[-4].identifier_ptr),(yyvsp[-2].declaration_list_ptr),(yyvsp[-1].method_list_ptr));}
#line 1617 "parser.cpp"
    break;

  case 12: /* superclass: name T_EXTENDS name T_LBRACKET members T_RBRACKET  */
#line 95 "parser.y"
                                                                        {(yyval.class_ptr) = new ClassNode((yyvsp[-5].identifier_ptr),(yyvsp[-3].identifier_ptr),(yyvsp[-1].declaration_list_ptr),NULL);}
#line 1623 "parser.cpp"
    break;

  case 13: /* superclass: name T_EXTENDS name T_LBRACKET methods T_RBRACKET  */
#line 96 "parser.y"
                                                                        {(yyval.class_ptr) = new ClassNode((yyvsp[-5].identifier_ptr),(yyvsp[-3].identifier_ptr),NULL,(yyvsp[-1].method_list_ptr));}
#line 1629 "parser.cpp"
    break;

  case 14: /* superclass: name T_EXTENDS name T_LBRACKET T_RBRACKET  */
#line 97 "parser.y"
                                                                        {(yyval.class_ptr) = new ClassNode((yyvsp[-4].identifier_ptr),(yyvsp[-2].identifier_ptr),NULL,NULL);}
#line 1635 "parser.cpp"
    break;

  case 15: /* members: members type name T_SEMICOLON  */
#line 100 "parser.y"
                                         {(yyval.declaration_list_ptr) = (yyvsp[-3].declaration_list_ptr); std::list<IdentifierNode*> *n = new std::list<IdentifierNode*>(); n->push_back((yyvsp[-1].identifier_ptr)); DeclarationNode *d = new DeclarationNode((yyvsp[-2].type_ptr),n); (yyval.declaration_list_ptr)->push_back(d);}
#line 1641 "parser.cpp"
    break;

  case 16: /* members: type name T_SEMICOLON  */
#line 101 "parser.y"
                              {(yyval.declaration_list_ptr) = new std::list<DeclarationNode*>();std::list<IdentifierNode*> *n = new std::list<IdentifierNode*>(); n->push_back((yyvsp[-1].identifier_ptr)); DeclarationNode *d = new DeclarationNode((yyvsp[-2].type_ptr),n); (yyval.declaration_list_ptr)->push_back(d);}
#line 1647 "parser.cpp"
    break;

  case 17: /* methods: methods method_decl  */
#line 104 "parser.y"
                               {(yyval.method_list_ptr) = (yyvsp[-1].method_list_ptr); (yyval.method_list_ptr)->push_back((yyvsp[0].method_ptr));}
#line 1653 "parser.cpp"
    break;

  case 18: /* methods: method_decl  */
#line 105 "parser.y"
                    {(yyval.method_list_ptr) = new std::list<MethodNode*>(); (yyval.method_list_ptr)->push_back((yyvsp[0].method_ptr));}
#line 1659 "parser.cpp"
    break;

  case 19: /* method_decl: name T_LPAREN params T_RPAREN T_ARROW type T_LBRACKET body T_RBRACKET  */
#line 108 "parser.y"
                                                                                       {(yyval.method_ptr) = new MethodNode((yyvsp[-8].identifier_ptr),(yyvsp[-6].parameter_list_ptr),(yyvsp[-3].type_ptr),(yyvsp[-1].methodbody_ptr));}
#line 1665 "parser.cpp"
    break;

  case 20: /* method_decl: name T_LPAREN params T_RPAREN T_ARROW T_NONE T_LBRACKET body T_RBRACKET  */
#line 109 "parser.y"
                                                                                      {NoneNode* n = new NoneNode(); n->basetype = bt_none; (yyval.method_ptr) = new MethodNode((yyvsp[-8].identifier_ptr),(yyvsp[-6].parameter_list_ptr),n,(yyvsp[-1].methodbody_ptr));}
#line 1671 "parser.cpp"
    break;

  case 21: /* body: declarations statements return_  */
#line 114 "parser.y"
                                        {(yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[-2].declaration_list_ptr),(yyvsp[-1].statement_list_ptr),(yyvsp[0].returnstatement_ptr));}
#line 1677 "parser.cpp"
    break;

  case 22: /* body: declarations statements  */
#line 115 "parser.y"
                                        {(yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[-1].declaration_list_ptr),(yyvsp[0].statement_list_ptr),NULL);}
#line 1683 "parser.cpp"
    break;

  case 23: /* body: declarations return_  */
#line 116 "parser.y"
                                        {(yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[-1].declaration_list_ptr),NULL,(yyvsp[0].returnstatement_ptr));}
#line 1689 "parser.cpp"
    break;

  case 24: /* body: declarations  */
#line 117 "parser.y"
                                        {(yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[0].declaration_list_ptr),NULL,NULL);}
#line 1695 "parser.cpp"
    break;

  case 25: /* body: statements return_  */
#line 118 "parser.y"
                                        {(yyval.methodbody_ptr) = new MethodBodyNode(NULL,(yyvsp[-1].statement_list_ptr),(yyvsp[0].returnstatement_ptr));}
#line 1701 "parser.cpp"
    break;

  case 26: /* body: statements  */
#line 119 "parser.y"
                                        {(yyval.methodbody_ptr) = new MethodBodyNode(NULL,(yyvsp[0].statement_list_ptr),NULL);}
#line 1707 "parser.cpp"
    break;

  case 27: /* body: return_  */
#line 120 "parser.y"
                                        {(yyval.methodbody_ptr) = new MethodBodyNode(NULL,NULL,(yyvsp[0].returnstatement_ptr));}
#line 1713 "parser.cpp"
    break;

  case 28: /* body: %empty  */
#line 121 "parser.y"
                                        {(yyval.methodbody_ptr) = new MethodBodyNode(NULL,NULL,NULL);}
#line 1719 "parser.cpp"
    break;

  case 29: /* declarations: declarations declaration  */
#line 124 "parser.y"
                                          {(yyval.declaration_list_ptr) = (yyvsp[-1].declaration_list_ptr); (yyval.declaration_list_ptr)->push_back((yyvsp[0].declaration_ptr));}
#line 1725 "parser.cpp"
    break;

  case 30: /* declarations: declaration  */
#line 125 "parser.y"
                          {(yyval.declaration_list_ptr) = new std::list<DeclarationNode*>(); (yyval.declaration_list_ptr)->push_back((yyvsp[0].declaration_ptr));}
#line 1731 "parser.cpp"
    break;

  case 31: /* declaration: type names T_SEMICOLON  */
#line 128 "parser.y"
                                        {(yyval.declaration_ptr) = new DeclarationNode((yyvsp[-2].type_ptr), (yyvsp[-1].identifier_list_ptr));}
#line 1737 "parser.cpp"
    break;

  case 32: /* names: name  */
#line 131 "parser.y"
                {(yyval.identifier_list_ptr) = new std::list<IdentifierNode*>(); (yyval.identifier_list_ptr)->push_back((yyvsp[0].identifier_ptr));}
#line 1743 "parser.cpp"
    break;

  case 33: /* names: names T_COMMA name  */
#line 132 "parser.y"
                             {(yyval.identifier_list_ptr) = (yyvsp[-2].identifier_list_ptr); (yyval.identifier_list_ptr)->push_back((yyvsp[0].identifier_ptr));}
#line 1749 "parser.cpp"
    break;

  case 34: /* return_: T_RETURN expression T_SEMICOLON  */
#line 134 "parser.y"
                                          {(yyval.returnstatement_ptr) = new ReturnStatementNode((yyvsp[-1].expression_ptr));}
#line 1755 "parser.cpp"
    break;

  case 35: /* statements: statements statement  */
#line 136 "parser.y"
                                   {(yyval.statement_list_ptr) = (yyvsp[-1].statement_list_ptr); (yyval.statement_list_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1761 "parser.cpp"
    break;

  case 36: /* statements: statement  */
#line 137 "parser.y"
                   {(yyval.statement_list_ptr) = new std::list<StatementNode*>(); (yyval.statement_list_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1767 "parser.cpp"
    break;

  case 37: /* statement: assignment T_SEMICOLON  */
#line 140 "parser.y"
                                   {(yyval.statement_ptr) = (yyvsp[-1].assignment_ptr);}
#line 1773 "parser.cpp"
    break;

  case 38: /* statement: method_call T_SEMICOLON  */
#line 141 "parser.y"
                                  {(yyval.statement_ptr) = new CallNode((yyvsp[-1].methodcall_ptr));}
#line 1779 "parser.cpp"
    break;

  case 39: /* statement: if_else  */
#line 142 "parser.y"
                   {(yyval.statement_ptr) = (yyvsp[0].ifelse_ptr);}
#line 1785 "parser.cpp"
    break;

  case 40: /* statement: while_  */
#line 143 "parser.y"
                  {(yyval.statement_ptr) = (yyvsp[0].while_ptr);}
#line 1791 "parser.cpp"
    break;

  case 41: /* statement: do_while T_SEMICOLON  */
#line 144 "parser.y"
                             {(yyval.statement_ptr) = (yyvsp[-1].dowhile_ptr);}
#line 1797 "parser.cpp"
    break;

  case 42: /* statement: print T_SEMICOLON  */
#line 145 "parser.y"
                              {(yyval.statement_ptr) = (yyvsp[-1].print_ptr);}
#line 1803 "parser.cpp"
    break;

  case 43: /* assignment: name T_EQ expression  */
#line 149 "parser.y"
                                    {(yyval.assignment_ptr) = new AssignmentNode((yyvsp[-2].identifier_ptr),NULL,(yyvsp[0].expression_ptr));}
#line 1809 "parser.cpp"
    break;

  case 44: /* assignment: name T_DOT name T_EQ expression  */
#line 150 "parser.y"
                                                {(yyval.assignment_ptr) = new AssignmentNode((yyvsp[-4].identifier_ptr),(yyvsp[-2].identifier_ptr),(yyvsp[0].expression_ptr));}
#line 1815 "parser.cpp"
    break;

  case 45: /* if_else: T_IF expression T_LBRACKET statements T_RBRACKET  */
#line 153 "parser.y"
                                                             {(yyval.ifelse_ptr) = new IfElseNode((yyvsp[-3].expression_ptr), (yyvsp[-1].statement_list_ptr), NULL);}
#line 1821 "parser.cpp"
    break;

  case 46: /* if_else: T_IF expression T_LBRACKET statements T_RBRACKET T_ELSE T_LBRACKET statements T_RBRACKET  */
#line 154 "parser.y"
                                                                                                   {(yyval.ifelse_ptr) = new IfElseNode((yyvsp[-7].expression_ptr),(yyvsp[-5].statement_list_ptr),(yyvsp[-1].statement_list_ptr));}
#line 1827 "parser.cpp"
    break;

  case 47: /* while_: T_WHILE expression T_LBRACKET statements T_RBRACKET  */
#line 156 "parser.y"
                                                               {(yyval.while_ptr) = new WhileNode((yyvsp[-3].expression_ptr),(yyvsp[-1].statement_list_ptr));}
#line 1833 "parser.cpp"
    break;

  case 48: /* do_while: T_DO T_LBRACKET statements T_RBRACKET T_WHILE T_LPAREN expression T_RPAREN  */
#line 158 "parser.y"
                                                                                       {(yyval.dowhile_ptr) = new DoWhileNode((yyvsp[-5].statement_list_ptr),(yyvsp[-1].expression_ptr));}
#line 1839 "parser.cpp"
    break;

  case 49: /* print: T_PRINT expression  */
#line 161 "parser.y"
                            {(yyval.print_ptr) = new PrintNode((yyvsp[0].expression_ptr));}
#line 1845 "parser.cpp"
    break;

  case 50: /* name: T_ID  */
#line 164 "parser.y"
            {(yyval.identifier_ptr) = new IdentifierNode((yyvsp[0].base_char_ptr));}
#line 1851 "parser.cpp"
    break;

  case 51: /* params: params_  */
#line 168 "parser.y"
                    {(yyval.parameter_list_ptr) = (yyvsp[0].parameter_list_ptr);}
#line 1857 "parser.cpp"
    break;

  case 52: /* params: %empty  */
#line 169 "parser.y"
               {(yyval.parameter_list_ptr) = new std::list<ParameterNode*>();}
#line 1863 "parser.cpp"
    break;

  case 53: /* params_: params_ T_COMMA param  */
#line 171 "parser.y"
                                  {(yyval.parameter_list_ptr) = (yyvsp[-2].parameter_list_ptr); (yyval.parameter_list_ptr)->push_back((yyvsp[0].parameter_ptr));}
#line 1869 "parser.cpp"
    break;

  case 54: /* params_: param  */
#line 172 "parser.y"
                {(yyval.parameter_list_ptr) = new std::list<ParameterNode*>(); (yyval.parameter_list_ptr)->push_back((yyvsp[0].parameter_ptr));}
#line 1875 "parser.cpp"
    break;

  case 55: /* param: type name  */
#line 175 "parser.y"
                  {(yyval.parameter_ptr) = new ParameterNode((yyvsp[-1].type_ptr),(yyvsp[0].identifier_ptr));}
#line 1881 "parser.cpp"
    break;

  case 56: /* type: T_BOOL  */
#line 178 "parser.y"
              {(yyval.type_ptr) = new BooleanTypeNode(); (yyval.type_ptr)->basetype = bt_boolean;}
#line 1887 "parser.cpp"
    break;

  case 57: /* type: T_INT  */
#line 179 "parser.y"
              {(yyval.type_ptr) = new IntegerTypeNode(); (yyval.type_ptr)->basetype = bt_integer;}
#line 1893 "parser.cpp"
    break;

  case 58: /* type: name  */
#line 180 "parser.y"
              {(yyval.type_ptr) = new ObjectTypeNode((yyvsp[0].identifier_ptr)); (yyval.type_ptr)->basetype = bt_object; (yyval.type_ptr)->objectClassName = (yyvsp[0].identifier_ptr)->name;}
#line 1899 "parser.cpp"
    break;

  case 59: /* expression: expression T_ADD expression  */
#line 183 "parser.y"
                                         {(yyval.expression_ptr) = new PlusNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1905 "parser.cpp"
    break;

  case 60: /* expression: expression T_SUB expression  */
#line 184 "parser.y"
                                          {(yyval.expression_ptr) = new MinusNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1911 "parser.cpp"
    break;

  case 61: /* expression: expression T_MUL expression  */
#line 185 "parser.y"
                                          {(yyval.expression_ptr) = new TimesNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1917 "parser.cpp"
    break;

  case 62: /* expression: expression T_DIV expression  */
#line 186 "parser.y"
                                          {(yyval.expression_ptr) = new DivideNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1923 "parser.cpp"
    break;

  case 63: /* expression: expression T_GT expression  */
#line 187 "parser.y"
                                         {(yyval.expression_ptr) = new GreaterNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1929 "parser.cpp"
    break;

  case 64: /* expression: expression T_GTE expression  */
#line 188 "parser.y"
                                          {(yyval.expression_ptr) = new GreaterEqualNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1935 "parser.cpp"
    break;

  case 65: /* expression: expression T_EQUALTO expression  */
#line 189 "parser.y"
                                              {(yyval.expression_ptr) = new EqualNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1941 "parser.cpp"
    break;

  case 66: /* expression: expression T_AND expression  */
#line 190 "parser.y"
                                          {(yyval.expression_ptr) = new AndNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1947 "parser.cpp"
    break;

  case 67: /* expression: expression T_OR expression  */
#line 191 "parser.y"
                                         {(yyval.expression_ptr) = new OrNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1953 "parser.cpp"
    break;

  case 68: /* expression: T_NOT expression  */
#line 192 "parser.y"
                               {(yyval.expression_ptr) = new NotNode((yyvsp[0].expression_ptr));}
#line 1959 "parser.cpp"
    break;

  case 69: /* expression: expression T_QMARK expression T_COLON expression  */
#line 193 "parser.y"
                                                               {(yyval.expression_ptr) = new QMNode((yyvsp[-4].expression_ptr),(yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1965 "parser.cpp"
    break;

  case 70: /* expression: T_UNARYMINUS expression  */
#line 194 "parser.y"
                                      {(yyval.expression_ptr) = new NegationNode((yyvsp[0].expression_ptr));}
#line 1971 "parser.cpp"
    break;

  case 71: /* expression: T_LPAREN expression T_RPAREN  */
#line 195 "parser.y"
                                           {(yyval.expression_ptr) = (yyvsp[-1].expression_ptr);}
#line 1977 "parser.cpp"
    break;

  case 72: /* expression: T_NUM  */
#line 196 "parser.y"
                    {(yyval.expression_ptr) = new IntegerLiteralNode(new IntegerNode((yyvsp[0].base_int)));}
#line 1983 "parser.cpp"
    break;

  case 73: /* expression: name T_DOT name  */
#line 197 "parser.y"
                              {(yyval.expression_ptr) = new MemberAccessNode((yyvsp[-2].identifier_ptr),(yyvsp[0].identifier_ptr));}
#line 1989 "parser.cpp"
    break;

  case 74: /* expression: name  */
#line 198 "parser.y"
                   {(yyval.expression_ptr) = new VariableNode((yyvsp[0].identifier_ptr));}
#line 1995 "parser.cpp"
    break;

  case 75: /* expression: method_call  */
#line 199 "parser.y"
                          {(yyval.expression_ptr) = (yyvsp[0].methodcall_ptr);}
#line 2001 "parser.cpp"
    break;

  case 76: /* expression: T_TRUE  */
#line 200 "parser.y"
                     {(yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(1));}
#line 2007 "parser.cpp"
    break;

  case 77: /* expression: T_FALSE  */
#line 201 "parser.y"
                       {(yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(0));}
#line 2013 "parser.cpp"
    break;

  case 78: /* expression: new  */
#line 202 "parser.y"
                  {(yyval.expression_ptr) = (yyvsp[0].new_ptr);}
#line 2019 "parser.cpp"
    break;

  case 79: /* new: T_NEW name  */
#line 205 "parser.y"
                 {(yyval.new_ptr) = new NewNode((yyvsp[0].identifier_ptr), new std::list<ExpressionNode*>());}
#line 2025 "parser.cpp"
    break;

  case 80: /* new: T_NEW name T_LPAREN arguments T_RPAREN  */
#line 206 "parser.y"
                                             {(yyval.new_ptr) = new NewNode((yyvsp[-3].identifier_ptr), (yyvsp[-1].expression_list_ptr));}
#line 2031 "parser.cpp"
    break;

  case 81: /* method_call: name T_LPAREN arguments T_RPAREN  */
#line 210 "parser.y"
                                               {(yyval.methodcall_ptr) = new MethodCallNode((yyvsp[-3].identifier_ptr),NULL,(yyvsp[-1].expression_list_ptr));}
#line 2037 "parser.cpp"
    break;

  case 82: /* method_call: name T_DOT name T_LPAREN arguments T_RPAREN  */
#line 211 "parser.y"
                                                          {(yyval.methodcall_ptr) = new MethodCallNode((yyvsp[-5].identifier_ptr), (yyvsp[-3].identifier_ptr),(yyvsp[-1].expression_list_ptr));}
#line 2043 "parser.cpp"
    break;

  case 83: /* arguments: arguments_  */
#line 214 "parser.y"
                       {(yyval.expression_list_ptr) = (yyvsp[0].expression_list_ptr);}
#line 2049 "parser.cpp"
    break;

  case 84: /* arguments: %empty  */
#line 215 "parser.y"
                    {(yyval.expression_list_ptr) = new std::list<ExpressionNode*>();}
#line 2055 "parser.cpp"
    break;

  case 85: /* arguments_: arguments_ T_COMMA expression  */
#line 218 "parser.y"
                                           {(yyval.expression_list_ptr) = (yyvsp[-2].expression_list_ptr); (yyval.expression_list_ptr)->push_back((yyvsp[0].expression_ptr));}
#line 2061 "parser.cpp"
    break;

  case 86: /* arguments_: expression  */
#line 219 "parser.y"
                        {(yyval.expression_list_ptr) = new std::list<ExpressionNode*>(); (yyval.expression_list_ptr)->push_back((yyvsp[0].expression_ptr));}
#line 2067 "parser.cpp"
    break;


#line 2071 "parser.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 223 "parser.y"


extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}
