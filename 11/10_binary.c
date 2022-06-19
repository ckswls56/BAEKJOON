#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int *arr;
int count; //total vaild coordinate 

int main() {
	int n, j;
	scanf("%d", &n);

	int *res;
	arr = (int*)malloc(sizeof(int)*n); //sorted array
	res = (int*)malloc(sizeof(int)*n);
	//memset(arr, -0x2f, sizeof(arr));
	count = 1;
	scanf("%d", &arr[0]); res[0] = arr[0];
	int i = 0;
	while (++i < n) {
		scanf("%d", &res[i]);
		
		int low = 0, high = i, mid = (low + high) / 2;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] == res[i])
				break;
			else if (arr[mid] > res[i])
				high = mid - 1;
			else
				low = mid + 1;
		}
		if (low > high) {
			if (arr[mid] < res[i])
				arr[i] = res[i];
			else {
				int temp = i;
				while (temp > mid) {
					arr[temp] = arr[temp - 1];
					temp--;
				}
				arr[mid] = res[i];
			}
			count++;
		}
	}

	i = 0;
	while (i < n) {
		int low = 0, high = count - 1, mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (arr[mid] == res[i]) {
				printf("%d ", mid);
				break;
			}
			else if (arr[mid] > res[i])
				high = mid - 1;
			else
				low = mid + 1;
		}
		i++;
	}
	return 0;
}
