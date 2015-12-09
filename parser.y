%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    #include "ast.hpp"
    #define YYINITDEPTH 500 
    #define YYDEBUG 1
    int yylex(void);
    void yyerror(const char *);
    
    extern ASTNode* astRoot;
%}

%error-verbose

/* WRITEME: Copy your token and precedence specifiers from Project 3 here */
%token T_DIVIDE T_MULTIPLY T_MINUS T_PLUS T_LESSTHANOREQUAL T_LESSTHAN T_DOT
%token T_AND T_OR T_NOT T_OPENPAREN T_CLOSEPAREN T_OPENBRACE T_CLOSEBRACE
%token T_SEMICOLON T_INTLITERAL T_ARROW T_COMMA T_COLON T_PRINT T_RETURN
%token T_IF T_ELSE T_WHILE T_NEW T_INT T_BOOL T_NONE T_EQUALS 
%token T_TRUE T_FALSE T_EXTENDS T_REPEAT T_UNTIL T_IDENTIFIER

%left T_OR 
%left T_AND 
%left T_LESSTHAN T_LESSTHANOREQUAL T_EQUALS
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE
%right T_NOT

/* WRITEME: Specify types for all nonterminals and necessary terminals here */
%type <program_ptr> Start
%type <class_list_ptr> Classes
%type <class_ptr> Class
%type <identifier_ptr> Extend
%type <declaration_list_ptr> Members
%type <declaration_ptr> Member
%type <identifier_list_ptr> ID
%type <method_list_ptr> Methods
%type <method_ptr> Method
%type <type_ptr> Type
%type <type_ptr> ReturnType
%type <parameter_list_ptr> Parameters
%type <methodbody_ptr> Body
%type <declaration_list_ptr> DeclarationsList
%type <declaration_ptr> Declaration
%type <identifier_list_ptr> Identifiers
%type <statement_list_ptr> StatementsBody
%type <returnstatement_ptr> ReturnStatement
%type <statement_ptr> Statements
%type <assignment_ptr> Assignment
%type <methodcall_ptr> Call
%type <ifelse_ptr> IfElse
%type <while_ptr> WhileLoop
%type <repeat_ptr> RepeatUntil
%type <print_ptr> Print
%type <statement_list_ptr> Block
%type <expression_list_ptr> Arguments
%type <expression_ptr> Expr
%type <base_char_ptr> T_IDENTIFIER
%type <none_ptr> T_NONE
%type <base_int> T_INTLITERAL
%type <booleanliteral_ptr> T_TRUE
%type <booleanliteral_ptr> T_FALSE
%type <integertype_ptr> T_INT
%type <booleantype_ptr> T_BOOL


%%

/* WRITEME: This rule is a placeholder. Replace it with your grammar
            rules from Project 3 */

Start : Classes                                                                          { astRoot = new ProgramNode($1); }
      ;

Classes : Classes Class                                                                  { $$ = $1; $$ -> push_back($2); }
        | Class                                                                          { $$ = new std::list<ClassNode*>(); $$ -> push_back($1);}
        ;

Class : T_IDENTIFIER Extend T_OPENBRACE Members Methods T_CLOSEBRACE                     { $$ = new ClassNode(new IdentifierNode($1), $2, $4, $5); }
      ;

Extend : T_EXTENDS T_IDENTIFIER                                                          { $$ = new IdentifierNode($2); }
       |                                                                                 { $$ = NULL; }
       ;

Members : Members Member                                                                 { $$ = $1; $$ -> push_back($2); }
        |                                                                                { $$ = new std::list<DeclarationNode*>(); }
        ;

Member : Type ID T_SEMICOLON                                                             { $$ = new DeclarationNode($1, $2); }
       ;

ID : T_IDENTIFIER                                                                        { $$ = new std::list<IdentifierNode*>(); $$ -> push_back(new IdentifierNode($1)); }
   ;

Methods : Method Methods                                                                 { $$ = $2; $$ -> push_front($1);}
        |                                                                                { $$ = new std::list<MethodNode*>(); }
        ;

Method : T_IDENTIFIER T_OPENPAREN Parameters T_CLOSEPAREN T_ARROW ReturnType T_OPENBRACE Body T_CLOSEBRACE  { $$ = new MethodNode(new IdentifierNode($1), $3, $6, $8); }
       ;

ReturnType : T_INT                                                                       { $$ = new IntegerTypeNode(); }
           | T_BOOL                                                                      { $$ = new BooleanTypeNode(); }
           | T_IDENTIFIER                                                                { $$ = new ObjectTypeNode(new IdentifierNode($1)); }
           | T_NONE                                                                      { $$ = new NoneNode(); }
           ;

Type : T_INT                                                                             { $$ = new IntegerTypeNode(); }
     | T_BOOL                                                                            { $$ = new BooleanTypeNode(); }
     | T_IDENTIFIER                                                                      { $$ = new ObjectTypeNode(new IdentifierNode($1)); }
     ;


Parameters : Parameters T_COMMA T_IDENTIFIER T_COLON Type                                { $$ = $1; $$ -> push_back(new ParameterNode($5,new IdentifierNode($3)));}
           | T_IDENTIFIER T_COLON Type                                                   { $$ = new std::list<ParameterNode*>; $$ -> push_back(new ParameterNode($3,new IdentifierNode($1))); }
           |                                                                             { $$ = new std::list<ParameterNode*>; }
           ;

Body : DeclarationsList StatementsBody ReturnStatement                                   { $$ = new MethodBodyNode($1,$2,$3); }
     ;

