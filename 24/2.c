#include <stdio.h>
#include <stdlib.h>
#define INF 2147483647
#define min(a, b) (((a) < (b)) ? (a) : (b))
int dp[501][501];

typedef struct matrix
{
    int x;
    int y;
} matrix;

int main()
{
    int n;
    scanf("%d", &n);
    matrix *m;
    m = (matrix *)malloc(sizeof(matrix) * (n + 1));

    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &m[i].x, &m[i].y);
    }

    for (int d = 1; d < n; ++d)
    {
        for (int i = 1; i + d <= n; ++i)
        {
            int j = i + d;
            dp[i][j] = INF;

            for (int mid = i; mid < j; ++mid)
                dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + m[i].x * m[mid].y * m[j].y);
        }
    }
    printf("%d", dp[1][n]);
}