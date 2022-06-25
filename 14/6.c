#include <stdio.h>

int     gcd(int a, int b) {
	int i = b;
	while (i >0) {
		if (a%i == 0 && b%i == 0)
			return i;
		i--;
	}
	return 0;
}

int main() {
	int n, first_ring, GCD, temp;
	scanf("%d", &n);
	scanf("%d", &first_ring);
	for (int i = 1; i < n; i++) {
		scanf("%d", &temp);
		GCD = gcd(first_ring, temp);
		printf("%d/%d\n", first_ring / GCD, temp / GCD);
	}

	return 0;
}

