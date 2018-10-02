%{
#include <stdio.h>
int if_new_line = 1;
void print_if_new_line();
%}

%%

[a-zA-Z] {
	print_if_new_line();
	printf("CH(%s) ", yytext);
}
[ \t]+ {}
"exit"|"quit"|"q" {
	printf(">> Bye!\n");
	exit(0);
}
"+" {
	print_if_new_line();
	printf("ADD ");
}
"-" {
	print_if_new_line();
	printf("SUB ");
}
"*" {
	print_if_new_line();
	printf("MUL ");
}
"/" {
	print_if_new_line();
	printf("DIV ");
}
"^" {
	print_if_new_line();
	printf("POW ");
}
"(" {
	print_if_new_line();
	printf("L ");
}
")" {
	print_if_new_line();
	printf("R ");
}
[0-9]+(\.[0-9]+)? {
	print_if_new_line();
	printf("NUM(%s) ", yytext);
}
\n {
	if_new_line = 1;
	printf("EOL\n");
}
. {}

%%

void print_if_new_line()
{
	if (if_new_line > 0)
		printf(">> ");
	if_new_line = 0;
}

int main(int argc, char** argv)
{
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}
