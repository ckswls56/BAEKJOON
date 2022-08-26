#include <stdio.h>
#include <stdlib.h>

int q[100000];
int *arr;
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

void print_path()
{
    while (!is_empty())
    {
        printf("%d ", pop());
    }
}

void dfs(int n)
{
    if (n == 1)
    {
        push(1);
        print_path();
        exit(0);
    }
    else
    {
        if (n % 3 == 0 && arr[n / 3] == arr[n] - 1)
        {
            push(n);
            dfs(n / 3);
            pop();
        }
        if (n % 2 == 0 && arr[n / 2] == arr[n] - 1)
        {
            push(n);
            dfs(n / 2);
            pop();
        }
        if (arr[n - 1] == arr[n] - 1)
        {
            push(n);
            dfs(n - 1);
            pop();
        }
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * (n + 1));

    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    int a, b, c;
    for (int i = 4; i <= n; i++)
    {
        a = arr[i / 3] + 1;
        b = arr[i / 2] + 1;
        c = arr[i - 1] + 1;

        if (i % 6 == 0)
        {
            if (a < b)
                arr[i] = a;
            else
                arr[i] = b;
        }
        else if (i % 3 == 0 && a < c)
        {
            arr[i] = a;
        }
        else if (i % 2 == 0 && b < c)
        {
            arr[i] = b;
        }
        else
            arr[i] = c;
    }

    printf("%d\n", arr[n]);
    dfs(n);
}