#include <stdio.h>
#include <stdlib.h>

typedef struct bag {
	int weight;
	int value;
}bag;


int main() {

	int n, max_bag;
	int *dp;
	bag b[100];

	scanf("%d %d", &n, &max_bag);
	

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &b[i].weight,&b[i].value);
	}
	

	dp = (int*)malloc(sizeof(int)*(max_bag+1));

	for (int i = 0; i <= max_bag; i++) {
		dp[i] = 0;
	}

	int w, v;
	for (int i = 0; i < n; i++) {
		w = b[i].weight; v = b[i].value;
		for (int j = max_bag; j > 0; j--) {
			if (w <= j) {
				if (dp[j] < v + dp[j - w])
					dp[j] = v + dp[j-w];
			}
			else
				break;
		}
	}

	printf("%d", dp[max_bag]);
}
