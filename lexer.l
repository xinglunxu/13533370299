%option yylineno
%pointer

%{
    #include <stdlib.h>
    #include <errno.h>
    #include <limits.h>
    #include "ast.hpp"
    #include "parser.hpp"
    void yyerror(const char *);
%}

DIGIT       [1-9][0-9]*
ID          [a-zA-Z][a-zA-Z0-9]*
WS          [ \t\s\n\r]+

%%

"/*"               {
                     register int c;
     
                     for ( ; ; )
                         {
                         while ( (c = yyinput()) != '*' &&
                                 c != EOF )
                             ;    /* eat up text of comment */
     
                         if ( c == '*' )
                             {
                             while ( (c = yyinput()) == '*' )
                                 ;
                             if ( c == '/' )
                                 break;    /* found the end */
                             }
     
                         if ( c == EOF )
                             {
                             yyerror( "EOF in comment" );
                             break;
                             }
                         }
                     }

"+"                     { return T_PLUS; }
"-"                     { return T_MINUS; }
"*"                     { return T_MULTIPLY; }
"/"                     { return T_DIVIDE; }
"<="                    { return T_LESSTHANOREQUAL; }
"<"                     { return T_LESSTHAN; }
"="                     { return T_EQUALS; }
"equals"                { return T_EQUALS; }
"&&"                    { return T_AND; }
"and"                   { return T_AND; }
"or"                    { return T_OR; }
"||"                    { return T_OR; }
"!"                     { return T_NOT; }
"not"                   { return T_NOT; }
"("                     { return T_OPENPAREN; }
")"                     { return T_CLOSEPAREN; }
"{"                     { return T_OPENBRACE; }
"}"                     { return T_CLOSEBRACE; }
"."                     { return T_DOT; }
","                     { return T_COMMA; }
":"                     { return T_COLON; }
";"                     { return T_SEMICOLON; }
"->"                    { return T_ARROW; }
"print"                 { return T_PRINT; }
"return"                { return T_RETURN; }
"if"                    { return T_IF; }
"else"                  { return T_ELSE; }
"while"                 { return T_WHILE; }
"new"                   { return T_NEW; }
"integer"               { return T_INT; }
"boolean"               { return T_BOOL; }
"none"                  { return T_NONE; }
"true"                  { return T_TRUE; }
"false"                 { return T_FALSE; }
"extends"               { return T_EXTENDS; }
"repeat"                { return T_REPEAT; }
"until"                 { return T_UNTIL; }
0|{DIGIT}               { yylval.base_int = atoi(yytext); return T_INTLITERAL; }
{ID}                    { yylval.base_char_ptr = strdup(yytext); return T_IDENTIFIER; }
{WS}                    ;

.                 { yyerror("invalid character"); }

%%

int yywrap(void) {
  return 1;
}
