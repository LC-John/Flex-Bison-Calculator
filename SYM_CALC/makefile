all:	calc

calc: 	calc.lex calc.y ct.h ct.c
	gcc -c ct.h ct.c
	bison -d -y calc.y
	flex calc.lex
	gcc -c y.tab.h y.tab.c lex.yy.c
	gcc ct.o y.tab.o lex.yy.o -o $@ -lm

clean:
	rm -rf calc *.o *.gch lex.yy.* y.tab.*
