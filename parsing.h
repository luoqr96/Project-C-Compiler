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
func_list func_table = NULL;


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
#line 14 "Parsing.y"
{
	int const_int;
	float const_float;
	char const_char;
  char *const_str;
	char *id;
	struct { v_type tp; int order; } t;
	struct { v_type tp; char *name; } fun_dec;
	expression exp;
	v_type tp;
	variable var;
	parameter p;
	OP op;
	statement stmt;
	function f;
}
/* Line 193 of yacc.c.  */
#line 233 "parsing.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 246 "parsing.h"

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1472

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNRULES -- Number of states.  */
#define YYNSTATES  212

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
      71,    68,    54,    52,    45,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    72,
      50,    46,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    48,    70,    73,     2,     2,     2,
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
      35,    39,    42,    44,    50,    55,    57,    59,    61,    63,
      65,    67,    69,    71,    74,    77,    79,    83,    86,    90,
      92,    94,    96,    99,   102,   104,   107,   113,   121,   129,
     137,   143,   151,   157,   163,   169,   175,   181,   187,   193,
     196,   200,   202,   204,   207,   211,   214,   216,   218,   220,
     222,   224,   227,   230,   233,   238,   240,   242,   244,   246,
     248,   250,   252,   256,   258,   263,   267,   272,   274,   276,
     278,   280,   282,   286,   290,   294,   298,   302,   306,   310,
     314,   318,   322,   326,   329,   332,   335,   338,   341,   344,
     347,   350,   353,   356,   360,   364,   368,   372,   376,   380,
     384,   388,   392,   396,   400,   404,   408,   412,   416,   420,
     424,   428
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    77,    -1,    78,    -1,    77,    78,    -1,
      97,    -1,    77,    97,    -1,    79,    85,    68,    69,    89,
      70,    -1,    79,     9,    68,    69,    89,    70,    -1,    79,
      68,    69,    89,    70,    -1,    82,     3,    71,    -1,    82,
       3,    -1,    81,    -1,    82,     3,    65,    12,    66,    -1,
      81,    65,    12,    66,    -1,    83,    -1,    84,    -1,     4,
      -1,     5,    -1,     7,    -1,     6,    -1,     8,    -1,     9,
      -1,    83,    54,    -1,    84,    54,    -1,    80,    -1,    85,
      45,    80,    -1,    87,    88,    -1,    87,    89,    88,    -1,
      69,    -1,    70,    -1,    96,    -1,    89,    72,    -1,    89,
      96,    -1,    86,    -1,    89,    86,    -1,    36,    71,    98,
      68,    96,    -1,    36,    71,    98,    68,    96,    37,    96,
      -1,    36,    71,    98,    68,    86,    37,    96,    -1,    36,
      71,    98,    68,    96,    37,    86,    -1,    36,    71,    98,
      68,    86,    -1,    36,    71,    98,    68,    86,    37,    86,
      -1,    36,    71,    98,    68,    72,    -1,    42,    71,    98,
      68,    86,    -1,    42,    71,    98,    68,    72,    -1,    42,
      71,    98,    68,    96,    -1,    38,    71,    93,    68,    86,
      -1,    38,    71,    93,    68,    72,    -1,    38,    71,    93,
      68,    96,    -1,    94,    94,    -1,    94,    94,    98,    -1,
      96,    -1,    72,    -1,    44,    72,    -1,    44,    98,    72,
      -1,    98,    72,    -1,    90,    -1,    97,    -1,    91,    -1,
      92,    -1,    95,    -1,    39,    72,    -1,    40,    72,    -1,
      80,    72,    -1,    80,    46,    98,    72,    -1,   102,    -1,
     101,    -1,   103,    -1,   105,    -1,   106,    -1,   104,    -1,
     100,    -1,    71,    98,    68,    -1,    99,    -1,     3,    71,
      98,    68,    -1,     3,    71,    68,    -1,    98,    65,    98,
      66,    -1,    10,    -1,    12,    -1,    11,    -1,    13,    -1,
       3,    -1,    98,    46,    98,    -1,    98,    31,    98,    -1,
      98,    33,    98,    -1,    98,    32,    98,    -1,    98,    25,
      98,    -1,    98,    26,    98,    -1,    98,    28,    98,    -1,
      98,    29,    98,    -1,    98,    27,    98,    -1,    98,    34,
      98,    -1,    98,    30,    98,    -1,    73,    98,    -1,    74,
      98,    -1,    49,    98,    -1,    54,    98,    -1,    53,    98,
      -1,    52,    98,    -1,    23,    98,    -1,    24,    98,    -1,
      98,    23,    -1,    98,    24,    -1,    98,    52,    98,    -1,
      98,    53,    98,    -1,    98,    54,    98,    -1,    98,    55,
      98,    -1,    98,    56,    98,    -1,    98,    47,    98,    -1,
      98,    49,    98,    -1,    98,    48,    98,    -1,    98,    45,
      98,    -1,    98,    50,    98,    -1,    98,    51,    98,    -1,
      98,    15,    98,    -1,    98,    14,    98,    -1,    98,    18,
      98,    -1,    98,    16,    98,    -1,    98,    17,    98,    -1,
      98,    20,    98,    -1,    98,    21,    98,    -1,    98,    19,
      98,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    71,    72,    73,    74,    80,    86,    92,
     101,   113,   125,   131,   154,   157,   158,   162,   163,   164,
     165,   166,   167,   171,   185,   189,   190,   194,   195,   198,
     205,   208,   209,   210,   211,   212,   215,   216,   217,   218,
     219,   220,   221,   224,   225,   226,   229,   230,   231,   234,
     235,   238,   239,   243,   244,   248,   249,   250,   251,   252,
     253,   254,   255,   259,   268,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   292,   302,   314,   317,   318,   319,
     320,   323,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   352,   353,   354,   355,   356,   357,   360,
     361,   362,   363,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384
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
  "BIT_NEG", "'['", "']'", "IFX", "')'", "'{'", "'}'", "'('", "';'", "'~'",
  "'!'", "$accept", "CODE_TEXT", "PROGRAM", "FUNCTION", "FUNC_DEC",
  "DECLARATION", "DECLARATION_ARRAY", "TYPE", "SIMPLE_TYPE",
  "POINTER_TYPE", "PARAMETER", "COMPOUND_STATEMENT", "LPAREN", "RPAREN",
  "STATEMENT_LIST", "IF_STATEMENT", "WHILE_STATEMENT", "FOR_STATEMENT",
  "FOR_EXP", "FOR_EXP1", "RETURN_STATEMENT", "STATEMENT",
  "INITIALIZATION_STATEMENT", "EXPRESSION", "CALL_FUNCTION",
  "ARRAY_OPERATION", "CONSTANT_EXPRESSION", "IDENTIFIER_EXPRESSION",
  "ASSIGNMENT_EXPRESSION", "UNARY_OPERATION", "SELF_OPERATION",
  "BINARY_OPERATION", 0
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
     303,   304,   305,   306,   307,    91,    93,   308,    41,   123,
     125,    40,    59,   126,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    77,    77,    78,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      88,    89,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99,    99,   100,   101,   101,   101,
     101,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   104,   104,   104,   105,
     105,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     6,     6,     5,
       3,     2,     1,     5,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     3,     2,     3,     1,
       1,     1,     2,     2,     1,     2,     5,     7,     7,     7,
       5,     7,     5,     5,     5,     5,     5,     5,     5,     2,
       3,     1,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     3,     4,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,    18,    20,    19,    21,    22,     0,     2,     3,
       0,     0,    12,     0,    15,    16,     5,     1,     4,     6,
      22,     0,    25,     0,     0,     0,    63,     0,    11,    23,
      24,     0,     0,    11,     0,     0,    81,    77,    79,    78,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    71,    66,    65,    67,    70,    68,    69,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,    29,
      34,     0,     0,    56,    58,    59,    60,    31,    57,     0,
      26,     0,     0,    99,   100,    95,    98,    97,    96,     0,
      93,    94,     0,     0,     0,     0,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,    14,     0,     0,     0,
       0,    61,    62,     0,    53,     0,    30,    27,     0,     9,
      32,    35,    33,    55,     0,    75,     0,    72,   115,   114,
     117,   118,   116,   121,   119,   120,    86,    87,    90,    88,
      89,    92,    83,    85,    84,    91,   111,    82,   108,   110,
     109,   112,   113,   103,   104,   105,   106,   107,     0,    13,
       8,     0,    52,     0,     0,    51,     0,    54,    28,     7,
      74,    76,     0,     0,    49,     0,    42,    40,    36,    47,
      46,    48,    50,    44,    43,    45,     0,     0,    41,    38,
      39,    37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    12,    23,    14,    15,
      24,    70,    71,   137,    72,    73,    74,    75,   183,   184,
      76,    77,    78,    79,    51,    52,    53,    54,    55,    56,
      57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int16 yypact[] =
{
      23,   -56,   -56,   -56,   -56,   -56,   -56,    12,    23,   -56,
      -3,   -37,   -52,    51,     1,     4,   -56,   -56,   -56,   -56,
      -8,    -7,   -56,    58,   -20,   724,   -56,    52,   -12,   -56,
     -56,    -6,   600,    10,    23,     7,    -5,   -56,   -56,   -56,
     -56,   724,   724,   724,   724,   724,   724,   724,   724,   724,
     785,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,    35,
      91,   -56,   600,    38,    40,    41,    46,    44,   109,   -56,
     -56,   392,   184,   -56,   -56,   -56,   -56,   -56,   -56,   844,
     -56,   600,   697,   -13,   -13,   -13,   -13,   -13,   -13,   962,
     -13,   -13,   724,   724,   724,   724,   724,   724,   724,   724,
     -56,   -56,   724,   724,   724,   724,   724,   724,   724,   724,
     724,   724,   724,   724,   724,   724,   724,   724,   724,   724,
     724,   724,   724,   724,   724,   -56,   -56,    59,   236,   724,
     652,   -56,   -56,   724,   -56,   903,   -56,   -56,   288,   -56,
     -56,   -56,   -56,   -56,   340,   -56,  1017,   -56,   -16,   -16,
    1299,  1407,  1321,  1385,   729,   729,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,   663,  1342,
    1364,   729,   729,    -9,    -9,   -13,   -13,   -13,  1182,   -56,
     -56,  1072,   -56,    60,   652,   -56,  1127,   -56,   -56,   -56,
     -56,   -56,   444,   496,   724,   548,   -56,    69,    89,   -56,
     -56,   -56,  1235,   -56,   -56,   -56,   600,   600,   -56,   -56,
     -56,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -56,   -56,   -56,   119,   -56,    16,   -56,    33,   -56,   -56,
     -56,   -21,   -56,    -4,    43,   -56,   -56,   -56,   -56,   -55,
     -56,   -28,    34,   -25,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      50,     1,     2,     3,     4,     5,    20,   100,   101,    25,
     100,   101,    17,    27,   100,   101,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    34,    22,     1,     2,     3,
       4,     5,     6,    13,    16,    26,   119,   120,   121,   122,
     123,    13,    19,   135,   142,   121,   122,   123,    35,   124,
      80,   141,   124,    60,    28,    29,   124,   146,    30,    61,
      31,    33,    32,    62,    59,    21,    82,   148,   149,   150,
     151,   152,   153,   154,   155,    60,    81,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     142,   126,   185,   127,   181,   128,   206,   141,   186,   129,
     142,   130,    36,   131,   138,   133,   142,   141,   132,    37,
      38,    39,    40,   141,   144,   179,   207,    18,   193,   194,
       0,     0,    41,    42,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   185,     0,    43,     0,
       0,    44,    45,    46,   198,   201,     0,   205,     0,   202,
       0,   197,   200,     0,   204,     0,     0,     0,   209,   211,
      47,   134,    48,    49,     0,   208,   210,    36,     1,     2,
       3,     4,     5,     6,    37,    38,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,    64,    65,    66,     0,    67,     0,    68,     0,
       0,     0,     0,    43,     0,     0,    44,    45,    46,    36,
       1,     2,     3,     4,     5,     6,    37,    38,    39,    40,
       0,     0,     0,    69,   139,    47,   140,    48,    49,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,    64,    65,    66,     0,    67,     0,
      68,     0,     0,     0,     0,    43,     0,     0,    44,    45,
      46,    36,     1,     2,     3,     4,     5,     6,    37,    38,
      39,    40,     0,     0,     0,    69,   180,    47,   140,    48,
      49,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,    64,    65,    66,     0,
      67,     0,    68,     0,     0,     0,     0,    43,     0,     0,
      44,    45,    46,    36,     1,     2,     3,     4,     5,     6,
      37,    38,    39,    40,     0,     0,     0,    69,   136,    47,
     140,    48,    49,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,    64,    65,
      66,     0,    67,     0,    68,     0,     0,     0,     0,    43,
       0,     0,    44,    45,    46,    36,     1,     2,     3,     4,
       5,     6,    37,    38,    39,    40,     0,     0,     0,    69,
     189,    47,   140,    48,    49,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
      64,    65,    66,     0,    67,     0,    68,     0,     0,     0,
       0,    43,     0,     0,    44,    45,    46,    36,     1,     2,
       3,     4,     5,     6,    37,    38,    39,    40,     0,     0,
       0,    69,   136,    47,     0,    48,    49,    41,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,    64,    65,    66,     0,    67,     0,    68,     0,
       0,     0,     0,    43,     0,     0,    44,    45,    46,    36,
       1,     2,     3,     4,     5,     6,    37,    38,    39,    40,
       0,     0,     0,    69,     0,    47,   196,    48,    49,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,    64,    65,    66,     0,    67,     0,
      68,     0,     0,     0,     0,    43,     0,     0,    44,    45,
      46,    36,     1,     2,     3,     4,     5,     6,    37,    38,
      39,    40,     0,     0,     0,    69,     0,    47,   199,    48,
      49,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,    64,    65,    66,     0,
      67,     0,    68,     0,     0,     0,     0,    43,     0,     0,
      44,    45,    46,    36,     1,     2,     3,     4,     5,     6,
      37,    38,    39,    40,     0,     0,     0,    69,     0,    47,
     203,    48,    49,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,    64,    65,
      66,     0,    67,     0,    68,     0,     0,     0,     0,    43,
       0,     0,    44,    45,    46,    36,     1,     2,     3,     4,
       5,     6,    37,    38,    39,    40,     0,     0,     0,    69,
       0,    47,     0,    48,    49,    41,    42,    92,    93,     0,
      95,     0,    97,    98,    99,     0,   100,   101,    63,     0,
      64,    65,    66,     0,    67,     0,    68,     0,     0,     0,
      36,    43,     0,     0,    44,    45,    46,    37,    38,    39,
      40,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      41,    42,     0,    47,   182,    48,    49,    36,   124,     0,
       0,     0,     0,     0,    37,    38,    39,    40,     0,     0,
       0,     0,     0,    92,    93,     0,    43,    41,    42,    44,
      45,    46,   100,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,    47,     0,
      48,    49,     0,    43,     0,     0,    44,    45,    46,     0,
       0,   119,   120,   121,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,   124,    47,     0,    48,    49,    92,
      93,    94,    95,    96,    97,    98,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,   125,    92,    93,
      94,    95,    96,    97,    98,    99,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,   143,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,     0,     0,     0,   187,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
     147,    92,    93,    94,    95,    96,    97,    98,    99,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,     0,   190,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
     192,    92,    93,    94,    95,    96,    97,    98,    99,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   124,     0,     0,   195,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   191,    92,
      93,    94,    95,    96,    97,    98,    99,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,    92,    93,    94,    95,    96,    97,    98,    99,
     124,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,    92,    93,     0,    95,    96,    97,    98,
      99,     0,   100,   101,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    92,    93,     0,    95,     0,
      97,    98,    99,   124,   100,   101,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    92,    93,     0,    95,
       0,    97,    98,    99,   124,   100,   101,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,    92,    93,
       0,    95,     0,    97,    98,    99,   124,   100,   101,     0,
       0,   116,   117,   118,   119,   120,   121,   122,   123,    92,
      93,     0,    95,     0,     0,    98,    99,   124,   100,   101,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,    92,    93,     0,     0,     0,     0,    98,    99,   124,
     100,   101,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   124
};

