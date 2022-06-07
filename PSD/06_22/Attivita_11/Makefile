CC= gcc
CFLAGS= -Wall -g
BIN= main.o bst.o btree.o queue.o item.o

all: bst.out

bst.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c util.h bst.h 
	$(CC) $(CFLAGS) -c $<

bst.o: bst.c bst.h 
	$(CC) $(CFLAGS) -c $<

btree.o: btree.c btree.h
	$(CC) $(CFLAGS) -c $<

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c $<

item.o: item.c item.h
	$(CC) $(CFLAGS) -c $< 

clean: 
	rm *.o *.out
