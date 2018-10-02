echo: echo.o
	gcc $^ -o $@

echo.o: lex.yy.c
	gcc $< -c -o $@

%.o: %.c
	gcc $< -c

lex.yy.c: echo.lex
	flex $<

clean:
	rm -rf echo *.o lex.yy.c
