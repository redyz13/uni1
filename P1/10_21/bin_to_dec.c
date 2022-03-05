#include <stdio.h>

int main() {
    int bnum, pos = 0, base = 1;
    int digit, temp_bnum;
    double dnum = 0;

    printf("Insert the binary number: ");
    scanf("%d", &bnum);

    temp_bnum = bnum;

    while(temp_bnum > 0) {
        digit = temp_bnum % 10;
        dnum += digit * base;

        temp_bnum /= 10;
        base *= 2;
        pos++;
    }
    
    printf("\n%d in binary equals %.0f in decimal\n", bnum, dnum);

    return 0;
}
