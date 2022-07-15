#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char command[6][6] = {"push", "pop", "size", "empty", "front", "back"};
int q[2000000];
int front = -1;
int rear = -1;

int get_command(char *str)
{
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(command[i], str) == 0)
            return i;
    }
    return -1;
}

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

void print_front()
{
    if (!is_empty())
        printf("%d\n", q[front + 1]);
    else
        printf("-1\n");
}

void print_back()
{
    if (!is_empty())
        printf("%d\n", q[rear]);
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
            printf("%d\n", pop());
            break;
        case 2:
            printf("%d\n", size());
            break;
        case 3:
            printf("%d", is_empty());
            break;
        case 4:
            print_front();
            break;
        case 5:
            print_back();
            break;
        default:
            printf("error input");
            break;
        }
    }
    return 0;
}