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
%}

%define parse.error verbose


%token T_PRINT T_RETURN T_IF T_ELSE T_WHILE T_NEW T_NONE T_EXTENDS T_DO  T_ARROW T_DOT T_COMMA T_METHODNAME
%token T_LBRACKET T_RBRACKET
%token T_QMARK T_COLON T_SEMICOLON 
%token T_OR
%token T_AND
%token T_EQUALTO T_GT T_GTE
%token T_ADD T_SUB
%token T_DIV T_MUL
%token T_UNARYMINUS T_NOT
%token T_LPAREN T_RPAREN 
%token T_ID T_INT T_TRUE T_FALSE T_NUM T_BOOL
%token T_EQ


%right T_QMARK T_COLON
%left T_OR
%left T_AND 
%left T_EQUALTO T_GT T_GTE 
%left T_ADD T_SUB 
%left T_DIV T_MUL  
%precedence T_UNARYMINUS T_NOT

%type <program_ptr> Start
%type <class_list_ptr> classes
%type <class_ptr> class superclass class_
%type <identifier_ptr> name
%type <declaration_list_ptr> members declarations
%type <method_list_ptr> methods
%type <method_ptr> method_decl
%type <parameter_list_ptr> params_ params
%type <type_ptr> type
%type <methodbody_ptr> body
%type <statement_list_ptr> statements
%type <returnstatement_ptr> return_
%type <parameter_ptr> param
%type <declaration_ptr> declaration
%type <identifier_list_ptr> names
%type <expression_ptr> expression
%type <assignment_ptr> assignment

%type <methodcall_ptr> method_call
%type <ifelse_ptr> if_else
%type <while_ptr> while_
%type <dowhile_ptr> do_while
%type <print_ptr> print

%type <expression_list_ptr> arguments_ arguments

%type <new_ptr> new
%type <statement_ptr> statement

%type <base_int> T_NUM
%type <booleantype_ptr> T_BOOL
%type <base_char_ptr> T_ID

%%

Start : classes   {astRoot = new ProgramNode($1);}
      ;


classes : classes class_ {$$ = $1; $$->push_back($2);}
      | class  {$$ = new std::list<ClassNode*>(); $$->push_back($1);}
      ;

class_ : superclass  {$$ = $1;}
      | class   {$$ = $1;}
      ;

class : name T_LBRACKET members methods T_RBRACKET    {$$ = new ClassNode($1,NULL,$3,$4);}
      | name T_LBRACKET members T_RBRACKET            {$$ = new ClassNode($1,NULL,$3,NULL);}
      | name T_LBRACKET methods T_RBRACKET            {$$ = new ClassNode($1,NULL,NULL,$3);}
      | name T_LBRACKET T_RBRACKET                    {$$ = new ClassNode($1,NULL,NULL,NULL);}
      ;

superclass : name T_EXTENDS name T_LBRACKET members methods T_RBRACKET  {$$ = new ClassNode($1,$3,$5,$6);}
            | name T_EXTENDS name T_LBRACKET members T_RBRACKET         {$$ = new ClassNode($1,$3,$5,NULL);}
            | name T_EXTENDS name T_LBRACKET methods T_RBRACKET         {$$ = new ClassNode($1,$3,NULL,$5);}
            | name T_EXTENDS name T_LBRACKET T_RBRACKET                 {$$ = new ClassNode($1,$3,NULL,NULL);}
            ;

members : members type name T_SEMICOLON  {$$ = $1; std::list<IdentifierNode*> *n = new std::list<IdentifierNode*>(); n->push_back($3); DeclarationNode *d = new DeclarationNode($2,n); $$->push_back(d);}
      | type name T_SEMICOLON {$$ = new std::list<DeclarationNode*>();std::list<IdentifierNode*> *n = new std::list<IdentifierNode*>(); n->push_back($2); DeclarationNode *d = new DeclarationNode($1,n); $$->push_back(d);}
      ;

methods : methods method_decl  {$$ = $1; $$->push_back($2);}
      | method_decl {$$ = new std::list<MethodNode*>(); $$->push_back($1);}
      ;

method_decl : name T_LPAREN params T_RPAREN T_ARROW type T_LBRACKET body T_RBRACKET    {$$ = new MethodNode($1,$3,$6,$8);}
            | name T_LPAREN params T_RPAREN T_ARROW T_NONE T_LBRACKET body T_RBRACKET {NoneNode* n = new NoneNode(); n->basetype = bt_none; $$ = new MethodNode($1,$3,n,$8);}
            ;



body : declarations statements return_  {$$ = new MethodBodyNode($1,$2,$3);}
     | declarations statements          {$$ = new MethodBodyNode($1,$2,NULL);}
     | declarations return_             {$$ = new MethodBodyNode($1,NULL,$2);}
     | declarations                     {$$ = new MethodBodyNode($1,NULL,NULL);}
     | statements return_               {$$ = new MethodBodyNode(NULL,$1,$2);}
     | statements                       {$$ = new MethodBodyNode(NULL,$1,NULL);}
     | return_                          {$$ = new MethodBodyNode(NULL,NULL,$1);}
     | %empty                           {$$ = new MethodBodyNode(NULL,NULL,NULL);}
      ;

