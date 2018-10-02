all:	calc

calc: 	calc.lex calc.y
	bison -d -y calc.y
	flex calc.lex
	gcc -c y.tab.h y.tab.c lex.yy.c
	gcc y.tab.o lex.yy.o -o $@ -lm

clean:
	rm -rf calc *.o *.c *.h y.tab.*
