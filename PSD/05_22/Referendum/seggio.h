typedef struct Seggio *Seggio;

typedef struct Scheda *Scheda;

#define NULLITEM NULL

Scheda creaScheda(int id_scheda, int aventi_diritto_voto, int votanti,
                  int voti_nulli, int voti_si, int voti_no);

void printSeggio(Seggio seggio);

Scheda getScheda(Seggio seggio);

int getIdScheda(Scheda scheda);

int getIdSeggio(Seggio seggio);

Seggio creaSeggio(int id_seggio, Scheda scheda);