static const yytype_int16 yycheck[] =
{
      25,     4,     5,     6,     7,     8,     9,    23,    24,    46,
      23,    24,     0,    65,    23,    24,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    45,    10,     4,     5,     6,
       7,     8,     9,     0,     0,    72,    52,    53,    54,    55,
      56,     8,     8,    68,    72,    54,    55,    56,    68,    65,
      34,    72,    65,    65,     3,    54,    65,    82,    54,    71,
      68,     3,    69,    69,    12,    68,    71,    92,    93,    94,
      95,    96,    97,    98,    99,    65,    69,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     128,    66,   130,    12,   129,    62,    37,   128,   133,    71,
     138,    71,     3,    72,    71,    71,   144,   138,    72,    10,
      11,    12,    13,   144,    81,    66,    37,     8,    68,   184,
      -1,    -1,    23,    24,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,    49,    -1,
      -1,    52,    53,    54,   192,   193,    -1,   195,    -1,   194,
      -1,   192,   193,    -1,   195,    -1,    -1,    -1,   206,   207,
      71,    72,    73,    74,    -1,   206,   207,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    54,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    69,    70,    71,    -1,    73,    74,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    38,    39,    40,    -1,    42,    -1,    44,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    54,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    69,    -1,    71,    72,    73,    74,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    38,    39,    40,    -1,    42,    -1,
      44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      54,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    69,    -1,    71,    72,    73,
      74,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    39,    40,    -1,
      42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      52,    53,    54,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    69,    -1,    71,
      72,    73,    74,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    74,    23,    24,    14,    15,    -1,
      17,    -1,    19,    20,    21,    -1,    23,    24,    36,    -1,
      38,    39,    40,    -1,    42,    -1,    44,    -1,    -1,    -1,
       3,    49,    -1,    -1,    52,    53,    54,    10,    11,    12,
      13,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      23,    24,    -1,    71,    72,    73,    74,     3,    65,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    14,    15,    -1,    49,    23,    24,    52,
      53,    54,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      73,    74,    -1,    49,    -1,    -1,    52,    53,    54,    -1,
      -1,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    71,    -1,    73,    74,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    72,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      68,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    68,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      68,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    68,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    14,    15,    16,    17,    18,    19,    20,    21,
      65,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    14,    15,    -1,    17,    18,    19,    20,
      21,    -1,    23,    24,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    14,    15,    -1,    17,    -1,
      19,    20,    21,    65,    23,    24,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    14,    15,    -1,    17,
      -1,    19,    20,    21,    65,    23,    24,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    14,    15,
      -1,    17,    -1,    19,    20,    21,    65,    23,    24,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    14,
      15,    -1,    17,    -1,    -1,    20,    21,    65,    23,    24,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    14,    15,    -1,    -1,    -1,    -1,    20,    21,    65,
      23,    24,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    97,     0,    78,    97,
       9,    68,    80,    82,    85,    46,    72,    65,     3,    54,
      54,    68,    69,     3,    45,    68,     3,    10,    11,    12,
      13,    23,    24,    49,    52,    53,    54,    71,    73,    74,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    12,
      65,    71,    69,    36,    38,    39,    40,    42,    44,    69,
      86,    87,    89,    90,    91,    92,    95,    96,    97,    98,
      80,    69,    71,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    14,    15,    16,    17,    18,    19,    20,    21,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    65,    72,    66,    12,    89,    71,
      71,    72,    72,    71,    72,    98,    70,    88,    89,    70,
      72,    86,    96,    72,    89,    68,    98,    68,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    66,
      70,    98,    72,    93,    94,    96,    98,    72,    88,    70,
      68,    66,    68,    68,    94,    68,    72,    86,    96,    72,
      86,    96,    98,    72,    86,    96,    37,    37,    86,    96,
      86,    96
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
#line 68 "Parsing.y"
    {  ;}
    break;

  case 7:
#line 80 "Parsing.y"
    {
																																(yyval.f) = insert_func(func_table, (yyvsp[(1) - (6)].fun_dec).name, (yyvsp[(2) - (6)].p), NULL, (yyvsp[(1) - (6)].fun_dec).tp);
			 																													if(!(yyval.f)) {
																																	yyerror("函数重定义！");
																																}
																															;}
    break;

  case 8:
#line 86 "Parsing.y"
    {
																																(yyval.f) = insert_func(func_table, (yyvsp[(1) - (6)].fun_dec).name, NULL, NULL, (yyvsp[(1) - (6)].fun_dec).tp);
																																if(!(yyval.f)) {
																																	yyerror("函数重定义！");
																																}
																															;}
    break;

  case 9:
#line 92 "Parsing.y"
    {
																																(yyval.f) = insert_func(func_table, (yyvsp[(1) - (5)].fun_dec).name, NULL, NULL, (yyvsp[(1) - (5)].fun_dec).tp);
																																if(!(yyval.f)) {
																																	yyerror("函数重定义！");
																																}
																															;}
    break;

  case 10:
#line 101 "Parsing.y"
    {
															(yyval.fun_dec).tp = (yyvsp[(1) - (3)].t).tp;
			 												(yyval.fun_dec).name = (yyvsp[(2) - (3)].id);
															parent_table = temp_table; temp_table = gen_table();
										 					add_child_table(parent_table, temp_table);
															temp_stmt = NULL;
														;}
    break;

  case 11:
#line 113 "Parsing.y"
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

  case 12:
#line 125 "Parsing.y"
    { (yyval.var) = (yyvsp[(1) - (1)].var); ;}
    break;

  case 13:
#line 131 "Parsing.y"
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
																															yyerror("Redeclared variable！");
																															(yyval.var) = NULL;
																														}
																													;}
    break;

  case 14:
