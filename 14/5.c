#include <stdio.h>
#include <math.h>

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
int get_gcd(int a,int b) {
	if (b == 0)
		return 0;
	while (b > 0) {
		int temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

void divisors(int *arr,int gcd,int *cnt) {

	arr[(*cnt)++] = gcd;
	int i = 1;
	while (++i <= sqrt(gcd)) {
		if (gcd % i == 0) {
			if (i == gcd / i) {
				arr[(*cnt)++] = i;
			}
			else {
				arr[(*cnt)++] = gcd / i;
				arr[(*cnt)++] = i;
			}
		}
	}
}

int main() {
	int n, i, gcd;
	scanf("%d", &n);
	int *heap;
	heap = (int*)malloc(sizeof(int)*n);
	int div[300];
	int div_cnt = 0;

	i = 0;
	while (i < n)
		scanf("%d", &heap[i++]);
	makeheap(heap, n);
	deleteheap(heap, n);
	gcd = heap[1] - heap[0];
	i = 2;
	while (i < n) {
		int temp = heap[i] - heap[i - 1];
		gcd = get_gcd(gcd, temp);
		i++;
	}

	divisors(div, gcd, &div_cnt);
	makeheap(div, div_cnt);
	deleteheap(div, div_cnt);

	i = 0;
	while (i < div_cnt)
		printf("%d ", div[i++]);
	return 0;
}

