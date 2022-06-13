#include <stdio.h>
#include<stdlib.h>
int main() {
	int i,j,k,n,count;
	int *arr;
	double average;
	scanf("%d", &n);
	i = 0;
	while (i < n) {
		scanf("%d", &j);
		arr = (int*)malloc(sizeof(int)*j);
		average = 0; k = 0;
		while (k<j) {
			scanf("%d", &arr[k]);
			average += arr[k];
			k++;
		}
		average /= (double)j;
		k = 0; count = 0;
		while (k < j) {
			if (average < arr[k])
				count++; k++;
		}
		printf("%.3lf%%\n", count/(double)j * 100);
		i++;
	}
}
