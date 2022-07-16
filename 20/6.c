#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 20000

int q[MAXSIZE];
int front = MAXSIZE / 2;
int rear = MAXSIZE / 2;

int is_empty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}

void push_front(int c)
{
    q[--front] = c;
}

void push_back(int c)
{
    q[rear++] = c;
}

int pop_front()
{
    if (!is_empty())
        return q[front++];
    else
        return -1;
}

int pop_back()
{
    if (!is_empty())
        return q[--rear];
    else
        return -1;
}

int get_front()
{
    if (!is_empty())
        return q[front];
    else
        return -1;
}

int size()
{
    return rear - front;
}
int find(int c)
{
    for (int i = front; i <= front + size() / 2; i++)
    {
        if (c == q[i])
            return 1;
    }
    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *arr;
    arr = (int *)malloc(sizeof(int) * m);

    for (int i = 1; i <= n; i++)
    {
        push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        if (get_front() == arr[i])
            pop_front();
        else
        {
            if (find(arr[i]))
            {
                while (get_front() != arr[i])
                {
                    push_back(pop_front());
                    cnt++;
                }
                pop_front();
            }
            else
            {
                while (get_front() != arr[i])
                {
                    push_front(pop_back());
                    cnt++;
                }
                pop_front();
            }
        }
    }
    printf("%d", cnt);

    return 0;
}