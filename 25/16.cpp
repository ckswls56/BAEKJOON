#include <iostream>
#include <vector>
#include <queue>   // use bfs algorithm
#include <stdio.h> // use printf, scanf
#include <cstring> // use memset

using namespace std;

vector<int> graph[20001];
int visited[20001];

void bfs(int r)
{
    queue<int> q;
    int color = 1;

    visited[r] = 1;
    q.push(r);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        color = -visited[x];

        for (int i = 0; i < graph[x].size(); i++)
        {
            int next = graph[x][i];
            if (!visited[next])
            {
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

void dfs(int r)
{
    if (!visited[r])
        visited[r] = 1;

    for (int i = 0; i < graph[r].size(); i++)
    {
        int next = graph[r][i];
        if (!visited[next])
        {
            visited[next] = visited[r] * -1;
            dfs(next);
        }
    }
}

bool is_bipartite_graph(int v)
{
    for (int i = 1; i <= v; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j];

            if (visited[i] == visited[next])
                return false;
        }
    }
    return true;
}

int main()
{
    int K, V, E, u, v;
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d %d", &V, &E);
        for (int i = 1; i <= E; i++)
        {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                // bfs(i);
                dfs(i);
            }
        }

        if (is_bipartite_graph(V))
            printf("YES\n");
        else
            printf("NO\n");

        for (int i = 1; i <= V; i++)
        {
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));
    }
}