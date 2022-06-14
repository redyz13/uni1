CC= gcc
CFLAGS= -Wall -g
BIN= main.o btree.o list.o item.o

all: btree.out

btree.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c $<

btree.o: btree.c btree.h 
	$(CC) $(CFLAGS) -c $<

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $< 

item.o: item.c item.h
	$(CC) $(CFLAGS) -c $< 

clean: 
	rm *.o *.out
