#include <stdio.h>
#include <stdlib.h>


int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	long long int *arr;
	arr = (long long int*)malloc(sizeof(long long int)*(n));
	long long int *mod;
	mod = (long long int*)malloc(sizeof(long long int)*(m));

	mod[0] = 0;
	for (int i = 1; i < m; i++) {
		mod[i] = -1;
	}


	scanf("%lld", &arr[0]);
	arr[0] %= m;
	mod[arr[0]]++;

	for (int i = 1; i < n; i++) {
		scanf("%lld", &arr[i]);
		arr[i] += arr[i - 1];
		mod[arr[i]%m] = mod[arr[i]%m] + 1;
	}

	long long int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (mod[i] != -1)
			cnt += (mod[i] * (mod[i]+1) ) / 2;
	}

	printf("%lld", cnt);

}
