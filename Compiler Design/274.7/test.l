%{
	#include<stdio.h>
	#include"test.tab.h++"
	int yylex(void);
	void yyerror(char const *s);
	extern int yylineno;
%}

string \"[a-z0-9]*\"
integer [0-9]+
real [0-9]+\.[0-9]+
id [a-zA-Z][a-zA-Z]*
else else
if if
deql ==
do do
nop nop
print print
read read
str str
then then
while while
whitespace [ \t\n]
comment \/\/.*\n

%%

{integer} {printf("integer=%s\n",yytext);return IC;}
{real} {printf("Real=%s\n",yytext);return FC;}
{id} {printf("Id=%s\n",yytext);return ID;}
{else} {printf("Else\n");return ELSE;}
{if} {printf("If\n");return IF;}
{do} {printf("Do\n");return DO;}
{nop} {printf("nop\n");return NOP;}
{print} {printf("print\n");return PRINT;}
{read} {printf("Read\n");return READ;}
{string} {printf("Strng=%s\n",yytext);return STR;}
{then} {printf("Then\n");return THEN;}
{while} {printf("While\n");return WHILE;}
{whitespace} {printf("Whitespace\n");}
{comment} {printf("comment=%s",yytext);}
{deql} {printf("equal comp\n");return DEQL;}
"+" {printf("addn");return (int)'+';}
"-" {printf("addn");return (int)'-';}
"*" {printf("addn");return (int)'*';}
"/" {printf("addn");return (int)'/';}
"(" {printf("addn");return (int)'(';}
")" {printf("addn");return (int)')';}
"<" {printf("addn");return (int)'<';}
">" {printf("addn");return (int)'>';}
"&" {printf("addn");return (int)'&';}
"|" {printf("addn");return (int)'|';}
"~" {printf("addn");return (int)'~';}
";" {printf("addn");return (int)';';}
"." {printf("not identified\n");}

%%









