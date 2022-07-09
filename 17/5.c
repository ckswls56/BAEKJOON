#include <stdio.h>
#include <stdlib.h>


int main() {
	int n, m;
	int x1, y1, x2, y2;
	scanf("%d %d", &n, &m);

	int **arr;
	arr = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*(n+1));
	}

	for (int i = 0; i < n; i++) {
		arr[i][0] = 0;
	}
	

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i][j - 1];
		}
	}


	while (m-- > 0) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int sum = 0;
		for (int i = x1 - 1; i < x2; i++) {
			sum += arr[i][y2] - arr[i][y1 - 1];
		}
		printf("%d\n", sum);
	}

}