#line 154 "Parsing.y"
    { update_dimension((yyvsp[(1) - (4)].var)->dim, (yyvsp[(3) - (4)].const_int)); (yyval.var) = (yyvsp[(1) - (4)].var); (yyval.var)->order++; ;}
    break;

  case 15:
#line 157 "Parsing.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 16:
#line 158 "Parsing.y"
    { (yyval.t) = (yyvsp[(1) - (1)].t); ;}
    break;

  case 17:
#line 162 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 18:
#line 163 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 19:
#line 164 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 20:
#line 165 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 21:
#line 166 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 22:
#line 167 "Parsing.y"
    { (yyval.t).tp = (yyvsp[(1) - (1)].tp); (yyval.t).order = 0; ;}
    break;

  case 23:
#line 171 "Parsing.y"
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

  case 24:
#line 185 "Parsing.y"
    { (yyval.t) = (yyvsp[(1) - (2)].t); (yyval.t).order++; ;}
    break;

  case 25:
#line 189 "Parsing.y"
    { (yyval.p) = new_parameter((yyvsp[(1) - (1)].var)); ;}
    break;

  case 26:
#line 190 "Parsing.y"
    { (yyval.p) = update_parameter((yyvsp[(1) - (3)].p), (yyvsp[(3) - (3)].var)); ;}
    break;

  case 29:
