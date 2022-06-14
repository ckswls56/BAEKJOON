#include <stdio.h>

int isprime(int n) {
	if (n < 2)
		return -1;
	int i = 2;
	while (i*i <= n) {
		if (n%i == 0)
			return -1;
		i++;
	}
	return 1;
}
int main() {
	int n,a;
	scanf("%d", &n);
	int count = 0;
	while (n-- > 0) {
		scanf("%d", &a);
		if (isprime(a)==1)
			count++;
	}
	printf("%d", count);
	return 0;
}
