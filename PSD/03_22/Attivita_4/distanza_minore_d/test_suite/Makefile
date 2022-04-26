punto.out: punto.o main.o file.o
	gcc -Wall punto.o main.o file.o -o punto.out -lm

main.o: main.c
	gcc -Wall -c main.c -lm

punto.o: punto.c punto.h
	gcc -Wall -c punto.c -lm

file.o: file.c file.h
	gcc -Wall -c file.c

clean: 
	rm *.o punto.out
