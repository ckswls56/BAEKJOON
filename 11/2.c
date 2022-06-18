#include <stdio.h>

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
int main() {
	int n, i, j;
	scanf("%d", &n);
	int *heap;
	heap = (int*)malloc(sizeof(int)*n);

	i = 0;
	while (i < n)
		scanf("%d", &heap[i++]);
	makeheap(heap, n);

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

	i = 0;
	while (i < n)
		printf("%d\n", heap[i++]);
	return 0;
}
