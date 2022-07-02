#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int **arr;
	arr = (int **)malloc(sizeof(int *)*n);
	int **sum;
	sum = (int **)malloc(sizeof(int *)*n);
	for (int i = 1; i <= n; i++) {
		arr[i-1] = (int *)malloc(sizeof(int)*i);
		sum[i-1] = (int *)malloc(sizeof(int)*i);
		for (int j = 0; j < i; j++) {
			scanf("%d", &arr[i - 1][j]);
			sum[i - 1][j] = 0;
		}
			
	}

	sum[0][0] = arr[0][0];


	for (int i = 1; i < n; i++) {

		sum[i][0] = sum[i - 1][0] + arr[i][0];

		for (int j = 1; j <i; j++) {
			if (sum[i - 1][j-1] > sum[i - 1][j])
				sum[i][j] = sum[i - 1][j-1] + arr[i][j];
			else
				sum[i][j] = sum[i - 1][j] + arr[i][j];
		}

		sum[i][i] = sum[i - 1][i - 1] + arr[i][i];
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < sum[n-1][i])
			max = sum[n-1][i];
	}

	printf("%d", max);
}
