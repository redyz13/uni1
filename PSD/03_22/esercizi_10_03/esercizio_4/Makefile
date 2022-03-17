run.out: vettore.o run_test_somma_array.o
	gcc vettore.o run_test_somma_array.o -o run.out

vettore.o: vettore.c
	gcc -c vettore.c

run_test_somma_array.o: run_test_somma_array.c vettore.h
	gcc -c run_test_somma_array.c
