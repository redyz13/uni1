#include <stdio.h>
#include <stdlib.h>
#include "processo.h"

struct Processo {
    int id;
    int cpu_burst;
};

void printProcesso(Processo p){
    printf("ID: %d\n", p->id);
    printf("Cpu-Burst: %d\n", p->cpu_burst);
}

Processo creaProcesso(int id, int cpu_burst) {
    Processo p; 
    
    p = malloc(sizeof(*p));
    if(!p) return NULL;

    p->id = id;
    p->cpu_burst = cpu_burst;
    
    return p;
}

int getID(Processo p) {
    return p->id;
}

int getBurst(Processo p) {
    return p->cpu_burst;
}

void setID(Processo p, int id) {
    p->id = id;
}

void setBurst(Processo p, int cpu_burst) {
    p->cpu_burst = cpu_burst;
}

void freeProcesso(Processo p) {
    free(p);
}
