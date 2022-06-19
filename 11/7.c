#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate {
	int x;
	int y;
}cord;

void swap(cord *a, cord *b) {
	cord temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void makeheap(cord *arr, int n) {
	for (int i = 1; i < n; i++) {
		int c = i;
		do {
			int p = (c - 1) / 2;
			if ((arr[p].y <= arr[c].y)) {
				if(arr[p].y == arr[c].y && arr[p].x < arr[c].x)
					swap(&arr[p], &arr[c]);
				else if(arr[p].y < arr[c].y)
					swap(&arr[p], &arr[c]);
			}
			c = p;
		} while (c != 0);
	}
	return;
}
void deleteheap(cord * heap, int n) {
	for (int i = n - 1; i >= 0; i--) {
		cord max = heap[0];
		heap[0] = heap[i];
		heap[i] = max;
		int p = 0;
		int c = 1;
		do {
			c = 2 * p + 1;
			// find bigger child
			if (c < i - 1 && heap[c].y <= heap[c + 1].y ) {
				if (heap[c].y == heap[c + 1].y && heap[c].x < heap[c + 1].x)
					c++;
				else if (heap[c].y < heap[c+1].y)
					c++;
			}
			if (c < i && heap[p].y <= heap[c].y) {
				if (heap[p].y == heap[c].y && heap[p].x < heap[c].x)
					swap(&heap[p], &heap[c]);
				else if (heap[p].y < heap[c].y)
					swap(&heap[p], &heap[c]);
			}
			p = c;
		} while (c < i);
	}
	return;
}

int main() {
	int n,i,j;
	cord * heap;
	scanf("%d", &n);
	heap = (cord*)malloc(sizeof(cord)*n);
	i = 0;
	while (i < n) {
		scanf("%d %d", &heap[i].x, &heap[i].y);
		i++;
	}
	makeheap(heap, n);
	deleteheap(heap, n);
	//sort

	i = 0;
	while (i < n) {
		printf("%d %d\n", heap[i].x, heap[i].y);
		i++;
	}

	return 0;
}
