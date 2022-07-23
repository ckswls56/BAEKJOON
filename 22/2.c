#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

int main()
{
    long long k, n;
    scanf("%lld %lld", &k, &n);

    long long *arr;
    arr = (long long *)malloc(sizeof(long long) * k);
    long long max = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &arr[i]);
    }

    long long lan, low, mid, high;
    high = max * 2;
    low = 0;

    while (low < high && high - low != 1)
    {
        mid = (low + high) / 2;
        lan = 0;
        for (int i = 0; i < k; i++)
        {
            lan += arr[i] / mid;
        }
        if (lan < n)
        {
            high = mid;
        }
        else
        {
            low = mid;
            max = low;
        }
    }
    printf("%lld", max);
}