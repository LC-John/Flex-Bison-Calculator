# Flex/Bison Calculator

This is a lab project of Compiler, PKU.
It implements a calculator with Flex/Bison (Lex/YACC).

## Echo

Repeat the expression.

```
Flex Grammar
CHAR		[a-zA-Z]
FLOAT NUMBER	[0-9]+(\.[0-9]+)?
ADD		"+"
SUB		"-"
MUL		"*"
DIV		"/"
POW		"^"
L BRACKET	"("
R BRACKET	")"
EOL		\n
EXIT		"exit"|"quit"|"q"
```

## Numeric Calc

Calculate the numeric value of the expression.

```
Flex Grammer
FLOAT NUMBER	[0-9]+(\.[0-9]+)?
ADD		"+"
SUB		"-"
MUL		"*"
DIV		"/"
POW		"^"
L BRACKET	"("
R BRACKET	")"
L FUNC BRACKET	"["
R FUNC BRACKET	"]"
COMMA		","
SIN FUNC	"sin"|"SIN"
COS FUNC	"cos"|"COS"
TAN FUNC	"tan"|"TAN"
COT FUNC	"cot"|"COT"
SEC FUNC	"sec"|"SEC"
CSC FUNC	"csc"|"CSC"
SQRT FUNC 	"sqrt"|"SQRT"
CEIL FUNC	"ceil"|"CEIL"
FLOOR FUNC	"floor"|"FLOOR"
ABSOLUTE VALUE	"abs"|"fabs"|"ABS"|"FABS"
LOG FUNC	"log"|"LOG"
LOG 10 FUNC	"log10"|"LOG10"
LOG 7 FUNC	"log7"|"LOG7"
LOG 5 FUNC	"log5"|"LOG5"
LOG 3 FUNC	"log3"|"LOG3"
LOG 2 FUNC	"log2"|"LOG2"
LOG e FUNC	"ln"|"LN"
EOL		\n
EXIT		"exit"|"quit"
```
```
Bison Syntax Grammar (Note that white space is ignored)
g	-> g e EOL		{ // Output the result }
	| g EOL 		{ // Do nothing }
	| g EXIT 		{ // Exit }
	| epsilon
	;
e	-> FLOAT_NUMBER		{ // Pass the value }
	| e1 ADD e2		{ // Add e1 and e2 }
	| e1 SUB e2		{ // Minus e2 with e1 }
	| e1 MUL e2		{ // Multiply e1 and e2 }
	| e1 DIV e2		{ // Divide e2 with e1 }
	| e1 POW e2		{ // e2 power of e1 }
	| L_BRACKET e1 R_BRACKET	{ // Pass the value }
	| (SIN_FUNC|COS_FUNC|TAN_FUNC|COT_FUNC|SEC_FUNC|CSC_FUNC) L_FUNC_BRACKET e1 R_FUNC_BRACKET
		{ // Trigonometric function of e1 }
	| SQRT_FUNC L_FUNC_BRACKET e1 R_FUNC_BRACKET
		{ // Square root of e1 }
	| (CEIL_FUNC|FLOOR_FUNC|ABSOLUTE_VALUE) L_FUNC_BRACKET e1 R_FUNC_BRACKET
		{ // Ceil/floor/absolute value of e1 }
	| (LOG_10_FUNC|LOG_7_FUNC|LOG_5_FUNC|LOG_3_FUNC|LOG_2_FUNC|LOG_e_FUNC) L_FUNC_BRACKET e1 R_FUNC_BRACKET
		{ // Log 10/7/5/3/2/e value of e1 }
	| LOG_FUNC L_FUNC_BRACKET e1 COMMA e2 R_FUNC_BRACKET
		{ // log of e2 with the base of e1 }
	| (ADD|SUB) e1		{ // Positive/negative of e1 }
```

## How2Use

Make the project using "make", and clean it using "make clean".
There are 2 programs -- "echo" and "calc".
**echo** is a program, using Flex to repeat the input expression.
**calc** is a calculator, which implements "+", "-", "*", "/", "^"(power), trigonometric function and some other simple functions.

```
$ make		# Make the project
...
...
...
$ ./echo	# Run the echo program
(1+2)*3/4
>> L NUM(1) ADD NUM(2) R MUL NUM(3) DIV NUM(4) EOL
exit
>> Bye!
$ ./calc	# Run the calc program
log[2,(1+2)*3-1]
= 3.000000
exit
>> Bye!
$ make clean	# Clean the project
```
