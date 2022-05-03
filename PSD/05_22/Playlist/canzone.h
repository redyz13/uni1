typedef struct Item *Canzone;

#define NULLITEM NULL;

Canzone creaCanzone(char *ti, char *ca, int du);

char *getTitolo(Canzone c);

char *getCantante(Canzone c);

int getDurata(Canzone c);

void printCanzone(Canzone c);

void freeCanzone(Canzone c);
