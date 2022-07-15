#include <stdio.h>
#include <stdlib.h>

int q[10000000];
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

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        push(i);
    }

    while (size() != 1)
    {
        pop();
        push(pop());
    }

    printf("%d", pop());
}