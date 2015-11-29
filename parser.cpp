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
     T_OR = 258,
     T_AND = 259,
     T_LESSTHAN = 260,
     T_LESSTHANOREQUAL = 261,
     T_EQUALS = 262,
     T_PLUS = 263,
     T_MINUS = 264,
     T_MULTIPLY = 265,
     T_DIVIDE = 266,
     T_NOT = 267,
     T_IDENTIFIER = 268,
     T_INTEGERLITERAL = 269,
     T_PRINT = 270,
     T_RETURN = 271,
     T_IF = 272,
     T_ELSE = 273,
     T_WHILE = 274,
     T_NEW = 275,
     T_INTEGER = 276,
     T_BOOLEAN = 277,
     T_NONE = 278,
     T_TRUE = 279,
     T_FALSE = 280,
     T_EXTENDS = 281,
     T_REPEAT = 282,
     T_UNTIL = 283,
     T_OPENBRACKET = 284,
     T_CLOSEDBRACKET = 285,
     T_OPENPAREN = 286,
     T_CLOSEDPAREN = 287,
     T_SEMI = 288,
     T_COLON = 289,
     T_METHODRETURN = 290,
     T_COMMA = 291,
     T_DOT = 292,
     T_EQUALSBOOL = 293,
     T_CLASSTYPE = 294
   };
#endif
/* Tokens.  */
#define T_OR 258
#define T_AND 259
#define T_LESSTHAN 260
#define T_LESSTHANOREQUAL 261
#define T_EQUALS 262
#define T_PLUS 263
#define T_MINUS 264
#define T_MULTIPLY 265
#define T_DIVIDE 266
#define T_NOT 267
#define T_IDENTIFIER 268
#define T_INTEGERLITERAL 269
#define T_PRINT 270
#define T_RETURN 271
#define T_IF 272
#define T_ELSE 273
#define T_WHILE 274
#define T_NEW 275
#define T_INTEGER 276
#define T_BOOLEAN 277
#define T_NONE 278
#define T_TRUE 279
#define T_FALSE 280
#define T_EXTENDS 281
#define T_REPEAT 282
#define T_UNTIL 283
#define T_OPENBRACKET 284
#define T_CLOSEDBRACKET 285
#define T_OPENPAREN 286
#define T_CLOSEDPAREN 287
#define T_SEMI 288
#define T_COLON 289
#define T_METHODRETURN 290
#define T_COMMA 291
#define T_DOT 292
#define T_EQUALSBOOL 293
#define T_CLASSTYPE 294




