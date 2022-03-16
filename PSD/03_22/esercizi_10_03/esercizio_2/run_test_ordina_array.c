// file run_test_ordina_array.c

# include <stdio.h>
# include <stdlib.h>
# include "vettore.h"

# define M 20

int run_test_case(char *tc_id, int n);

int main(int argc, char *argv[]){    
    FILE *test_suite, *result;  
    char tc_id[M];  // stringa contenente l'identificativo del test case
    int n, pass;
    
    if(argc < 3){
         printf("Nomi dei file mancanti \n");
         exit(1);
    }    
    
    test_suite = fopen(argv[1], "r");  // apro file contenente test suite               
    result = fopen(argv[2], "w");   // apro file contenente risultati test        
    
    if( test_suite==NULL || result == NULL ) {
        printf("Errore in apertura dei file \n");    
        exit(1);
    }
     
    /* Scansione del file di input nel ciclo while. 
    Ad ogni iterazione si leggono i due elementi di una riga:
    l'identificativo del test case tc_id e il numero n di elementi
    da ordinare */
    
    while(fscanf(test_suite, "%s%d", tc_id, &n) == 2){
         pass = run_test_case(tc_id, n);
    
         fprintf(result,"%s ", tc_id);
         if(pass == 1)
               fprintf(result, "PASS \n");
         else   
               fprintf(result, "FAIL \n");			
         }	
    
    fclose(test_suite);  // chiusura file di input
    fclose(result);         // chiusura file di output
}

int run_test_case(char *tc_id, int n){
    char input_fname[M], output_fname[M], oracle_fname[M];	
    int *input, *oracle;
    // costruiamo i nomi dei file

    switch(tc_id[2]){
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
    input = malloc(sizeof(int) * n);

    if(!input) {
        exit(-1);
    }
 
    // carica file di input
    finput_array(input_fname, input, n);
    // ordina array
    ordina(input, n);
    //  scrive file di output
    foutput_array(output_fname, input, n);
 
    // allochiamo memoria per array oracolo
    oracle = malloc(sizeof(int) * n);
    
    if(!oracle){
        exit(-1);
    }

    // carichiamo oracolo
    finput_array(oracle_fname, oracle, n);

    // confrontiamo array
    return confronta_array(oracle, input, n);
}
