typedef struct Punto *Punto;

#define NULLITEM NULL

Punto creaPunto(float x, float y);

void printItem(Punto p);

float getAscissa(Punto p);

float getOrdinata(Punto p);

int isEqual(Punto p1, Punto p2);

float distanza(Punto p1, Punto p2);

void freePunto(Punto p);
