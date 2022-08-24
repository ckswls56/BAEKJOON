#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, s, res, sum;
    scanf("%d %d", &n, &s);

    int *arr, *start, *end;
    arr = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    start = &arr[0];
    end = &arr[0];

    res = 100001;
    sum = 0;
    while (start != &arr[n])
    {

        if (sum >= s)
        {
            if (res > (end - start))
                res = (end - start);
        }

        if (sum >= s || end == &arr[n])
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

    if (res == 100001)
        printf("0");
    else
        printf("%d", res);
}