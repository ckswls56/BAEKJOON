#include <stdio.h>
int main() {
	int i,n;
	scanf("%d", &n);
	i = 0;
	while (++i < 10)
		printf("%d * %d = %d\n", n, i, n*i);
	return 0;
}
