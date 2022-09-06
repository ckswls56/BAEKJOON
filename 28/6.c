#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
char visited[MAX];
int q[MAX];
int res[MAX];
int path[MAX];
int front = -1;
int rear = -1;

int n, k, i;

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

void print_path()
{
    while (i > -1)
    {
        printf("%d ", path[i--]);
    }
}

void dfs(int c)
{
    if (c == n)
    {
        path[i] = c;
        print_path();
        exit(0);
    }

    if (c - 1 >= 0 && res[c - 1] == res[c] - 1)
    {
        path[i++] = c;
        dfs(c - 1);
        i--;
    }
    if (c + 1 < 100001 && res[c + 1] == res[c] - 1)
    {
        path[i++] = c;
        dfs(c + 1);
        i--;
    }
    if (c / 2 >= 0 && res[c / 2] == res[c] - 1)
    {
        path[i++] = c;
        dfs(c / 2);
        i--;
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    bfs();
    printf("%d\n", res[k]);
    res[n] = 0;
    dfs(k);
}