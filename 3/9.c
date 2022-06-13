#include <stdio.h>
int main() {
	int i,j,n;
	scanf("%d", &n);
	i = 0;
	while (i < n) {
		j = 0;
		while (j++ <= i)
			printf("*");
		printf("\n");
	i++;
	}

	return 0;
}
