run.out: utile.o vettore.o run_test_ordina_array.o
	gcc utile.o vettore.o run_test_ordina_array.o -o run.out

utile.o: utile.c
	gcc -c utile.c

vettore.o: vettore.c utile.h
	gcc -c vettore.c 

run_test_ordina_array.o: run_test_ordina_array.c vettore.h
	gcc -c run_test_ordina_array.c


