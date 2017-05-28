/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     BOOL = 259,
     CHAR = 260,
     FLOAT = 261,
     INT = 262,
     DOUBLE = 263,
     VOID = 264,
     CONSTANT_FLOAT = 265,
     CONSTANT_STRING = 266,
     CONSTANT_INTEGER = 267,
     CONSTANT_CHARACTER = 268,
     OP_RS = 269,
     OP_LS = 270,
     OP_OR = 271,
     OP_EQ = 272,
     OP_AND = 273,
     OP_NE = 274,
     OP_GE = 275,
     OP_LE = 276,
     OP_PTR = 277,
     OP_INCRE = 278,
     OP_DECRE = 279,
     ASSIGN_ADD = 280,
     ASSIGN_SUB = 281,
     ASSIGN_RS = 282,
     ASSIGN_MUL = 283,
     ASSIGN_LS = 284,
     ASSIGN_DIV = 285,
     ASSIGN_OR = 286,
     ASSIGN_XOR = 287,
     ASSIGN_AND = 288,
     ASSIGN_MOD = 289,
     CONST = 290,
     IF = 291,
     ELSE = 292,
     FOR = 293,
     BREAK = 294,
     CONTINUE = 295,
     STRUCT = 296,
     WHILE = 297,
     COMMENT = 298,
     RETURN = 299,
     NEG = 300,
     POS = 301,
     PREFIX_DECRE = 302,
     PREFIX_INCRE = 303,
     GET_VALUE = 304,
     GET_ADDRESS = 305,
     INV = 306,
     BIT_NEG = 307,
     IFX = 308
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define BOOL 259
#define CHAR 260
#define FLOAT 261
#define INT 262
#define DOUBLE 263
#define VOID 264
#define CONSTANT_FLOAT 265
#define CONSTANT_STRING 266
#define CONSTANT_INTEGER 267
#define CONSTANT_CHARACTER 268
#define OP_RS 269
#define OP_LS 270
#define OP_OR 271
#define OP_EQ 272
#define OP_AND 273
#define OP_NE 274
#define OP_GE 275
#define OP_LE 276
#define OP_PTR 277
#define OP_INCRE 278
#define OP_DECRE 279
#define ASSIGN_ADD 280
#define ASSIGN_SUB 281
#define ASSIGN_RS 282
#define ASSIGN_MUL 283
#define ASSIGN_LS 284
#define ASSIGN_DIV 285
#define ASSIGN_OR 286
#define ASSIGN_XOR 287
#define ASSIGN_AND 288
#define ASSIGN_MOD 289
#define CONST 290
#define IF 291
#define ELSE 292
#define FOR 293
#define BREAK 294
#define CONTINUE 295
#define STRUCT 296
#define WHILE 297
#define COMMENT 298
#define RETURN 299
#define NEG 300
#define POS 301
#define PREFIX_DECRE 302
#define PREFIX_INCRE 303
#define GET_VALUE 304
#define GET_ADDRESS 305
#define INV 306
#define BIT_NEG 307
#define IFX 308




/* Copy the first part of user declarations.  */
#line 1 "Parsing.y"

