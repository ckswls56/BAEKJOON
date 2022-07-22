#include <stdio.h>
#include <stdlib.h>

int **make_arr(int n, int m, int input)
{

    int **arr;
    arr = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * m);
    }

    if (input)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
    }

    return arr;
}

void matrix_mul(int **res, int **a, int **b, int n, int m, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            res[i][j] = 0;
            for (int q = 0; q < m; q++)
            {
                res[i][j] += a[i][q] * b[q][j];
            }
        }
    }
}

int main()
{
    int n, m, k;
    scanf("%d %d", &n, &m);
    int **a;
    int **b;
    int **res;
    a = make_arr(n, m, 1);
    scanf("%d %d", &m, &k);
    b = make_arr(m, k, 1);
    res = make_arr(n, k, 0);

    matrix_mul(res, a, b, n, m, k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}