#include <stdio.h>

int main()
{
    int total, n, a, b;
    scanf("%d %d", &total, &n);

    while (n--)
    {
        scanf("%d %d", &a, &b);
        total -= a * b;
    }
    if (total == 0)
    {
        printf("Yes");
    }
    else
        printf("No");
}