/* Copy the first part of user declarations.  */
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
    std::list<StatementNode*>* StatementNodeList;
    std::list<IdentifierNode*>* IdentifierNodeList;
    std::list<DeclarationNode*>* DeclarationNodeList = new std::list<DeclarationNode*>();

    std::list<MethodNode*>* MethodNodeList;
    std::list<DeclarationNode*>* DeclarationNodeList2 = new std::list<DeclarationNode*>();
    char* ClassName;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 206 "parser.cpp"

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    16,    21,    26,
      28,    30,    32,    34,    36,    37,    40,    42,    53,    55,
      56,    60,    62,    66,    68,    70,    75,    77,    81,    83,
      87,    88,    90,    91,    94,    96,    98,   101,   103,   105,
     107,   109,   114,   121,   127,   137,   143,   153,   157,   161,
     165,   169,   173,   177,   181,   185,   189,   193,   196,   199,
     201,   205,   207,   211,   213,   215,   217,   220,   226,   231,
     238,   240,   241,   245
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    42,    43,    -1,    43,    -1,
      44,    -1,    13,    26,    44,    -1,    13,    29,    45,    30,
      -1,    46,    13,    33,    45,    -1,    47,    -1,    21,    -1,
      22,    -1,    13,    -1,    48,    -1,    -1,    48,    49,    -1,
      49,    -1,    13,    31,    50,    32,    35,    53,    29,    54,
      56,    30,    -1,    51,    -1,    -1,    51,    36,    52,    -1,
      52,    -1,    13,    34,    46,    -1,    46,    -1,    23,    -1,
      46,    55,    33,    54,    -1,    57,    -1,    55,    36,    13,
      -1,    13,    -1,    16,    65,    33,    -1,    -1,    58,    -1,
      -1,    59,    58,    -1,    59,    -1,    60,    -1,    66,    33,
      -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,    13,
       7,    65,    33,    -1,    13,    37,    13,     7,    65,    33,
      -1,    17,    65,    29,    58,    30,    -1,    17,    65,    29,
      58,    30,    18,    29,    58,    30,    -1,    19,    65,    29,
      58,    30,    -1,    27,    29,    58,    30,    28,    31,    65,
      32,    33,    -1,    15,    65,    33,    -1,    65,     8,    65,
      -1,    65,     9,    65,    -1,    65,    10,    65,    -1,    65,
      11,    65,    -1,    65,     5,    65,    -1,    65,     6,    65,
      -1,    65,    38,    65,    -1,    65,     4,    65,    -1,    65,
       3,    65,    -1,    12,    65,    -1,     9,    65,    -1,    13,
      -1,    13,    37,    13,    -1,    66,    -1,    31,    65,    32,
      -1,    14,    -1,    24,    -1,    25,    -1,    20,    13,    -1,
      20,    13,    31,    67,    32,    -1,    13,    31,    67,    32,
      -1,    13,    37,    13,    31,    67,    32,    -1,    68,    -1,
      -1,    68,    36,    65,    -1,    65,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    82,    83,    86,    87,    90,    93,    94,
      97,    98,    99,   102,   103,   106,   107,   110,   113,   114,
     117,   118,   121,   123,   124,   127,   128,   131,   132,   135,
     136,   141,   142,   145,   146,   149,   150,   151,   152,   153,
     154,   157,   158,   161,   162,   165,   167,   169,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   193,   194,
     197,   198,   201,   202
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_OR", "T_AND", "T_LESSTHAN",
  "T_LESSTHANOREQUAL", "T_EQUALS", "T_PLUS", "T_MINUS", "T_MULTIPLY",
  "T_DIVIDE", "T_NOT", "T_IDENTIFIER", "T_INTEGERLITERAL", "T_PRINT",
  "T_RETURN", "T_IF", "T_ELSE", "T_WHILE", "T_NEW", "T_INTEGER",
  "T_BOOLEAN", "T_NONE", "T_TRUE", "T_FALSE", "T_EXTENDS", "T_REPEAT",
  "T_UNTIL", "T_OPENBRACKET", "T_CLOSEDBRACKET", "T_OPENPAREN",
  "T_CLOSEDPAREN", "T_SEMI", "T_COLON", "T_METHODRETURN", "T_COMMA",
  "T_DOT", "T_EQUALSBOOL", "T_CLASSTYPE", "$accept", "Start", "CLASS1",
  "CLASS", "DECLARATION", "IMPLEMENTATION", "TYPE", "METHOD2", "METHOD1",
  "METHOD", "PARAMETERS1", "PARAMETERS", "PARAMETER", "RETURN_TYPE",
  "BODY", "VARIABLE_", "RETURN_STATEMENT", "STATEMENTS1", "STATEMENTS",
  "STATEMENT", "ASSIGNMENT", "IFELSE", "WHILELOOP", "REPEATUNTIL",
  "PRINT1", "EXPRESSION", "METHODCALL", "ARGUMENTS", "ARGUMENTS_", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    45,    45,
      46,    46,    46,    47,    47,    48,    48,    49,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    62,    63,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     4,     4,     1,
       1,     1,     1,     1,     0,     2,     1,    10,     1,     0,
       3,     1,     3,     1,     1,     4,     1,     3,     1,     3,
       0,     1,     0,     2,     1,     1,     2,     1,     1,     1,
       1,     4,     6,     5,     9,     5,     9,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       3,     1,     3,     1,     1,     1,     2,     5,     4,     6,
       1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     5,     0,    14,     1,     3,
       0,     6,    12,    10,    11,     0,     0,     9,    13,    16,
      19,     7,     0,     0,    15,     0,     0,    18,    21,    14,
       0,     0,     0,     8,    12,    22,     0,    20,    24,    23,
       0,    32,    12,     0,     0,     0,     0,     0,    30,    26,
      31,    34,    35,    37,    38,    39,    40,     0,     0,    71,
       0,     0,     0,    59,    63,     0,    64,    65,     0,     0,
      61,     0,     0,     0,    28,     0,     0,     0,     0,    33,
      36,     0,    73,     0,    70,     0,    58,    57,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,    32,     0,     0,    17,    41,    68,
       0,     0,    71,    60,    71,    62,    56,    55,    52,    53,
      48,    49,    50,    51,    54,     0,     0,     0,    25,    27,
      29,    72,     0,     0,     0,    43,    45,     0,    42,    69,
      67,     0,     0,     0,     0,     0,     0,    44,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    15,    16,    17,    18,    19,
      26,    27,    28,    40,    48,    75,    77,    49,    50,    51,
      52,    53,    54,    55,    56,    82,    70,    83,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
      -9,   -21,    13,    -9,   -43,   -43,    20,    91,   -43,   -43,
      30,   -43,    31,   -43,   -43,    48,    53,   -43,    72,   -43,
      81,   -43,    66,    31,   -43,    71,    76,    79,   -43,    91,
     130,    82,    81,   -43,   -43,   -43,    88,   -43,   -43,   -43,
      85,   203,     4,   184,   184,   184,    89,   106,   132,   -43,
     -43,   175,   -43,   -43,   -43,   -43,   -43,   101,   184,   184,
     140,   184,   184,   -22,   -43,   141,   -43,   -43,   184,    34,
     -43,    19,    78,   175,   -43,   -15,   184,   119,     4,   -43,
     -43,    87,   176,   123,   131,     0,   -43,   -43,   155,   135,
     118,   184,   184,   184,   184,   184,   184,   184,   184,   -43,
     184,   175,   175,   159,   203,   170,   127,   -43,   -43,   -43,
     184,   184,   184,   164,   184,   -43,   153,    65,   202,   202,
      36,    36,   -43,   -43,   202,   171,   173,   172,   -43,   -43,
     -43,   176,   136,   174,   185,   189,   -43,   188,   -43,   -43,
     -43,   192,   184,   175,   167,   193,   194,   -43,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,   -43,   223,   222,   200,   -24,   -43,   -43,   213,
     -43,   -43,   201,   -43,   128,   -43,   -43,   -43,   -37,   -43,
     -43,   -43,   -43,   -43,   -43,   -42,   -41,   -35,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      57,    69,    71,    72,     1,     6,    35,   111,     7,    59,
      57,    58,    39,     8,    79,    88,    81,    47,   104,    86,
      87,   105,    91,    92,    93,    94,    90,    95,    96,    97,
      98,   112,    57,    10,   106,    59,   103,    91,    92,    93,
      94,    60,    95,    96,    97,    98,    97,    98,   101,   116,
     117,   118,   119,   120,   121,   122,   123,   100,   124,     7,
      57,    57,    20,    57,   125,   126,    22,    99,   131,   132,
      93,    94,   100,    95,    96,    97,    98,   133,    21,   134,
      47,    91,    92,    93,    94,    23,    95,    96,    97,    98,
      91,    92,    93,    94,    25,    95,    96,    97,    98,    29,
     144,    34,    57,   100,    12,    30,   145,   102,    31,    13,
      14,    38,    13,    14,    41,    32,   100,    36,    73,    74,
     108,    91,    92,    93,    94,   100,    95,    96,    97,    98,
      91,    92,    93,    94,    80,    95,    96,    97,    98,    91,
      92,    93,    94,    34,    95,    96,    97,    98,    76,   107,
     115,    13,    14,    85,    89,   109,   100,    92,    93,    94,
     130,    95,    96,    97,    98,   100,   114,   110,   113,   138,
      91,    92,    93,    94,   100,    95,    96,    97,    98,    91,
      92,    93,    94,   129,    95,    96,    97,    98,    78,   127,
      43,   100,    44,    61,    45,   112,    62,    63,    64,   146,
     137,   135,    46,   136,    65,   100,   139,   141,    66,    67,
      95,    96,    97,    98,   100,    68,    42,   140,    43,   142,
      44,   143,    45,   147,    13,    14,     9,   148,    11,    33,
      46,    24,   128,    37
};

