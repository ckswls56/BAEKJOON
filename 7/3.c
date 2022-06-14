#include <stdio.h>

void print(int count, int x,int flag, int i, int j) {

	while (count < x) {

		if (flag == 1) {
			i--; j++;
		}
		else {
			i++; j--;
		}
		if (i == 1 || j == 1) {
			flag *= -1; count++;
			if (i == 1 && count<x)
				j++;
			if (j == 1 && count<x)
				i++;
		}
			
		count++;
	}
	printf("%d/%d\n", i, j);
}

int main(void) {
	int x; 
	scanf("%d", &x);
	if (x == 1)
		printf("1/1");
	else if (x == 2)
		printf("1/2");
	else if (x == 3)
		printf("2/1");
	else
		print(4, x, 1, 3, 1);
}
