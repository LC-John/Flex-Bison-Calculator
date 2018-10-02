# Flex/Bison Calculator

This is a lab project of Compiler, PKU.
It implements a calculator with Flex/Bison (Lex/YACC).

## Echo

Repeat the expression.

```
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
