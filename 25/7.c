#include <stdio.h>
#include <stdlib.h>

int visited[25][25];
char **arr;
int n;
int cnt = 0;

int sorted[25 * 25]; // 필요할떄마다 생성시 비효율적이다.

void merge(int *list, int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;
    while (i <= mid && j <= right)
    {
        if (list[i] < list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid)
        for (int n = j; n <= right; n++)
            sorted[k++] = list[n];
    else
        for (int n = i; n <= mid; n++)
            sorted[k++] = list[n];

    for (int n = left; n <= right; n++)
        list[n] = sorted[n];
}

void merge_sort(int *list, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);

        merge(list, left, mid, right);
    }
}

int dfs(int y, int x)
{
    if (visited[y][x] == 1 || x >= n || x < 0 || y >= n || y < 0)
    {
        return 0;
    }

    visited[y][x] = 1;
    if (arr[y][x] == 0)
        return 0;
    else
    {
        int left = dfs(y, x - 1);
        int right = dfs(y, x + 1);
        int down = dfs(y + 1, x);
        int up = dfs(y - 1, x);
        return left + right + down + up + 1;
    }
}

int main()
{
    scanf("%d\n", &n);

    arr = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
        arr[i] = (char *)malloc(sizeof(char) * n);

    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &arr[i][j]);
            arr[i][j] -= '0';
        }
        scanf("%c", &temp); //개행 입력 방지
    }

    int res[25 * 25];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp = dfs(i, j);
            if (temp > 0)
            {
                res[cnt++] = temp;
            }
        }
    }
    merge_sort(res, 0, cnt - 1);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d\n", res[i]);
    }
}