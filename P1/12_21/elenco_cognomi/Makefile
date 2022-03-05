CC=gcc
CFLAGS=-Wall -g
BIN = elenco_cognomi.o persona.o

all: elenco_cognomi.out 

elenco_cognomi.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ 

elenco_cognomi.o: elenco_cognomi.c
	$(CC) $(CFLAGS) -c $< 

persona.o: persona.c persona.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out *.o