#include <stdlib.h>
#include "absyn.h"
int yylex();
void yyerror(char *s);
extern int col;
extern int row;
var_table global_table;
var_table temp_table;
var_table parent_table;
statement temp_stmt = NULL;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "Parsing.y"
{
	int const_int;
	float const_float;
	char const_char;
  char *const_str;
	char *id;
	struct { v_type tp; int order; } t;
	expression exp;
	v_type tp;
	variable var;
	parameter p;
	OP op;
	statement stmt;
}
/* Line 193 of yacc.c.  */
#line 230 "parsing.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 243 "parsing.h"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,     2,     2,    56,    49,     2,
      68,    69,    54,    52,    45,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
      50,    46,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    48,    72,    73,     2,     2,     2,
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
      57,    58,    59,    60,    61,    62,    63,    64,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    15,    22,    29,
      35,    42,    49,    55,    58,    60,    66,    71,    73,    75,
      77,    79,    81,    83,    85,    87,    90,    93,    95,    99,
     102,   106,   108,   110,   112,   115,   118,   120,   123,   129,
     137,   145,   153,   159,   167,   173,   179,   185,   191,   197,
     203,   209,   212,   216,   218,   220,   223,   227,   230,   232,
     234,   236,   238,   240,   243,   246,   249,   254,   256,   258,
     260,   262,   264,   266,   268,   272,   277,   279,   281,   283,
     285,   287,   291,   295,   299,   303,   307,   311,   315,   319,
     323,   327,   331,   334,   337,   340,   343,   346,   349,   352,
     355,   358,   361,   365,   369,   373,   377,   381,   385,   389,
     393,   397,   401,   405,   409,   413,   417,   421,   425,   429,
     433
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    77,    -1,    78,    -1,    77,    78,    -1,
      96,    -1,    77,    96,    -1,    81,     3,    68,    84,    69,
      70,    -1,    81,     3,    68,     9,    69,    70,    -1,    81,
       3,    68,    69,    70,    -1,    81,     3,    68,    84,    69,
      85,    -1,    81,     3,    68,     9,    69,    85,    -1,    81,
       3,    68,    69,    85,    -1,    81,     3,    -1,    80,    -1,
      81,     3,    65,    12,    66,    -1,    80,    65,    12,    66,
      -1,    82,    -1,    83,    -1,     4,    -1,     5,    -1,     7,
      -1,     6,    -1,     8,    -1,     9,    -1,    82,    54,    -1,
      83,    54,    -1,    79,    -1,    84,    45,    79,    -1,    86,
      87,    -1,    86,    88,    87,    -1,    71,    -1,    72,    -1,
      95,    -1,    88,    70,    -1,    88,    95,    -1,    85,    -1,
      88,    85,    -1,    36,    68,    97,    69,    95,    -1,    36,
      68,    97,    69,    95,    37,    95,    -1,    36,    68,    97,
      69,    85,    37,    95,    -1,    36,    68,    97,    69,    95,
      37,    85,    -1,    36,    68,    97,    69,    85,    -1,    36,
      68,    97,    69,    85,    37,    85,    -1,    36,    68,    97,
      69,    70,    -1,    42,    68,    97,    69,    85,    -1,    42,
      68,    97,    69,    70,    -1,    42,    68,    97,    69,    95,
      -1,    38,    68,    92,    69,    85,    -1,    38,    68,    92,
      69,    70,    -1,    38,    68,    92,    69,    95,    -1,    93,
      93,    -1,    93,    93,    97,    -1,    95,    -1,    70,    -1,
      44,    70,    -1,    44,    97,    70,    -1,    97,    70,    -1,
      89,    -1,    96,    -1,    90,    -1,    91,    -1,    94,    -1,
      39,    70,    -1,    40,    70,    -1,    79,    70,    -1,    79,
      46,    97,    70,    -1,   100,    -1,    99,    -1,   101,    -1,
     103,    -1,   104,    -1,   102,    -1,    98,    -1,    68,    97,
      69,    -1,    97,    65,    97,    66,    -1,    10,    -1,    12,
      -1,    11,    -1,    13,    -1,     3,    -1,    97,    46,    97,
      -1,    97,    31,    97,    -1,    97,    33,    97,    -1,    97,
      32,    97,    -1,    97,    25,    97,    -1,    97,    26,    97,
      -1,    97,    28,    97,    -1,    97,    29,    97,    -1,    97,
      27,    97,    -1,    97,    34,    97,    -1,    97,    30,    97,
      -1,    73,    97,    -1,    74,    97,    -1,    49,    97,    -1,
      54,    97,    -1,    53,    97,    -1,    52,    97,    -1,    23,
      97,    -1,    24,    97,    -1,    97,    23,    -1,    97,    24,
      -1,    97,    52,    97,    -1,    97,    53,    97,    -1,    97,
      54,    97,    -1,    97,    55,    97,    -1,    97,    56,    97,
      -1,    97,    47,    97,    -1,    97,    49,    97,    -1,    97,
      48,    97,    -1,    97,    45,    97,    -1,    97,    50,    97,
      -1,    97,    51,    97,    -1,    97,    15,    97,    -1,    97,
      14,    97,    -1,    97,    18,    97,    -1,    97,    16,    97,
      -1,    97,    17,    97,    -1,    97,    20,    97,    -1,    97,
      21,    97,    -1,    97,    19,    97,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    66,    67,    68,    69,    72,    73,    74,
      75,    76,    77,    81,    93,    99,   122,   125,   126,   130,
     131,   132,   133,   134,   135,   139,   153,   157,   158,   162,
     163,   166,   173,   176,   177,   178,   179,   180,   183,   184,
     185,   186,   187,   188,   189,   192,   193,   194,   197,   198,
     199,   202,   203,   206,   207,   211,   212,   216,   217,   218,
     219,   220,   221,   222,   223,   227,   236,   249,   250,   251,
     252,   253,   254,   255,   256,   263,   266,   267,   268,   269,
     272,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   301,   302,   303,   304,   305,   306,   309,   310,
     311,   312,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "BOOL", "CHAR", "FLOAT",
  "INT", "DOUBLE", "VOID", "CONSTANT_FLOAT", "CONSTANT_STRING",
  "CONSTANT_INTEGER", "CONSTANT_CHARACTER", "OP_RS", "OP_LS", "OP_OR",
  "OP_EQ", "OP_AND", "OP_NE", "OP_GE", "OP_LE", "OP_PTR", "OP_INCRE",
  "OP_DECRE", "ASSIGN_ADD", "ASSIGN_SUB", "ASSIGN_RS", "ASSIGN_MUL",
  "ASSIGN_LS", "ASSIGN_DIV", "ASSIGN_OR", "ASSIGN_XOR", "ASSIGN_AND",
  "ASSIGN_MOD", "CONST", "IF", "ELSE", "FOR", "BREAK", "CONTINUE",
  "STRUCT", "WHILE", "COMMENT", "RETURN", "','", "'='", "'^'", "'|'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "NEG", "POS",
  "PREFIX_DECRE", "PREFIX_INCRE", "GET_VALUE", "GET_ADDRESS", "INV",
  "BIT_NEG", "'['", "']'", "IFX", "'('", "')'", "';'", "'{'", "'}'", "'~'",
  "'!'", "$accept", "CODE_TEXT", "PROGRAM", "FUNCTION", "DECLARATION",
  "DECLARATION_ARRAY", "TYPE", "SIMPLE_TYPE", "POINTER_TYPE", "PARAMETER",
  "COMPOUND_STATEMENT", "LPAREN", "RPAREN", "STATEMENT_LIST",
  "IF_STATEMENT", "WHILE_STATEMENT", "FOR_STATEMENT", "FOR_EXP",
  "FOR_EXP1", "RETURN_STATEMENT", "STATEMENT", "INITIALIZATION_STATEMENT",
  "EXPRESSION", "ARRAY_OPERATION", "CONSTANT_EXPRESSION",
  "IDENTIFIER_EXPRESSION", "ASSIGNMENT_EXPRESSION", "UNARY_OPERATION",
  "SELF_OPERATION", "BINARY_OPERATION", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    44,    61,    94,   124,    38,
      60,    62,    43,    45,    42,    47,    37,   300,   301,   302,
     303,   304,   305,   306,   307,    91,    93,   308,    40,    41,
      59,   123,   125,   126,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    77,    77,    78,    78,    78,
      78,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    87,    88,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    99,    99,    99,    99,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   103,   103,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     6,     6,     5,
       6,     6,     5,     2,     1,     5,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     3,     2,
       3,     1,     1,     1,     2,     2,     1,     2,     5,     7,
       7,     7,     5,     7,     5,     5,     5,     5,     5,     5,
       5,     2,     3,     1,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    20,    22,    21,    23,    24,     0,     2,     3,
       0,    14,     0,    17,    18,     5,     1,     4,     6,     0,
      65,     0,    13,    25,    26,    80,    76,    78,    77,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    68,    67,    69,    72,    70,    71,     0,     0,     0,
      98,    99,    94,    97,    96,    95,     0,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,    16,     0,    24,     0,    27,     0,     0,
      74,   114,   113,   116,   117,   115,   120,   118,   119,    85,
      86,    89,    87,    88,    91,    82,    84,    83,    90,   110,
      81,   107,   109,   108,   111,   112,   102,   103,   104,   105,
     106,     0,    15,     0,     9,    31,    12,     0,    13,     0,
       0,    75,     8,    11,     0,     0,     0,     0,     0,     0,
      32,    36,    29,     0,    58,    60,    61,    62,    33,    59,
       0,    28,     7,    10,     0,     0,    63,    64,     0,    55,
       0,    34,    37,    30,    35,    57,     0,    54,     0,     0,
      53,     0,    56,     0,     0,    51,     0,    44,    42,    38,
      49,    48,    50,    52,    46,    45,    47,     0,     0,    43,
      40,    41,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    98,    13,    14,    99,
     136,   137,   152,   153,   154,   155,   156,   178,   179,   157,
     180,   159,   160,    40,    41,    42,    43,    44,    45,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int16 yypact[] =
{
      24,   -62,   -62,   -62,   -62,   -62,   -62,     4,    24,   -62,
     -44,   -31,    46,    41,    45,   -62,   -62,   -62,   -62,   459,
     -62,    89,   -60,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   520,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,    34,    90,    16,
      63,    63,    63,    63,    63,    63,   691,    63,    63,   459,
     459,   459,   459,   459,   459,   459,   459,   -62,   -62,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   459,   459,   459,   459,   459,   459,   459,   459,
     459,   459,   -62,   -62,    37,    35,   -61,   -62,   102,   -42,
     -62,   -17,   -17,   976,  1105,   998,  1084,   450,   450,   955,
     955,   955,   955,   955,   955,   955,   955,   955,   955,   955,
     955,  1019,  1041,  1062,   450,   450,   109,   109,    63,    63,
      63,   859,   -62,    19,   -62,   -62,   -62,   147,    42,    24,
      27,   -62,   -62,   -62,    43,    47,    48,    50,    49,   124,
     -62,   -62,   -62,    70,   -62,   -62,   -62,   -62,   -62,   -62,
     577,   -62,   -62,   -62,   459,   355,   -62,   -62,   459,   -62,
     634,   -62,   -62,   -62,   -62,   -62,   747,   -62,    44,   355,
     -62,   803,   -62,   199,   251,   459,   303,   -62,    79,    92,
     -62,   -62,   -62,   912,   -62,   -62,   -62,   407,   407,   -62,
     -62,   -62,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   113,   -48,   -62,    84,   -62,   -62,   -62,
     301,   -62,   -28,   -62,   -62,   -62,   -62,   -62,   -53,   -62,
     269,    88,   -19,   -62,   -62,   -62,   -62,   -62,   -62,   -62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    97,    19,   139,    16,    48,    67,    68,    49,   134,
     135,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       1,     2,     3,     4,     5,    95,    20,   140,     1,     2,
       3,     4,     5,     6,    21,    86,    87,    88,    89,    90,
     101,   102,   103,   104,   105,   106,   107,   108,    91,    22,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,    25,     1,     2,     3,     4,     5,     6,
      26,    27,    28,    29,    12,    96,    67,    68,    15,   142,
     135,   161,    12,    30,    31,    23,    18,   162,   135,    24,
      93,    47,    94,   132,   133,   138,   144,    48,   145,   146,
     147,   164,   148,   184,   149,   165,   197,   168,   166,    32,
     167,    17,    33,    34,    35,   173,   185,    25,    91,   198,
     170,     0,    67,    68,    26,    27,    28,    29,    36,     0,
     171,   135,   150,    37,    38,   176,     0,    30,    31,   181,
      25,     1,     2,     3,     4,     5,     6,    26,    27,    28,
      29,     0,     0,    88,    89,    90,   193,     0,     0,     0,
      30,    31,     0,    32,    91,     0,    33,    34,    35,     0,
       0,     0,     0,   144,     0,   145,   146,   147,     0,   148,
       0,   149,    36,     0,   169,     0,    32,    37,    38,    33,
      34,    35,    25,     1,     2,     3,     4,     5,     6,    26,
      27,    28,    29,     0,     0,    36,     0,     0,   135,   150,
      37,    38,    30,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,     0,   145,   146,   147,
       0,   148,     0,   149,     0,     0,     0,     0,    32,     0,
       0,    33,    34,    35,    25,     1,     2,     3,     4,     5,
       6,    26,    27,    28,    29,     0,     0,    36,     0,   187,
     135,     0,    37,    38,    30,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,     0,   145,
     146,   147,     0,   148,     0,   149,     0,     0,     0,     0,
      32,     0,     0,    33,    34,    35,    25,     1,     2,     3,
       4,     5,     6,    26,    27,    28,    29,     0,     0,    36,
       0,   190,   135,     0,    37,    38,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   144,
       0,   145,   146,   147,     0,   148,     0,   149,     0,     0,
       0,     0,    32,     0,     0,    33,    34,    35,    25,     1,
       2,     3,     4,     5,     6,    26,    27,    28,    29,     0,
       0,    36,     0,   194,   135,     0,    37,    38,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,     0,   145,   146,   147,     0,   148,     0,   149,
       0,     0,     0,     0,    32,     0,   158,    33,    34,    35,
      25,     1,     2,     3,     4,     5,     6,    26,    27,    28,
      29,     0,   174,    36,     0,   177,     0,     0,    37,    38,
      30,    31,     0,     0,   143,     0,     0,     0,   151,     0,
       0,   163,     0,   144,     0,   145,   146,   147,     0,   148,
       0,   149,   189,   192,   172,   196,    32,     0,     0,    33,
      34,    35,    25,     0,    59,    60,   200,   202,     0,    26,
      27,    28,    29,    67,    68,    36,     0,     0,   135,     0,
      37,    38,    30,    31,   188,   191,     0,   195,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,   201,
       0,     0,    86,    87,    88,    89,    90,     0,    32,     0,
       0,    33,    34,    35,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     0,    37,    38,    59,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,     0,     0,     0,
      92,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,   175,    59,    60,
      61,    62,    63,    64,    65,    66,     0,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,   182,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,     0,
     100,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,   183,    59,    60,    61,
      62,    63,    64,    65,    66,     0,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,     0,     0,     0,     0,    91,     0,
       0,     0,   186,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
       0,     0,     0,     0,    91,   141,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    59,
      60,    61,    62,    63,    64,    65,    66,    91,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      59,    60,     0,    62,    63,    64,    65,    66,     0,    67,
      68,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    59,    60,     0,    62,     0,    64,    65,    66,
      91,    67,    68,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    59,    60,     0,    62,     0,    64,    65,
      66,    91,    67,    68,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    59,    60,     0,    62,     0,
      64,    65,    66,    91,    67,    68,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    59,    60,     0,    62,
       0,    64,    65,    66,    91,    67,    68,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    90,    59,    60,
       0,    62,     0,     0,    65,    66,    91,    67,    68,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,    59,
      60,     0,     0,     0,     0,    65,    66,    91,    67,    68,
       0,     0,     0,     0,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,    91,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,     0,     0,     0,
      91
};

