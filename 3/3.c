#include <stdio.h>
int main() {
	int n,sum;
	scanf("%d", &n);
	sum = 0;
	while (n > 0) {
		sum += n;
		n--;
	}
	printf("%d", sum);		
	return 0;
}
