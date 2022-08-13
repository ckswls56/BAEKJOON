#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50

int arr[MAX_LENGTH][MAX_LENGTH];
int visited[MAX_LENGTH][MAX_LENGTH];
int m, n;

int dfs(int y, int x)
{
    if (visited[y][x] == 1 || x >= m || x < 0 || y >= n || y < 0)
    {
        return 0;
    }

    visited[y][x] = 1;
    if (arr[y][x] == 0)
        return 0;
    else
    {
        int left = dfs(y, x - 1);
        int right = dfs(y, x + 1);
        int down = dfs(y + 1, x);
        int up = dfs(y - 1, x);
        return left + right + down + up + 1;
    }
}

int main()
{
    int t, k, x, y, cnt;
    scanf("%d", &t);

    while (t--)
    {
        cnt = 0;
        scanf("%d %d %d", &m, &n, &k);
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        while (k--)
        {
            scanf("%d %d", &x, &y);
            arr[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dfs(i, j) > 0)
                    cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}