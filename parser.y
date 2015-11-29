%{
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
%}

%error-verbose

/* WRITEME: List all your tokens here */
%token T_OR T_AND T_LESSTHAN T_LESSTHANOREQUAL T_EQUALS 
%token T_PLUS T_MINUS T_MULTIPLY T_DIVIDE T_NOT
%token T_IDENTIFIER T_INTEGERLITERAL T_PRINT T_RETURN T_IF T_ELSE T_WHILE
%token T_NEW T_INTEGER T_BOOLEAN T_NONE  T_TRUE T_FALSE T_EXTENDS T_REPEAT T_UNTIL
%token T_OPENBRACKET T_CLOSEDBRACKET T_OPENPAREN T_CLOSEDPAREN T_SEMI T_COLON
%token T_METHODRETURN T_COMMA T_DOT 
%token T_EQUALSBOOL T_CLASSTYPE

/* WRITEME: Specify precedence here */
%left T_OR
%left T_AND 
%left T_LESSTHAN T_LESSTHANOREQUAL T_EQUALSBOOL
%left T_PLUS T_MINUS
%left T_MULTIPLY T_DIVIDE
%right T_NOT

%type<base_char_ptr> T_IDENTIFIER
%type<base_int> T_INTEGERLITERAL
%type<booleanliteral_ptr> T_TRUE
%type<booleanliteral_ptr> T_FALSE

%type<none_ptr> T_NONE
%type<integertype_ptr> T_INTEGER
%type<booleantype_ptr> T_BOOLEAN


%type<program_ptr> Start
%type<class_list_ptr> CLASS1
%type<class_ptr> CLASS
%type<expression_ptr> EXPRESSION 
%type<expression_list_ptr> ARGUMENTS_ ARGUMENTS
%type<methodcall_ptr> METHODCALL
%type<statement_ptr> STATEMENT
%type<statement_list_ptr> STATEMENTS STATEMENTS1
%type<assignment_ptr> ASSIGNMENT
%type<ifelse_ptr> IFELSE
%type<while_ptr> WHILELOOP
%type<repeat_ptr> REPEATUNTIL
%type<print_ptr> PRINT1
%type<identifier_list_ptr> VARIABLE_
%type<type_ptr> TYPE RETURN_TYPE
%type<parameter_ptr> PARAMETER
%type<parameter_list_ptr> PARAMETERS PARAMETERS1
%type<returnstatement_ptr> RETURN_STATEMENT
%type<method_ptr> METHOD
%type<method_list_ptr> METHOD1 METHOD2


%%

/* WRITEME: This rule is a placeholder. Replace it with your grammar
            rules from Project 3 */

Start : CLASS1  {astRoot = new ProgramNode($1);}
      ;

CLASS1  : CLASS1 CLASS {$$ = $1; $$ -> push_back($2);}
        | CLASS {$$ = new std::list<ClassNode*>(); $$ -> push_front($1);}
        ;

CLASS : DECLARATION {$$ = new ClassNode(new IdentifierNode(ClassName), NULL, DeclarationNodeList2, MethodNodeList); DeclarationNodeList2 = new std::list<DeclarationNode*>();}
      | T_IDENTIFIER T_EXTENDS DECLARATION {$$ = new ClassNode(new IdentifierNode($1), new IdentifierNode(ClassName), DeclarationNodeList2, MethodNodeList);DeclarationNodeList2 = new std::list<DeclarationNode*>();}
      ;

DECLARATION : T_IDENTIFIER T_OPENBRACKET IMPLEMENTATION T_CLOSEDBRACKET {ClassName = $1;}
            ;

IMPLEMENTATION : TYPE T_IDENTIFIER T_SEMI IMPLEMENTATION {std::list<IdentifierNode*>* temp = new std::list<IdentifierNode*>(); temp -> push_front(new IdentifierNode($2)); ;DeclarationNodeList2 -> push_front(new DeclarationNode($1, temp));}
               | METHOD2 {MethodNodeList = $1;}
               ;

TYPE       : T_INTEGER {$$ = new IntegerTypeNode();}
           | T_BOOLEAN {$$ = new BooleanTypeNode();}
           | T_IDENTIFIER {$$ = new ObjectTypeNode(new IdentifierNode($1));}
           ;

METHOD2    : METHOD1 {$$ = $1;}
           | {$$ = new std::list<MethodNode*>();}
           ;

METHOD1    : METHOD1 METHOD {$$ = $1; $$ -> push_back($2);}
           | METHOD {$$ = new std::list<MethodNode*>(); $$ -> push_front($1);}
           ;

METHOD     : T_IDENTIFIER T_OPENPAREN PARAMETERS1 T_CLOSEDPAREN T_METHODRETURN RETURN_TYPE T_OPENBRACKET BODY RETURN_STATEMENT T_CLOSEDBRACKET {$$ = new MethodNode(new IdentifierNode($1),$3,$6, new MethodBodyNode(DeclarationNodeList,StatementNodeList,$9));DeclarationNodeList = new std::list<DeclarationNode*>();}
           ;

PARAMETERS1 : PARAMETERS {$$ = $1;}
            | {$$ = new std::list<ParameterNode*>();}
            ;

PARAMETERS : PARAMETERS T_COMMA PARAMETER {$$ = $1; $$ -> push_back($3);}
           | PARAMETER {$$ = new std::list<ParameterNode*>(); $$ -> push_front($1);}
           ;

PARAMETER  : T_IDENTIFIER T_COLON TYPE {$$ = new ParameterNode($3, new IdentifierNode($1));}

RETURN_TYPE : TYPE {$$ = $1;}
           | T_NONE {$$ = new NoneNode();}
           ;

