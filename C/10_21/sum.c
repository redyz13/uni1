#include <stdio.h>

int main() {
    int x, y;
    
    printf("This program adds two numbers\n\n");

    printf("Insert the first number: ");
    scanf("%d", &x);

    printf("Insert the second number: ");
    scanf("%d", &y);

    printf("\nSum = %d\n", x + y);

    return 0;
}
