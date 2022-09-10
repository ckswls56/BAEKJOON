#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 100000 + 1
using namespace std;

vector<pair<int, int>> graph[MAX_VERTEX];
int res;

struct comp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int dfs(int node, int b)
{
    if (graph[node].size() == 0)
    {
        return b;
    }
    priority_queue<int> q;
    int leaf1, leaf2;
    int max_leaf = 0;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int leaf = dfs(graph[node][i].first, graph[node][i].second);
        max_leaf = max(max_leaf, leaf);
        q.push(leaf);
    }

    leaf1 = q.top();
    q.pop();
    if (!q.empty())
        leaf2 = q.top();
    else
        leaf2 = 0;

    if (leaf1 + leaf2 > res)
    {
        res = leaf1 + leaf2;
    }

    return leaf1 + b;
}

int main()
{
    int n, u, v, w;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &u, &v);
        v = 0;
        while (v != -1)
        {
            scanf("%d", &w);
            graph[u].push_back({v, w});
            scanf("%d", &v);
        }
    }
    res = max(res, dfs(1, 0));
    printf("%d\n", res);
}