#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	scanf("%d", &n);
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	if (n == 1)
		printf("%d", arr[0]);
	else if (n == 2)
		printf("%d", arr[0] + arr[1]);
	else {
		int **sum;
		sum = (int**)malloc(sizeof(int) * 2);
		sum[0] = (int*)malloc(sizeof(int)*n);
		sum[1] = (int*)malloc(sizeof(int)*n);

		sum[0][0] = arr[0]; sum[1][0] = arr[0];
		sum[0][1] = arr[1]; sum[1][1] = arr[0] + arr[1];
		int max = sum[1][0];
		for (int i = 2; i < n; i++) {
			sum[0][i] = max + arr[i];
			sum[1][i] = sum[0][i - 1] + arr[i];
			if (max < sum[0][i - 1] || max < sum[1][i - 1]) {
				if(sum[0][i-1]>sum[1][i-1])
					max = sum[0][i - 1];
				else
					max = sum[1][i - 1];
			}	
		}

		if (max < sum[0][n - 1])
			max = sum[0][n - 1];
		if (max < sum[1][n - 1])
			max = sum[1][n - 1];

		printf("%d", max);
	}
//이 문제는 계단 올라가기(16_8)와 비슷하지만 최대값이 반드시 주변에 있지 않음에 주의하여야 한다.
}
