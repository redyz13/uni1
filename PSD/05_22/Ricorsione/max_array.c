#include <stdio.h>

int max_array(int *arr, int n) {
    if (n == 0) return arr[0];

    int m;

    m = max_array(arr, n - 1);

    if (m > arr[n]) return m;

    return arr[n];
}

int main(void) {
    int arr[] = {7, 6, 9, 1, 4, 5, 9};
    int n = sizeof(arr) / sizeof(*arr);

    printf("Largest element of the array: %d\n", max_array(arr, n - 1));

    return 0;
}