
%{
#include <stdio.h>
#include <string.h>
#include "parsing.h"
void check_string();
void check_comment();
void check_character();
void count();
int col = 0;
int row = 0;
%}
DIGIT   [0-9]
LETTER  [a-zA-Z]
WHITESPACE ([ \t])+
SPACE [\n|(\r\n)]
%%
"_Bool"                 { count(); yylval.tp = TYPE_BOOL; return BOOL; }
"int"                   { count(); yylval.tp = TYPE_INT; return INT; }
"char"                  { count(); yylval.tp = TYPE_CHAR; return CHAR; }
"float"                 { count(); yylval.tp = TYPE_FLOAT; return FLOAT; }
"double"                { count(); yylval.tp = TYPE_DOUBLE; return DOUBLE; }
"void"                  { count(); yylval.tp = TYPE_VOID; return VOID; }
"const"                 { count(); return CONST; }
"if"                    { count(); return IF; }
"else"                  { count(); return ELSE; }
"for"                   { count(); return FOR; }
"break"                 { count(); return BREAK; }
"continue"              { count(); return CONTINUE; }
"struct"                { count(); return STRUCT; }
"while"                 { count(); return WHILE; }
"return"                { count(); return RETURN; }

"+"                     { count(); return '+'; }
"-"                     { count(); return '-'; }
"/"                     { count(); return '/'; }
"*"                     { count(); return '*'; }
"^"                     { count(); return '^'; }
"%"                     { count(); return '%'; }
"&"                     { count(); return '&'; }
"|"                     { count(); return '|'; }
"<"                     { count(); return '<'; }
">"                     { count(); return '>'; }
"."                     { count(); return '.'; }
">>"                    { count(); return OP_RS; }
"<<"                    { count(); return OP_LS; }
"&&"                    { count(); return OP_AND; }
"||"                    { count(); return OP_OR; }
"=="                    { count(); return OP_EQ; }
"!="                    { count(); return OP_NE; }
">="                    { count(); return OP_GE; }
"<="                    { count(); return OP_LE; }
"++"                    { count(); return OP_INCRE; }
"--"                    { count(); return OP_DECRE; }
"->"                    { count(); return OP_PTR; }

"!"                     { count(); return '!'; }
"~"                     { count(); return '~'; }

","                     { count(); return ','; }
":"                     { count(); return ':'; }
";"                     { count(); return ';'; }
"{"                     { count(); return '{'; }
"}"                     { count(); return '}'; }
"("                     { count(); return '('; }
")"                     { count(); return ')'; }
"["                     { count(); return '['; }
"]"                     { count(); return ']'; }
"?"                     { count(); return '?'; }

"="                     { count(); return '='; }
"+="                    { count(); return ASSIGN_ADD; }
"-="                    { count(); return ASSIGN_SUB; }
"*="                    { count(); return ASSIGN_MUL; }
"/="                    { count(); return ASSIGN_DIV; }
"^="                    { count(); return ASSIGN_XOR; }
"&="                    { count(); return ASSIGN_AND; }
"%="                    { count(); return ASSIGN_MOD; }
">>="                   { count(); return ASSIGN_RS; }
"<<="                   { count(); return ASSIGN_LS; }
"|="                    { count(); return ASSIGN_OR; }






"/*"                    { /* printf("comment\n"); */ check_comment(); count(); /* return COMMENT; */ }
"//"[^\n]*              { /* printf("comment\n"); */ /* return COMMENT; */ }

(({LETTER}|"_")({DIGIT}|{LETTER})*)     {
                                          int len = strlen(yytext);
                                          count();
                                          //yylval.id = yytext;
                                          //printf("%s\n", yylval.id);
                                          yylval.id = (char *)malloc(sizeof(char) * (len + 1));
                                          memcpy(yylval.id, yytext, len + 1);
                                          return IDENTIFIER;
                                        }
{DIGIT}+                { /* printf("interger\n"); */ count(); yylval.const_int = atoi((char *)yytext); return CONSTANT_INTEGER; }
{DIGIT}*\.{DIGIT}+      { /* printf("float\n"); */ count(); yylval.const_float = atof((char *)yytext); return CONSTANT_FLOAT; }
{DIGIT}+\.{DIGIT}*      { /* printf("float\n"); */ count(); yylval.const_float = atof((char *)yytext); return CONSTANT_FLOAT; }
\"                      {
                          check_string();
                          count();
                          int len = strlen(yytext);
                          yylval.id = (char *)malloc(sizeof(char) * (len + 1));
                          memcpy(yylval.id, yytext, len + 1);
                          yylval.const_str = yytext;/* printf("string\n"); */
                          return CONSTANT_STRING;
                        }
\'                      { check_character(); count(); yylval.const_char = *yytext;/* printf("character\n"); */ return CONSTANT_CHARACTER; }
{WHITESPACE}            { /* printf("whitespace\n"); */ count(); }
{SPACE}                 { /* printf("space\n"); */ /* return *yytext; */ count(); }
%%
void check_string()
{
  char cur = 0, pre = 0;
  int i = 1;
  while((cur = input())) {
    *(yytext + i) = cur;
    i++;

    if(pre == '\\') {
      switch(cur) {
        case('a'):  break;
        case('b'):  break;
        case('\\'): break;
        case('\''): break;
        case('\"'): break;
        case('n'):  break;
        case('f'):  break;
        case('r'):  break;
        case('t'):  break;
        case('v'):  break;
        case('?'):  break;
        case('0'):  break;
        default: yyerror("Unmatched escape character!"); break;
      }
      pre = 0;
    }
    else {
      if(cur == '\"') {
        yytext[i] = 0;
        return;
      }
      if(cur == '\n') {
        yyerror("Unmatched double quotes!");
        yytext[i] = 0;
        return;
      }
      pre = cur;
    }
  }
  yyerror("Unmatched double quotes!");
}
void check_character()
{
  int n = 0;
  char cur = 0, pre = 0;
  while((cur = input())) {
    n++;
    if(pre == '\\') {
      switch(cur) {
        case('a'):  break;
        case('b'):  break;
        case('\\'): break;
        case('\''): break;
        case('\"'): break;
        case('n'):  break;
        case('f'):  break;
        case('r'):  break;
        case('t'):  break;
        case('v'):  break;
        case('?'):  break;
        case('0'):  break;
        default: yyerror("Unmatched escape character!"); break;
      }
      n--;
      pre = 0;
    }
    else {
      if(cur == '\'') {
          if(n > 2) {
            yyerror("Exceed one character!");
          }
          return;
      }
      if(cur == '\n') {
        yyerror("Unmatched single quote!");
        return;
      }
      pre = cur;
    }
  }
  yyerror("Unmatched single quote!");
}

void check_comment()
{
  char cur = 0, pre = 0;
  while((cur = input())) {
    if(pre == '*' && cur == '/') {
      return;
    }
    pre = cur;
  }
  yyerror("Unmatched comment characters!");
}
void count()
{
  int i;
  for(i = 0; yytext[i]; i++) {
    if(yytext[i] == '\n') {
      col = 0;
      row++;
    }
    else if(yytext[i] == '\t') {
      col += 8 - (col % 8);
    }
    else {
      col++;
    }
  }
}
int yywrap()
{
	return 1;
}
/*
int main()
{
  yyin = stdin;
  yylex();
  return 0;
}
*/
int main(int argc, char *argv[])
{
	global_table = gen_table();
	temp_table = global_table;
	parent_table = NULL;
  /*yyin = fopen(argv[1], "r");*/
	yyin = fopen("test.c", "r");
  yyparse();
  fclose(yyin);
  return 0;
}
