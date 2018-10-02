%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ct.h"
#define YYSTYPE double
int yylex(void);
void yyerror(char*);

NODE* root;
%}

%token NUM
%token EOL
%token SYM_PRNL SYM_PRNR SYM_COMMA
%token FUNC_L FUNC_R
%token FUNC_ABS FUNC_SIN FUNC_COS FUNC_TAN FUNC_COT FUNC_SEC FUNC_CSC FUNC_SQRT FUNC_CEIL FUNC_FLOOR
%token FUNC_LOG FUNC_LOG10 FUNC_LOG7 FUNC_LOG5 FUNC_LOG3 FUNC_LOG2 FUNC_LN
%token CMD_EXT

%left OP_ADD OP_SUB
%left OP_MUL OP_DIV
%left OP_POW

%%

g	: g e EOL { printf("= %lf\n", $2); }
	| g EOL { printf("\n"); }
	| g CMD_EXT { printf(">> Bye!\n"); exit(0); }
	|
	;
e	: NUM
	| e OP_ADD e { $$ = $1 + $3; }
	| e OP_SUB e { $$ = $1 - $3; }
	| e OP_MUL e { $$ = $1 * $3; }
	| e OP_DIV e { $$ = $1 / $3; }
	| e OP_POW e { $$ = pow($1, $3); }
	| SYM_PRNL e SYM_PRNR { $$ = $2; }
	| FUNC_SQRT FUNC_L e FUNC_R { $$ = sqrt($3); }
	| FUNC_CEIL FUNC_L e FUNC_R { $$ = ceil($3); }
	| FUNC_FLOOR FUNC_L e FUNC_R { $$ = floor($3); }
	| FUNC_ABS FUNC_L e FUNC_R { $$ = fabs($3); }
	| FUNC_SIN FUNC_L e FUNC_R { $$ = sin($3); }
	| FUNC_COS FUNC_L e FUNC_R { $$ = cos($3); }
	| FUNC_TAN FUNC_L e FUNC_R { $$ = sin($3) / cos($3); }
	| FUNC_COT FUNC_L e FUNC_R { $$ = cos($3) / sin($3); }
	| FUNC_SEC FUNC_L e FUNC_R { $$ = 1 / cos($3); }
	| FUNC_CSC FUNC_L e FUNC_R { $$ = 1 / sin($3); }
	| FUNC_LOG10 FUNC_L e FUNC_R { $$ = log($3) / log(10); }
	| FUNC_LOG7 FUNC_L e FUNC_R { $$ = log($3) / log(7); }
	| FUNC_LOG5 FUNC_L e FUNC_R { $$ = log($3) / log(5); }
	| FUNC_LOG3 FUNC_L e FUNC_R { $$ = log($3) / log(3); }
	| FUNC_LOG2 FUNC_L e FUNC_R { $$ = log($3) / log(2); }
	| FUNC_LN FUNC_L e FUNC_R { $$ = log($3); }
	| FUNC_LOG FUNC_L e SYM_COMMA e FUNC_R { $$ = log($5) / log($3); }
	| OP_ADD e { $$ = $2; }
	| OP_SUB e { $$ = 0 - $2; }
	;
%%

void yyerror(char *s)
{
	fprintf(stderr, ">> %s\n", s);
}

int main()
{
	yyparse();
	return 0;
}
