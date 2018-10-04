%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char*);
double* double_carrier;
char* string_carrier;
%}

%token NUM SYM
%token EOL
%token SYM_PRNL SYM_PRNR
%token CMD_EXIT CMD_CALC CMD_ASN CMD_RESET CMD_PRINT

%left OP_ADD OP_SUB
%left OP_MUL OP_DIV
%left OP_POW

%%

g	: g e EOL { stack_print(); }
	| g EOL { printf("\n"); }
	| g CMD_PRINT EOL { stack_print(); }
	| g SYM CMD_ASN NUM EOL {
		if (stack_assign(get_stack_bottom(), string_carrier, *double_carrier, 0) == 0)
			printf ("\tUndefined variable\n");
		free(string_carrier);
		free(double_carrier);
	}
	| g CMD_CALC EOL  {
		stack_calc(1);
		if (get_stack_state() < 0)
			printf("Some ERROR occurred...\n");
		reset_stack_state();
	}
	| g CMD_RESET EOL { stack_clean(); }
	| g CMD_EXIT EOL { printf(">> Bye!\n"); exit(0); } 
	| g CMD_EXIT { printf(">> Bye!\n"); exit(0); }
	|
	;
e	: NUM 
{
	stack_push_num(*double_carrier); 
	free(double_carrier);
}
	| SYM
{
	stack_push_sym(string_carrier);
	free(string_carrier);
}
	| e OP_ADD e { stack_push_op(1001); }
	| e OP_SUB e { stack_push_op(1002); }
	| e OP_MUL e { stack_push_op(1003); }
	| e OP_DIV e { stack_push_op(1004); }
	| e OP_POW e { stack_push_op(1005); }
	| SYM_PRNL e SYM_PRNR { ; }
	| OP_ADD e { stack_push_op(101); }
	| OP_SUB e { stack_push_op(102); }
	;
%%

void yyerror(char *s)
{
	fprintf(stderr, ">> %s\n", s);
}

int main()
{
	stack_build();
	yyparse();
	stack_destroy();
	return 0;
}
