#include <stdio.h>
#include <stdlib.h>
int stack[1000000];
int top = -1;

void push(int c)
{
    stack[++top] = c;
}

int get_top()
{
    return stack[top];
}

void binary_search(int c)
{

    int low, mid, high;
    low = -1;
    high = top + 1;

    while (low + 1 < high)
    {
        mid = (low + high) / 2;

        if (c <= stack[mid])
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    stack[low + 1] = c;
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
    push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (get_top() < arr[i])
            push(arr[i]);
        else if (get_top() > arr[i])
            binary_search(arr[i]);
    }
    printf("%d", top + 1);
}
// https://23dotory.tistory.com/24