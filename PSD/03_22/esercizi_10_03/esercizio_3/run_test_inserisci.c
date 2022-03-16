// file run_test_ins_array.c

#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

#define M 20
#define EXTRA 1    // spazio extra per consentire inserimento

int run_test_case(char *tc_id, int n, int elem, int pos) {
    // dichiarazione delle variabili necessarie
    
    TODO
    
    // costruiamo i nomi dei file
    
    TODO
    
    // allochiamo memoria per array di input
    // carica file di input
    
    TODO
        
    // inserimento in array
    // NB: n è stato incrementato nella funzione inserisci
    // scrive file di outptut
    
    TODO
    
    // allochiamo memoria per array oracolo
    // carichiamo oracolo
    // confrontiamo array
    
    TODO	
}	

int main(int argc, char *argv[]) { 	
    FILE *test_suite, *result;  
    
    TODO
    
    // stringa contenente l'identificativo del test case
    // apro file contenente test suite               
    // apro file contenente risultati test        
    
    TODO
    
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i quattro elementi di una riga:
    l’identificativo del test case tc_id, il numero n di elementi
    da ordinare, l’elemento elem da inserire e la posizione pos  */
    
    TODO
    
    // chiusura file di input
    // chiusura file di output
    TODO
}