#line 198 "Parsing.y"
    {
								parent_table = temp_table; temp_table = gen_table();
			 					add_child_table(parent_table, temp_table);
								temp_stmt = NULL;
							;}
    break;

  case 30:
#line 205 "Parsing.y"
    { temp_table = temp_table->parent; ;}
    break;

  case 36:
#line 215 "Parsing.y"
    { printf("1\n"); ;}
    break;

  case 37:
#line 216 "Parsing.y"
    { printf("2\n"); ;}
    break;

  case 38:
#line 217 "Parsing.y"
    { printf("3\n"); ;}
    break;

  case 39:
#line 218 "Parsing.y"
    { printf("4\n"); ;}
    break;

  case 40:
#line 219 "Parsing.y"
    { printf("5\n"); ;}
    break;

  case 41:
#line 220 "Parsing.y"
    { printf("6\n"); ;}
    break;

  case 42:
#line 221 "Parsing.y"
    { printf("7\n"); ;}
    break;

  case 63:
#line 259 "Parsing.y"
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

  case 64:
#line 268 "Parsing.y"
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

  case 65:
#line 281 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 66:
#line 282 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 67:
#line 283 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 68:
#line 284 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 69:
#line 285 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 70:
#line 286 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 71:
#line 287 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 72:
#line 288 "Parsing.y"
    { (yyval.exp) = (yyvsp[(2) - (3)].exp); ;}
    break;

  case 73:
