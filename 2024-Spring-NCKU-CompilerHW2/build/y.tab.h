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
     COUT = 258,
     SHR = 259,
     SHL = 260,
     BAN = 261,
     BOR = 262,
     BNT = 263,
     BXO = 264,
     ADD = 265,
     SUB = 266,
     MUL = 267,
     DIV = 268,
     REM = 269,
     NOT = 270,
     GTR = 271,
     LES = 272,
     GEQ = 273,
     LEQ = 274,
     EQL = 275,
     NEQ = 276,
     LAN = 277,
     LOR = 278,
     VAL_ASSIGN = 279,
     ADD_ASSIGN = 280,
     SUB_ASSIGN = 281,
     MUL_ASSIGN = 282,
     DIV_ASSIGN = 283,
     REM_ASSIGN = 284,
     BAN_ASSIGN = 285,
     BOR_ASSIGN = 286,
     BXO_ASSIGN = 287,
     SHR_ASSIGN = 288,
     SHL_ASSIGN = 289,
     INC_ASSIGN = 290,
     DEC_ASSIGN = 291,
     IF = 292,
     ELSE = 293,
     FOR = 294,
     WHILE = 295,
     RETURN = 296,
     BREAK = 297,
     CONTINUE = 298,
     VARIABLE_T = 299,
     IDENT = 300,
     INT_LIT = 301,
     FLOAT_LIT = 302,
     BOOL_LIT = 303,
     STR_LIT = 304
   };
#endif
/* Tokens.  */
#define COUT 258
#define SHR 259
#define SHL 260
#define BAN 261
#define BOR 262
#define BNT 263
#define BXO 264
#define ADD 265
#define SUB 266
#define MUL 267
#define DIV 268
#define REM 269
#define NOT 270
#define GTR 271
#define LES 272
#define GEQ 273
#define LEQ 274
#define EQL 275
#define NEQ 276
#define LAN 277
#define LOR 278
#define VAL_ASSIGN 279
#define ADD_ASSIGN 280
#define SUB_ASSIGN 281
#define MUL_ASSIGN 282
#define DIV_ASSIGN 283
#define REM_ASSIGN 284
#define BAN_ASSIGN 285
#define BOR_ASSIGN 286
#define BXO_ASSIGN 287
#define SHR_ASSIGN 288
#define SHL_ASSIGN 289
#define INC_ASSIGN 290
#define DEC_ASSIGN 291
#define IF 292
#define ELSE 293
#define FOR 294
#define WHILE 295
#define RETURN 296
#define BREAK 297
#define CONTINUE 298
#define VARIABLE_T 299
#define IDENT 300
#define INT_LIT 301
#define FLOAT_LIT 302
#define BOOL_LIT 303
#define STR_LIT 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 12 "./compiler.y"
{
    ObjectType var_type;

    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val;
}
/* Line 1529 of yacc.c.  */
#line 158 "./build/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

