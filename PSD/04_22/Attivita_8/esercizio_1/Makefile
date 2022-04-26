CC=gcc 
CFLAGS= -Wall -g
BIN=main.o queue.o punto.o

all: main.out

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ -lm

main.o: main.c queue.h util.h
	$(CC) $(CFLAGS) -c $<

queue.o: queue.c queue.h 
	$(CC) $(CFLAGS) -c $<

punto.o: punto.c punto.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.out
