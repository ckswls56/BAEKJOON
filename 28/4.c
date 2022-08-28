#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
char stack[1001];
int top = -1;
int dp[1001][1001];

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
        return -1;
    else
    {
        return stack[top--];
    }
}

void print_path(char *a, char *b, int a_len, int b_len)
{

    int x = a_len;
    int y = b_len;

    while (!(x == 0 || y == 0))
    {
        if (a[x - 1] == b[y - 1])
        {
            push(a[x - 1]);
            x--;
            y--;
        }
        else if (dp[x][y] == dp[x - 1][y])
        {
            x--;
        }
        else if (dp[x][y] == dp[x][y - 1])
        {
            y--;
        }
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
}

int main()
{

    char a[1001];
    char b[1001];
    scanf("%s %s", a, b);

    int a_len, b_len, lcs_len;
    a_len = strlen(a);
    b_len = strlen(b);

    for (int i = 1; i <= a_len; i++)
    {
        for (int j = 1; j <= b_len; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    lcs_len = dp[a_len][b_len];

    printf("%d\n", lcs_len);
    print_path(a, b, a_len, b_len);
    return 0;
}