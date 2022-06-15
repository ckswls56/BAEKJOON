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
	int m,n;
	scanf("%d %d",&m, &n);
	while (m <= n) {
		if (isprime(m) == 1) {
			printf("%d\n",m);
		}
		m++;
	}
	return 0;
}