static const yytype_int16 yycheck[] =
{
      19,    49,    46,    45,     0,    65,    23,    24,    68,    70,
      71,    30,    31,    32,    33,    34,    35,    36,    37,    38,
       4,     5,     6,     7,     8,     9,    70,    69,     4,     5,
       6,     7,     8,     9,    65,    52,    53,    54,    55,    56,
      59,    60,    61,    62,    63,    64,    65,    66,    65,     3,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,    69,    23,    24,     0,    70,
      71,   139,     8,    23,    24,    54,     8,    70,    71,    54,
      66,    12,    12,    66,    69,     3,    36,    65,    38,    39,
      40,    68,    42,    69,    44,    68,    37,    68,    70,    49,
      70,     8,    52,    53,    54,   153,   179,     3,    65,    37,
     149,    -1,    23,    24,    10,    11,    12,    13,    68,    -1,
      70,    71,    72,    73,    74,   164,    -1,    23,    24,   168,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    54,    55,    56,   185,    -1,    -1,    -1,
      23,    24,    -1,    49,    65,    -1,    52,    53,    54,    -1,
      -1,    -1,    -1,    36,    -1,    38,    39,    40,    -1,    42,
      -1,    44,    68,    -1,    70,    -1,    49,    73,    74,    52,
      53,    54,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    54,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    68,    -1,    70,
      71,    -1,    73,    74,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,    54,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    68,
      -1,    70,    71,    -1,    73,    74,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    52,    53,    54,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    68,    -1,    70,    71,    -1,    73,    74,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    -1,    44,
      -1,    -1,    -1,    -1,    49,    -1,   137,    52,    53,    54,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,   153,    68,    -1,    70,    -1,    -1,    73,    74,
      23,    24,    -1,    -1,   133,    -1,    -1,    -1,   137,    -1,
      -1,   140,    -1,    36,    -1,    38,    39,    40,    -1,    42,
      -1,    44,   183,   184,   153,   186,    49,    -1,    -1,    52,
      53,    54,     3,    -1,    14,    15,   197,   198,    -1,    10,
      11,    12,    13,    23,    24,    68,    -1,    -1,    71,    -1,
      73,    74,    23,    24,   183,   184,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,   198,
      -1,    -1,    52,    53,    54,    55,    56,    -1,    49,    -1,
      -1,    52,    53,    54,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    73,    74,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      70,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    70,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    70,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      69,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    69,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    69,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    14,
      15,    16,    17,    18,    19,    20,    21,    65,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      14,    15,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    14,    15,    -1,    17,    -1,    19,    20,    21,
      65,    23,    24,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    14,    15,    -1,    17,    -1,    19,    20,
      21,    65,    23,    24,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    14,    15,    -1,    17,    -1,
      19,    20,    21,    65,    23,    24,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    14,    15,    -1,    17,
      -1,    19,    20,    21,    65,    23,    24,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    14,    15,
      -1,    17,    -1,    -1,    20,    21,    65,    23,    24,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    14,
      15,    -1,    -1,    -1,    -1,    20,    21,    65,    23,    24,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    76,    77,    78,
      79,    80,    81,    82,    83,    96,     0,    78,    96,    46,
      70,    65,     3,    54,    54,     3,    10,    11,    12,    13,
      23,    24,    49,    52,    53,    54,    68,    73,    74,    97,
      98,    99,   100,   101,   102,   103,   104,    12,    65,    68,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    14,
      15,    16,    17,    18,    19,    20,    21,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    65,    70,    66,    12,     9,    69,    79,    81,    84,
      69,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    66,    69,    70,    71,    85,    86,     3,    45,
      69,    66,    70,    85,    36,    38,    39,    40,    42,    44,
      72,    85,    87,    88,    89,    90,    91,    94,    95,    96,
      97,    79,    70,    85,    68,    68,    70,    70,    68,    70,
      97,    70,    85,    87,    95,    70,    97,    70,    92,    93,
      95,    97,    70,    69,    69,    93,    69,    70,    85,    95,
      70,    85,    95,    97,    70,    85,    95,    37,    37,    85,
      95,    85,    95
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 63 "Parsing.y"
    {  ;}
    break;

  case 10:
#line 75 "Parsing.y"
    {  ;}
    break;

  case 11:
#line 76 "Parsing.y"
    {  ;}
    break;

  case 12:
#line 77 "Parsing.y"
    {  ;}
    break;

  case 13:
#line 81 "Parsing.y"
    {
															entry en = lookup_in_cur_environment(temp_table, (yyvsp[(2) - (2)].id));
															if(!en) {
																(yyval.var) = new_variable((yyvsp[(2) - (2)].id), (yyvsp[(1) - (2)].t).tp, NULL, 0);
																insert(temp_table, (yyval.var));
															}
															else {
																free((yyvsp[(2) - (2)].id));
																yyerror("变量重定义！");
																(yyval.var) = NULL;
															}
														;}
    break;

  case 14:
#line 93 "Parsing.y"
    { (yyval.var) = (yyvsp[(1) - (1)].var); ;}
    break;

  case 15:
#line 99 "Parsing.y"
    {
																														entry en = lookup_in_cur_environment(temp_table, (yyvsp[(2) - (5)].id));
																														v_type t;
																														if(!en) {
																															switch((yyvsp[(1) - (5)].t).tp) {
																																case TYPE_INT: t = TYPE_ARRAY_INT; break;
																																case TYPE_BOOL: t = TYPE_ARRAY_BOOL; break;
																																case TYPE_CHAR: t = TYPE_ARRAY_CHAR; break;
																																case TYPE_FLOAT: t = TYPE_ARRAY_FLOAT; break;
																																case TYPE_DOUBLE: t = TYPE_ARRAY_DOUBLE; break;
																																default: t = (yyvsp[(1) - (5)].t).tp; break;
																															}
																															(yyval.var) = new_variable((yyvsp[(2) - (5)].id), t, new_dimension((yyvsp[(4) - (5)].const_int)), (yyvsp[(1) - (5)].t).order);
																															(yyval.var)->order = 1;
																															insert(temp_table, (yyval.var));
																														}
																														else {
																															free((yyvsp[(2) - (5)].id));
																															yyerror("变量重定义！");
																															(yyval.var) = NULL;
																														}
																													;}
    break;

  case 16:
#line 122 "Parsing.y"
    { update_dimension((yyvsp[(1) - (4)].var)->dim, (yyvsp[(3) - (4)].const_int)); (yyval.var) = (yyvsp[(1) - (4)].var); (yyval.var)->order++; ;}
    break;

  case 17:
#line 125 "Parsing.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 18:
#line 126 "Parsing.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 19:
#line 130 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 20:
#line 131 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 21:
#line 132 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 22:
#line 133 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 23:
#line 134 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 24:
#line 135 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 25:
#line 139 "Parsing.y"
    {
															v_type t;
															switch((yyvsp[(1) - (2)].t).tp) {
																case TYPE_INT: t = TYPE_POINTER_INT; break;
																case TYPE_BOOL: t = TYPE_POINTER_BOOL; break;
																case TYPE_CHAR: t = TYPE_POINTER_CHAR; break;
																case TYPE_FLOAT: t = TYPE_POINTER_FLOAT; break;
																case TYPE_DOUBLE: t = TYPE_POINTER_DOUBLE; break;
																default: t = (yyvsp[(1) - (2)].t).tp; break;
															}
															(yyval.t) = (yyvsp[(1) - (2)].t);
															(yyval.t).tp = t;
															(yyval.t).order = 1;
														;}
    break;

  case 26:
#line 153 "Parsing.y"
    { (yyval.t) = (yyvsp[(1) - (2)].t); (yyval.t).order++; ;}
    break;

  case 27:
#line 157 "Parsing.y"
    { (yyval.p) = new_parameter((yyvsp[(1) - (1)].var)); ;}
    break;

  case 28:
#line 158 "Parsing.y"
    { (yyval.p) = update_parameter((yyvsp[(1) - (3)].p), (yyvsp[(3) - (3)].var)); ;}
    break;

  case 31:
#line 166 "Parsing.y"
    {
								parent_table = temp_table; temp_table = gen_table();
			 					add_child_table(parent_table, temp_table);
								temp_stmt = NULL;
							;}
    break;

  case 32:
#line 173 "Parsing.y"
    { temp_table = temp_table->parent; ;}
    break;

  case 38:
#line 183 "Parsing.y"
    { printf("1\n"); ;}
    break;

  case 39:
#line 184 "Parsing.y"
    { printf("2\n"); ;}
    break;

  case 40:
#line 185 "Parsing.y"
    { printf("3\n"); ;}
    break;

  case 41:
#line 186 "Parsing.y"
    { printf("4\n"); ;}
    break;

  case 42:
#line 187 "Parsing.y"
    { printf("5\n"); ;}
    break;

  case 43:
#line 188 "Parsing.y"
    { printf("6\n"); ;}
    break;

  case 44:
#line 189 "Parsing.y"
    { printf("7\n"); ;}
    break;

  case 65:
#line 227 "Parsing.y"
    {
																					if(!(yyvsp[(1) - (2)].var)) {
																						(yyval.stmt) = NULL;
																					}
																					else {
																						var_init vi = new_var_init((yyvsp[(1) - (2)].var), NULL);
																						(yyval.stmt) = new_stmt_init(vi);
																					}
																				;}
    break;

  case 66:
#line 236 "Parsing.y"
    {
																					if(!(yyvsp[(1) - (4)].var)) {
																						(yyval.stmt) = NULL;
																					}
																					else {
																						var_init vi = new_var_init((yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].exp));
																						(yyval.stmt) = new_stmt_init(vi);
																					}
																				;}
    break;

  case 67:
