#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, k;

    scanf("%d %d", &n, &k);

    int *arr;
    arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int cnt = 0;
    while (k > 0)
    {
        int i = n - 1;
        while (i >= 0)
        {
            if (arr[i] > k)
                i--;
            else
            {
                cnt += k / arr[i];
                k %= arr[i];
                i--;
            }
            if (k <= 0)
                break;
        }
    }

    printf("%d", cnt);
}