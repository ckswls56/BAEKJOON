#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct person {
	unsigned int age;
	int order;
	char *name;
}p;

void merge(p *list, int left, int mid, int right) {
	int i, j, k;
	p *sorted;
	sorted = (p*)malloc(sizeof(p)*(right+1));
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (list[i].age < list[j].age || (list[i].age == list[j].age && list[i].order < list[j].order))
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

void merge_sort(p * list, int left, int right) {
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
	char str[101];
	p * res;
	res = (p*)malloc(sizeof(p)*n);
	int i = 0;
	while (i < n) {
		scanf("%d %s", &res[i].age, str);
		res[i].name = strdup(str);
		res[i].order = ++i;
	}
	merge_sort(res, 0, n - 1);

	i = 0;
	while (i < n) {
		printf("%d %s\n", res[i].age, res[i].name);
		i++;
	}
	free(res);
	return 0;
}
