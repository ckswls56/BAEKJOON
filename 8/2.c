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
	int m,n,min;
	scanf("%d %d",&m, &n);
	int sum = 0; min = -1;
	while (m <= n) {
		if (isprime(m) == 1) {
			sum += m;
			if (min == -1)
				min = m;
		}
		m++;
	}
	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum,min);
	return 0;
}
