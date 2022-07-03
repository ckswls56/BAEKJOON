#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define div 1000000000

int main() {

	int n;
	scanf("%d", &n);
	int **arr;
	arr = (int**)malloc(sizeof(int*)*n);

	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*10);
	}

	for (int i = 0; i <= 9; i++) {
		arr[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		arr[i][0] = arr[i - 1][1] % div;
		for (int j = 1; j <9; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1])%div;
		}
		arr[i][9] = arr[i-1][8] % div;
	}

	long long int sum = 0;

	for (int i = 1; i <= 9; i++) {
		sum += arr[n-1][i];
	}
	printf("%lld", sum);

	
}
