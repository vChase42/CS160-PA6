/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_PRINT = 258,                 /* T_PRINT  */
    T_RETURN = 259,                /* T_RETURN  */
    T_IF = 260,                    /* T_IF  */
    T_ELSE = 261,                  /* T_ELSE  */
    T_WHILE = 262,                 /* T_WHILE  */
    T_NEW = 263,                   /* T_NEW  */
    T_NONE = 264,                  /* T_NONE  */
    T_EXTENDS = 265,               /* T_EXTENDS  */
    T_DO = 266,                    /* T_DO  */
    T_ARROW = 267,                 /* T_ARROW  */
    T_DOT = 268,                   /* T_DOT  */
    T_COMMA = 269,                 /* T_COMMA  */
    T_METHODNAME = 270,            /* T_METHODNAME  */
    T_LBRACKET = 271,              /* T_LBRACKET  */
    T_RBRACKET = 272,              /* T_RBRACKET  */
    T_QMARK = 273,                 /* T_QMARK  */
    T_COLON = 274,                 /* T_COLON  */
    T_SEMICOLON = 275,             /* T_SEMICOLON  */
    T_OR = 276,                    /* T_OR  */
    T_AND = 277,                   /* T_AND  */
    T_EQUALTO = 278,               /* T_EQUALTO  */
    T_GT = 279,                    /* T_GT  */
    T_GTE = 280,                   /* T_GTE  */
    T_ADD = 281,                   /* T_ADD  */
    T_SUB = 282,                   /* T_SUB  */
    T_DIV = 283,                   /* T_DIV  */
    T_MUL = 284,                   /* T_MUL  */
    T_UNARYMINUS = 285,            /* T_UNARYMINUS  */
    T_NOT = 286,                   /* T_NOT  */
    T_LPAREN = 287,                /* T_LPAREN  */
    T_RPAREN = 288,                /* T_RPAREN  */
    T_ID = 289,                    /* T_ID  */
    T_INT = 290,                   /* T_INT  */
    T_TRUE = 291,                  /* T_TRUE  */
    T_FALSE = 292,                 /* T_FALSE  */
    T_NUM = 293,                   /* T_NUM  */
    T_BOOL = 294,                  /* T_BOOL  */
    T_EQ = 295                     /* T_EQ  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
