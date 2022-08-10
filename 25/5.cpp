#include <iostream>
#include <queue>
#include <deque>
#include <string.h>
#include <math.h>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[101];
int visited[101] = {0};
int cnt = -1;

void dfs(int r)
{
    if (visited[r] == 1)
    { // 방문 한 곳이면 return
        return;
    }

    visited[r] = 1; // 방문하지 않았다면 방문했다고 표시
    cnt++;

    for (int i = 0; i < graph[r].size(); i++)
    {
        dfs(graph[r][i]);
    }
}
int main()
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v); // (1,4) (1,2) (2,3) (2,4) (3,4)
        graph[v].push_back(u);
    }

    dfs(1);
    printf("%d", cnt);
}