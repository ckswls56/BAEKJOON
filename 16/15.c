#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max_arr(int *arr, int n) {

	int max = 0;

	for (int i = 0; i < n; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}

int main() {

	char a[1001];
	char b[1001];
	scanf("%s %s", a, b);

	int a_len, b_len;
	a_len = strlen(a);
	b_len = strlen(b);

	int *dp;
	dp = (int *)malloc(sizeof(int*) * (b_len));
	for (int i = 0; i < b_len; i++) {
		dp[i] = 0;
	}
	

	for (int i = 0; i < a_len; i++) {
		int cnt = 0;
		for (int j = 0; j < b_len; j++) {
			if (cnt < dp[j])
				cnt = dp[j];
			else if (a[i] == b[j])
				dp[j] = cnt + 1;
		}
	}

	printf("%d", max_arr(dp,b_len));
	return 0;
}
