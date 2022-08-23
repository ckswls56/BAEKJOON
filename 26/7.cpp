#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 400 + 1
#define INF 10000000
using namespace std;

int d[MAX_VERTEX][MAX_VERTEX];
int V, E;

vector<pair<int, int>> graph[MAX_VERTEX];

struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int start, int *d)
{
    for (int i = 1; i <= V; i++)
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
    int u, v, w, res;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
    }

    for (int i = 1; i <= V; i++)
    {
        dijkstra(i, d[i]);
    }

    res = INF;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (d[i][j] != 0 && d[j][i] != 0 && d[i][j] != INF && d[j][i] != INF)
            {
                if (res > d[i][j] + d[j][i])
                    res = d[i][j] + d[j][i];
            }
        }
    }

    if (res == INF)
        printf("-1");
    else
        printf("%d", res);
}