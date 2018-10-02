%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
extern YYSTYPE yylval;
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
"," {
	return SYM_COMMA;
}
"sin"|"SIN" {
	return FUNC_SIN;
}
"cos"|"COS" {
	return FUNC_COS;
}
"tan"|"TAN" {
	return FUNC_TAN;
}
"cot"|"COT" {
	return FUNC_COT;
}
"sec"|"SEC" {
	return FUNC_SEC;
}
"csc"|"CSC" {
	return FUNC_CSC;
}
"sqrt"|"SQRT" {
	return FUNC_SQRT;
}
"ceil"|"CEIL" {
	return FUNC_CEIL;
}
"floor"|"FLOOR" {
	return FUNC_FLOOR;
}
"abs"|"fabs"|"ABS"|"FABS" {
	return FUNC_ABS;
}
"log"|"LOG" {
	return FUNC_LOG;
}
"log10"|"LOG10" {
	return FUNC_LOG10;
}
"log7"|"LOG7" {
	return FUNC_LOG7;
}
"log5"|"LOG5" {
	return FUNC_LOG5;
}
"log3"|"LOG3" {
	return FUNC_LOG3;
}
"log2"|"LOG2" {
	return FUNC_LOG2;
}
"ln"|"LN" {
	return FUNC_LN;
}
"[" {
	return FUNC_L;
}
"]" {
	return FUNC_R;
}
[0-9]+(\.[0-9]+)? {
	sscanf(yytext, "%lf", &yylval);
	return NUM;
}
\n {
	return EOL;
}
[ \t]+ {}
"quit"|"exit" {
	return CMD_EXT;
}
. {
	yyerror("ERROR: Unrecognized input!");
}

%%

int yywrap()
{
	return 1;
}
