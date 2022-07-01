#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max = INT_MIN;
int *arr;


void	con_sum(int n) {

	int sum = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] > sum && sum<=0)
			sum = arr[i];
		else
			sum += arr[i];
		if(sum>max)
			max = sum;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	con_sum(n);
	
	printf("%d", max);

}
