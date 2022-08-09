#include <stdio.h>
#include <stdlib.h>

int *arr;
int sorted[1000000]; // 필요할떄마다 생성시 비효율적이다.

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
        list[n] = sorted[n];
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

int exist(int start, int end, int c)
{
    if (start > end)
        return 0;

    int mid = (end + start) / 2;
    int ret;

    if (arr[mid] > c)
        ret = exist(start, mid - 1, c);
    else if (arr[mid] < c)
        ret = exist(mid + 1, end, c);
    else
        ret = 1;

    return ret;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    scanf("%d", &m);
    while (m--)
    {
        int c;
        scanf("%d", &c);
        printf("%d\n", exist(0, n - 1, c));
    }
}