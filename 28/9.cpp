#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 100 + 1
#define INF 987654321
using namespace std;

int dp[MAX_VERTEX][MAX_VERTEX];
char waypoint[MAX_VERTEX][MAX_VERTEX];
vector<int> path;
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
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                if (dp[a][b] > dp[a][k] + dp[k][b])
                {
                    dp[a][b] = dp[a][k] + dp[k][b];
                    waypoint[a][b] = k;
                }
            }
        }
    }
}

void dfs(char start, char end)
{
    int k = waypoint[start][end];
    if (k == 0)
        return;
    else
    {
        dfs(start, k);
        path.push_back(k);
        dfs(k, end);
    }
}

//모든 노드에서 다른 모든 노드까지의 최단 경로.
int main()
{
    cin >> n >> m;
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || dp[i][j] == INF)
                printf("0\n");
            else
            {
                path.clear();
                dfs(i, j);
                printf("%d %d ", 2 + path.size(), i);
                for (int i = 0; i < path.size(); i++)
                {
                    printf("%d ", path[i]);
                }
                printf("%d\n", j);
            }
        }
    }
}