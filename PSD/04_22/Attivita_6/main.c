#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void) {
    List list;
    int d_min;
    Punto p;
    
    list = newList();

    for(int i = 1; i < 9; i++) {
        p = creaPunto(i, i);
        if(p == NULL) return -1;
        list = addHead(list, p);
    }

    list = reverseList(list);
    printList(list);
    
    d_min = distanza_minore(list, 0.5);
    
    printf("Il numero di coppie con una distanza minore di 0.5 sono %d\n", d_min);

    Punto *coppia;

    coppia = distanza_massima(list);

    printf("\nCoppia di punti a distanza massima:\n");
    printItem(coppia[0]);
    printItem(coppia[1]);
    
    char criterio, coordinata;
    
    printf("\nAggiungi la coordinata da ordinare: ");
    coordinata = getchar();

    printf("Aggiungi il criterio secondo cui ordinarla");
    printf(" (c = crescente , d = decrescente): ");
    
    getchar();
    
    criterio = getchar();

    list = reverseList(list);

    riordina(&list, coordinata, criterio);

    putchar('\n');
    printList(list);

    List sotto_l;

    sotto_l = sottolista(&list, 2, 5);
    
    printf("\nLista vecchia\n");
    printList(list);

    printf("\nSottolista\n");
    printList(sotto_l);
    
    List k; 

    k = newList();

    for(int i = 9; i < 11; i++) {
        k = addHead(k, creaPunto(i, i));
    }
    
    k = reverseList(k);

    list = inserisci_lista(list, k, 3);
    
    printf("Lista l dopo l'aggiunta: \n");
    printList(list);
    
    putchar('\n');

    printf("Lista k dopo l'aggiunta: \n");
    printList(k);
    
    return 0;
}

int distanza_minore(List l, float d) {
    int size = sizeList(l);
    int coppie = 0;
    float d_tmp;
    Punto prev, p; 

    prev = getFirst(l); 

    for(int i = 1; i < size; i++) {
        p = getItem(l, i);

        d_tmp = distanza(p, prev); 
    
        if(d_tmp < d) {
            coppie++;
        }

        prev = p;
    }
    return coppie;
}

Punto *distanza_massima(List l) {
    int size = sizeList(l);
    int index = 1;
    float d_tmp;
    Punto prev, p; 
    float max;
    Punto *coppia;

    coppia = malloc(sizeof(Punto) * 2);
    if(coppia == NULL) return NULL;

    prev = getFirst(l); 
    p = getItem(l, 1);

    d_tmp = distanza(p, prev);

    max = d_tmp; 

    prev = p;

    for(int i = 2; i < size; i++) {
        p = getItem(l, i);

        d_tmp = distanza(p, prev); 
    
        if(max < d_tmp) {
            max = d_tmp;
            index = i;
        }

        prev = p;
    }
    
    coppia[0] = getItem(l, index - 1);
    coppia[1] = getItem(l, index);
    
    return coppia;
}

// Precondizione m < n < sizeList
List sottolista(List *l, int m, int n) {
    if(isEmpty(*l)) return *l;

    List sotto_lista, new, tmp;
    Punto val;
    int i;

    sotto_lista = newList();
    new = newList();

    // Vecchia lista 1
    for(i = 0; i < m; i++) {
        val = getFirst(*l);
        new = addHead(new, val);
        tmp = *l;
        *l = tailList(*l);
        free(tmp);
    }

    // Sottolista
    for(i = 0; i <= n - m; i++) {
        val = getFirst(*l);
        sotto_lista = addHead(sotto_lista, val);
        tmp = *l;
        *l = tailList(*l);
        free(tmp);
    }
    
    sotto_lista = reverseList(sotto_lista);

    // Vecchia lista 2
    while(!isEmpty(*l)) {
        val = getFirst(*l);
        new = addHead(new, val);
        tmp = *l;
        *l = tailList(*l);
        free(tmp);
    }
    
    *l = reverseList(new);

    return sotto_lista;
}

List inserisci_lista(List l, List k, int m) {
    int i;
    List new;
    Punto val;

    new = newList();

    for(i = 0; i <= m; i++) {
        val = getFirst(l);
        new = addHead(new, val); 
        l = tailList(l);
    }

    while(!isEmpty(k)) {
        val = getFirst(k);
        new = addHead(new, val);
        k = tailList(k);
    }

    while(!isEmpty(l)) {
        val = getFirst(l);
        new = addHead(new, val);
        l = tailList(l);
    }

    l = reverseList(new); 

    return l;
}

void riordina(List *l, char coordinata, char criterio) {
    Punto p, min;
    float x, y;
    int size = sizeList(*l);
    int i, j, min_index;

    List new = newList();

    min_index = 0;

    for(i = 0; i < size; i++) {
        min = getFirst(*l);

        for(j = 1; j < sizeList(*l); j++) {
            p = getItem(*l, j);

            if(coordinata == 'x') {
                x = getAscissa(p);
                if(getAscissa(min) > x) {
                    min = p;
                    min_index = j;
                }
            }
            else if(coordinata == 'y') {
                y = getOrdinata(p);
                if(getOrdinata(min) > y) {
                    min = p;
                    min_index = j;
                }
            }
        }

        new = addHead(new, min);
        *l = removeList(*l, min_index);
    }

    if(criterio == 'c')
        new = reverseList(new);

    *l = new;
}
