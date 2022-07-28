#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Max Heap
    priority_queue<int, vector<int>, less<int>> max_h;
    priority_queue<int, vector<int>, greater<int>> min_h;

    int n, x;

    scanf("%d", &n);

    while (n--)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            if (max_h.empty() && min_h.empty())
            {
                printf("0\n");
            }
            else
            {
                if (max_h.empty())
                {
                    printf("%d\n", min_h.top());
                    min_h.pop();
                }
                else if (min_h.empty())
                {
                    printf("%d\n", max_h.top());
                    max_h.pop();
                }
                else
                {
                    if (abs(max_h.top()) <= min_h.top())
                    {
                        printf("%d\n", max_h.top());
                        max_h.pop();
                    }
                    else
                    {
                        printf("%d\n", min_h.top());
                        min_h.pop();
                    }
                }
            }
        }
        else
        {
            if (x > 0)
                min_h.push(x);
            else
                max_h.push(x);
        }
    }
}