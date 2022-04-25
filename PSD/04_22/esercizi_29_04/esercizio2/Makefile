CC=gcc 
CFLAGS= -Wall -g
BIN=main.o queue.o processo.o

all: main.out

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c queue.h util.h
	$(CC) $(CFLAGS) -c $<

queue.o: queue.c queue.h 
	$(CC) $(CFLAGS) -c $<

processo.o: processo.c processo.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.out
