#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char command[5][6] = {"push", "pop", "size", "empty", "top"};
int stack[10000];
int top = -1;

int get_command(char *str)
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(command[i], str) == 0)
            return i;
    }
    return -1;
}

void push(int c)
{
    stack[++top] = c;
}

void pop()
{
    if (top == -1)
        printf("-1\n");
    else
    {
        printf("%d\n", stack[top--]);
    }
}

void size()
{
    printf("%d\n", top + 1);
}

void empty()
{
    if (top == -1)
    {
        printf("1\n");
    }
    else
        printf("0\n");
}

void print_top()
{
    if (top != -1)
        printf("%d\n", stack[top]);
    else
        printf("-1\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    char str[6];
    while (n--)
    {
        scanf("%s", str);
        switch (get_command(str))
        {
        case 0:
        {
            int x;
            scanf("%d", &x);
            push(x);
            break;
        }
        case 1:
            pop();
            break;
        case 2:
            size();
            break;
        case 3:
            empty();
            break;
        case 4:
            print_top();
            break;
        default:
            printf("error input");
            break;
        }
    }
    return 0;
}