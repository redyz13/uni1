typedef struct miopunto *punto;

punto creapunto(float x, float y); 
float ascissa(punto p);
float ordinata(punto p);
float distanza(punto p1, punto p2);
void stampa(punto p);
int calcolo_distanze(punto *p, int n, int d);