#line 289 "Parsing.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); ;}
    break;

  case 74:
#line 292 "Parsing.y"
    {
																						function f = check_function(func_table, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].exp));
																						if(f) {
																							(yyval.exp) = new_function_expression(f);
																						}
																						else {
																							(yyval.exp) = NULL;
																						}
																						free((yyvsp[(1) - (4)].id));
																					;}
    break;

  case 75:
#line 302 "Parsing.y"
    {
																						function f = check_function(func_table, (yyvsp[(1) - (3)].id), NULL);
																						if(f) {
																							(yyval.exp) = new_function_expression(f);
																						}
																						else {
																							(yyval.exp) = NULL;
																						}
																						free((yyvsp[(1) - (3)].id));
																					;}
    break;

  case 76:
#line 314 "Parsing.y"
    { (yyval.exp) = new_array_expression((yyvsp[(1) - (4)].exp), (yyvsp[(3) - (4)].exp)); ;}
    break;

  case 77:
#line 317 "Parsing.y"
    { (yyval.exp) = new_const_expression(CONST_FLOAT, TYPE_FLOAT); ;}
    break;

  case 78:
#line 318 "Parsing.y"
    { (yyval.exp) = new_const_expression(CONST_INT, TYPE_INT); ;}
    break;

  case 79:
