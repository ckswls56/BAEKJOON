#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 100000 + 1
using namespace std;

vector<pair<int, int>> graph[MAX_VERTEX];
bool visit[MAX_VERTEX];
int max_dist, max_node;
void dfs(int node, int dist)
{
    if (visit[node])
        return;

    if (max_dist < dist)
    {
        max_dist = dist;
        max_node = node;
    }
    visit[node] = true;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i].first;
        int next_dist = graph[node][i].second;
        dfs(next, dist + next_dist);
    }
}

int main()
{ // 트리의 지름은 임의의 한정점 에서 가장먼 v1를 찾고 v1에서 가장 먼 v2를 찾아 거리 출력
    int n, u, v, w;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &u, &v);
        while (v != -1)
        {
            scanf("%d", &w);
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
            scanf("%d", &v);
        }
    }
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    max_dist = 0;

    dfs(max_node, 0);

    printf("%d\n", max_dist);
}