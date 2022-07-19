#include <stdio.h>
#include <stdlib.h>

int **arr;
int minus_cnt = 0;
int zero_cnt = 0;
int plus_cnt = 0;

void devide(int x, int y, int n)
{

    if (n == 1)
    {
        if (arr[y][x] < 0)
            minus_cnt++;
        else if (arr[y][x] == 0)
            zero_cnt++;
        else
            plus_cnt++;
        return;
    }

    int flag = 0;

    int start;
    if (arr[y][x] < 0)
        start = -1;
    else if (arr[y][x] == 0)
        start = 0;
    else
        start = 1;

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (start == -1 && (arr[i][j] == 0 || arr[i][j] == 1))
            {
                flag = 1;
                break;
            }
            else if (start == 0 && (arr[i][j] == -1 || arr[i][j] == 1))
            {
                flag = 1;
                break;
            }
            else if (start == 1 && (arr[i][j] == -1 || arr[i][j] == 0))
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag)
    {
        for (int i = y; i < y + n; i += n / 3)
        {
            for (int j = x; j < x + n; j += n / 3)
                devide(j, i, n / 3);
        }
    }
    else
    {
        if (start < 0)
            minus_cnt++;
        else if (start == 0)
            zero_cnt++;
        else
            plus_cnt++;
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
    printf("%d\n%d\n%d", minus_cnt, zero_cnt, plus_cnt);
}