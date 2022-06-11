CC=gcc
CFLAGS=-Wall -g
BIN=main.o pqueue.o key.o

all: pqueue.out

pqueue.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c util.h
	$(CC) $(CFLAGS) -c $<

pqueue.o: pqueue.c pqueue.h
	$(CC) $(CFLAGS) -c $<

key.o: key.c key.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.out
