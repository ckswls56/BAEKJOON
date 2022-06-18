#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxsize 4000

int makemode(int *arr) {
	int i = 0;
	int max = 0;
	int count = 0;
	while (i < maxsize * 2+1) {
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	i = 0;
	while (i < maxsize * 2+1) {
		if (max == arr[i])
			count++;
		i++;
	}
	if (count == 1) {
		i = 0;
		while (i < maxsize * 2+1) {
			if (max == arr[i])
				return i - 4000;
			i++;
		}
	}
	else {
		int *temp; int j; j = count;
		temp = (int*)malloc(sizeof(int)*count);
		i = 0;
		while (i < maxsize * 2+1) {
			if (max == arr[i])
				temp[--count] = i - 4000;
			i++;
		}
		return temp[j - 2];
	}
}
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void makeheap(int *arr, int n) {
	for (int i = 1; i < n; i++) {
		int c = i;
		do {
			int p = (c - 1) / 2;
			if (arr[p] < arr[c]) {
				swap(&arr[p], &arr[c]);
			}
			c = p;
		} while (c != 0);
	}
}
void deleteheap(int *heap, int n) {

	for (int i = n - 1; i >= 0; i--) {
		int max = heap[0];
		heap[0] = heap[i];
		heap[i] = max;
		int p = 0;
		int c = 1;
		do {
			c = 2 * p + 1;
			// find bigger child
			if (c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}
			if (c < i && heap[p] < heap[c]) {
				swap(&heap[p], &heap[c]);
			}
			p = c;
		} while (c < i);
	}
}

int main() {
	int n, sum, max, min, average, mid, mode, range;
	int *arr;
	int count[maxsize * 2 +1] = { 0 };
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int)*n);
	sum = 0; max = -4000; min = maxsize;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
		count[arr[i] + 4000]+=1;
	}
	average = (int)round((sum / (double)n));
	range = max - min;
	makeheap(arr, n);
	deleteheap(arr, n);
	mid = arr[n / 2];
	mode = makemode(count);

	printf("%d\n%d\n%d\n%d\n", average, mid, mode, range);
	return 0;
}
