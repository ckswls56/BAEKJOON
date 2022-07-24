#include <stdio.h>
#include <stdlib.h>
int sorted[200000]; // 필요할떄마다 생성시 비효율적이다.

void merge(long long *list, int left, int mid, int right)
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

void merge_sort(long long *list, int left, int right)
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
    long long n, c;
    scanf("%lld %lld", &n, &c);
    long long *arr;
    arr = (long long *)malloc(sizeof(long long) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    merge_sort(arr, 0, n - 1);
    if (c == 2)
    {
        printf("%d", arr[n - 1] - arr[0]);
    }
    else
    {

        long long wifi, low, mid, high;
        high = 1000000000 * 2;
        low = 1;
        int left;

        while (low < high && high - low != 1)
        {
            mid = (low + high) / 2;
            wifi = 0;
            left = 0;
            for (int i = 1; i < n; i++)
            {
                if (arr[i] - arr[left] >= mid)
                {
                    left = i;
                    wifi++;
                }
            }
            if (wifi < c - 1)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        printf("%lld", low);
    }
}