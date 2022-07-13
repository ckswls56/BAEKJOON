#include <stdio.h>

int stack[100000];
int top = -1;

void push(int c)
{
    stack[++top] = c;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int k;
    scanf("%d", &k);
    int x;
    while (k--)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            pop();
        }
        else
            push(x);
    }
    int sum = 0;
    while (top != -1)
    {
        sum += pop();
    }

    printf("%d", sum);
}