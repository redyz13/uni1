typedef struct Processo *Processo;

#define NULLITEM NULL

Processo creaProcesso(int id, int cpu_burst);

void printProcesso(Processo p);

int getID(Processo p);

int getBurst(Processo p);

void setID(Processo p, int id);

void setBurst(Processo p, int cpu_burst);

void freeProcesso(Processo p);
