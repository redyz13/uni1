CC=gcc
CFLAGS=-Wall -g
BIN = operazioni_matrici.o op_matrici.o

all: operazioni_matrici.out

operazioni_matrici.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

operazioni_matrici.o: operazioni_matrici.c
	$(CC) $(CFLAGS) -c $<

op_matrici.o: op_matrici.c op_matrici.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out *.o