#line 249 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 68:
#line 250 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 69:
#line 251 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 70:
#line 252 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 71:
#line 253 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 72:
#line 254 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 73:
#line 255 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 74:
#line 256 "Parsing.y"
    { (yyval.exp) = (yyvsp[(2) - (3)].exp); ;}
    break;

  case 75:
#line 263 "Parsing.y"
    { (yyval.exp) = new_array_expression((yyvsp[(1) - (4)].exp), (yyvsp[(3) - (4)].exp)); ;}
    break;

  case 76:
#line 266 "Parsing.y"
    { (yyval.exp) = new_const_expression(CONST_FLOAT, TYPE_FLOAT); ;}
    break;

  case 77:
#line 267 "Parsing.y"
    { (yyval.exp) = new_const_expression(CONST_INT, TYPE_INT); ;}
    break;

  case 78:
#line 268 "Parsing.y"
    { (yyval.exp) = new_const_expression(CONST_STR, TYPE_ADDRESS); ;}
    break;

  case 79:
#line 269 "Parsing.y"
    { (yyval.exp) = new_const_expression(CONST_CHAR, TYPE_CHAR); ;}
    break;

  case 80:
#line 272 "Parsing.y"
    {
													entry en = lookup(temp_table, (yyvsp[(1) - (1)].id));
													//printf("VAR:%s\n", $1);
													//printf("TABLE:0x%0X\n", &temp_table);
													if(en) {
														//printf("%s!!!\n", $1);
														(yyval.exp) = new_var_expression(en->var);
													}
													else {
														free((yyvsp[(1) - (1)].id));
														yyerror("Uninitialized variable!");
													}
											;}
    break;

  case 81:
