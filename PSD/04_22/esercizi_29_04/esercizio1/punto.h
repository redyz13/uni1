typedef struct Punto *Punto;

#define NULLITEM NULL

Punto creaPunto(float x, float y);

void printPunto(Punto p);

float getAscissa(Punto p);

float getOrdinata(Punto p);

float distanza(Punto p1, Punto p2);

void freePunto(Punto p);
