#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321
#define MAX 501
#define ll long long

int N, M;

ll d[MAX];
vector<pair<int, int>> graph[MAX];

void bellman_ford(bool &cycle)
{
    d[1] = 0;

    for (int i = 1; i <= N; i++)
    { // n-1번 반복하고 n번쨰에 최단경로가 갱신이 된다면 음의 사이클이 존재한다.
        for (int start = 1; start <= N; start++)
        {
            for (auto x : graph[start])
            {
                int end = x.first;
                int cost = x.second;

                if (d[start] != INF && d[end] > d[start] + cost)
                {
                    d[end] = d[start] + cost;
                    if (i == N)
                    {
                        cycle = true;
                    }
                }
            }
        }
    }
}

int main()
{
    for (int i = 1; i < MAX; i++)
        d[i] = INF;

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);
        graph[s].push_back({e, c});
    }
    bool cycle = false;
    bellman_ford(cycle);

    if (cycle)
        cout << -1;
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (d[i] >= INF)
                cout << "-1\n";
            else
                cout << d[i] << "\n";
        }
    }
}