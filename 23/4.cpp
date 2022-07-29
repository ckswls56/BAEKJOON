#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Max Heap
    priority_queue<int, vector<int>, less<int>> max_h;    // 중앙값보다 큰 집합
    priority_queue<int, vector<int>, greater<int>> min_h; // 중앙값보다 작은 집합

    int n, x, mid;
    scanf("%d", &n);
    scanf("%d", &mid);
    printf("%d\n", mid);

    while (--n)
    {
        scanf("%d", &x);
        if (x > mid)
            min_h.push(x);
        else
            max_h.push(x);

        if (min_h.size() - max_h.size() == 2)
        {
            max_h.push(mid);
            mid = min_h.top();
            min_h.pop();
        }
        else if (max_h.size() - min_h.size() == 2)
        {
            min_h.push(mid);
            mid = max_h.top();
            max_h.pop();
        }
        else
        {
            if (max_h.size() > min_h.size() && max_h.top() < mid)
            {
                min_h.push(mid);
                mid = max_h.top();
                max_h.pop();
            }
        }

        printf("%d\n", mid);
    }
}