BODY       : TYPE VARIABLE_ T_SEMI BODY {DeclarationNodeList -> push_front(new DeclarationNode($1, $2));}
           | STATEMENTS1 {StatementNodeList = $1;}
           ;

VARIABLE_  : VARIABLE_ T_COMMA T_IDENTIFIER {$$ = $1; $$ -> push_back(new IdentifierNode($3));}
           | T_IDENTIFIER {$$ = new std::list<IdentifierNode*>(); $$ -> push_front(new IdentifierNode($1));}
           ;

RETURN_STATEMENT : T_RETURN EXPRESSION T_SEMI {$$ = new ReturnStatementNode($2);} 
                 | {$$ = NULL;}
                 ;



STATEMENTS1 : STATEMENTS {$$ = $1;}
           | {$$ = new std::list<StatementNode*>();}
           ;

STATEMENTS : STATEMENT STATEMENTS {$$ = $2; $$ -> push_front($1);}
           | STATEMENT {$$ = new std::list<StatementNode*>(); $$ -> push_back($1);}
           ;

STATEMENT  : ASSIGNMENT {$$ = $1;}
           | METHODCALL T_SEMI{$$ = new CallNode($1);}
           | IFELSE {$$ = $1;}
           | WHILELOOP {$$ = $1;}
           | REPEATUNTIL {$$ = $1;}
           | PRINT1 {$$ = $1;}
           ;

ASSIGNMENT : T_IDENTIFIER T_EQUALS EXPRESSION T_SEMI {$$ = new AssignmentNode(new IdentifierNode($1),NULL,$3);}
           | T_IDENTIFIER T_DOT T_IDENTIFIER T_EQUALS EXPRESSION T_SEMI {$$ = new AssignmentNode(new IdentifierNode($1),new IdentifierNode($3),$5);}
           ;

IFELSE    : T_IF EXPRESSION T_OPENBRACKET STATEMENTS T_CLOSEDBRACKET {$$ = new IfElseNode($2,$4,NULL);}
           | T_IF EXPRESSION T_OPENBRACKET STATEMENTS T_CLOSEDBRACKET T_ELSE T_OPENBRACKET STATEMENTS T_CLOSEDBRACKET {$$ = new IfElseNode($2,$4,$8);}
           ;

WHILELOOP : T_WHILE EXPRESSION T_OPENBRACKET STATEMENTS T_CLOSEDBRACKET {$$ = new WhileNode($2,$4);}

REPEATUNTIL : T_REPEAT T_OPENBRACKET STATEMENTS T_CLOSEDBRACKET T_UNTIL T_OPENPAREN EXPRESSION T_CLOSEDPAREN T_SEMI {$$ = new RepeatNode($3, $7);}

PRINT1     : T_PRINT EXPRESSION T_SEMI {$$ = new PrintNode($2);}

EXPRESSION : EXPRESSION T_PLUS EXPRESSION {$$ = new PlusNode($1,$3);}
           | EXPRESSION T_MINUS EXPRESSION {$$ = new MinusNode($1,$3);}
           | EXPRESSION T_MULTIPLY EXPRESSION {$$ = new TimesNode($1,$3);}
           | EXPRESSION T_DIVIDE EXPRESSION {$$ = new DivideNode($1,$3);}
           | EXPRESSION T_LESSTHAN EXPRESSION {$$ = new LessNode($1,$3);}
           | EXPRESSION T_LESSTHANOREQUAL EXPRESSION {$$ = new LessEqualNode($1,$3);}
           | EXPRESSION T_EQUALSBOOL EXPRESSION {$$ = new EqualNode($1,$3);}
           | EXPRESSION T_AND EXPRESSION {$$ = new AndNode($1,$3);}
           | EXPRESSION T_OR EXPRESSION {$$ = new OrNode($1,$3);}
           | T_NOT EXPRESSION {$$ = new NotNode($2);}
           | T_MINUS EXPRESSION %prec T_NOT {$$ = new NegationNode($2);}
           | T_IDENTIFIER {$$ = new VariableNode(new IdentifierNode($1));}
           | T_IDENTIFIER T_DOT T_IDENTIFIER {$$ = new MemberAccessNode(new IdentifierNode($1),new IdentifierNode($3));}
           | METHODCALL {$$ = $1;}
           | T_OPENPAREN EXPRESSION T_CLOSEDPAREN {$$ = $2;}
           | T_INTEGERLITERAL {$$ = new IntegerLiteralNode(new IntegerNode($1));}
           | T_TRUE {$$ = new BooleanLiteralNode(new IntegerNode(1));}
           | T_FALSE {$$ = new BooleanLiteralNode(new IntegerNode(0));}
           | T_NEW T_IDENTIFIER {$$ = new NewNode(new IdentifierNode($2), NULL);}
           | T_NEW T_IDENTIFIER T_OPENPAREN ARGUMENTS T_CLOSEDPAREN {$$ = new NewNode(new IdentifierNode($2), $4);}
           ;

METHODCALL : T_IDENTIFIER T_OPENPAREN ARGUMENTS T_CLOSEDPAREN {$$ = new MethodCallNode(new IdentifierNode($1),NULL,$3);}
           | T_IDENTIFIER T_DOT T_IDENTIFIER T_OPENPAREN ARGUMENTS T_CLOSEDPAREN {$$ = new MethodCallNode(new IdentifierNode($1),new IdentifierNode($3),$5);}
           ;

ARGUMENTS  : ARGUMENTS_ {$$ = $1;}
           | {$$ = new std::list<ExpressionNode*>();}
           ;

ARGUMENTS_ : ARGUMENTS_ T_COMMA EXPRESSION {$$ = $1; $$ -> push_back($3);}
           | EXPRESSION {$$ = new std::list<ExpressionNode*>(); $$ -> push_front($1);}
           ;

%%

extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}
