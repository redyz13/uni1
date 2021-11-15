// 151202 --> 15 dicembre 2002
#include <stdio.h>

int verifica_data(int giorno, int mese, int anno);
int divisione_data(int data, int *giorno, int *mese, int *anno);
void ciruzzo_ritornami_mese(int mese);

int main() {
    int data;
    int g, m, a;

    printf("Inserire la data: ");
    scanf("%d", &data);

    divisione_data(data, &g, &m, &a);

    if(verifica_data(g, m, a) == 0) {
        printf("\nCiao");
        ciruzzo_ritornami_mese(m);
    }
    else {

    }

    return 0;
}

int divisione_data(int data, int *giorno, int *mese, int *anno) {
   if((data / 1000000) != 0)
       return -1;

    *anno = data % 100;
    *mese = data % 10000;
    *giorno = data % 1000000;
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


void ciruzzo_ritornami_mese(int mese) {
        
}
