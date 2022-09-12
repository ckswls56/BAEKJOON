#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_VERTEX 500 + 1
using namespace std;

bool visited[MAX_VERTEX];      // 방문
vector<int> graph[MAX_VERTEX]; // 그래프
int p[MAX_VERTEX];             // 부모노드를 저장

int n, m;

int bfs()
{
    int total = 0;
    bool istree;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            istree = true;
            visited[i] = true;
            q.push(i);

            while (!q.empty())
            {
                int x = q.front();
                q.pop();

                for (int j = 0; j < graph[x].size(); j++)
                {
                    int t = graph[x][j];
                    if (visited[t] && p[x] != t)
                    {
                        istree = false;
                    }
                    else if (visited[t])
                        continue;
                    else
                    {
                        visited[t] = true;
                        p[t] = x;
                        q.push(t);
                    }
                }
            }
            if (istree)
                total++;
        }
    }
    return total;
}

int main()
{
    int t, tree_cnt, a, b;
    t = 1;
    while (1)
    {
        scanf("%d %d", &n, &m);
        if (!n && !m)
            break;
        for (int i = 1; i <= n; i++)
        {
            graph[i].clear();
            visited[i] = false;
            p[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        printf("Case %d: ", t++);
        tree_cnt = bfs();

        if (tree_cnt == 0)
            printf("No trees.\n");
        else if (tree_cnt == 1)
            printf("There is one tree.\n");
        else
            printf("A forest of %d trees.\n", tree_cnt);
    }
    return 0;
}