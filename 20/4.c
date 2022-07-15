#include <stdio.h>
#include <stdlib.h>

int *q[20000];
int front = -1;
int rear = -1;

int is_empty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}

void push(int *c)
{
    q[++rear] = c;
}

int *pop()
{
    if (!is_empty())
        return q[++front];
    else
        return NULL;
}

int size()
{
    return rear - front;
}

int check(int c)
{
    for (int i = front + 1; i <= rear; i++)
    {
        if (c < *q[i])
            return 1;
    }
    return 0;
}

int main()
{
    int t, n, m;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        int *arr;
        arr = (int *)malloc(sizeof(int) * n);
        int *find;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        find = &arr[m];

        for (int i = 0; i < n; i++)
        {
            push(&arr[i]);
        }

        int cnt = 0;
        while (size() != 0)
        {
            if (check(*q[front + 1]))
                push(pop());
            else
            {
                cnt++;
                if (pop() == find)
                {
                    printf("%d\n", cnt);
                }
            }
        }

        free(arr);
    }
}