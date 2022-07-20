#include <stdio.h>
#define m 1000000007

long long mul(int a, int b)
{
    if (b == 0)
        return 1;
    long long temp = mul(a, b / 2);
    temp = ((temp * temp) % m);
    if (b % 2 == 0)
        return temp;
    else
        return temp * a % m;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    long long a, b;
    a = 1;
    b = 1;
    for (int i = 1; i <= n; i++)
    {
        a *= i;
        a %= m;
    }
    for (int i = 1; i <= k; i++)
    {
        b *= i;
        b %= m;
    }
    for (int i = 1; i <= n - k; i++)
    {
        b *= i;
        b %= m;
    }

    printf("%lld", (a * (mul(b, m - 2))) % m);
    return 0;
}