// Give the item a type
typedef struct Libretto *Libretto;
typedef struct Esame *Lista_esami;

// Print data of an item to stdout
void printLibretto(Libretto data);

// Costruttore libretto
Libretto new_lib(char *, char *, int, Lista_esami);

// Getters
char *getNome(Libretto);
char *getCognome(Libretto);
int getMatricola(Libretto);
Lista_esami getLista_esami(Libretto);
int getVoto(Lista_esami);

// Setters
void setVoto(Lista_esami);

// Calcolo della media
float getMedia(Lista_esami);

// Cerca esame
int cercaEsame(Libretto lib, char *nome_esame);

// Controlla se il libretto non ha voti
int isEmpty(Libretto);

// Confronta il nome di due esami 
int equal(Lista_esami, Lista_esami);
