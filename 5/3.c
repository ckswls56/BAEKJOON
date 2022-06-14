#include <stdio.h>
#include <stdlib.h>
int nbrlen(int n) {
	int len = 0;
	while (n > 0) {
		n /= 10;
		len++;
	}
	return len;
}
void devide(int *arr, int n) {
	int i = 0;
	while (n > 0) {
		arr[i++] = n % 10;
		n /= 10;
	}
}
int	hansu(int n)
{
	int * arr;
	int i = 0;
	int len = nbrlen(n);
	if (len < 3)
		return 1;
	arr = (int *)malloc(sizeof(int)*len);
	devide(arr, n);
	while (i < len - 2) {
		if (arr[i] - arr[i + 1] != arr[i+1] - arr[i + 2])
			return 0;
		i++;
	}
	return 1;
}
int main() {
	int i = 1;
	int sum = 0;
	int n;
	scanf("%d", &n);
	while (i <= n) {
		if (hansu(i++))
			sum++;
	}
	printf("%d\n", sum);
}
