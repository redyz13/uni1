#include <stdio.h>

int main() {
	int i = 0;

	while(i <= 10) {
		printf("%d è %spari\n", i, i % 2 == 0 ? "" : "dis");

		i++;
	}

	printf("\n");
	
	return 0;
}
