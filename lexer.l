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

DIGIT [0-9]
CHAR [a-z]|[A-Z]
ID {CHAR}({CHAR}|{DIGIT})*  


%x unary

%%

<INITIAL,unary>[\n] {yylineno = yylineno + 0.5;}
<INITIAL,unary>[ \t]
<INITIAL,unary>"/*"    {
        int c;
        int line = yylineno;
        while(true)
            {
            if((c = yyinput()) == 0){
                yylineno -= (yylineno - line)/2;
                yyerror("dangling comment");
            }
            if(c == '\n')
                ++yylineno;

            else if(c == '*')
                {
                if((c = yyinput()) == '/')
                    break;
                else
                    unput(c);
                }
            }
        }



<unary>"-" {BEGIN(unary); return T_UNARYMINUS;}
<unary>. {BEGIN(0); unput(*yytext);}

"print" {BEGIN(unary); return T_PRINT;}
"return" {BEGIN(unary); return T_RETURN;}
"if" {BEGIN(unary); return T_IF;}
"else" {return T_ELSE;}
"while" {BEGIN(unary); return T_WHILE;}
"new" {return T_NEW;}
"none" {return T_NONE;}
"extends" {return T_EXTENDS;}
"do" {return T_DO;}
"=" {BEGIN(unary); return T_EQ;}
"->" {return T_ARROW;}
"." {return T_DOT;}
"," {BEGIN(unary); return T_COMMA;}
"(" {BEGIN(unary); return T_LPAREN;}
")" {return T_RPAREN;}
"{" {return T_LBRACKET;}
"}" {return T_RBRACKET;}
"?" {BEGIN(unary); return T_QMARK;}
":" {BEGIN(unary); return T_COLON;}
";" {return T_SEMICOLON;}
"or" {BEGIN(unary); return T_OR;}
"and" {BEGIN(unary); return T_AND;}
"==" {BEGIN(unary); return T_EQUALTO;}
">=" {BEGIN(unary); return T_GTE;}
">" {BEGIN(unary); return T_GT;}
"+" {BEGIN(unary); return T_ADD;}
"-" {BEGIN(unary); return T_SUB;}
"*" {BEGIN(unary); return T_MUL;}
"/" {BEGIN(unary); return T_DIV;}
"not" {BEGIN(unary); return T_NOT;}
"int" {return T_INT;}
"boolean" {return T_BOOL;}
"False" {return T_FALSE;}
"True" {return T_TRUE;}

([1-9][0-9]*)|"0" {yylval.base_int = std::stoi(std::string(yytext,yyleng));return T_NUM;}

{ID} {std::string s = std::string(yytext,yyleng); yylval.base_char_ptr = new char(yyleng+1); strcpy(yylval.base_char_ptr, s.c_str()); return T_ID;}


.                 { yyerror("invalid character"); }

%%

int yywrap(void) {
  return 1;
}