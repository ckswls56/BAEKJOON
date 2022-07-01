#include <stdio.h>
#include <stdlib.h>

int cnt1 = 0;
int cnt2 = 0;

int fib(n) {

	if (n == 1 || n == 2) {
		cnt1++;
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
	
}

int fibonacci(n) {
	int * f;
	f = (int*)malloc(sizeof(int)*n);
	f[0] = 1; f[1] = 1;
	for (int i = 2; i < n; i++) {
		cnt2++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n-1];
	
}

int main() {
	int n;
	scanf("%d", &n);
	fib(n); fibonacci(n);
	printf("%d %d", cnt1, cnt2);
}
