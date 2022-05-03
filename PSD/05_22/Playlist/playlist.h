#include "canzone.h"

typedef struct Queue *Playlist;

Playlist newPlaylist(void);

int isEmpty(Playlist p);

int enqueue(Playlist p, Canzone c);

Canzone dequeue(Playlist p);

/* Specifica sintattica:
*    removeCanzone(Playlist, int) -> bool
*
*  Specifica semantica:
*    Precondizioni:
*       1. La playlist deve esistere
*       2. La posizione deve esistere all'interno della playlist
*    Postcondizioni:
*       1. Ritorna 1 se c'è stata la rimozione della canzone,
*       altrimenti 0
*
*   Progettazione:
*       Se la playlist non esiste ritorna 0
*       Se la posizione indicata è la posizione 0, rimuove la prima
*       canzone della lista e ritorna 1
*       Se la posizione è maggiore di 0 allora itera fino a trovare la canzone
*       corrispondente, se viene trovata, viene rimossa e viene restituito 1,
*       se la canzone non è stata trovata, restituisce 0
*/
int removeCanzone(Playlist p, int pos);

/* Specifica sintattica:
*    forward(Playlist, int) -> bool
*
*  Specifica semantica:
*    Precondizioni:
*       1. La playlist deve esistere
*       2. Il forward può essere fatto dalla canzone 0
*          alla canzone n - 1, dove n è il numero di canzoni
*          presenti nella lista
*/
int forward(Playlist p, int pos);

void printPlaylist(Playlist p);

void freePlaylist(Playlist p);
