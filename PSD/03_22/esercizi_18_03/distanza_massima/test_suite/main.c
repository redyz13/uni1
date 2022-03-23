#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "punto.h"
#include "file.h"

#define M 20

int run_test_case(char *tc_id, int d);

int main(int argc, char **argv) {
    FILE *test_suite, *result;
    int pass;
    float d;
    char tc_id[M];

    if(argc < 3) {
        printf("Nomi dei file mancanti\n");
        exit(-1);
    }

    test_suite = fopen(argv[1], "r");
    result = fopen(argv[2], "w");

    if(!test_suite || !result) {
        printf("Errore in apertura dei file\n");
        exit(-1);
    }

    while(fscanf(test_suite, "%s%f", tc_id, &d) == 2) {
        pass = run_test_case(tc_id, d);

        fprintf(result, "%s ", tc_id);
        
        pass == 1 ? fprintf(result, "PASS\n") : fprintf(result, "FAIL\n");
    }

    fclose(test_suite);
    fclose(result);

    return 0;
}

int run_test_case(char *tc_id, int d) {
    char input_fname[M], output_fname[M], oracle_fname[M];	
    punto *input;
    float output, oracle;
    int npunti;

    strcpy(input_fname, tc_id);
    strcat(input_fname, "_input.txt");

    strcpy(output_fname, tc_id);
    strcat(output_fname, "_output.txt");

    strcpy(oracle_fname, tc_id);
    strcat(oracle_fname, "_oracle.txt");

    input = finput_punto(input_fname, &npunti);

    // Calcola le distanze a coppie e controlla che siano minori di d
    output = calcolo_distanze(input, npunti, d);

    foutput_punto(output_fname, output);

    oracle = fread_oracle(oracle_fname);

    return output == oracle ? 1 : 0;
}
