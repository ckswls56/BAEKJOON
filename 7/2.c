#include <stdio.h>

int main(void) {
	int i = 1;
	int n;
	int sum = i;
	scanf("%d", &n);
	while (i < n) {
		if (sum >= n)
			break;
		sum += 6 * i; i++;
	}
	printf("%d", i);
}
