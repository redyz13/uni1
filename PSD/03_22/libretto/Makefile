CC=gcc
CFGLAGS=-Wall -g
BIN = main.o list.o libretto.o

all: main.out

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

list.o: list.c list.h libretto.h
	$(CC) $(CFLAGS) -c $<

libretto.o: libretto.c libretto.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out *.o
