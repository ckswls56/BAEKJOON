#include <stdio.h>

int chess[6] = {1, 1, 2, 2, 2, 8};

int main()
{
    int x;
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &x);
        chess[i] -= x;
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", chess[i]);
    }
    return 0;
}