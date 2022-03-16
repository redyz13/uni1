// FILE: vettore.c
// restituisce 1 se i due vettori di ingresso sono uguali, 0 altrimenti

#include "vettore.h"
#include <stdio.h>
#include <stdlib.h>

int confronta_array(int a[], int b[], int n) {  
    int i;

    for(i = 0; i < n; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }

    return 1;
}

void inserisci(int a[], int *n, int el, int pos) {
    int i;

    for(i = *n; i > pos; i--) {
        a[i] = a[i-1];
    }

    a[pos] = el;
    (*n)++;
}

void foutput_array(char *file_name, int a[], int n) {  
    int i;  
    FILE *fd; 	

    fd=fopen(file_name, "w"); 		

    if(fd==NULL) 
        printf("Errore in apertura del file %s \n", file_name);    
    else {
            for(i=0; i<n; i++)      
                fprintf(fd, "%d\n", a[i]);		
            fclose(fd); 
    }
}

void finput_array(char *file_name, int a[], int n) {
    int i;
    FILE *fd;

    fd=fopen(file_name, "r");

    if(fd==NULL) {
        printf("Errore in apertura del file %s \n", file_name);
    }
    else {
        for(i=0; i<n; i++) {
            fscanf(fd, "%d", &a[i]);
        }

        fclose(fd);
    }
}
