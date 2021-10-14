#include <stdio.h>

int main() {
    int bnum[100], dnum;
    int temp_dnum, i;

    printf("Insert the decimal number: ");
    scanf("%d", &dnum);
    
    temp_dnum = dnum;

    for(i = 0; temp_dnum > 0; i++) {
        bnum[i] = temp_dnum % 2;
        temp_dnum /= 2;
    }

    printf("\n%d in decimal equals ", dnum); 

    for(i -= 1; i >= 0; i--) {
        printf("%d", bnum[i]);
    }

    printf(" in binary\n");

    return 0;
}
