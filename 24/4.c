#include <stdio.h>
#include <string.h>
int arr[2001];
int dp[2001][2001];

void palindrome(int n)
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;

        if (arr[i - 1] == arr[i] && i != 1) // ex 22 44 55
            dp[i - 1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; i + j <= n; j++)
        {
            if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1] == 1)
                dp[j][i + j] = 1;
        }
    }
}

int main()
{
    int n, m, s, e;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &m);

    palindrome(n);
    while (m--)
    {
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
    // 가운데 수를 기준으로 양쪽이 회문이면 된다.
}