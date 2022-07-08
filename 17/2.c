#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,k;
	scanf("%d %d", &n, &k);

	int *arr;
	arr = (int*)malloc(sizeof(int)*(n+1));
	
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
		
	}
	
	int max = -100 * 100000;
	for (int i = k; i <= n; i++) {
		if (max < arr[i] - arr[i - k])
			max = arr[i] - arr[i - k];
		
	}
	printf("%d", max);
}
