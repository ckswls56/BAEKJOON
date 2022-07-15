#include <stdio.h>
#include <stdlib.h>

int q[501500];
int front = -1;
int rear = -1;

int is_empty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}

void push(int c)
{
    q[++rear] = c;
}

int pop()
{
    if (!is_empty())
        return q[++front];
    else
        return -1;
}

int size()
{
    return rear - front;
}

void yousepusu(int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        push(pop());
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
    {
        push(i);
    }

    printf("<");
    while (size() != 1)
    {
        yousepusu(k);
        printf("%d, ", pop());
    }

    printf("%d>", pop());
}