typedef struct Libro *Libro;

Libro creaLibro(char *t, char *e, float p, int a);

char *getTitolo(Libro l);

char *getEditore(Libro l);

int getAnno(Libro l);

float getPrezzo(Libro l);

float sconto(Libro *l, float percentuale);

void aggiornaAnno(Libro *l, int anno);

void printLibro(Libro l);

void freeLibro(Libro l);
