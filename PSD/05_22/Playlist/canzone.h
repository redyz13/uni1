typedef struct Item *Canzone;

#define NULLITEM NULL;

Canzone creaCanzone(char *ti, char *ca, int du);

void printCanzone(Canzone c);

void freeCanzone(Canzone c);
