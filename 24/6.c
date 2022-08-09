#include <stdio.h>

int dp[10001];
int k;

void sol(int x)
{
    for (int i = x; i <= k; i++)
    {
        dp[i] += dp[i - x];
    }
}

int main()
{
    dp[0] = 1;
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int coin;
        scanf("%d", &coin);
        sol(coin);
    }

    printf("%d", dp[k]);
}