#include <stdio.h>
#include <stdlib.h>

typedef struct powerpole {
	int left;
	int right;
}pole;

void merge(pole *list, int left, int mid, int right) {
	int i, j, k;
	pole *sorted;
	sorted = (pole*)malloc(sizeof(pole)*(right + 1));
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (list[i].left < list[j].left)
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
		for (int n = j; n <= right; n++)
			sorted[k++] = list[n];
	else
		for (int n = i; n <= mid; n++)
			sorted[k++] = list[n];

	for (int n = left; n <= right; n++)
		list[n] = sorted[n];
	free(sorted);
}

void merge_sort(pole * list, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);

		merge(list, left, mid, right);
	}
}



int main() {

	int n;
	scanf("%d", &n);

	pole * p;
	p = (pole*)malloc(sizeof(pole)*n);
	int * sum;
	sum = (int*)malloc(sizeof(int)*n);
	

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].left, &p[i].right);
	}

	merge_sort(p, 0, n - 1);

	sum[0] = 1;
	int res = 1; //LIS
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (p[i].right > p[j].right && max < sum[j])
				max = sum[j];
		}
		sum[i] = max + 1;

		if (res < sum[i])
			res = sum[i];
	}


	printf("%d", n - res);

}
/*
1. 왼쪽 전봇대를 기준으로 정렬을 시켜준다.
2. 오른쪽 전봇대에서 "가장 긴 증가하는 부분 수열"을 구해준다.
3. 2번과정에서 구한 "가장 긴 증가하는 부분 수열"의 크기를 N에서 빼준다.
*/
