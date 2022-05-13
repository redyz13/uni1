#include <stdio.h>

void print_array(int *arr, int n) {
    if (n < 0) return;

    print_array(arr, n - 1);

    printf("%d ", arr[n]);
}

int main(void) {
    int arr[] = {0, 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(*arr);

    print_array(arr, n - 1);

    return 0;
}