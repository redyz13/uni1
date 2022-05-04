#include "seggio.h"

typedef struct Referendum *Referendum;

Referendum creaRef(void);

int isEmpty(Referendum r);

Referendum insertSeggio(Referendum r, Seggio seggio);

void printSeggi(Referendum r);

// Verifica se la lista dei seggi è completa
int completeRef(Referendum r);