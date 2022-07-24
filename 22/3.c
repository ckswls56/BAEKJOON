#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

int main()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);

    long long *arr;
    arr = (long long *)malloc(sizeof(long long) * n);
    long long max = 2000000000;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    long long tree, low, mid, high, temp;
    int flag = 0;
    high = max * 2;
    low = 0;

    while (low < high && high - low != 1)
    {
        mid = (low + high) / 2;
        tree = 0;
        for (int i = 0; i < n; i++)
        {
            temp = arr[i] - mid;
            if (temp > 0)
                tree += temp;
        }
        if (tree < m)
        {
            high = mid;
        }
        else
        {
            low = mid;
            max = low;
            flag = 1;
        }
    }
    if (flag)
        printf("%lld", max);
    else
        printf("%d", flag);
}