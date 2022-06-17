#include <stdio.h>
#include <stdlib.h>
int main(){
	int n,m,i,j,k,max,sum;
	scanf("%d %d", &n, &m);
	
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);
	i = 0;
	while (i < n)
		 scanf("%d",&arr[i++]);
	i = 0; max = 0;
	while (i < n-2) {
		j = i + 1;
		while (j < n - 1) {
			k = j + 1;
			while (k < n) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= m && sum>max) {
					max = sum;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	printf("%d", max);

	return 0;
}
