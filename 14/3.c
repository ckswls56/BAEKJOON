#include <stdio.h>

int	gcd(int a, int b) {
	int i = a;
	while (i <= 10000 * 10000) {
		if(i%a == 0 && i%b == 0)
			return i;
		i++;
	}
	return 0;
}

int lcm(int a, int b) {
	int i = a;
	while (i > 0) {
		if (a%i == 0 && b%i == 0)
			return i;
		i--;
	}
	return 0;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(){
	
	int a, b;
	scanf("%d %d", &a, &b); 
	if (b > a) // a is aways bigger than b
		swap(&a, &b);
	printf("%d\n", lcm(a, b));
	printf("%d\n", gcd(a, b));
	return 0;
}
