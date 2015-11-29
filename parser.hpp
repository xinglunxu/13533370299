/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

