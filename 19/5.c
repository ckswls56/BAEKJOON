#include <stdio.h>
#include <stdlib.h>

int stack[100000];
int top = -1;
char *res;
int idx = 0;

void push(int c)
{
    stack[++top] = c;
    res[idx++] = '+';
}

int pop()
{
    res[idx++] = '-';
    return stack[top--];
}

int get_top()
{
    if (top == -1)
        return -1;
    else
        return stack[top];
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr;
    arr = (int *)malloc(sizeof(int) * n);
    res = (char *)malloc(sizeof(char) * (2 * n));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        push(i);
        if (i == arr[j])
        {
            pop();
            j++;
        }
        while (arr[j] == get_top())
        {
            pop();
            j++;
        }
    }

    if (idx == (2 * n))
    {
        for (int i = 0; i < idx; i++)
        {
            printf("%c\n", res[i]);
        }
    }
    else
        printf("NO");
}