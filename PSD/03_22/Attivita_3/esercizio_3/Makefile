run.out: vettore.o run_test_inserisci.o
	gcc vettore.o run_test_inserisci.o -o run.out

vettore.o: vettore.c
	gcc -c vettore.c

run_test_inserisci.o: run_test_inserisci.c vettore.h
	gcc -c run_test_inserisci.c
