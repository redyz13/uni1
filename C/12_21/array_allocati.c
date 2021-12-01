#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int *read_array(int size);

int main() {
    int *arr[2];

    printf("\nInserimento Array 1:\n");
    arr[0] = read_array(5);

    printf("\nInserimento Array 2:\n");
    arr[1] = read_array(2);

    printf("\nOutput Array 1:\n");

    for(int i = 0; i < 5; i++)
        printf("%d ", *(*(arr+0)+i));  

    printf("\n\nOutput Array 2:\n");

    for(int i = 0; i < 2; i++)
        printf("%d ", *(*(arr+1)+i));

    return 0;
}

int *read_array(int size) {
    int *arr, i;

    arr = malloc(sizeof(int) * SIZE);

    if(!arr) return NULL;

    for(i = 0; i < size; i++) {
        printf("Cella array [%d]: ", i);
        scanf("%d", (arr+i));
    }

    arr = realloc(arr, i);

    if(!arr) return NULL;

    return arr;
}
