#include <stdio.h>
#include <stdlib.h>

int sorted[500010];
int arr[500010];
int cnt, res, n, K;

void merge(int *list, int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        if (list[i] < list[j])
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
    {
        list[n] = sorted[n];
        if (++cnt == K)
            res = sorted[n];
    }
}

void merge_sort(int *list, int left, int right)
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

    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, n - 1);

    if (cnt >= K)
        printf("%d", res);
    else
        printf("-1");
}