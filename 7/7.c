#include <stdio.h>

int calc(int n) {
	int div = n / 5;
	int i ;
	while (div > 0) {
		i = 1;
		while ((div * 5) + (i * 3) <= n) {
			if ((div * 5) + (i * 3) == n)
				return div + i;
			i++;
		}
		div--; 
	}
	if (n % 3 == 0)
		return n / 3;

	return -1;
}
int main() {
	int n; 
	scanf("%d", &n);

	if (n % 5 == 0) {
		printf("%d", n / 5);
		return 0;
	 }
	
	printf("%d", calc(n));
	
		
	return 0;
}
