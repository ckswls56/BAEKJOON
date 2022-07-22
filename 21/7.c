#include <stdio.h>
#include <stdlib.h>

int n;

int **make_arr(int input)
{

    int **arr;
    arr = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * n);
    }
    if (input)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
    }

    return arr;
}

int **cpy_arr(int **res)
{
    int **temp = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        temp[i] = (int *)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = res[i][j];
        }
    }
    return temp;
}

int **matrix_power(int **a, int **res, long long b)
{
    if (b == 1)
        return a;
    int **temp = matrix_power(a, res, b / 2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for (int q = 0; q < n; q++)
            {
                res[i][j] += temp[i][q] * temp[q][j];
            }
            res[i][j] %= 1000;
        }
    }
    if (b % 2 == 0)
    {
        temp = cpy_arr(res);
        return temp;
    }
    else
    {
        temp = cpy_arr(res);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = 0;
                for (int q = 0; q < n; q++)
                {
                    res[i][j] += temp[i][q] * a[q][j];
                }
                res[i][j] %= 1000;
            }
        }
        free(temp);
        temp = cpy_arr(res);
        return temp;
    }
}

int main()
{
    long long b;
    scanf("%d %lld", &n, &b);
    int **a, **res;
    a = make_arr(1);
    res = make_arr(0);
    res = matrix_power(a, res, b);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", res[i][j] % 1000);
        }
        printf("\n");
    }

    return 0;
}