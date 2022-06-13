#include <stdio.h>
#include <stdlib.h>
int main() {
	int n,tmp,count;
	int s[2];
	scanf("%d", &n);
	s[0] = n % 10;
	s[1] = (n / 10 + n%10) % 10;
	tmp = -1; count = 0;
	while (n != tmp) {
		tmp = (s[0] * 10) + s[1];
		s[0] = tmp % 10;
		s[1] = (tmp / 10 + tmp % 10) % 10;
		count++;
	}
	printf("%d", count);
		
	return 0;
}
