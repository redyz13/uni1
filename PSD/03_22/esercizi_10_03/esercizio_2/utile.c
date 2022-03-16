// Implementazione del Modulo: file utile.c

/* commenti relativi alla progettazione 
e realizzazione della funzione scambia */
void scambia(int * x, int * y)
{	
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}
