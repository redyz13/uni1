CC=gcc 
CFLAGS= -Wall -g
BIN=main.o list.o punto.o

all: main.out

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ -lm

main.o: main.c list.h util.h
	$(CC) $(CFLAGS) -c $<

list.o: list.c list.h 
	$(CC) $(CFLAGS) -c $<

punto.o: punto.c punto.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.out
