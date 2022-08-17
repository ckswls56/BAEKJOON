#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 800 + 1
#define INF 987654321
using namespace std;
int n, e;

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
    for (int i = 1; i <= n; i++)
        d[i] = INF;

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
    int v1, v2, s_to_v1, s_to_v2, v1_to_v2, v1_to_n, v2_to_n, res;
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    scanf("%d %d", &v1, &v2);

    // start -> v1 -> v2 -> N or start -> v2 -> v1 -> N

    dijkstra(1);
    s_to_v1 = d[v1];
    s_to_v2 = d[v2];
    dijkstra(v1);
    v1_to_v2 = d[v2]; // v1_to_v2 == v2_to_v1
    v1_to_n = d[n];
    dijkstra(v2);
    v2_to_n = d[n];

    res = min(s_to_v1 + v1_to_v2 + v2_to_n, s_to_v2 + v1_to_v2 + v1_to_n);
    if (v1_to_v2 == INF || res >= INF)
        printf("-1");
    else
        printf("%d", res);
}