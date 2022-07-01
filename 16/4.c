#include <stdio.h>
#include <stdlib.h>

long long int p(int n) {
	long long int *arr;
	arr = (long long int*)malloc(sizeof(long long int) * 100);
	arr[0] = 1; arr[1] = 1; arr[2] = 1;
	arr[3] = 2; arr[4] = 2; arr[5] = 3;
	arr[6] = 4; arr[7] = 5; arr[8] = 7;
	arr[9] = 9;
	
	for (int i = 10; i <= n;i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	return arr[n-1];
}

int main() {
	int t;
	scanf("%d", &t);

	while (t-- > 0) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", p(n));
	}

}
