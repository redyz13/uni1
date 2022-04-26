CC=gcc
CFLAGS=-Wall -g
BIN=main.o libro.o

all: main.out

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c libro.h
	$(CC) $(CFLAGS) -c $<

libro.o: libro.c libro.h 
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.out
