#include <stdio.h>
#define MAX 101
char ladder[MAX];
int visited[MAX];
int q[MAX * MAX];
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

void bfs()
{
    push(1);
    while (size())
    {
        int x = pop();
        if (x == MAX - 1)
            return;
        for (int i = 1; i <= 6; i++)
        {
            if (visited[i + x] == 0 && x + i <= 100)
            {
                if (ladder[i + x])
                {
                    push(ladder[i + x]);
                    if (!visited[ladder[i + x]])
                        visited[ladder[i + x]] = visited[x] + 1;
                }
                else
                {
                    push(i + x);
                    visited[i + x] = visited[x] + 1;
                }
            }
        }
    }
}

int main()
{
    int n, m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n + m; i++)
    {
        scanf("%d %d", &u, &v);
        ladder[u] = v;
    }

    bfs();
    printf("%d", visited[MAX - 1]);
}