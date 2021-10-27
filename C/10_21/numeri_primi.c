#include <stdio.h>

int primo(int x);

int main() {
    int i = 1;

    printf("[Lista numeri primi]\n\n");

    while(i < 100) {
        if(primo(i))
            printf("%d\n", i);
        
        i++;
    }

    return 0;
}

int primo(int x) {
    int i = 2, flag = 1;

    while(i < x) {
        flag = flag && x % i != 0;
        i++;
    }

    if(flag)
        return flag;
    else
        return 0;
}
