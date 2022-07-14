#include <stdio.h>
#include <stdlib.h>

int stack[1000000];
int top = -1;

void push(int c)
{
    stack[++top] = c;
}

int pop()
{
    if (top != -1)
        return stack[top--];
    else
        return -1;
}

int get_top()
{
    if (top != -1)
        return stack[top];
    else
        return -1;
}

int find(int c)
{
    for (int i = top; i >= 0; i--)
    {
        if (stack[i] > c)
            return stack[i];
    }
    return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr;
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    push(arr[n - 1]);
    int max = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (max < arr[i])
            max = arr[i];

        if (arr[i] < arr[i + 1])
        {
            push(arr[i + 1]);
        }
        else if (arr[i] == arr[i + 1])
            push(get_top());
        else
        {
            if (arr[i] < get_top())
                push(get_top());
            else
            {
                if (max == arr[i])
                    push(arr[i]);
                else
                {
                    push(find(arr[i]));
                }
            }
        }
    }

    int nge;
    for (int i = 0; i < n; i++)
    {
        nge = pop();
        if (arr[i] == nge)
        {
            printf("-1 ");
        }
        else
            printf("%d ", nge);
    }
}