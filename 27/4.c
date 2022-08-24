#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n, res, sum;
    scanf("%d", &n);

    int *arr, *start, *end;

    int cnt = 0;
    arr = (int *)malloc(sizeof(int) * 283146);
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
            arr[cnt++] = i;
    }

    start = &arr[0];
    end = &arr[0];

    res = 0;
    sum = 0;
    while (start != &arr[cnt])
    {

        if (sum == n)
        {
            res++;
        }

        if (sum >= n || end == &arr[cnt])
        {
            sum -= *start;
            start++;
        }
        else
        {
            sum += *end;
            end++;
        }
    }

    printf("%d", res);
}