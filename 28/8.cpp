#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 1000 + 1
#define INF 1000000000
using namespace std;
int V, E;

vector<pair<int, int>> graph[MAX_VERTEX];
int d[MAX_VERTEX];
int path[MAX_VERTEX];

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
                path[next] = current;
                pq.push(make_pair(next, nextDistance));
            }
        }
    }
}

void print_path(int start, int end)
{
    stack<int> s;
    while (start != end)
    {
        s.push(end);
        end = path[end];
    }
    s.push(start);
    cout << s.size() << endl;
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
}

int main()
{
    int start, end, u, v, w;
    scanf("%d %d", &V, &E);

    for (int i = 1; i <= V; i++)
    {
        d[i] = INF;
    }

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(v, w));
    }

    scanf("%d %d", &start, &end);
    dijkstra(start);
    int min_cost = d[end];
    printf("%d\n", min_cost);
    print_path(start, end);
}