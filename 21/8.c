#include <stdio.h>
#include <stdlib.h>

long long **make_arr(int n)
{
    long long **arr;
    arr = (long long **)malloc(sizeof(long long *) * n);
    for (int i = 0; i < 2; i++)
    {
        arr[i] = (long long *)malloc(sizeof(long long) * n);
    }
    return arr;
}

long long **cpy_arr(long long **res)
{
    long long **temp = (long long **)malloc(sizeof(long long *) * 2);
    for (int i = 0; i < 2; i++)
    {
        temp[i] = (long long *)malloc(sizeof(long long) * 2);
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            temp[i][j] = res[i][j];
        }
    }
    return temp;
}

void matrix_mul(long long **res, long long **a, long long **b)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = 0;
            for (int q = 0; q < 2; q++)
            {
                res[i][j] += a[i][q] * b[q][j];
            }
            res[i][j] %= 1000000007;
        }
    }
}

long long **matrix_power(long long **a, long long **res, long long b)
{
    if (b == 1)
        return a;
    long long **temp = matrix_power(a, res, b / 2);
    matrix_mul(res, temp, temp);

    if (b % 2 == 0)
    {
        temp = cpy_arr(res);
        return temp;
    }
    else
    {
        temp = cpy_arr(res);
        matrix_mul(res, temp, a);
        free(temp);
        temp = cpy_arr(res);
        return temp;
    }
}

int main()
{
    long long n;
    scanf("%lld", &n);
    long long **a;
    long long **res;
    res = make_arr(2);
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    res = matrix_power(a, res, n);

    printf("%d ", res[1][0] % 1000000007);
    return 0;
}