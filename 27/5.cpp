#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll n, c, ans;
ll arr[31];
vector<ll> front;
vector<ll> back;

void dfs(int s, int e, vector<ll> &v, long long sum)
{
    if (s > e)
    {
        v.push_back(sum);
        return;
    }
    else
    {
        dfs(s + 1, e, v, sum);
        dfs(s + 1, e, v, sum + arr[s]);
    }
    // O(2^n);
}

int main()
{
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dfs(0, n / 2, front, 0);
    dfs(n / 2 + 1, n - 1, back, 0);
    sort(back.begin(), back.end());

    for (int i = 0; i < front.size(); i++)
    {
        ans += upper_bound(back.begin(), back.end(), c - front[i]) - back.begin();
        // upper_bound의 반환형이 iter이다.
    }

    cout << ans << endl;
}
