/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    EOL = 259,
    SYM_PRNL = 260,
    SYM_PRNR = 261,
    SYM_COMMA = 262,
    FUNC_L = 263,
    FUNC_R = 264,
    FUNC_ABS = 265,
    FUNC_SIN = 266,
    FUNC_COS = 267,
    FUNC_TAN = 268,
    FUNC_COT = 269,
    FUNC_SEC = 270,
    FUNC_CSC = 271,
    FUNC_SQRT = 272,
    FUNC_CEIL = 273,
    FUNC_FLOOR = 274,
    FUNC_LOG = 275,
    FUNC_LOG10 = 276,
    FUNC_LOG7 = 277,
    FUNC_LOG5 = 278,
    FUNC_LOG3 = 279,
    FUNC_LOG2 = 280,
    FUNC_LN = 281,
    CMD_EXT = 282,
    OP_ADD = 283,
    OP_SUB = 284,
    OP_MUL = 285,
    OP_DIV = 286,
    OP_POW = 287
  };
#endif
/* Tokens.  */
#define NUM 258
#define EOL 259
#define SYM_PRNL 260
#define SYM_PRNR 261
#define SYM_COMMA 262
#define FUNC_L 263
#define FUNC_R 264
#define FUNC_ABS 265
#define FUNC_SIN 266
#define FUNC_COS 267
#define FUNC_TAN 268
#define FUNC_COT 269
#define FUNC_SEC 270
#define FUNC_CSC 271
#define FUNC_SQRT 272
#define FUNC_CEIL 273
#define FUNC_FLOOR 274
#define FUNC_LOG 275
#define FUNC_LOG10 276
#define FUNC_LOG7 277
#define FUNC_LOG5 278
#define FUNC_LOG3 279
#define FUNC_LOG2 280
#define FUNC_LN 281
#define CMD_EXT 282
#define OP_ADD 283
#define OP_SUB 284
#define OP_MUL 285
#define OP_DIV 286
#define OP_POW 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
