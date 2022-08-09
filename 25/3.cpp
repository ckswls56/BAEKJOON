#include <iostream>
#include <queue>
#include <deque>
#include <string.h>
#include <math.h>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001] = {0};
int result[100001];
int cnt = 0;

void bfs(int r)
{
    visited[r] = 1;
    result[r] = ++cnt;
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
                result[graph[u][i]] = ++cnt;
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
    bfs(r);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", result[i]);
    }
}