#include <stdio.h>

/*
*   Creato da BP e Anto
    ~ Dedicato al Prof. Distasi
*/

int verifica_range(int data);

int restituisci_anno(int data);

int restituisci_mese(int data);

int restituisci_giorno(int data);

int main() {
    
    int data, bisestile;
    int verifica_rangee, verifica_mese_giorno30, verifica_mese_giorno31, verifica_bisestile;

    printf("Inserisci una data: ");

    scanf("%d", &data);

    // Primo controllo - Verifica che la data sia compresa nell'intervallo
    verifica_rangee =  verifica_range(data);
    
    // Secondo controllo - Verifica che l'anno bisestile sia scritto in formato corretto
    bisestile = restituisci_anno(data) % 4;
    verifica_bisestile = (bisestile != 1 && restituisci_mese(data) == 2 && restituisci_giorno(data) < 29)
        || (bisestile == 0 && restituisci_mese(data) == 2 && restituisci_giorno(data) == 29);
    
    // Terzo controllo - Verifica che i mesi 04, 06, 09 e 11 abbiano 30 giorni
    verifica_mese_giorno30 = (restituisci_mese(data) == 4 || restituisci_mese(data) == 6
        || restituisci_mese(data) == 9 || restituisci_mese(data) == 11) && (restituisci_giorno(data) >= 1
            && restituisci_giorno(data) <=30); 
    
    // Quarto controllo - Verifica che i mesi 01, 03, 05, 07, 08, 10 e 12 abbiano 31 giorni
    verifica_mese_giorno31 = (restituisci_mese(data) == 1 || restituisci_mese(data) == 3
        || restituisci_mese(data) == 5 || restituisci_mese(data) == 7 || restituisci_mese(data) == 8
            || restituisci_mese(data) == 10 || restituisci_mese(data) == 12) 
                && (restituisci_giorno(data) >= 1 && restituisci_giorno(data) <=31); 

    // Controllo finale - Verifica che tutti i controli effettuati siano rispettati
    (verifica_rangee) && (verifica_mese_giorno30 || verifica_mese_giorno31 
        || verifica_bisestile) ? printf("\nData verificata\n") : printf("\nData non verificata\n");
}

int verifica_range(int data) {
    return data >= 1101582 && data <= 31122021;
}

int restituisci_anno(int data) {
    return data % 10000;
}

int restituisci_mese(int data) {
    return (data / 10000) % 100;
}

int restituisci_giorno(int data) {
    return (data / 1000000); 
}
