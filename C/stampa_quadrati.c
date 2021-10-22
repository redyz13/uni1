#include <stdio.h>

void stampa_quadrato(int n);
void stampa_quadrato_eroinomane(int n);

int main() {
    int n;

    do {
        printf("Inserire il lato del quadrato: ");
        scanf("%d", &n);
    }
	while(n < 0);

    stampa_quadrato_eroinomane(n);

    return 0;
}

void stampa_quadrato(int n) {
    int m = n, i = 0;
    printf("\n[Quadrato]\n");
    
    while(m >= 0) {
		while(i < n) {
			printf("*");
			i++;
		}

		printf("\n");
		m--;
		i = 0;
    }
}

void stampa_quadrato_eroinomane(int n) {
	int m = n, i = 0;
	printf("\n[Quadrato eroinomane]\n");

	while(m > 0) {
		if(m == n || m == 1) {
			while(i < n) {
				printf("*");
				i++;
			}
		}
		else {
			while(i < n) {
				if(i == n - 1 || i == 0)
					printf("*");
				else
					printf(" ");
				i++;
			}
		}

		printf("\n");
		m--;
		i = 0;
	}
}
