CC = gcc
CFLAGS = -Wall -g
BIN = main.o playlist.o canzone.o

all: main.out

main.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c playlist.h
	$(CC) $(CFLAGS) -c $<

playlist.o: playlist.c playlist.h
	$(CC) $(CFLAGS) -c $<

canzone.o: canzone.c canzone.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.out
