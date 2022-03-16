// FILE:   vettore.c
// restituisce 1 se i due vettori di ingresso sono uguali, 0 altrimenti

#include "vettore.h"
#include <stdio.h>
#include <stdlib.h>

int confronta_array(int a[], int b[], int n){
    int i;

    for(i = 0; i < n; i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    
    return 1;
}

void foutput_array(char *file_name, int a[], int n) 
{  
	int i;  
	FILE *fd; 	

    //aprire il file in scrittura
    fd = fopen(file_name, "w");

    //controllare che il file sia stato aperto correttamente
    if (!fd){
        fprintf(stderr, "Apertura del file non riuscita\n");
        exit(-1);
    }
    //e scrivere il contenuto (fprintf()) di a in fd
	for(i = 0; i < n; i++){
        fprintf(fd, "%d\n", a[i]);
    }
	// chiudere il file
    fclose(fd);
}

void finput_array(char *file_name, int a[], int n)
{
	int i;
	FILE *fd;

    //apertura file in lettura
	fd = fopen(file_name, "r");
	
	//Controllare se il file esiste e
    if (!fd){
        fprintf(stderr, "Apertura del file non riuscita\n");
        exit(-1);
    }
	//leggere il contenuto (fscanf()) da scrivere in array a
	for(i = 0; i < n; i++){
        fscanf(fd, "%d", &a[i]);
    }
	
	//chiudere il file
	fclose(fd);
}

void ordina(int a[], int n){
    int i, j;
    int temp; 

    for(i = 0; i < n; i++){
        for(j = 0; j < (n - 1 - i); j++){
            if (a[j] > a[j+1]){
                scambia(&a[j], &a[j+1]);
            }
        }
    }
}
   

