#include "seggio.h"

typedef struct Referendum *Referendum;

Referendum creaRef(void);

int isEmpty(Referendum r);

Referendum insertSeggio(Referendum r, Seggio seggio);

void stampa(Referendum r);