#line 287 "Parsing.y"
    { (yyval.exp) = new_assign_expression(ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 82:
#line 288 "Parsing.y"
    { (yyval.exp) = new_assign_expression(OR_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 83:
#line 289 "Parsing.y"
    { (yyval.exp) = new_assign_expression(AND_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 84:
#line 290 "Parsing.y"
    { (yyval.exp) = new_assign_expression(XOR_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 85:
#line 291 "Parsing.y"
    { (yyval.exp) = new_assign_expression(ADD_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 86:
#line 292 "Parsing.y"
    { (yyval.exp) = new_assign_expression(SUB_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 87:
#line 293 "Parsing.y"
    { (yyval.exp) = new_assign_expression(MUL_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 88:
#line 294 "Parsing.y"
    { (yyval.exp) = new_assign_expression(LS_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 89:
#line 295 "Parsing.y"
    { (yyval.exp) = new_assign_expression(RS_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 90:
#line 296 "Parsing.y"
    { (yyval.exp) = new_assign_expression(MOD_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 91:
#line 297 "Parsing.y"
    { (yyval.exp) = new_assign_expression(DIV_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 92:
#line 301 "Parsing.y"
    { (yyval.exp) = new_unary_expression(BITWISE_NEG, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 93:
#line 302 "Parsing.y"
    { (yyval.exp) = new_unary_expression(LOGICAL_INV, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 94:
#line 303 "Parsing.y"
    { (yyval.exp) = new_unary_expression(GET_ADDR, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 95:
#line 304 "Parsing.y"
    { (yyval.exp) = new_unary_expression(GET_VAL, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 96:
#line 305 "Parsing.y"
    { (yyval.exp) = new_unary_expression(SIGN_MINUS, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 97:
#line 306 "Parsing.y"
    { (yyval.exp) = new_unary_expression(SIGN_PLUS, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 98:
#line 309 "Parsing.y"
    { (yyval.exp) = new_self_expression(INCRE, (yyvsp[(2) - (2)].exp), INCRE_LEFT); ;}
    break;

  case 99:
#line 310 "Parsing.y"
    { (yyval.exp) = new_self_expression(DECRE, (yyvsp[(2) - (2)].exp), DECRE_LEFT); ;}
    break;

  case 100:
#line 311 "Parsing.y"
    { (yyval.exp) = new_self_expression(INCRE, (yyvsp[(1) - (2)].exp), INCRE_RIGHT); ;}
    break;

  case 101:
#line 312 "Parsing.y"
    { (yyval.exp) = new_self_expression(DECRE, (yyvsp[(1) - (2)].exp), DECRE_RIGHT); ;}
    break;

  case 102:
#line 315 "Parsing.y"
    { (yyval.exp) = new_binary_expression(ADD, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 103:
#line 316 "Parsing.y"
    { (yyval.exp) = new_binary_expression(SUB, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 104:
#line 317 "Parsing.y"
    { (yyval.exp) = new_binary_expression(MUL, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 105:
#line 318 "Parsing.y"
    { (yyval.exp) = new_binary_expression(DIV, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 106:
#line 319 "Parsing.y"
    { (yyval.exp) = new_binary_expression(MOD, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 107:
#line 320 "Parsing.y"
    { (yyval.exp) = new_binary_expression(XOR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 108:
#line 321 "Parsing.y"
    { (yyval.exp) = new_binary_expression(AND, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 109:
#line 322 "Parsing.y"
    { (yyval.exp) = new_binary_expression(OR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 110:
#line 323 "Parsing.y"
    { (yyval.exp) = new_binary_expression(COMMA, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 111:
#line 324 "Parsing.y"
    { (yyval.exp) = new_binary_expression(L, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 112:
#line 325 "Parsing.y"
    { (yyval.exp) = new_binary_expression(G, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 113:
#line 326 "Parsing.y"
    { (yyval.exp) = new_binary_expression(LS, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 114:
#line 327 "Parsing.y"
    { (yyval.exp) = new_binary_expression(RS, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 115:
#line 328 "Parsing.y"
    { (yyval.exp) = new_binary_expression(LOGICAL_AND, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 116:
#line 329 "Parsing.y"
    { (yyval.exp) = new_binary_expression(LOGICAL_OR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 117:
#line 330 "Parsing.y"
    { (yyval.exp) = new_binary_expression(EQ, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 118:
#line 331 "Parsing.y"
    { (yyval.exp) = new_binary_expression(GE, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 119:
#line 332 "Parsing.y"
    { (yyval.exp) = new_binary_expression(LE, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 120:
#line 333 "Parsing.y"
    { (yyval.exp) = new_binary_expression(NE, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2342 "parsing.h"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 336 "Parsing.y"

void yyerror(char *s)
{
  fprintf(stderr, "line%d column%d %s\n", row, col, s);
  //printf("Error: %s\n", emseg);
}

