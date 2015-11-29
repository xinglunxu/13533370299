%option yylineno
%pointer

%{
    #include <cstdlib>
    #include <cerrno>
    #include <climits>
    #include <limits>
    #include "ast.hpp"
    #include "parser.hpp"
    
	void yyerror(const char *);
%}

/* WRITEME: Write any definitions here. You can find information on
            definitions here:
            http://flex.sourceforge.net/manual/Definitions-Section.html */

/* WRITEME: If you are going to use start conditions, write them here.
            You can find more information on start conditions here:
            http://flex.sourceforge.net/manual/Start-Conditions.html
            You will probably want to use exclusive conditions rather
            than inclusive conditions (use the %x instead of the %s). */

%x COMMENT

%%

  /* WRITEME: Write your Flex token rules here */
[ \n\t]           {}
"print"           {return T_PRINT;}
"return"          {return T_RETURN;}
"if"              {return T_IF;}
"else"            {return T_ELSE;}
"while"           {return T_WHILE;}
"new"             {return T_NEW;}
"integer"         {return T_INTEGER;}
"boolean"         {return T_BOOLEAN;}
"none"            {return T_NONE;}
"equals"          {return T_EQUALSBOOL;}
"and"             {return T_AND;}
"or"              {return T_OR;}
"not"             {return T_NOT;}
"true"            {return T_TRUE;}
"false"           {return T_FALSE;}
"extends"         {return T_EXTENDS;}
"repeat"          {return T_REPEAT;}
"until"           {return T_UNTIL;}
"/*"              {BEGIN(COMMENT);}
<COMMENT>"*/"     {BEGIN(INITIAL);}
<COMMENT>[ \n]    {}
<COMMENT>.        {}
<COMMENT><<EOF>>  {yyerror("invalid character");}
"{"               {return T_OPENBRACKET;}
"}"               {return T_CLOSEDBRACKET;}
"("               {return T_OPENPAREN;}
")"               {return T_CLOSEDPAREN;}
"+"               {return T_PLUS;}
"-"               {return T_MINUS;}
"*"               {return T_MULTIPLY;}
"/"               {return T_DIVIDE;}
"<"               {return T_LESSTHAN;}
"<="              {return T_LESSTHANOREQUAL;}
"="               {return T_EQUALS;}
";"               {return T_SEMI;}
":"               {return T_COLON;}
"->"              {return T_METHODRETURN;}
","               {return T_COMMA;}
"."               {return T_DOT;}
[a-zA-Z][a-zA-Z0-9]*      {yylval.base_char_ptr = strdup(yytext);return T_IDENTIFIER;}
"0"|[1-9][0-9]*       {yylval.base_int = atoi(yytext);return T_INTEGERLITERAL;}
.                 {yyerror("Error produced"); }

%%

int yywrap(void) {
  return 1;
}
