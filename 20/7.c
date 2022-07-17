#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000000

char q[MAXSIZE];
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

int size()
{
    return rear - front;
}

int main()
{
    int t, n;
    char p[100001];
    char x[500005];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", p);
        scanf("%d", &n);
        scanf("%s", x);
        char *ptr = strtok(x, "[],"); // "[]," 문자를 기준으로 문자열을 자름, 포인터 반환
        while (ptr != NULL)           // 자른 문자열이 나오지 않을 때까지 반복
        {
            push_back(atoi(ptr));
            ptr = strtok(NULL, "[],"); // 다음 문자열을 잘라서 포인터를 반환
        }
        int flag = 1;
        int rev = 1;
        ptr = p;
        while (*ptr)
        {
            if (*ptr == 'R')
            {
                if (*(ptr + 1) == 'R')
                    ptr++;
                else
                    rev *= -1;
            }
            else if (*ptr == 'D')
            {
                if (n == 0)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    if (rev == 1)
                        pop_front();
                    else
                        pop_back();
                    n--;
                }
            }
            ptr++;
        }

        if (flag)
        {
            printf("[");
            if (rev == 1)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    printf("%d,", pop_front());
                }
            }
            else
            {
                for (int i = 0; i < n - 1; i++)
                {
                    printf("%d,", pop_back());
                }
            }
            if (is_empty())
                printf("]\n");
            else
                printf("%d]\n", pop_front());
        }
        else
        {
            printf("error\n");
        }
    }

    return 0;
}