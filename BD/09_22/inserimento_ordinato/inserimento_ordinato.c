#include <stdio.h>
#include <string.h>

int insert_into(char *matricola, char *nome, double media_voti);
void stampa_file(void);

int main(void) {
    char matricola[3];
    char nome[50];
    double media_voti;

    // Variabile di controllo sull'output della funzione
    int res = -1;

    stampa_file();

    printf("Inserisci la matricola, il nome e la media dei voti di uno studente\n");
    printf("Inserisci EOF per concludere l'inserimento dei dati\n");
    scanf("%s%s%lf", matricola, nome, &media_voti);

    // Richiama la funzione per scrivere nel file
    while (!feof(stdin)) {
        res = insert_into(matricola, nome, media_voti);
        if (res == 0)
            printf("Studente %s inserito con successo\n", nome);
        else
            printf("Studente %s NON inserito\n", nome);
        scanf("%s%s%lf", matricola, nome, &media_voti);
    }

    return 0;
}

int insert_into(char *matricola_new, char *nome_new, double media_voti_new) {
    char matricola[3];
    char nome[50];
    double media_voti;

    FILE *f_in; // Puntatore del file studenti.txt
    FILE *f_temp; // Puntatore del file temporaneo

    int inserted = 0; // Variabile di controllo per l'inserimento

    if ((f_in = fopen("studentiOrd.txt", "r")) == NULL) {
        if ((f_in = fopen("studentiOrd.txt", "w")) == NULL) {
            printf("Il file non può essere né aperto né creato\n");
            return -1;
        }
        else {
            printf("Inserisco la prima riga con lo studente %s\n", nome_new);
            fprintf(f_in, "%s\t %s\t %lf\n", matricola_new, nome_new, media_voti_new);
            fclose(f_in);
            return 0;
        }
    }
    else {
        if ((f_temp = fopen("temp.txt", "w")) == NULL)
            printf("Il file non può essere creato\n");
        else {
            fscanf(f_in, "%s%s%lf", matricola, nome, &media_voti);

            // Legge i dati dal file
            while (!feof(f_in)) {
                if (strcmp(matricola, matricola_new) == 0) {
                    printf("Non puoi inserire uno studente con la stessa matricola\n");
                    fclose(f_temp);
                    fclose(f_in);
                    remove("temp.txt");
                    return -1;
                }
                else if (strcmp(matricola, matricola_new) > 0) {
                    fprintf(f_temp, "%s\t %s\t %lf\n", matricola_new, nome_new, media_voti_new);
                    inserted = 1;
                }
                
                fprintf(f_temp, "%s\t %s\t %lf\n", matricola, nome, media_voti);
                fscanf(f_in, "%s%s%lf", matricola, nome, &media_voti);
            }

            if (inserted == 0)
                fprintf(f_temp, "%s\t %s\t %lf\n", matricola_new, nome_new, media_voti_new);

            fclose(f_temp);
        }

        fclose(f_in);
    }

    remove("studentiOrd.txt");
    rename("temp.txt", "studentiOrd.txt");

    return 0;
}

void stampa_file(void) {
    FILE *f_in;

    if ((f_in = fopen("studentiOrd.txt", "r")) == NULL)
        return;
    else {
        char matricola[3];
        char nome[50];
        double media_voti;

        while (!feof(f_in)) {
            fscanf(f_in, "%s%s%lf", matricola, nome, &media_voti);
            printf("%s\t %s\t %lf\n", matricola, nome, media_voti);
        }
    }

    fclose(f_in);
}