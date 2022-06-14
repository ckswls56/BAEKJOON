#include <stdio.h>
#include <stdlib.h>
void apart(int ** arr, int k, int n) {
	int i = 1;
	int j = 0;
	while (j < n) {
		arr[0][j] = j + 1;
		j++;
	}
	while (i <= k) {
		j = 1;
		arr[i][0] = 1;
		while (j < n) {
			arr[i][j] = arr[i][j-1] + arr[i - 1][j];
			j++;
		}
		i++;
	}
	printf("%d\n", arr[k][n-1]);
	i = 0;
}
int main(void) {
	int t; scanf("%d", &t);
	int k, n,i=0;
	int ** arr;
	int * floor;
	while (t > 0) {
		scanf("%d %d", &k, &n);
		arr = (int**)malloc(sizeof(int*)*k + 1);
		i = 0;
		while (i <= k) {
			arr[i] = (int*)malloc(sizeof(int)*n + 1);
			i++;
		}
		apart(arr,k, n);
		t--;
	}
}
