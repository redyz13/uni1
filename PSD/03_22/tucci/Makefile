CC=gcc
CFGLAGS=-Wall -g
BIN = main.o list.o item.o

all: main.out

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

list.o: list.c list.h item.h
	$(CC) $(CFLAGS) -c $<

item.o: item.c item.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out *.o
