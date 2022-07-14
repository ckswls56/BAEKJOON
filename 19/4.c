#include <stdio.h>
#include <stdlib.h>

int stack[1000];
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

int main()
{
    char s[102];
    int flag;
    int s_cnt[2];
    int b_cnt[2];

    gets(s);
    while (*s != '.')
    {
        flag = 1;
        s_cnt[0] = 0;
        s_cnt[1] = 0;
        b_cnt[0] = 0;
        b_cnt[1] = 0;
        char *tmp = s;
        while (*tmp != '.')
        {

            if (*tmp == '(')
            {
                push(1);
                s_cnt[0]++;
            }
            else if (*tmp == '[')
            {
                push(2);
                b_cnt[0]++;
            }
            else if (*tmp == ')')
            {
                if (pop() != 1)
                {
                    flag = 0;
                    break;
                }
                else
                    s_cnt[1]++;
            }
            else if (*tmp == ']')
            {
                if (pop() != 2)
                {
                    flag = 0;
                    break;
                }
                else
                    b_cnt[1]++;
            }
            tmp++;
        }

        if (flag && s_cnt[0] == s_cnt[1] && b_cnt[0] == b_cnt[1])
            printf("yes\n");
        else
            printf("no\n");
        top = -1;
        gets(s);
    }
}