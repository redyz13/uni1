punto.out: punto.o main.o
	gcc -Wall punto.o main.o -o punto.out -lm

main.o: main.c
	gcc -Wall -c main.c -lm

punto.o: punto.c punto.h
	gcc -Wall -c punto.c -lm

clean: 
	rm *.o punto.out
