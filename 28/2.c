#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
int arr[1000001];
int dp[1000001];
int stack[1000000];
int top = -1;

void push(int c)
{
    stack[++top] = c;
}

int pop()
{
    if (top == -1)
        return -1;
    else
    {
        return stack[top--];
    }
}

int get_top()
{
    return stack[top];
}

int get_max_idx(int n)
{
    int max = 0;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > max)
        {
            ret = i;
            max = dp[i];
        }
    }
    return ret;
}

void print_path(int n)
{
    int len = dp[n];
    push(arr[n]);
    while (len != 1)
    {
        if (dp[n - 1] == len - 1 && get_top() > arr[n - 1])
        {
            push(arr[n - 1]);
            len--;
        }
        n--;
    }

    while (top != -1)
    {
        printf("%d ", pop());
    }
}

int main()
{
    int n, max_idx;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    max_idx = get_max_idx(n);

    printf("%d\n", dp[max_idx]);
    print_path(max_idx);
}