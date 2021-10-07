#include <stdio.h>

int main() {
    const float costo_unitario = 0.056;
    int codice_utente;
    float kwh_pre, kwh_att, canone;
    float kwh_cons, ammontare;
    
    printf("Inserire il codice utente: ");
    scanf("%d", &codice_utente);

    do {
        printf("\nInserire i kWh della lettura precedente: ");
        scanf("%g", &kwh_pre);

        printf("Inserire i kWh della lettura attuale: ");
        scanf("%g", &kwh_att);
    }while(kwh_pre >= kwh_att);

    do {
        printf("Inserire l'ammontare del canone: ");
        scanf("%g", &canone);
    }while(canone <= 0);

    kwh_cons = kwh_att - kwh_pre;

    ammontare = canone + kwh_cons * costo_unitario;

    printf("\nkWh consumati: %g", kwh_cons);
    printf("\nAmmontare bolletta: %g\n", ammontare);

    return 0;
}
