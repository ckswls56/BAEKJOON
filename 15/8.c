#include <stdio.h>
#include <stdlib.h>

int **arr;
int *check;
int idx = 0;
int min = 1000;
int n;

int abs(int n) {
	if (n < 0)
		return -n;
	return n;
}


void	sol(int pos) {
	if (idx == n/2) {

		int start = 0;
		int link = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (check[i] && check[j])
					start += arr[i][j];
				if (!check[i] && !check[j])
					link += arr[i][j];
			}
		}

		int diff = abs(start-link);
		if (diff == 0) {
			printf("0");
			exit(0);
		}
		if (min > diff)
			min = diff;
	}
	else {
		for (int i = pos; i < n; i++) {
			check[i] = 1;
			idx++;
			sol(i + 1);
			idx--;
			check[i] = 0;
		}

	}
	
}

int main() {
	
	scanf("%d", &n);
	arr = (int**)malloc(sizeof(int*)*n);

	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int)*n);
	}

	check = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
		check[i] = 0;
	}

	sol(1);

	printf("%d", min);

	return 0;
}
