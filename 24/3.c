#include <stdio.h>
#include <string.h>
#define MAX 501
const int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dp[MAX][MAX];
int arr[MAX][MAX];
int m, n;

int dfs(int y, int x)
{
    //기저 사례
    if (y == m && x == n)
    {
        return 1;
    }

    if (dp[y][x] == -1)
    {
        dp[y][x] = 0;
        for (int i = 0; i < 4; i++)
        {
            int dy = y + direction[i][0];
            int dx = x + direction[i][1];
            if (arr[dy][dx] != 0 && arr[y][x] > arr[dy][dx])
            {
                dp[y][x] += dfs(dy, dx);
            }
        }
    }
    // 방문한 곳이라면 해당 좌표에서 목적지까지 도달할 수 있는 경로 반환
    return dp[y][x];
}

int main()
{

    scanf("%d %d", &m, &n);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", dfs(1, 1));
}