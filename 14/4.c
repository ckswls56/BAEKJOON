#include <stdio.h>

int icm(int a, int b) {
	int i = a;
	while (i > 0) {
		if (a%i == 0 && b%i == 0)
			return i;
		i--;
	}
	return 0;
}

int	gcd(int a, int b) {
	int ICM = icm(a, b);
	if (ICM == 0)
		return a * b;
	else
		return a * b / ICM;

}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int t;
	scanf("%d", &t);
	int a, b;
	while (t-- > 0) {
		scanf("%d %d", &a, &b);
		if (b > a)
			swap(&a, &b);
		printf("%d\n", gcd(a, b));
	}
	
	return 0;
}
