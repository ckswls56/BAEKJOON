#include <stdio.h>

int a, c;

long long mul(int b)
{
    if (b == 0)
        return 1;
    long long temp = mul(b / 2);
    temp = ((temp * temp) % c);
    if (b % 2 == 0)
        return temp;
    else
        return temp * a % c;
}

int main()
{
    int b;
    scanf("%d %d %d", &a, &b, &c);

    printf("%lld", mul(b));
}
// 10^11 = 10 * (10^5)^2