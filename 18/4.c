#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len = 0;

void insert_arr(int *arr, char *s)
{
    int sum = 0;
    while (*s)
    {
        sum += atoi(s);
        while (*s >= '0' && *s <= '9')
        {
            s++;
        }
        if (*s == '+')
            s++;
    }
    arr[len++] = sum;
}

int main()
{
    char s[51];
    int arr[50] = {0};
    scanf("%s", s);

    char *ptr = strtok(s, "-"); // "-" 문자를 기준으로 문자열을 자름, 포인터 반환
    while (ptr != NULL)         // 자른 문자열이 나오지 않을 때까지 반복
    {
        insert_arr(arr, ptr);    // 자른 문자열 int a+b 형식이므로 저장
        ptr = strtok(NULL, "-"); // 다음 문자열을 잘라서 포인터를 반환
    }

    int sum = arr[0];
    for (int i = 1; i < len; i++)
    {
        sum -= arr[i];
    }
    printf("%d", sum);
}