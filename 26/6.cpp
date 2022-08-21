#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 100 + 1
#define INF 10000000
using namespace std;

int dp[MAX_VERTEX][MAX_VERTEX];
int n, m;

void floyd()
{
    int a, b, c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                dp[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        dp[a][b] = min(dp[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                dp[a][b] = min(dp[a][b], dp[a][k] + dp[k][b]);
            }
        }
    }
}

//모든 노드에서 다른 모든 노드까지의 최단 경로.
int main()
{
    scanf("%d %d", &n, &m);
    floyd();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == INF)
                printf("0 ");
            else
                printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}