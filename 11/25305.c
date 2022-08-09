#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int bubblesort(int *arr, int n)
{
    int i, j;
    i = 0;
    while (i < n)
    {
        j = i;
        while (j < n)
        {
            if (arr[i] < arr[j])
                swap(&arr[i], &arr[j]);
            j++;
        }
        i++;
    }
    return 0;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr;
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);

    printf("%d", arr[k - 1]);
}