static const yytype_uint8 yycheck[] =
{
      41,    43,    44,    45,    13,    26,    30,     7,    29,    31,
      51,     7,    36,     0,    51,    37,    58,    41,    33,    61,
      62,    36,     3,     4,     5,     6,    68,     8,     9,    10,
      11,    31,    73,    13,    76,    31,    73,     3,     4,     5,
       6,    37,     8,     9,    10,    11,    10,    11,    29,    91,
      92,    93,    94,    95,    96,    97,    98,    38,   100,    29,
     101,   102,    31,   104,   101,   102,    13,    33,   110,   111,
       5,     6,    38,     8,     9,    10,    11,   112,    30,   114,
     104,     3,     4,     5,     6,    13,     8,     9,    10,    11,
       3,     4,     5,     6,    13,     8,     9,    10,    11,    33,
     142,    13,   143,    38,    13,    34,   143,    29,    32,    21,
      22,    23,    21,    22,    29,    36,    38,    35,    29,    13,
      33,     3,     4,     5,     6,    38,     8,     9,    10,    11,
       3,     4,     5,     6,    33,     8,     9,    10,    11,     3,
       4,     5,     6,    13,     8,     9,    10,    11,    16,    30,
      32,    21,    22,    13,    13,    32,    38,     4,     5,     6,
      33,     8,     9,    10,    11,    38,    31,    36,    13,    33,
       3,     4,     5,     6,    38,     8,     9,    10,    11,     3,
       4,     5,     6,    13,     8,     9,    10,    11,    13,    30,
      15,    38,    17,     9,    19,    31,    12,    13,    14,    32,
      28,    30,    27,    30,    20,    38,    32,    18,    24,    25,
       8,     9,    10,    11,    38,    31,    13,    32,    15,    31,
      17,    29,    19,    30,    21,    22,     3,    33,     6,    29,
      27,    18,   104,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    41,    42,    43,    44,    26,    29,     0,    43,
      13,    44,    13,    21,    22,    45,    46,    47,    48,    49,
      31,    30,    13,    13,    49,    13,    50,    51,    52,    33,
      34,    32,    36,    45,    13,    46,    35,    52,    23,    46,
      53,    29,    13,    15,    17,    19,    27,    46,    54,    57,
      58,    59,    60,    61,    62,    63,    64,    66,     7,    31,
      37,     9,    12,    13,    14,    20,    24,    25,    31,    65,
      66,    65,    65,    29,    13,    55,    16,    56,    13,    58,
      33,    65,    65,    67,    68,    13,    65,    65,    37,    13,
      65,     3,     4,     5,     6,     8,     9,    10,    11,    33,
      38,    29,    29,    58,    33,    36,    65,    30,    33,    32,
      36,     7,    31,    13,    31,    32,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    58,    58,    30,    54,    13,
      33,    65,    65,    67,    67,    30,    30,    28,    33,    32,
      32,    18,    31,    29,    65,    58,    32,    30,    33
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
#line 79 "parser.y"
    {astRoot = new ProgramNode((yyvsp[(1) - (1)].class_list_ptr));;}
    break;

  case 3:
#line 82 "parser.y"
    {(yyval.class_list_ptr) = (yyvsp[(1) - (2)].class_list_ptr); (yyval.class_list_ptr) -> push_back((yyvsp[(2) - (2)].class_ptr));;}
    break;

  case 4:
#line 83 "parser.y"
    {(yyval.class_list_ptr) = new std::list<ClassNode*>(); (yyval.class_list_ptr) -> push_front((yyvsp[(1) - (1)].class_ptr));;}
    break;

  case 5:
#line 86 "parser.y"
    {(yyval.class_ptr) = new ClassNode(new IdentifierNode(ClassName), NULL, DeclarationNodeList2, MethodNodeList); DeclarationNodeList2 = new std::list<DeclarationNode*>();;}
    break;

  case 6:
#line 87 "parser.y"
    {(yyval.class_ptr) = new ClassNode(new IdentifierNode((yyvsp[(1) - (3)].base_char_ptr)), new IdentifierNode(ClassName), DeclarationNodeList2, MethodNodeList);DeclarationNodeList2 = new std::list<DeclarationNode*>();;}
    break;

  case 7:
#line 90 "parser.y"
    {ClassName = (yyvsp[(1) - (4)].base_char_ptr);;}
    break;

  case 8:
#line 93 "parser.y"
    {std::list<IdentifierNode*>* temp = new std::list<IdentifierNode*>(); temp -> push_front(new IdentifierNode((yyvsp[(2) - (4)].base_char_ptr))); ;DeclarationNodeList2 -> push_front(new DeclarationNode((yyvsp[(1) - (4)].type_ptr), temp));;}
    break;

  case 9:
#line 94 "parser.y"
    {MethodNodeList = (yyvsp[(1) - (1)].method_list_ptr);;}
    break;

  case 10:
#line 97 "parser.y"
    {(yyval.type_ptr) = new IntegerTypeNode();;}
    break;

  case 11:
#line 98 "parser.y"
    {(yyval.type_ptr) = new BooleanTypeNode();;}
    break;

  case 12:
#line 99 "parser.y"
    {(yyval.type_ptr) = new ObjectTypeNode(new IdentifierNode((yyvsp[(1) - (1)].base_char_ptr)));;}
    break;

  case 13:
#line 102 "parser.y"
    {(yyval.method_list_ptr) = (yyvsp[(1) - (1)].method_list_ptr);;}
    break;

  case 14:
#line 103 "parser.y"
    {(yyval.method_list_ptr) = new std::list<MethodNode*>();;}
    break;

  case 15:
#line 106 "parser.y"
    {(yyval.method_list_ptr) = (yyvsp[(1) - (2)].method_list_ptr); (yyval.method_list_ptr) -> push_back((yyvsp[(2) - (2)].method_ptr));;}
    break;

  case 16:
#line 107 "parser.y"
    {(yyval.method_list_ptr) = new std::list<MethodNode*>(); (yyval.method_list_ptr) -> push_front((yyvsp[(1) - (1)].method_ptr));;}
    break;

  case 17:
#line 110 "parser.y"
    {(yyval.method_ptr) = new MethodNode(new IdentifierNode((yyvsp[(1) - (10)].base_char_ptr)),(yyvsp[(3) - (10)].parameter_list_ptr),(yyvsp[(6) - (10)].type_ptr), new MethodBodyNode(DeclarationNodeList,StatementNodeList,(yyvsp[(9) - (10)].returnstatement_ptr)));DeclarationNodeList = new std::list<DeclarationNode*>();;}
    break;

  case 18:
#line 113 "parser.y"
    {(yyval.parameter_list_ptr) = (yyvsp[(1) - (1)].parameter_list_ptr);;}
    break;

  case 19:
#line 114 "parser.y"
    {(yyval.parameter_list_ptr) = new std::list<ParameterNode*>();;}
    break;

  case 20:
#line 117 "parser.y"
    {(yyval.parameter_list_ptr) = (yyvsp[(1) - (3)].parameter_list_ptr); (yyval.parameter_list_ptr) -> push_back((yyvsp[(3) - (3)].parameter_ptr));;}
    break;

  case 21:
#line 118 "parser.y"
    {(yyval.parameter_list_ptr) = new std::list<ParameterNode*>(); (yyval.parameter_list_ptr) -> push_front((yyvsp[(1) - (1)].parameter_ptr));;}
    break;

  case 22:
#line 121 "parser.y"
    {(yyval.parameter_ptr) = new ParameterNode((yyvsp[(3) - (3)].type_ptr), new IdentifierNode((yyvsp[(1) - (3)].base_char_ptr)));;}
    break;

  case 23:
#line 123 "parser.y"
    {(yyval.type_ptr) = (yyvsp[(1) - (1)].type_ptr);;}
    break;

  case 24:
#line 124 "parser.y"
    {(yyval.type_ptr) = new NoneNode();;}
    break;

  case 25:
#line 127 "parser.y"
    {DeclarationNodeList -> push_front(new DeclarationNode((yyvsp[(1) - (4)].type_ptr), (yyvsp[(2) - (4)].identifier_list_ptr)));;}
    break;

  case 26:
#line 128 "parser.y"
    {StatementNodeList = (yyvsp[(1) - (1)].statement_list_ptr);;}
    break;

  case 27:
#line 131 "parser.y"
    {(yyval.identifier_list_ptr) = (yyvsp[(1) - (3)].identifier_list_ptr); (yyval.identifier_list_ptr) -> push_back(new IdentifierNode((yyvsp[(3) - (3)].base_char_ptr)));;}
    break;

  case 28:
#line 132 "parser.y"
    {(yyval.identifier_list_ptr) = new std::list<IdentifierNode*>(); (yyval.identifier_list_ptr) -> push_front(new IdentifierNode((yyvsp[(1) - (1)].base_char_ptr)));;}
    break;

  case 29:
#line 135 "parser.y"
    {(yyval.returnstatement_ptr) = new ReturnStatementNode((yyvsp[(2) - (3)].expression_ptr));;}
    break;

  case 30:
#line 136 "parser.y"
    {(yyval.returnstatement_ptr) = NULL;;}
    break;

  case 31:
#line 141 "parser.y"
    {(yyval.statement_list_ptr) = (yyvsp[(1) - (1)].statement_list_ptr);;}
    break;

  case 32:
#line 142 "parser.y"
    {(yyval.statement_list_ptr) = new std::list<StatementNode*>();;}
    break;

  case 33:
#line 145 "parser.y"
    {(yyval.statement_list_ptr) = (yyvsp[(2) - (2)].statement_list_ptr); (yyval.statement_list_ptr) -> push_front((yyvsp[(1) - (2)].statement_ptr));;}
    break;

  case 34:
#line 146 "parser.y"
    {(yyval.statement_list_ptr) = new std::list<StatementNode*>(); (yyval.statement_list_ptr) -> push_back((yyvsp[(1) - (1)].statement_ptr));;}
    break;

  case 35:
#line 149 "parser.y"
    {(yyval.statement_ptr) = (yyvsp[(1) - (1)].assignment_ptr);;}
    break;

  case 36:
#line 150 "parser.y"
    {(yyval.statement_ptr) = new CallNode((yyvsp[(1) - (2)].methodcall_ptr));;}
    break;

  case 37:
#line 151 "parser.y"
    {(yyval.statement_ptr) = (yyvsp[(1) - (1)].ifelse_ptr);;}
    break;

  case 38:
#line 152 "parser.y"
    {(yyval.statement_ptr) = (yyvsp[(1) - (1)].while_ptr);;}
    break;

  case 39:
#line 153 "parser.y"
    {(yyval.statement_ptr) = (yyvsp[(1) - (1)].repeat_ptr);;}
    break;

  case 40:
#line 154 "parser.y"
    {(yyval.statement_ptr) = (yyvsp[(1) - (1)].print_ptr);;}
    break;

  case 41:
#line 157 "parser.y"
    {(yyval.assignment_ptr) = new AssignmentNode(new IdentifierNode((yyvsp[(1) - (4)].base_char_ptr)),NULL,(yyvsp[(3) - (4)].expression_ptr));;}
    break;

  case 42:
#line 158 "parser.y"
    {(yyval.assignment_ptr) = new AssignmentNode(new IdentifierNode((yyvsp[(1) - (6)].base_char_ptr)),new IdentifierNode((yyvsp[(3) - (6)].base_char_ptr)),(yyvsp[(5) - (6)].expression_ptr));;}
    break;

  case 43:
#line 161 "parser.y"
    {(yyval.ifelse_ptr) = new IfElseNode((yyvsp[(2) - (5)].expression_ptr),(yyvsp[(4) - (5)].statement_list_ptr),NULL);;}
    break;

  case 44:
#line 162 "parser.y"
    {(yyval.ifelse_ptr) = new IfElseNode((yyvsp[(2) - (9)].expression_ptr),(yyvsp[(4) - (9)].statement_list_ptr),(yyvsp[(8) - (9)].statement_list_ptr));;}
    break;

  case 45:
#line 165 "parser.y"
    {(yyval.while_ptr) = new WhileNode((yyvsp[(2) - (5)].expression_ptr),(yyvsp[(4) - (5)].statement_list_ptr));;}
    break;

  case 46:
#line 167 "parser.y"
    {(yyval.repeat_ptr) = new RepeatNode((yyvsp[(3) - (9)].statement_list_ptr), (yyvsp[(7) - (9)].expression_ptr));;}
    break;

  case 47:
#line 169 "parser.y"
    {(yyval.print_ptr) = new PrintNode((yyvsp[(2) - (3)].expression_ptr));;}
    break;

  case 48:
#line 171 "parser.y"
    {(yyval.expression_ptr) = new PlusNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 49:
#line 172 "parser.y"
    {(yyval.expression_ptr) = new MinusNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 50:
#line 173 "parser.y"
    {(yyval.expression_ptr) = new TimesNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 51:
#line 174 "parser.y"
    {(yyval.expression_ptr) = new DivideNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 52:
#line 175 "parser.y"
    {(yyval.expression_ptr) = new LessNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 53:
#line 176 "parser.y"
    {(yyval.expression_ptr) = new LessEqualNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 54:
#line 177 "parser.y"
    {(yyval.expression_ptr) = new EqualNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 55:
#line 178 "parser.y"
    {(yyval.expression_ptr) = new AndNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 56:
#line 179 "parser.y"
    {(yyval.expression_ptr) = new OrNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 57:
#line 180 "parser.y"
    {(yyval.expression_ptr) = new NotNode((yyvsp[(2) - (2)].expression_ptr));;}
    break;

  case 58:
#line 181 "parser.y"
    {(yyval.expression_ptr) = new NegationNode((yyvsp[(2) - (2)].expression_ptr));;}
    break;

  case 59:
#line 182 "parser.y"
    {(yyval.expression_ptr) = new VariableNode(new IdentifierNode((yyvsp[(1) - (1)].base_char_ptr)));;}
    break;

  case 60:
#line 183 "parser.y"
    {(yyval.expression_ptr) = new MemberAccessNode(new IdentifierNode((yyvsp[(1) - (3)].base_char_ptr)),new IdentifierNode((yyvsp[(3) - (3)].base_char_ptr)));;}
    break;

  case 61:
#line 184 "parser.y"
    {(yyval.expression_ptr) = (yyvsp[(1) - (1)].methodcall_ptr);;}
    break;

  case 62:
#line 185 "parser.y"
    {(yyval.expression_ptr) = (yyvsp[(2) - (3)].expression_ptr);;}
    break;

  case 63:
#line 186 "parser.y"
    {(yyval.expression_ptr) = new IntegerLiteralNode(new IntegerNode((yyvsp[(1) - (1)].base_int)));;}
    break;

  case 64:
#line 187 "parser.y"
    {(yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(1));;}
    break;

  case 65:
#line 188 "parser.y"
    {(yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(0));;}
    break;

  case 66:
#line 189 "parser.y"
    {(yyval.expression_ptr) = new NewNode(new IdentifierNode((yyvsp[(2) - (2)].base_char_ptr)), NULL);;}
    break;

  case 67:
#line 190 "parser.y"
    {(yyval.expression_ptr) = new NewNode(new IdentifierNode((yyvsp[(2) - (5)].base_char_ptr)), (yyvsp[(4) - (5)].expression_list_ptr));;}
    break;

  case 68:
#line 193 "parser.y"
    {(yyval.methodcall_ptr) = new MethodCallNode(new IdentifierNode((yyvsp[(1) - (4)].base_char_ptr)),NULL,(yyvsp[(3) - (4)].expression_list_ptr));;}
    break;

  case 69:
#line 194 "parser.y"
    {(yyval.methodcall_ptr) = new MethodCallNode(new IdentifierNode((yyvsp[(1) - (6)].base_char_ptr)),new IdentifierNode((yyvsp[(3) - (6)].base_char_ptr)),(yyvsp[(5) - (6)].expression_list_ptr));;}
    break;

  case 70:
#line 197 "parser.y"
    {(yyval.expression_list_ptr) = (yyvsp[(1) - (1)].expression_list_ptr);;}
    break;

  case 71:
#line 198 "parser.y"
    {(yyval.expression_list_ptr) = new std::list<ExpressionNode*>();;}
    break;

  case 72:
#line 201 "parser.y"
    {(yyval.expression_list_ptr) = (yyvsp[(1) - (3)].expression_list_ptr); (yyval.expression_list_ptr) -> push_back((yyvsp[(3) - (3)].expression_ptr));;}
    break;

  case 73:
#line 202 "parser.y"
    {(yyval.expression_list_ptr) = new std::list<ExpressionNode*>(); (yyval.expression_list_ptr) -> push_front((yyvsp[(1) - (1)].expression_ptr));;}
    break;


/* Line 1267 of yacc.c.  */
#line 1907 "parser.cpp"
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


#line 205 "parser.y"


extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}
