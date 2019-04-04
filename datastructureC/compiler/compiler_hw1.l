%{        
        #include <stdio.h>
	#include <stdlib.h>
        #include <string.h>
        int lc=0;
        int count2=0;
        char forcom[1000]={'0'};
        int test=0;
        int findcom(char *);
%}
/* Define regular expression label */
letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+
c_comment "/*"([^*]|\*+[^*/])*\*+"/"
cpluscomment "//"[^\n]+
INC "+"{2}
DEC -{2}
MTE ">="+
LTE "<="+
EQ  "=="+
NE  "!="+
str_const \"(\\.|[^"\\])*\"
intnu  [0-9]+
floatnu ({intnu}+"."{intnu}+) 
discard .
n  [\n]
%%
"+" 	{ printf("%s \t ADD\n", yytext); }
"-"     { printf("%s \t SUB\n", yytext); }
"*"     { printf("%s \t MUL\n", yytext); }
"/"     { printf("%s \t DIV\n", yytext); }
"%"     { printf("%s \t MOD\n", yytext); }
">"     { printf("%s \t MT\n", yytext); }
"<"     { printf("%s \t LT\n", yytext); }
"||" 	{ printf("%s \t OR\n", yytext); }
"["     { printf("%s \t LSB\n", yytext); }
"]"     { printf("%s \t RSB\n", yytext); }
","     { printf("%s \t COMMA\n", yytext); }
";"     { printf("%s \t SEMICOLON\n", yytext); }
"“"      { printf("%s \t QUOTA\n", yytext); }
"="      { printf("%s \t ASSIGN\n", yytext); }
"&&"      { printf("%s \t AND\n", yytext); }
"print"   { printf("%s \t PRINT\n", yytext); }
"if"   { printf("%s \t IF\n", yytext); }
"else"   { printf("%s \t else\n", yytext); }
"for"   { printf("%s \t for\n", yytext); }
"while"   { printf("%s \t while\n", yytext); }
"int"   { printf("%s \t INT\n", yytext); }
"float"   { printf("%s \t FLOAT\n", yytext); }
"string"   { printf("%s \t STRING\n", yytext); }
"+="   { printf("%s \t ADDASGN\n", yytext); }
"-="   { printf("%s \t SUBASGN\n", yytext); }
"*="   { printf("%s \t MULASGN\n", yytext); }
"/="   { printf("%s \t DIVASGN\n", yytext); }
"%="   { printf("%s \t MODASGN\n", yytext); }
"!"   { printf("%s \t NOT\n", yytext); }
"("   { printf("%s \t LB\n", yytext); }
")"   { printf("%s \t RB\n", yytext); }
"{"   { printf("%s \t LCB\n", yytext); }
"}"   { printf("%s \t RCB\n", yytext); }
"void"   { printf("%s \t VOID\n", yytext); }
"bool"   { printf("%s \t BOOL\n", yytext); }
"true"   { printf("%s \t TRUE\n", yytext); }
"false"   { printf("%s \t FALSE\n", yytext); }
"return"   { printf("%s \t RET\n", yytext); }
"continue"   { printf("%s \t CONT\n", yytext); }
"break"   { printf("%s \t BREAK\n", yytext); }
{intnu}   { printf("%s \t I_CONST\n", yytext); }
{floatnu}   { printf("%s \t F_CONST\n", yytext); }
{str_const}       { printf("%s \t STR_CONST\n", yytext); }
{n}			{ ++lc; }
{id}         { printf("%s \t ID\n", yytext); }
{c_comment}      { printf("%s \t c comment\n",yytext); strcpy(forcom,yytext); findcom(forcom);}
{cpluscomment}    { printf("%s \t c++comment\n",yytext); count2++;}
{INC}    {printf("%s \t INC\n",yytext); }
{DEC}    {printf("%s \t DEC\n",yytext); }
{MTE}    {printf("%s \t MTE\n",yytext); }
{LTE}    {printf("%s \t LTE\n",yytext); }
{EQ}    {printf("%s \t EQ\n",yytext); }
{discard} {/**/}
%%
/*	C Code section */
int yywrap(void)
{
    return 1;
}
int main(int argc,char *argv[])
{
    yyin = fopen(argv[1],"r");
    yylex();
    printf("lines of comments: %d \n",test+count2);
    printf("lines of codes: %d \n",lc+test-1); 
    return 0;
}
int findcom(char forcom[])
{
   int l;
   int i=0;
    l=strlen(forcom);
    while(i!=l)
    {
       if(forcom[i]=='\n')
       {
           test++;
       }
        i++;
    }
    test++;
}