#line 319 "Parsing.y"
    { (yyval.exp) = new_const_expression(CONST_STR, TYPE_ADDRESS); ;}
    break;

  case 80:
#line 320 "Parsing.y"
    { (yyval.exp) = new_const_expression(CONST_CHAR, TYPE_CHAR); ;}
    break;

  case 81:
#line 323 "Parsing.y"
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
														yyerror("Undeclared variable!");
													}
											;}
    break;

  case 82:
#line 338 "Parsing.y"
    { (yyval.exp) = new_assign_expression(ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 83:
#line 339 "Parsing.y"
    { (yyval.exp) = new_assign_expression(OR_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 84:
#line 340 "Parsing.y"
    { (yyval.exp) = new_assign_expression(AND_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 85:
#line 341 "Parsing.y"
    { (yyval.exp) = new_assign_expression(XOR_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 86:
#line 342 "Parsing.y"
    { (yyval.exp) = new_assign_expression(ADD_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 87:
#line 343 "Parsing.y"
    { (yyval.exp) = new_assign_expression(SUB_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 88:
#line 344 "Parsing.y"
    { (yyval.exp) = new_assign_expression(MUL_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 89:
#line 345 "Parsing.y"
    { (yyval.exp) = new_assign_expression(LS_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 90:
#line 346 "Parsing.y"
    { (yyval.exp) = new_assign_expression(RS_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 91:
#line 347 "Parsing.y"
    { (yyval.exp) = new_assign_expression(MOD_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 92:
#line 348 "Parsing.y"
    { (yyval.exp) = new_assign_expression(DIV_ASSIGN, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 93:
#line 352 "Parsing.y"
    { (yyval.exp) = new_unary_expression(BITWISE_NEG, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 94:
#line 353 "Parsing.y"
    { (yyval.exp) = new_unary_expression(LOGICAL_INV, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 95:
#line 354 "Parsing.y"
    { (yyval.exp) = new_unary_expression(GET_ADDR, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 96:
#line 355 "Parsing.y"
    { (yyval.exp) = new_unary_expression(GET_VAL, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 97:
#line 356 "Parsing.y"
    { (yyval.exp) = new_unary_expression(SIGN_MINUS, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 98:
#line 357 "Parsing.y"
    { (yyval.exp) = new_unary_expression(SIGN_PLUS, (yyvsp[(2) - (2)].exp)); ;}
    break;

  case 99:
#line 360 "Parsing.y"
    { (yyval.exp) = new_self_expression(INCRE, (yyvsp[(2) - (2)].exp), INCRE_LEFT); ;}
    break;

  case 100:
#line 361 "Parsing.y"
    { (yyval.exp) = new_self_expression(DECRE, (yyvsp[(2) - (2)].exp), DECRE_LEFT); ;}
    break;

  case 101:
#line 362 "Parsing.y"
    { (yyval.exp) = new_self_expression(INCRE, (yyvsp[(1) - (2)].exp), INCRE_RIGHT); ;}
    break;

  case 102:
#line 363 "Parsing.y"
    { (yyval.exp) = new_self_expression(DECRE, (yyvsp[(1) - (2)].exp), DECRE_RIGHT); ;}
    break;

  case 103:
#line 366 "Parsing.y"
    { (yyval.exp) = new_binary_expression(ADD, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 104:
#line 367 "Parsing.y"
    { (yyval.exp) = new_binary_expression(SUB, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 105:
#line 368 "Parsing.y"
    { (yyval.exp) = new_binary_expression(MUL, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 106:
#line 369 "Parsing.y"
    { (yyval.exp) = new_binary_expression(DIV, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 107:
#line 370 "Parsing.y"
    { (yyval.exp) = new_binary_expression(MOD, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 108:
#line 371 "Parsing.y"
    { (yyval.exp) = new_binary_expression(XOR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 109:
#line 372 "Parsing.y"
    { (yyval.exp) = new_binary_expression(AND, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 110:
#line 373 "Parsing.y"
    { (yyval.exp) = new_binary_expression(OR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 111:
#line 374 "Parsing.y"
    { (yyval.exp) = new_binary_expression(COMMA, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 112:
#line 375 "Parsing.y"
    { (yyval.exp) = new_binary_expression(L, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 113:
#line 376 "Parsing.y"
    { (yyval.exp) = new_binary_expression(G, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 114:
#line 377 "Parsing.y"
    { (yyval.exp) = new_binary_expression(LS, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 115:
#line 378 "Parsing.y"
    { (yyval.exp) = new_binary_expression(RS, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 116:
#line 379 "Parsing.y"
    { (yyval.exp) = new_binary_expression(LOGICAL_AND, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 117:
#line 380 "Parsing.y"
    { (yyval.exp) = new_binary_expression(LOGICAL_OR, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 118:
#line 381 "Parsing.y"
    { (yyval.exp) = new_binary_expression(EQ, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 119:
#line 382 "Parsing.y"
    { (yyval.exp) = new_binary_expression(GE, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 120:
#line 383 "Parsing.y"
    { (yyval.exp) = new_binary_expression(LE, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;

  case 121:
#line 384 "Parsing.y"
    { (yyval.exp) = new_binary_expression(NE, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2470 "parsing.h"
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


#line 387 "Parsing.y"

void yyerror(char *s)
{
  fprintf(stderr, "line%d column%d %s\n", row, col, s);
  //printf("Error: %s\n", emseg);
}

