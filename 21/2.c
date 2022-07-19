#include <stdio.h>
#include <stdlib.h>

char **arr;

void devide(int x, int y, int n)
{

    if (n == 1)
    {
        if (arr[y][x] == '1')
            printf("1");
        else
            printf("0");
        return;
    }

    char flag = 0;
    char start;
    if (arr[y][x] == '1')
        start = 1;
    else
        start = 0;

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (start && arr[i][j] == '0')
            {
                flag = 1;
                break;
            }
            else if (!start && arr[i][j] == '1')
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag)
    {
        printf("(");
        devide(x, y, n / 2);
        devide(x + n / 2, y, n / 2);
        devide(x, y + n / 2, n / 2);
        devide(x + n / 2, y + n / 2, n / 2);
        printf(")");
    }
    else
    {
        if (start)
            printf("1");
        else
            printf("0");
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    arr = (char **)malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(sizeof(char) * n);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    devide(0, 0, n);
}