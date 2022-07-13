#include <stdio.h>
#include <string.h>
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
    int t;
    scanf("%d", &t);
    char s[51];
    int len, cnt;
    while (t--)
    {
        scanf("%s", s);
        len = strlen(s);

        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
                push(0);
            else if (s[i] == ')')
                push(1);
        }
        cnt = 0;
        for (int i = 0; i < len; i++)
        {
            if (pop())
            {
                cnt++;
            }
            else
                cnt--;
            if (cnt < 0)
            {
                break;
            }
        }
        if (cnt == 0)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}