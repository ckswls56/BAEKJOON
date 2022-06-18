#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int bubblesort(int *arr, int n) {
	int i, j;
	i = 0;
	while (i < n) {
		j = i;
		while (j < n) {
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	return 0;
}
int main(){
	int n,i,j;
	scanf("%d", &n);
	int *arr;
	arr = (int*)malloc(sizeof(int)*n);
	i = 0;

	while (i < n)
		scanf("%d", &arr[i++]);
	bubblesort(arr, n);
	i = 0;
	while (i < n)
		printf("%d\n", arr[i++]);
	return 0;
}
