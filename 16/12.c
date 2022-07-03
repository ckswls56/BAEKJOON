#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int *arr;
	arr = (int*)malloc(sizeof(int)*n);

	int *sum;
	sum = (int*)malloc(sizeof(int)*n);


	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sum[0] = 1;
	int res = 1;
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i]>arr[j] && max < sum[j] )
				max = sum[j];
		}
		sum[i] = max + 1;
		
	
		if (res < sum[i])
			res = sum[i];
	}
	
	printf("%d", res);
}
