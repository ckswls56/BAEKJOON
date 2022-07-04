#include <stdio.h>
#include <stdlib.h>

int sum[2][1000] = { 0 };
int *arr;

int bito_left(int i,int j) { 
	
	if (sum[0][j] != 0 && arr[i] > arr[j])
		return sum[0][j] + 1;
	else {
		if (arr[i] > arr[j])
			return 2;
		else if (arr[i] == arr[j])
			return 1;
		else
			return 0;
	}
	
}

int bito_right(int i, int j) {

	if (sum[1][j] != 0 && arr[i] > arr[j])
		return sum[1][j] + 1;
	else {
		if (arr[i] > arr[j])
			return 2;
		else if (arr[i] == arr[j])
			return 1;
		else
			return 0;
	}

}



int main() {

	int n,temp;
	scanf("%d", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	arr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);


	for (int i = 0; i < n; i++) {
	
		for (int j = i - 1; j >= 0; j--) {
			temp = bito_left(i,j);
			if (temp > sum[0][i])
				sum[0][i] = temp;
		}

	}

	for (int i = n-1; i >= 0; i--) {

		for (int j = i + 1; j < n; j++) {
			temp = bito_right(i, j);
			if (temp > sum[1][i])
				sum[1][i] = temp;
		}

	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (sum[0][i] + sum[1][i] > max) {
			max = sum[0][i] + sum[1][i] - 1;
			if (sum[0][i] == 0 || sum[1][i] == 0)
				max++;
			//끝에 있는 수열 예외처리 ex) 1,2,3 or 3, 2 ,1
		}
			
		
	}
	printf("%d", max);
}
