masm_nr: hw4.o lex.yy.o
	gcc -o masm_nr hw4.o lex.yy.o
hw4.o:  hw4.c
	gcc -c -g hw4.c
lex.yy.o:  lex.yy.c
	gcc -c -g lex.yy.c
lex.yy.c: hw4.ll
	flex hw4.ll
clean:
	rm lex.yy.o lex.yy.c hw4.o masm_nr
