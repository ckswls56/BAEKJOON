#include <stdio.h>

int count(int n,int div) {
	int count = 0;
	if (div == 2) {
		for (unsigned int i = 2; n / i >= 1; i *= 2)
			count += n / i;
	}
	else {
		for (unsigned int i = 5; n / i >= 1; i *= 5)
			count += n / i;
		
	}
	return count;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int n2, n5;

	n2 = count(n, 2);
	n2 -= count(n - k, 2);
	n2 -= count(k, 2);

	n5 = count(n, 5);
	n5 -= count(n - k, 5);
	n5 -= count(k, 5);

	if (n2 < n5) {
		printf("%d\n", n2);
	}
	else
		printf("%d\n", n5);
	
	return 0;
}

