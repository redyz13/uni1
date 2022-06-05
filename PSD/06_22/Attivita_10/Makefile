CC= gcc
CFLAGS= -Wall -g
BIN= main.o btree.o queue.o item.o

all: btree.out

btree.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c util.h btree.h 
	$(CC) $(CFLAGS) -c $<

btree.o: btree.c btree.h 
	$(CC) $(CFLAGS) -c $<

queue.o: queue.c queue.h 
	$(CC) $(CFLAGS) -c $<

item.o: item.c item.h
	$(CC) $(CFLAGS) -c $< 

clean: 
	rm *.o *.out
