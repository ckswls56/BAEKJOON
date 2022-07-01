#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int min = 1000 * 1000;

	int arr[3][1000];
	int sum[3][1000]={0};
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &arr[0][i], &arr[1][i], &arr[2][i]);
	
	sum[0][0] = arr[0][0]; 
	sum[1][0] = arr[1][0]; 
	sum[2][0] = arr[2][0]; 
	int r, g, b;
	for (int i = 1; i <n; i++) {
		r = sum[0][i-1];
		g = sum[1][i-1];
		b = sum[2][i-1];
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				if (g < b)
					sum[j][i] = g;
				else
					sum[j][i] = b;
				break;
			case 1:
				if (r < b)
					sum[j][i] = r;
				else
					sum[j][i] = b;
				break;
			case 2:
				if (r < g)
					sum[j][i] = r;
				else
					sum[j][i] = g;
				break;
			}
			sum[j][i] += arr[j][i];
		}
	}
	
	for (int i = 0; i < 3; i++) {
		if (min > sum[i][n-1])
			min = sum[i][n-1];
	}

	printf("%d", min);
}
