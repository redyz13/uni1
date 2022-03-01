CC=gcc
CFLAGS=-Wall -g

all: spartiacque.out

spartiacque.out: spartiacque.o
	$(CC) $(CFLAGS) -o $@ $<

spartiacque.o: spartiacque.c
	$(CC) $(CFLAGS) -c $< 

clean:
	rm *.out *.o