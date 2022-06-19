#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct word {
	char *str;
	int len;
}word;

void swap(word *a, word *b) {
	word temp = *a;
	*a = *b;
	*b = temp;
}
void merge(word *list, int left, int mid, int right) {
	int i, j, k;
	word sorted[20000]; 
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (list[i].len < list[j].len || (list[i].len == list[j].len && strcmp(list[i].str, list[j].str) < 0))
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
	
}
void merge_sort(word * list, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;

		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);

		merge(list, left, mid, right);
	}
}
int main() {
	int n, i;
	scanf("%d", &n);
	word *res;
	char str[51];
	res = (word *)malloc(sizeof(word)*n);

	i = 0;
	while (i < n) {
		scanf("%s", str);
		res[i].str = strdup(str);
		res[i].len = strlen(res[i].str);
		i++;
	}

	merge_sort(res, 0, n-1);

	i = -1;
	while (++i < n - 1) {
		if (strcmp(res[i].str, res[i + 1].str) == 0)//overlap
			continue;
		printf("%s\n", res[i].str);
	}
	printf("%s\n", res[i].str);
	
	return 0;
}
