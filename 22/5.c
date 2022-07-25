#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr;
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int low, mid, high;
    low = 0;
    high = k;
    int c;
    while (low < high && high - low != 1)
    {
        mid = (low + high) / 2;
        c = 0;
        for (int i = 0; i < n; i++)
        {
            c += min(mid / arr[i], n);
        }
        if (c >= k)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    printf("%d", high);

    return 0;
}