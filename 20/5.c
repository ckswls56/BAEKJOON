#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 20000

const char command[8][11] = {"push_front", "push_back", "pop_front", "pop_back", "size", "empty", "front", "back"};
int q[MAXSIZE];
int front = MAXSIZE / 2;
int rear = MAXSIZE / 2;

int get_command(char *str)
{
    for (int i = 0; i < 8; i++)
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

int size()
{
    return rear - front;
}

void print_front()
{
    if (!is_empty())
        printf("%d\n", q[front]);
    else
        printf("-1\n");
}

void print_back()
{
    if (!is_empty())
        printf("%d\n", q[rear - 1]);
    else
        printf("-1\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    char str[11];
    while (n--)
    {
        scanf("%s", str);
        switch (get_command(str))
        {
        case 0:
        {
            int x;
            scanf("%d", &x);
            push_front(x);
            break;
        }
        case 1:
        {
            int x;
            scanf("%d", &x);
            push_back(x);
            break;
        }
        case 2:
            printf("%d\n", pop_front());
            break;
        case 3:
            printf("%d\n", pop_back());
            break;
        case 4:
            printf("%d\n", size());
            break;
        case 5:
            printf("%d\n", is_empty());
            break;
        case 6:
            print_front();
            break;
        case 7:
            print_back();
            break;
        default:
            printf("error input");
            break;
        }
    }
    return 0;
}