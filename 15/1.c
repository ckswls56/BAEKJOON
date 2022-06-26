#include <stdio.h>
#include <stdlib.h>

int idx = 0;
int promissing(char *arr,int n) {
	for (int j = idx; j > 0; j--) {
		if (arr[j - 1]-'0' == n)
			return 0;
	}
	return 1;
}

void ntom(int n, int m, char *arr) {

	
	if (m == 0) {
		
		for(int i=0;i<idx;i++)
			printf("%c ",arr[i]);
		printf("\n");
		return;
	}
	int flag = 1;
	for (int i = 1; i <= n; i++) {

		if (promissing(arr, i)) {
			arr[idx++] = '0' + i;
			ntom(n, m - 1, arr);

