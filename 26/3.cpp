#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 100000 + 1
#define INF 10000000
using namespace std;
int n, k;

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
    scanf("%d %d", &n, &k);

    for (int i = 0; i < MAX_VERTEX; i++)
    {
        d[i] = INF;
    }

    for (int i = 0; i <= 50000; i++)
    {
        graph[i].push_back(make_pair(i + 1, 1));
        graph[i + 1].push_back(make_pair(i, 1));
        graph[i].push_back(make_pair(i * 2, 0));
    }
    for (int i = 50000; i < 100000; i++)
    {
        graph[i].push_back(make_pair(i + 1, 1));
        graph[i + 1].push_back(make_pair(i, 1));
    }

    dijkstra(n);

    printf("%d", d[k]);
}