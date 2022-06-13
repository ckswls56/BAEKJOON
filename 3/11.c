#include <stdio.h>
#include <stdlib.h>
int main() {
	int i,n,x;
	int *A;
	scanf("%d %d", &n,&x);
	A = (int *)malloc(sizeof(int)*n);
	if (!A)
		return 0;
	i = 0;
	while (i < n) {
		scanf("%d", &A[i]);
		i++;
	}
	i = 0;
	while (i < n) {
		if (A[i] < x)
			printf("%d ", A[i]);
		i++;
	}

	return 0;
}
