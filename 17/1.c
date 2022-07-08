#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,m;
	scanf("%d %d", &n, &m);

	int *arr;
	arr = (int*)malloc(sizeof(int)*(n+1));
	arr[0] = 0;
    
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arr[i] += arr[i - 1];
	}
		
	int i, j;

	while (m-- > 0) {	
		scanf("%d %d", &i, &j);

		printf("%d\n",arr[j] - arr[i-1]);
	}
}
