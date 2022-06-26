#include <stdio.h>
#include <stdlib.h>

int idx = 0;
int promissing(char *arr,int n) {
	if(arr[idx-1]-'0' < n)
		return 1;
	return 0;
}

void ntom(int n, int m, char *arr) {

	if (m == 0) {
		for(int i=0;i<idx;i++)
			printf("%c ",arr[i]);
		printf("\n");
		return;
	}
    
	int flag = 1;
	for (int i = 1; i <= n; i++) {

		if (promissing(arr, i)) {
			arr[idx++] = '0' + i;
			ntom(n, m - 1, arr);
			idx--;
		}
		
	}

}

int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	char *num;
	num = (char*)malloc(sizeof(char) * 9);
	ntom(n, m,num);
	
	return 0;
}

