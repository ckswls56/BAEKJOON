#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000 + 1
vector<int> tree[MAX];
char visited[MAX];
int res[MAX];

void bfs()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int i = 0; i < tree[p].size(); i++)
        {
            int c = tree[p][i];
            if (!visited[c])
            {
                res[c] = p;
                visited[c] = 1;
                q.push(c);
            }
        }
    }
}
int main()
{
    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    bfs();
    for (int i = 2; i <= n; i++)
        printf("%d\n", res[i]);
}
