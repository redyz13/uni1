#include <stdio.h>
#include <math.h>

int main() {
    int bnum, pos = 0;
    int digit, temp_bnum;
    double dnum = 0;

    printf("Insert the binary number: ");
    scanf("%d", &bnum);

    temp_bnum = bnum;

    while(temp_bnum > 0) {
        digit = temp_bnum % 10;
        dnum += digit * (pow(2, pos));

        temp_bnum /= 10;
        pos++;
    }
    
    printf("\n%d in binary equals %.0f in decimal\n", bnum, dnum);

    return 0;
}
