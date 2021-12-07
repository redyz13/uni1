CC=gcc
CFLAGS=-Wall -g
BIN = forno.o ebreo.o

all: forno.out 

forno.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ 

forno.o: forno.c
	$(CC) $(CFLAGS) -c $< 

ebreo.o: ebreo.c ebreo.h
	$(CC) $(CFLAGS) -c $<

spazzacenere:
	rm *.out *.o
