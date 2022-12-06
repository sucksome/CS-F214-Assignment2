# -*- Makefile -*-

exec: main.o inf.o and_intro.o and_elim.o or_intro.o imp_elim.o modus_tollens.o
	gcc -o exec main.o inf.o and_intro.o and_elim.o or_intro.o imp_elim.o modus_tollens.o
	./exec

main.o: main.c Misc/inf/infixToPrefix.h  
	gcc -c main.c -o main.o

inf.o: Misc/inf/infixToPrefix.h Misc/inf/infixToPrefix.c
	gcc -c Misc/inf/infixToPrefix.c -o inf.o

and_intro.o: AND-rule/and_intro.h AND-rule/and_intro.c
	gcc -c AND-rule/and_intro.c -o and_intro.o

and_elim.o: AND-rule/and_elim.h AND-rule/and_elim.c Misc/inf/infixToPrefix.h Misc/inf/infixToPrefix.c
	gcc -c AND-rule/and_elim.c -o and_elim.o

or_intro.o: OR-rule/or_intro.h OR-rule/or_intro.c
	gcc -c OR-rule/or_intro.c -o or_intro.o

imp_elim.o: IMP-rule/imp_elim.h IMP-rule/imp_elim.c AND-rule/and_elim.h AND-rule/and_elim.c
	gcc -c IMP-rule/imp_elim.c -o imp_elim.o

modus_tollens.o: MT/modus_tollens.h MT/modus_tollens.c Misc/inf/infixToPrefix.h Misc/inf/infixToPrefix.c
	gcc -c MT/modus_tollens.c -o modus_tollens.o

clean:
	rm *.o
	rm exec
