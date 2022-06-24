#include <stdio.h>
#include <limits.h>

int real_divisor(int n) {
	int cnt = 0;
	int i = 2;
	while (i < n) {
		if (n%i++ == 0)
			cnt++;
	}
	return cnt;
}

int divisor(int *arr, int n,int max) {

	int i = max;
	int j;

	while (i<=INT_MAX) {
		
	for (j = 0; j < n; j++) {
		if (i%arr[j] != 0) {
			break;
		}
	}
	if (j == n && real_divisor(i)==n)
		return i;
	i++;
	}
	return 0;
}

int main(){
	
	int n;
	scanf("%d", &n);
	int arr[50];
	int max = 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}
	printf("%d", divisor(arr, n,max));
	
	return 0;
}
