#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
#define MAX 1000000
int arr[MAX + 1];
int dp[MAX + 1];

int get_max_idx(int n)
{
    int max = 0;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > max)
        {
            ret = i;
            max = dp[i];
        }
    }
    return ret;
}

void print_path(int n)
{
    stack<int> s;
    int len = dp[n];
    s.push(arr[n]);
    while (len != 1)
    {
        if (dp[n - 1] == len - 1 && s.top() > arr[n - 1])
        {
            s.push(arr[n - 1]);
            len--;
        }
        n--;
    }

    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
}

int main()
{
    int n, max_idx;
    vector<int> v;
    vector<int>::iterator p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    v.push_back(arr[0]);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (v[v.size() - 1] < arr[i])
        {
            v.push_back(arr[i]);
            dp[i] = v.size();
        }
        else
        {
            p = lower_bound(v.begin(), v.end(), arr[i]);
            *(p) = arr[i];
            dp[i] = p - v.begin() + 1;
        }
    }

    cout << v.size() << endl;
    max_idx = get_max_idx(n);
    print_path(max_idx);
}