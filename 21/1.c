#include <stdio.h>
#include <stdlib.h>

int **arr;
int blue_cnt = 0;
int white_cnt = 0;

void devide(int x, int y, int n)
{

    if (n == 1)
    {
        if (arr[y][x])
            blue_cnt++;
        else
            white_cnt++;
        return;
    }

    int flag = 0;
    int start;
    if (arr[y][x])
        start = 1;
    else
        start = 0;

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (start && !arr[i][j])
            {
                flag = 1;
                break;
            }
            else if (!start && arr[i][j])
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag)
    {
        devide(x, y, n / 2);
        devide(x + n / 2, y, n / 2);
        devide(x, y + n / 2, n / 2);
        devide(x + n / 2, y + n / 2, n / 2);
    }
    else
    {
        if (start)
            blue_cnt++;
        else
            white_cnt++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    arr = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    devide(0, 0, n);
    printf("%d\n%d", white_cnt, blue_cnt);
}