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

#ifndef YY_YY_D_FAKS_DIPLOMSKI_SQL_ENGINE_SQL_ENGINE_PARSER_H_INCLUDED
# define YY_YY_D_FAKS_DIPLOMSKI_SQL_ENGINE_SQL_ENGINE_PARSER_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING_VALUE = 259,            /* STRING_VALUE  */
    INT_VALUE = 260,               /* INT_VALUE  */
    BOOL_VALUE = 261,              /* BOOL_VALUE  */
    CREATE = 262,                  /* CREATE  */
    TABLE = 263,                   /* TABLE  */
    INSERT = 264,                  /* INSERT  */
    INTO = 265,                    /* INTO  */
    SELECT = 266,                  /* SELECT  */
    FROM = 267,                    /* FROM  */
    WHERE = 268,                   /* WHERE  */
    GROUP = 269,                   /* GROUP  */
    BY = 270,                      /* BY  */
    ORDER = 271,                   /* ORDER  */
    DROP = 272,                    /* DROP  */
    MIN = 273,                     /* MIN  */
    MAX = 274,                     /* MAX  */
    SUM = 275,                     /* SUM  */
    COUNT = 276,                   /* COUNT  */
    TOP = 277,                     /* TOP  */
    INT32 = 278,                   /* INT32  */
    STRING = 279,                  /* STRING  */
    BOOL = 280,                    /* BOOL  */
    EQ = 281,                      /* EQ  */
    GT = 282,                      /* GT  */
    GE = 283,                      /* GE  */
    LT = 284,                      /* LT  */
    LE = 285,                      /* LE  */
    NE = 286,                      /* NE  */
    STAR = 287,                    /* STAR  */
    LPAREN = 288,                  /* LPAREN  */
    RPAREN = 289,                  /* RPAREN  */
    COMMA = 290                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "D:\\FAKS\\DIPLOMSKI\\sql_engine\\sql_engine\\parser.y"

    int intval;
    char *strval;
    int boolval;

#line 105 "D:\\FAKS\\DIPLOMSKI\\sql_engine\\sql_engine\\parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_D_FAKS_DIPLOMSKI_SQL_ENGINE_SQL_ENGINE_PARSER_H_INCLUDED  */
