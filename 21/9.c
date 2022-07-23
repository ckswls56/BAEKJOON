#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
long long *arr;

long long sol(long long left, long long right)
{
    if (left == right)
        return arr[left];

    long long mid = (left + right) / 2;
    long long ret = max(sol(left, mid), sol(mid + 1, right));
    //중앙을 기준으로 분할!

    long long low = mid;
    long long high = mid + 1;
    long long height = min(arr[low], arr[high]);
    //가운데 2개의 직사각형인 경우를 고려한다.
    ret = max(ret, height * 2);

    while (left < low || high < right)
    {
        if (high < right && (low == left || arr[low - 1] < arr[high + 1]))
        {
            ++high;
            height = min(height, arr[high]);
        }
        else
        {
            --low;
            height = min(height, arr[low]);
        }

        ret = max(ret, height * (high - low + 1));
        // 왼쪽,오른쪽,중앙에서 부터만든 직사각형을 비교 가장큰값을 반환
    }

    return ret;
}

int main()
{
    int n;

    scanf("%d", &n);
    while (n != 0)
    {

        arr = (long long *)malloc(sizeof(long long) * n);
        for (long long i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        printf("%lld\n", sol(0, n - 1));
        scanf("%d", &n);
        free(arr);
    }

    return 0;
}