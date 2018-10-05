%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char*);
void print_help(char*);

extern FILE* yyin;
double* double_carrier;
char* string_carrier;
%}

%token NUM SYM
%token EOL
%token SYM_PRNL SYM_PRNR
%token CMD_EXIT CMD_CALC CMD_ASN CMD_RESET CMD_PRINT CMD_SHOW

%left OP_ADD OP_SUB
%left OP_MUL OP_DIV
%left OP_POW

%%

g	: g e EOL { printf("\t<= Expr %d\n", get_n_result()); }
	| g EOL { printf("\n"); }
	| g CMD_PRINT EOL { stack_print(); }
	| g SYM CMD_ASN NUM EOL {
		if (stack_assign(get_stack_bottom(), string_carrier, *double_carrier, 0) == 0)
			printf ("\tUndefined variable\n");
		free(string_carrier);
		free(double_carrier);
	}
	| g CMD_CALC EOL {
		stack_calc(1, 0);
		if (get_stack_state() < 0)
			printf("Some ERROR occurred...\n");
		reset_stack_state();
	}
	| g CMD_SHOW EOL { show_result(); }
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

void print_help(char* main_name)
{
	printf("/*******************************/\n");
	printf("/*                             */\n");
	printf("/*    Flex Bison Calculator    */\n");
	printf("/*       by Zhang Huangzhao    */\n");
	printf("/*                             */\n");
	printf("/*******************************/\n\n");
	printf("This is a calculator implemented with Flex and Bison.\n");
	printf("1. Use the command \"%s\" to run the program in CMD mode.\n", main_name);
	printf("2. Or use the command \"%s\ --input=[your input file]\" to run the program in script mode.\n\n", main_name);
	printf("Addition(+), subtraction(-), multiplication(*), division(/), power(^) and bracket are implemented. And the program also supports variable defination and assignment. Define the variables in the input expression, and variables are initialized to be 0.\n");
	printf("The program would build a Inverse Polish Expression stack for each input expression, and the legal commands are as follow:\n");
	printf("1. quit/exit -- Quit the program.\n");
	printf("2. print -- Print the IPE stack.\n");
	printf("3. [variable name] = [value] -- Assign value to the specific variable.\n");
	printf("4. calc -- Compute the value of the IPE stack.\n");
	printf("5. reset -- Reset the IPE stack.\n\n");
}

int main(int argc, char** argv)
{
	stack_build();
	if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
	{
		stack_destroy();
		print_help(argv[0]);
		return 1;
	}
	if (argc == 1)
		yyparse();
	else if (argc == 2 && strncmp(argv[1], "--input=", 8) == 0)
	{
		yyin = fopen(argv[1]+8, "r");
		yyparse();
	}
	else
	{
		print_help(argv[0]);
		stack_destroy();
		return 2;
	}
	stack_destroy();
	return 0;
}
