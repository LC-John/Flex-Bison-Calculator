%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
extern double* double_carrier;
extern char* string_carrier;
void yyerror(char*);
%}

%%

"+" {
	return OP_ADD;
}
"-" {
	return OP_SUB;
}
"*" {
	return OP_MUL;
}
"/" {
	return OP_DIV;
}
"^" {
	return OP_POW;
}
"(" {
	return SYM_PRNL;
}
")" {
	return SYM_PRNR;
}
[0-9]+(\.[0-9]+)? {
	double_carrier = (double*)(malloc(sizeof(double)));
	sscanf(yytext, "%lf", double_carrier);
	return NUM;
}
\n {
	return EOL;
}
[ \t]+ {}
"=" {
	return CMD_ASN;
}
"reset"|"RESET" {
	return CMD_RESET;
}
"print"|"PRINT" {
	return CMD_PRINT;
}
"show"|"SHOW" {
	return CMD_SHOW;
}
"calc"|"CALC" {
	return CMD_CALC;
}
"quit"|"exit"|"QUIT"|"EXIT" {
	return CMD_EXIT;
}
[a-zA-Z]+ {
	string_carrier = (char*)(malloc(sizeof(char)*(strlen(yytext)+2)));
	strcpy(string_carrier, yytext);
	return SYM;
}
. {
	yyerror("ERROR: Unrecognized input!");
}

%%

int yywrap()
{
	return 1;
}