declarations : declarations declaration   {$$ = $1; $$->push_back($2);}
            | declaration {$$ = new std::list<DeclarationNode*>(); $$->push_back($1);}
            ;

declaration : type names T_SEMICOLON    {$$ = new DeclarationNode($1, $2);}
            ;

names :  name   {$$ = new std::list<IdentifierNode*>(); $$->push_back($1);}
      | names T_COMMA name   {$$ = $1; $$->push_back($3);}
      ;
return_ : T_RETURN expression T_SEMICOLON {$$ = new ReturnStatementNode($2);}
      ;
statements : statements statement  {$$ = $1; $$->push_back($2);}
      | statement  {$$ = new std::list<StatementNode*>(); $$->push_back($1);}
      ;

statement : assignment T_SEMICOLON {$$ = $1;}
      | method_call T_SEMICOLON   {$$ = new CallNode($1);}
      | if_else    {$$ = $1;}
      | while_    {$$ = $1;}
      | do_while T_SEMICOLON {$$ = $1;}
      | print T_SEMICOLON     {$$ = $1;}
      ;


assignment : name T_EQ expression   {$$ = new AssignmentNode($1,NULL,$3);}
            | name T_DOT name T_EQ expression   {$$ = new AssignmentNode($1,$3,$5);}
            ;

if_else : T_IF expression T_LBRACKET statements T_RBRACKET   {$$ = new IfElseNode($2, $4, NULL);}
        | T_IF expression T_LBRACKET statements T_RBRACKET T_ELSE T_LBRACKET statements T_RBRACKET {$$ = new IfElseNode($2,$4,$8);}
        ;
while_ : T_WHILE expression T_LBRACKET statements T_RBRACKET   {$$ = new WhileNode($2,$4);}
        ;
do_while : T_DO T_LBRACKET statements T_RBRACKET T_WHILE T_LPAREN expression T_RPAREN  {$$ = new DoWhileNode($3,$7);}
        ;

print : T_PRINT expression  {$$ = new PrintNode($2);}
      ;

name : T_ID {$$ = new IdentifierNode($1);}
      ;


params : params_    {$$ = $1;}
      | %empty {$$ = new std::list<ParameterNode*>();}
      ;
params_ : params_ T_COMMA param   {$$ = $1; $$->push_back($3);}
      | param   {$$ = new std::list<ParameterNode*>(); $$->push_back($1);}
      ;

param : type name {$$ = new ParameterNode($1,$2);}
      ;

type : T_BOOL {$$ = new BooleanTypeNode(); $$->basetype = bt_boolean;}
      | T_INT {$$ = new IntegerTypeNode(); $$->basetype = bt_integer;}
      | name  {$$ = new ObjectTypeNode($1); $$->basetype = bt_object; $$->objectClassName = $1->name;}
      ;

expression : expression T_ADD expression {$$ = new PlusNode($1,$3);}
            | expression T_SUB expression {$$ = new MinusNode($1,$3);}
            | expression T_MUL expression {$$ = new TimesNode($1,$3);}
            | expression T_DIV expression {$$ = new DivideNode($1,$3);}
            | expression T_GT expression {$$ = new GreaterNode($1,$3);}
            | expression T_GTE expression {$$ = new GreaterEqualNode($1,$3);}
            | expression T_EQUALTO expression {$$ = new EqualNode($1,$3);}
            | expression T_AND expression {$$ = new AndNode($1,$3);}
            | expression T_OR expression {$$ = new OrNode($1,$3);}
            | T_NOT expression {$$ = new NotNode($2);}
            | expression T_QMARK expression T_COLON expression {$$ = new QMNode($1,$3,$5);}
            | T_UNARYMINUS expression {$$ = new NegationNode($2);}
            | T_LPAREN expression T_RPAREN {$$ = $2;}
            | T_NUM {$$ = new IntegerLiteralNode(new IntegerNode($1));}
            | name T_DOT name {$$ = new MemberAccessNode($1,$3);}
            | name {$$ = new VariableNode($1);}
            | method_call {$$ = $1;}
            | T_TRUE {$$ = new BooleanLiteralNode(new IntegerNode(1));}
            | T_FALSE  {$$ = new BooleanLiteralNode(new IntegerNode(0));}
            | new {$$ = $1;}
            ;

new : T_NEW name {$$ = new NewNode($2, new std::list<ExpressionNode*>());}
    | T_NEW name T_LPAREN arguments T_RPAREN {$$ = new NewNode($2, $4);}
    ;


method_call : name T_LPAREN arguments T_RPAREN {$$ = new MethodCallNode($1,NULL,$3);}
            | name T_DOT name T_LPAREN arguments T_RPAREN {$$ = new MethodCallNode($1, $3,$5);}
            ;

arguments : arguments_ {$$ = $1;}
          | %empty  {$$ = new std::list<ExpressionNode*>();}
          ;

arguments_ : arguments_ T_COMMA expression {$$ = $1; $$->push_back($3);}
          | expression  {$$ = new std::list<ExpressionNode*>(); $$->push_back($1);}
          ;


%%

extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}