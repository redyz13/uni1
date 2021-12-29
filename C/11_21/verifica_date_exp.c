// 151202 --> 15 dicembre 2002
/*
* Visualizza unicamento le date del millennio 2000
*/
#include <stdio.h>
#include <string.h>

#define SIZE 10

const char *months[12] = {
    "Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio",
    "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre",
    "Novembre", "Dicembre"
};

int verifica_data(int giorno, int mese, int anno);
void divisione_data(int data, int *giorno, int *mese, int *anno);

int main() {
    int data;
    int g, m, a;
    char m_string[SIZE];

    printf("Inserire la data: ");
    scanf("%d", &data);

    divisione_data(data, &g, &m, &a);

    if(verifica_data(g, m, a) == 0) {
        strcpy(m_string, months[m-1]);

        if(a > 9)
            printf("\nHai inserito la data: %d %s 20%d\n", g, m_string, a);
        else
            printf("\nHai inserito la data: %d %s 200%d\n", g, m_string, a);
    }
    else {
        printf("\nErrore data\n");
    }


    return 0;
}

void divisione_data(int data, int *giorno, int *mese, int *anno) {
    *anno = data % 100;
    *mese = (data / 100) % 100;
    *giorno = data / 10000;
}

int verifica_data(int giorno, int mese, int anno) {
    if(anno < 0) {
        return -1;
    }
    else if(mese < 1 || mese > 12) {
        return -1;
    }
    else if(giorno < 1 || giorno > 31){
        return -1;
    }
    else if((anno % 4 != 0 && mese == 2 && giorno > 28) || (anno % 4 == 0 && mese == 2 && giorno > 29)) {
        return -1;
    }
    else if((mese == 4 || mese == 6 || mese == 9 || mese == 1) && giorno > 30) {
        return -1;
    }
    else if((mese == 1 || mese == 3 || mese == 5 || mese == 7 || mese == 8 || 
             mese == 10 || mese == 12) && giorno > 31) {

        return -1;
    }
    else {
        return 0;
    }
}
