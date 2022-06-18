#include <stdio.h>
int nbrlen(int n) {
	int i=0;
	while (n > 0) {
		i++;
		n /= 10;
	}
	return i;
}
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
			if (arr[i] < arr[j])
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	return 0;
}

int main() {
	int n,len,i;
	scanf("%d", &n);
	len = nbrlen(n);
	int *arr; arr = (int*)malloc(sizeof(int)*len);
	i = len;
	while (i > 0) {
		arr[--i] = n % 10;
		n /= 10;
	}
	bubblesort(arr, len);
	i = 0;
	while (i < len) {
		printf("%d", arr[i++]);
	}

	return 0;
}
