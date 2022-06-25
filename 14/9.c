#include <stdio.h>
#include <stdlib.h>

void bino(int **arr, int n) {

	for (int i = 0; i <= n; i++) //left line insert 1
		arr[i][0] = 1;
	for (int i = 0; i <= n; i++) //right line insert 1
		arr[i][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <i; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]);
		}
	}

}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {

	int t,n, k;
	scanf("%d", &t);

	while (t-- > 0) {
		scanf("%d %d", &n, &k);
		if (k > n) {
			swap(&n, &k);
		}
		int **arr;
		arr = (int**)malloc(sizeof(int*)*(n + 1));
		for (int i = 0; i <= n; i++) {
			arr[i] = (int*)malloc(sizeof(int)*(i + 1));
		}

		bino(arr, n);

		printf("%d\n", arr[n][k]);
		free(arr);
	}
	
	return 0;
}

