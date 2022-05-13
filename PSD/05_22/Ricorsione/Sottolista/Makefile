CC=gcc
CFLAGS=-Wall -g
BIN=main.o list.o item.o

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c list.h
	$(CC) $(CFLAGS) -c $<

list.o: list.c list.h
	$(CC) $(CFLAGS) -c $<

item.o: item.c item.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.out
