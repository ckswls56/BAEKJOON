#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 20000 + 1
#define INF 10000000
using namespace std;
int V, E;

vector<pair<int, int>> graph[MAX_VERTEX];
int d[MAX_VERTEX];

struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int start)
{
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
    int k, u, v, w;
    scanf("%d %d", &V, &E);
    scanf("%d", &k);

    for (int i = 1; i <= V; i++)
    {
        d[i] = INF;
    }

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
    }
    dijkstra(k);

    for (int i = 1; i <= V; i++)
    {
        if (d[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", d[i]);
    }
}