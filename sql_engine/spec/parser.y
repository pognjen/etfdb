%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%union {
    int intval;
    char *strval;
    int boolval;
}

%token <strval> IDENTIFIER STRING_VALUE
%token <intval> INT_VALUE
%token <boolval> BOOL_VALUE
%token CREATE TABLE INSERT INTO SELECT FROM WHERE GROUP BY ORDER DROP MIN MAX SUM COUNT TOP INT32 STRING BOOL EQ GT GE LT LE NE STAR LPAREN RPAREN COMMA

%type <strval> table_name column_name

%start sql_statement

%define parse.error verbose

%%

sql_statement:
    create_table_statement
    | insert_into_statement
    | select_statement
    | drop_table_statement
    ;

create_table_statement:
    CREATE TABLE table_name LPAREN column_definition_list RPAREN
    ;

column_definition_list:
    column_definition
    | column_definition_list COMMA column_definition
    ;

column_definition:
    column_name data_type
    ;

data_type:
    INT32
    | STRING
    | BOOL
    ;

insert_into_statement:
    INSERT INTO table_name LPAREN value_list RPAREN
    ;

value_list:
    value
    | value_list COMMA value
    ;

value:
    INT_VALUE
    | STRING_VALUE
    | BOOL_VALUE
    ;

select_statement:
    SELECT select_body FROM table_name opt_where_clause opt_group_by_clause opt_order_by_clause
    ;

select_body:
    TOP INT_VALUE select_items
    | select_items
    ;

select_items:
    STAR
    | select_item
    | select_items COMMA select_item
    ;

select_item:
    column_name
    | aggregate_function
    ;

aggregate_function:
    MIN LPAREN column_name RPAREN
    | MAX LPAREN column_name RPAREN
    | SUM LPAREN column_name RPAREN
    | COUNT LPAREN column_name RPAREN
    | COUNT LPAREN STAR RPAREN
    ;

opt_where_clause:
    /* empty */
    | WHERE condition
    ;

condition:
    column_name operator literal
    ;

operator:
    EQ
    | GT
    | GE
    | LT
    | LE
    | NE
    ;

literal:
    INT_VALUE
    | STRING_VALUE
    | BOOL_VALUE
    ;

opt_group_by_clause:
    /* empty */
    | GROUP BY column_name
    ;

opt_order_by_clause:
    /* empty */
    | ORDER BY column_name
    ;

drop_table_statement:
    DROP TABLE table_name
    ;

table_name:
    IDENTIFIER
    ;

column_name:
    IDENTIFIER
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parsing error: %s\n", s);
}
