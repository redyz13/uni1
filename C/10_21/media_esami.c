/*
*   Stampa la media di un numero variabile di esami usando
*   una sentinella voti esami interi
*/

#include <stdio.h>

int main() {
    int voto = 0, contatore_voti = 0;
    int somma = 0;
    
    printf("\nCalcolo media esami: ");
    printf("\nIl voto deve essere compreso tra 18 e 30 o essere pari a 33 (lode)");
    printf("\nInserire -1 per uscire\n");

    while(voto != -1) {
       printf("\nInserisci voto esame: ");
       scanf("%d", &voto);

       if((voto >= 18 && voto <= 30) || voto == 33) {
           somma += voto;
           contatore_voti++;
       }
       else if(voto != -1) {
           printf("\n[Inserire un valore corretto]\n");
       }
       else {
           printf("\n[Calcolo Media]\n");
       }
    }
    
    printf("\nMedia dei voti = %.2f\n", (float)somma / contatore_voti);

    return 0;
}
