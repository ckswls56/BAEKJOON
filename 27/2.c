#include <stdio.h>
#include <stdlib.h>

void merge(int *list, int left, int mid, int right)
{
    int i, j, k;
    int *sorted;
    sorted = (int *)malloc(sizeof(int) * (right + 1));
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
    free(sorted);
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
    int n, characteristic_value, sum;
    characteristic_value = 2000000000;
    int res[2];
    scanf("%d", &n);

    int *arr, *start, *end;
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n - 1);

    start = &arr[0];
    end = &arr[n - 1];

    while (start != end)
    {
        sum = abs(*start + *end);

        if (sum < characteristic_value)
        {
            characteristic_value = sum;
            res[0] = *start;
            res[1] = *end;
        }

        if (abs(*start) > abs(*end))
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    printf("%d %d", res[0], res[1]);
}