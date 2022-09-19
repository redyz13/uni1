#include <stdio.h>
#include <string.h>

void dashboard(void);
void inserisci_canzone(void);
void visualizza_canzoni(void);
void modifica_nome(void);
void cancella_artista(void);
void leggi_stringa(char *s, int buff);

int main(void) {
    while (!feof(stdin))
        dashboard();

    return 0;
}

void dashboard(void) {
    printf("1. Visualizza canzoni artista\n2. Inserisci canzone\n");
    printf("3. Modifica nome artista\n4. Cancella canzoni artista\n[] Premere EOF per uscire\n");
    printf("\nSelezione: ");
    char c;
    scanf("%c", &c);
    getchar();

    switch(c) {
        case '1': visualizza_canzoni(); break;
        case '2': inserisci_canzone(); break;
        case '3': modifica_nome(); break;
        case '4': cancella_artista(); break;
        default: printf("\nCarattere non valido\n\n");
    }
}

void inserisci_canzone(void) {
    char nome_canzone[50];
    char nome_artista[50];

    FILE *fp;

    printf("\nInserire il nome della canzone: ");
    leggi_stringa(nome_canzone, 50);
    printf("Inserire il nome dell'artista: ");
    leggi_stringa(nome_artista, 50);

    if ((fp = fopen("archivio.txt", "a")) == NULL) {
        printf("\nIl file non può essere né aperto né creato\n\n");
        return;
    }
    else {
        printf("Inserisco la prima riga con la canzone %s\n", nome_canzone);
        fprintf(fp, "%s\t %s\n", nome_canzone, nome_artista);
        fclose(fp);
        printf("\nCanzone \"%s\" inserita con successo\n\n", nome_canzone);
        return;
    }
}

void visualizza_canzoni(void) {
    char nome_canzone[50];
    char nome_artista[50];
    char nome_ricerca[50];

    FILE *fp;

    printf("\nInserire il nome dell'artista di cui cercare le canzoni: ");
    leggi_stringa(nome_ricerca, 50);

    if ((fp = fopen("archivio.txt", "r")) == NULL) {
        printf("\nIl file non può essere aperto\n\n");
        return;
    }
    else {
        printf("\nCanzoni dell'artista \"%s\":\n", nome_ricerca);
        while (!feof(fp)) {
            fscanf(fp, "%s%s", nome_canzone, nome_artista);
            if (strcmp(nome_ricerca, nome_artista) == 0 && !feof(fp))
                printf("- %s\n", nome_canzone);
        }

        fclose(fp);
        putchar('\n');
        return;
    }
}

void leggi_stringa(char *s, int buff) {
    int ch, i = 0;

    while((ch = getchar()) != '\n')
        if (i < buff)
            s[i++] = ch;

    s[i] = '\0';
}

void modifica_nome(void) {
    char nome_canzone[50];
    char nome_artista[50];
    char nome_nuovo[50];
    char nome_vecchio[50];

    FILE *fp;
    FILE *ftmp;

    printf("\nInserire il nome dell'artista da modificare: ");
    leggi_stringa(nome_vecchio, 50);
    printf("Inserire il nuovo nome dell'artista da modificare: ");
    leggi_stringa(nome_nuovo, 50);

    if ((fp = fopen("archivio.txt", "r")) == NULL) {
        printf("\nIl file non può essere aperto\n\n");
        return;
    }
    else {
        if ((ftmp = fopen("temp.txt", "w")) == NULL) {
            printf("Il file non può essere creato\n");
            return;
        }
        else {
            fscanf(fp, "%s%s", nome_canzone, nome_artista);

            while (!feof(fp)) {
                if (strcmp(nome_vecchio, nome_artista) == 0)
                    fprintf(ftmp, "%s\t %s\n", nome_canzone, nome_nuovo);
                else
                    fprintf(ftmp, "%s\t %s\n", nome_canzone, nome_artista);

                fscanf(fp, "%s%s", nome_canzone, nome_artista);
            }

            fclose(ftmp);
        }

        printf("\nOperazione eseguita\n\n");
        fclose(fp);
    }

    remove("archivio.txt");
    rename("temp.txt", "archivio.txt");
}

void cancella_artista(void) {
    char nome_canzone[50];
    char nome_artista[50];
    char nome_rimozione[50];

    FILE *fp;
    FILE *ftmp;

    printf("\nInserire il nuovo nome dell'artista da rimuovere: ");
    leggi_stringa(nome_rimozione, 50);

    if ((fp = fopen("archivio.txt", "r")) == NULL) {
        printf("\nIl file non può essere aperto\n\n");
        return;
    }
    else {
        if ((ftmp = fopen("temp.txt", "w")) == NULL) {
            printf("Il file non può essere creato\n");
            return;
        }
        else {
            fscanf(fp, "%s%s", nome_canzone, nome_artista);

            while (!feof(fp)) {
                if (strcmp(nome_rimozione, nome_artista) == 0)
                    fscanf(fp, "%s%s", nome_canzone, nome_artista);
                else
                    fprintf(ftmp, "%s\t %s\n", nome_canzone, nome_artista);

                fscanf(fp, "%s%s", nome_canzone, nome_artista);
            }

            fclose(ftmp);
        }

        printf("\nOperazione eseguita\n\n");
        fclose(fp);
    }

    remove("archivio.txt");
    rename("temp.txt", "archivio.txt");
}