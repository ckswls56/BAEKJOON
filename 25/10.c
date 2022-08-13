#include <stdio.h>
#define MAX 100001
char visited[MAX];
int q[MAX];
int res[MAX];
int front = -1;
int rear = -1;

void push(int c)
{
    q[++rear] = c;
}

int pop()
{
    return q[++front];
}

int size()
{
    return rear - front;
}

void bfs(int n, int k)
{
    push(n);

    while (size())
    {
        int c = pop();
        if (visited[c] == 1)
            continue;
        if (c == k)
        {
            break;
        }
        visited[c] = 1;
        if (c - 1 >= 0 && res[c - 1] == 0)
        {
            push(c - 1);
            res[c - 1] = res[c] + 1;
        }
        if (c + 1 < 100001 && res[c + 1] == 0)
        {
            push(c + 1);
            res[c + 1] = res[c] + 1;
        }
        if (c * 2 < 100001 && res[c * 2] == 0)
        {
            push(c * 2);
            res[c * 2] = res[c] + 1;
        }
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    bfs(n, k);
    printf("%d", res[k]);
}