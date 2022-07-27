#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Max Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, x;

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }
}