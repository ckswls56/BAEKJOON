#include <stdio.h>
#include <stdlib.h>
#define limit 1000000000;
int min = limit;
int max = -limit;
int idx = 0;
int n;
int *arr;
int op[4];

void sol(int res) {
	if (++idx == n) {
		if (min > res)
			min = res;
		if (max < res)
			max = res;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (op[i] != 0) {
				op[i]--;
				switch (i) {
				case 0:
					sol(res + arr[idx]);
					break;
				case 1:
					sol(res - arr[idx]);
					break;
				case 2:
					sol(res * arr[idx]);
					break;
				case 3:
					sol(res / arr[idx]);
					break;
				}	
				op[i]++; idx--;
			}
			
		}
	}
}

int main() {

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}

	sol(arr[idx]);

	printf("%d\n%d", max, min);
	
}
