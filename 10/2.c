#include <stdio.h>
#include <stdlib.h>

int nbrlen(int n) {
	int i = 0;
	while (n > 0) {
		n /= 10; i++;
	}
	return i;

}

int decompose(int n) {
	int len = nbrlen(n);
	int sum = 0;
	while (len-- > 0) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}
int main(){
	int n,i;
	scanf("%d", &n);
	i = 0;
	while (i < n) {
		if (i + decompose(i) == n) {
			printf("%d", i);
			return 0;
		}
		i++;
	}
	printf("0");

	return 0;
}
