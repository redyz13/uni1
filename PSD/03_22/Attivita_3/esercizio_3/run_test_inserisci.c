// FILE: run_test_ins_array.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"

#define M 20
#define EXTRA 1 // spazio extra per consentire inserimento

int run_test_case(char *tc_id, int n, int elem, int pos);

int main(int argc, char *argv[]) { 	
    FILE *test_suite, *result;
    int n, elem, pos, pass;
    char tc_id[M];

    if(argc < 3) {
        printf("Nomi dei file mancanti\n");
        exit(-1);
    }
    
    // stringa contenente l'identificativo del test case
    // apro file contenente test suite               
    // apro file contenente risultati test        
    test_suite = fopen(argv[1], "r");
    result = fopen(argv[2], "w");

    if(!test_suite || !result) {
        printf("Errore in apertura dei file\n");
        exit(-1);
    }
    
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i quattro elementi di una riga:
    l'identificativo del test case tc_id, il numero n di elementi
    da ordinare, l'elemento elem da inserire e la posizione pos  */
    
    while(fscanf(test_suite, "%s%d%d%d", tc_id, &n, &elem, &pos) == 4) {
        pass = run_test_case(tc_id, n, elem, pos);

        fprintf(result, "%s ", tc_id);

        if(pass == 1)
            fprintf(result, "PASS\n");
        else
            fprintf(result, "FAIL\n");
    }
    
    // chiusura file di input
    fclose(test_suite);
    // chiusura file di output
    fclose(result);
}

int run_test_case(char *tc_id, int n, int el, int pos) {
    // dichiarazione delle variabili necessarie
    char input_fname[M], output_fname[M], oracle_fname[M];	
    int *input, *oracle;
    
    // costruiamo i nomi dei file
    switch(tc_id[2]) {
        case '1':
            strcpy(input_fname, "TC1_input.txt");
            strcpy(oracle_fname, "TC1_oracle.txt");
            strcpy(output_fname, "TC1_output.txt");
            break;
        case '2': 
            strcpy(input_fname, "TC2_input.txt");
            strcpy(oracle_fname, "TC2_oracle.txt");
            strcpy(output_fname, "TC2_output.txt");
            break;
        case '3': 
            strcpy(input_fname, "TC3_input.txt");
            strcpy(oracle_fname, "TC3_oracle.txt");
            strcpy(output_fname, "TC3_output.txt");
            break;
        case '4':
            strcpy(input_fname, "TC4_input.txt");
            strcpy(oracle_fname, "TC4_oracle.txt");
            strcpy(output_fname, "TC4_output.txt");
    }

    // allochiamo memoria per array di input
    input = malloc(sizeof(int) * n + 1);

    if(!input) {
        exit(-1);
    }
    // carica file di input
    finput_array(input_fname, input, n);

    // inserimento in array
    inserisci(input, &n, el, pos);
    // NB: n è stato incrementato nella funzione inserisci
    // scrive file di outptut
    foutput_array(output_fname, input, n);

    // allochiamo memoria per array oracolo
    oracle = malloc(sizeof(int) * n);
    
    if(!oracle) {
        exit(-1);
    }

    // carichiamo oracolo
    finput_array(oracle_fname, oracle, n);
    // confrontiamo array

    return confronta_array(oracle, input, n);
}
