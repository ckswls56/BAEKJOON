#include <stdio.h>
#include <stdlib.h>
int dp[500][500];
int m, n;
int **arr;

int check(int y1, int x1, int y2, int x2)
{
    if (y2 < 0 || x2 < 0 || y2 >= m || x2 >= n)
        return 0;
    if (arr[y1][x1] > arr[y2][x2])
        return 1;
    return 0;
}

void sol(int y, int x)
{
    dp[y][x]++;
    if (x == n - 1 && y == m - 1)
    {
        return;
    }

    if (check(y, x, y - 1, x)) // up
        sol(y - 1, x);
    if (check(y, x, y + 1, x)) // down
        sol(y + 1, x);
    if (check(y, x, y, x - 1)) // left
        sol(y, x - 1);
    if (check(y, x, y, x + 1)) // right
        sol(y, x + 1);
}

int main()
{

    scanf("%d %d", &m, &n);
    arr = (int **)malloc(sizeof(int *) * m);

    for (int i = 0; i < m; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    sol(0, 0);

    printf("%d", dp[m - 1][n - 1]);
}