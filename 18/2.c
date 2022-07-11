#include <stdio.h>
#include <stdlib.h>

typedef struct meeting
{
	unsigned int start;
	unsigned int end;
} meeting;

void merge(meeting *list, int left, int mid, int right)
{
	int i, j, k;
	meeting *sorted;
	sorted = (meeting *)malloc(sizeof(meeting) * (right + 1));
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (list[i].start < list[j].start)
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

void merge_sort(meeting *list, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);

		merge(list, left, mid, right);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	meeting *m;
	m = (meeting *)malloc(sizeof(meeting) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%u %u", &m[i].start, &m[i].end);
	}

	merge_sort(m, 0, n - 1);

	unsigned int cnt = 1;

	unsigned int start = m[n - 1].start;
	for (int i = n - 2; i >= 0; i--)
	{
		if ((m[i].end <= start))
		{
			start = m[i].start;
			cnt++;
		}
		else if (m[i].start == m[i + 1].end)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}