// 151202 --> 15 dicembre 2002
/*
* Visualizza unicamento le date del millennio 2000
*/
#include <stdio.h>
#include <string.h>

#define SIZE 10

int verifica_data(int giorno, int mese, int anno);
void divisione_data(int data, int *giorno, int *mese, int *anno);
void ritorna_mese(int mese, char m_string[]);

int main() {
    int data;
    int g, m, a;
    char m_string[SIZE];

    printf("Inserire la data: ");
    scanf("%d", &data);

    divisione_data(data, &g, &m, &a);

    if(verifica_data(g, m, a) == 0) {
        ritorna_mese(m, m_string);

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


void ritorna_mese(int mese, char m_string[]) {
    switch(mese) {
        case 1: strcpy(m_string, "Gennaio"); break;
        case 2: strcpy(m_string, "Febbraio"); break;
        case 3: strcpy(m_string, "Marzo"); break;
        case 4: strcpy(m_string, "Aprile"); break;
        case 5: strcpy(m_string, "Maggio"); break;
        case 6: strcpy(m_string, "Giugno"); break;
        case 7: strcpy(m_string, "Luglio"); break;
        case 8: strcpy(m_string, "Agosto"); break;
        case 9: strcpy(m_string, "Settembre"); break;
        case 10: strcpy(m_string, "Ottobre"); break;
        case 11: strcpy(m_string, "Novembre"); break;
        case 12: strcpy(m_string, "Dicembre");
    }
}
