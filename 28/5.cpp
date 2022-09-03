#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int n, w;

pair<int, int> work[1001];
int dp[1001][1001]; // dp[i][j] == i는 1번 경찰차가 마지막으로 처리한 사건번호 j는 2번경찰차가 마지막으로 처리한 사건번호

int dist(pair<int, int> a, pair<int, int> b)
{
    return abs(b.first - a.first) + abs(b.second - a.second);
}

int sol(int x, int y)
{

    if (x == w || y == w)
        return 0;

    // memoization
    int &cashe = dp[x][y];
    if (cashe != -1)
        return dp[x][y];

    int next = max(x, y) + 1;
    int dist1, dist2;

    if (x == 0)
        dist1 = dist({1, 1}, work[next]);
    else
        dist1 = dist(work[x], work[next]);

    if (y == 0)
        dist2 = dist({n, n}, work[next]);
    else
        dist2 = dist(work[y], work[next]);

    cashe = min(sol(next, y) + dist1, sol(x, next) + dist2);
    return cashe;
}

void trace(int x, int y)
{
    if (x == w || y == w)
        return;

    int next = max(x, y) + 1;
    int dist1, dist2;

    if (x == 0)
        dist1 = dist({1, 1}, work[next]);
    else
        dist1 = dist(work[x], work[next]);

    if (y == 0)
        dist2 = dist({n, n}, work[next]);
    else
        dist2 = dist(work[y], work[next]);

    if (dp[next][y] + dist1 > dp[x][next] + dist2)
    {
        printf("2\n");
        trace(x, next);
    }
    else
    {
        printf("1\n");
        trace(next, y);
    }
}

int main()
{
    scanf("%d %d", &n, &w);
    for (int i = 1; i <= w; i++)
    {
        scanf("%d %d", &work[i].first, &work[i].second);
    }
    memset(dp, -1, sizeof(dp));

    printf("%d\n", sol(0, 0));
    trace(0, 0);

    return 0;
}
