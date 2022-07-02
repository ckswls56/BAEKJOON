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
	else if(n==2)
		printf("%d", arr[0]+arr[1]);
	else {
		int sum[2][300];
		//sum[0][i] 은 다음칸에 갈수있는 최대값
		//sum[1][i] 은 다음칸에 갈수없는 최대값(다음번에 무조건 건너뛰어야함)
		sum[0][0] = arr[0]; sum[1][0] = arr[0];
		sum[0][1] = arr[1]; sum[1][1] = arr[0] + arr[1];

		for (int i = 2; i < n-1; i++) {
			if (sum[0][i - 2] > sum[1][i - 2])
				sum[0][i] = sum[0][i - 2];
			else
				sum[0][i] = sum[1][i - 2];
			sum[0][i] += arr[i];
			sum[1][i] = sum[0][i - 1];
			sum[1][i] += arr[i];
		}
		int a, b, c,res;
		a = sum[0][n - 3];
		b = sum[1][n - 3];
		c = sum[0][n - 2];

		if (a >= b && a >= c)
			res = a + arr[n - 1];
		else if (b >= a && b >= c)
			res = b + arr[n - 1];
		else
			res = c + arr[n - 1];
		printf("%d", res);
	}
	

}
