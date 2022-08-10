#include <iostream>
#include <queue>
#include <deque>
#include <string.h>
#include <math.h>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
int visited[1001] = {0};

void dfs(int r)
{
    if (visited[r] == 1)
    { // 방문 한 곳이면 return
        return;
    }

    visited[r] = 1; // 방문하지 않았다면 방문했다고 표시
    printf("%d ", r);

    for (int i = 0; i < graph[r].size(); i++)
    {
        dfs(graph[r][i]);
    }
}

void bfs(int r)
{
    visited[r] = 1;
    printf("%d ", r);
    queue<int> q;
    q.push(r);

    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++)
        {
            if (visited[graph[u][i]] == 0)
            {
                visited[graph[u][i]] = 1;
                q.push(graph[u][i]);
                printf("%d ", graph[u][i]);
            }
        }
    }
}

int main()
{
    int n, m, r, u, v;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v); // (1,4) (1,2) (2,3) (2,4) (3,4)
        graph[v].push_back(u); // (4,1) (2,1) (3,2) (4,2) (4,3)
    }
    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(r);

    printf("\n");
    memset(visited, 0, sizeof(visited));

    bfs(r);
}