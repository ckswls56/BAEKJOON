#include <stdio.h>
#define INF 1000000007
#define min(a, b) (((a) < (b)) ? (a) : (b))
int sum[501];
int dp[501][501];

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int k;
        scanf("%d", &k);
        sum[0] = 0;
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &sum[i]);
            sum[i] += sum[i - 1];
        }

        for (int d = 1; d < k; ++d)
        {
            for (int i = 1; i + d <= k; ++i)
            {
                int j = i + d;
                dp[i][j] = INF;

                for (int mid = i; mid < j; ++mid)
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
            }
        }

        printf("%d\n", dp[1][k]);
    }
}