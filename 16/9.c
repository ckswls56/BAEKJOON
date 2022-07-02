#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	scanf("%d", &n);

	if (n <= 1)
		printf("0");
	else if (n <= 3)
		printf("1");
	else {
		int *arr;
		arr = (int*)malloc(sizeof(int)*n);

		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 1;
		int a, b, c;
		for (int i = 3; i < n; i++) {
			a = arr[i / 3] + 1;	b = arr[i / 2] + 1;	c = arr[i - 1] + 1;
			
			if ((i + 1) % 6 == 0) {
				if (a < b)
					arr[i] = a;
				else
					arr[i] = b;
			}
			else if ((i + 1) % 3 == 0 && a < c) {
				arr[i] = a;
			}
			else if ((i + 1) % 2 == 0 && b < c) {
				arr[i] = b;
			}
			else
				arr[i] = c;
		}
			printf("%d" ,arr[n-1]);
	}

}
