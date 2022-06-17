#include <stdio.h>

int six(int n) {
	int count = 0;

	while (n > 0) {
		if (n % 10 == 6)
			count++;
		else
			count = 0;
		n /= 10;
		if (count == 3)
			return 1;
	}
	return 0;
}
int main(){
	int n,i,count;
	scanf("%d", &n);
	if (n < 1 || n>10000)
		return 0;
	count = 0;
	i = 665;
	while (count!=n) {
		if (six(++i))
			count++;
	}
	printf("%d", i);
	
	return 0;
}