DeclarationsList : DeclarationsList Declaration T_SEMICOLON                              { $$ = $1; $$ -> push_back($2); }
                 |                                                                       { $$ = new std::list<DeclarationNode*>(); }
                 ;

Declaration : Type Identifiers                                                           { $$ = new DeclarationNode($1,$2); }
            ;

Identifiers : T_IDENTIFIER T_COMMA Identifiers                                           { $$ = $3; $$ -> push_front(new IdentifierNode($1)); }
            | T_IDENTIFIER                                                               { $$ = new std::list<IdentifierNode*>(); $$ -> push_back(new IdentifierNode($1)); }
            ;

StatementsBody : Statements StatementsBody                                               { $$ = $2; $$ -> push_front($1); }
               |                                                                         { $$ = new std::list<StatementNode*>(); }
               ;

ReturnStatement : T_RETURN Expr T_SEMICOLON                                              { $$ = new ReturnStatementNode($2); }
                |                                                                        { $$ = NULL; }
                ;

Statements : Assignment                                                                  { $$ = $1; }
           | Call T_SEMICOLON                                                            { $$ = new CallNode($1); }
           | IfElse                                                                      { $$ = $1; }
           | WhileLoop                                                                   { $$ = $1; }
           | RepeatUntil                                                                 { $$ = $1; }
           | Print                                                                       { $$ = $1; }
           ;

Assignment : T_IDENTIFIER T_EQUALS Expr T_SEMICOLON                                      { $$ = new AssignmentNode(new IdentifierNode($1),NULL,$3); }
           | T_IDENTIFIER T_DOT T_IDENTIFIER T_EQUALS Expr T_SEMICOLON                   { $$ = new AssignmentNode(new IdentifierNode($1),new IdentifierNode($3),$5); }
           ;

Call : T_IDENTIFIER T_OPENPAREN Arguments T_CLOSEPAREN                                   { $$ = new MethodCallNode(new IdentifierNode($1),NULL,$3); }
     | T_IDENTIFIER T_DOT T_IDENTIFIER T_OPENPAREN Arguments T_CLOSEPAREN                { $$ = new MethodCallNode(new IdentifierNode($1),new IdentifierNode($3),$5); }
     ;


IfElse : T_IF Expr T_OPENBRACE Block T_CLOSEBRACE                                        { $$ = new IfElseNode($2,$4,NULL);}
       | T_IF Expr T_OPENBRACE Block T_CLOSEBRACE T_ELSE T_OPENBRACE Block T_CLOSEBRACE  { $$ = new IfElseNode($2,$4,$8);}
       ;

WhileLoop : T_WHILE Expr T_OPENBRACE Block T_CLOSEBRACE                                  { $$ = new WhileNode($2,$4); }
          ;

RepeatUntil : T_REPEAT T_OPENBRACE Block T_CLOSEBRACE T_UNTIL T_OPENPAREN Expr T_CLOSEPAREN T_SEMICOLON { $$ = new RepeatNode($3,$7); }
            ;

Print : T_PRINT Expr T_SEMICOLON                                                         { $$ = new PrintNode($2); }
      ;


Block : Statements StatementsBody                                                        { $$ = $2; $$ -> push_front($1); }
      ;


Arguments : Arguments T_COMMA Expr                                                       { $$ = $1; $$ -> push_back($3); }
          | Expr                                                                         { $$ = new std::list<ExpressionNode*>(); $$ -> push_back($1); }
          |                                                                              { $$ = new std::list<ExpressionNode*>(); }
          ;

Expr : Expr T_PLUS Expr                                                                  { $$ = new PlusNode($1, $3); }
     | Expr T_MINUS Expr                                                                 { $$ = new MinusNode($1, $3); }
     | Expr T_MULTIPLY Expr                                                              { $$ = new TimesNode($1, $3); }
     | Expr T_DIVIDE Expr                                                                { $$ = new DivideNode($1, $3); }
     | Expr T_LESSTHAN Expr                                                              { $$ = new LessNode($1, $3); }
     | Expr T_LESSTHANOREQUAL Expr                                                       { $$ = new LessEqualNode($1, $3); }
     | Expr T_EQUALS Expr                                                                { $$ = new EqualNode($1, $3); }
     | Expr T_AND Expr                                                                   { $$ = new AndNode($1, $3); }
     | Expr T_OR Expr                                                                    { $$ = new OrNode($1, $3); }
     | T_NOT Expr                                                                        { $$ = new NotNode($2); }
     | T_MINUS Expr %prec T_NOT                                                          { $$ = new NegationNode($2); }
     | T_IDENTIFIER                                                                      { $$ = new VariableNode(new IdentifierNode($1)); }
     | T_INTLITERAL                                                                      { $$ = new IntegerLiteralNode(new IntegerNode($1)); }
     | T_IDENTIFIER T_DOT T_IDENTIFIER                                                   { $$ = new MemberAccessNode(new IdentifierNode($1), new IdentifierNode($3)); }
     | Call                                                                              { $$ = $1; }
     | T_OPENPAREN Expr T_CLOSEPAREN                                                     { $$ = $2; }
     | T_TRUE                                                                            { $$ = new BooleanLiteralNode(new IntegerNode(1)); }
     | T_FALSE                                                                           { $$ = new BooleanLiteralNode (new IntegerNode(0)); }
     | T_NEW T_IDENTIFIER T_OPENPAREN Arguments T_CLOSEPAREN                             { $$ = new NewNode(new IdentifierNode($2), $4); }
     | T_NEW T_IDENTIFIER                                                                { $$ = new NewNode(new IdentifierNode($2), NULL); }
     ;


%%

extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}
