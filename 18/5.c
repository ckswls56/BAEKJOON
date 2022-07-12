#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *city, *distance;
    city = (int *)malloc(sizeof(int) * n);
    distance = (int *)malloc(sizeof(int) * n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &distance[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &city[i]);
    }

    long long int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += distance[i] * city[i];
        for (int j = i + 1; j < n - 1; j++)
        {
            if (city[i] != 0 && city[i] < city[j])
            {
                sum += distance[j] * city[i];
                city[j] = 0;
            }
            else
                break;
        }
    }
    printf("%lld", sum);

    return 0;
}