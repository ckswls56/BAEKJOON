#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 2000 + 1
#define INF 10000000
using namespace std;
int n;

vector<pair<int, int>> graph[MAX_VERTEX];
int d[MAX_VERTEX];
int start[MAX_VERTEX]; // 시작지점 부터 거리

struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int start, int *d)
{

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    pq.push(make_pair(start, 0));
    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        if (d[current] < distance)
            continue;
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int nextDistance = distance + graph[current][i].second;

            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push(make_pair(next, nextDistance));
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int m, t, s, g, h;
        priority_queue<int, vector<int>, greater<>> possible;
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);

        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            graph[a].push_back(make_pair(b, d));
            graph[b].push_back(make_pair(a, d));
        }
        for (int i = 0; i < t; i++)
        {
            int x;
            scanf("%d", &x);
            possible.push(x);
        }
        int v1, v2, s_to_g, s_to_h, g_to_h, g_to_n, h_to_n, res;

        dijkstra(g, start);
        g_to_h = start[h];
        dijkstra(s, start);
        s_to_g = start[g];
        s_to_h = start[h];

        for (int i = 0; i < t; i++)
        {
            int x = possible.top();
            dijkstra(g, d);
            g_to_n = d[x];
            dijkstra(h, d);
            h_to_n = d[x];
            res = (min(s_to_g + g_to_h + h_to_n, s_to_h + g_to_h + g_to_n));

            if (res < INF && res == start[x])
                printf("%d ", x);

            possible.pop();
        }
        printf("\n");

        for (int i = 0; i <= n; i++)
        {
            graph[i].clear();
        }
    }
}