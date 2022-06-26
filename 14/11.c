#include <stdio.h>

int zero_cnt(unsigned long long int temp, int dig) {
	int cnt = 0;
	while(temp % 10 == 0) {
		cnt++;
		temp /= 10;
	}
	return cnt;
}

int main() {

	int n, dig;
	scanf("%d", &n);

	dig = 0; 
	unsigned long long int temp = 1;
	for (int i = 2; i <= n; i++) {
		temp *= i;
		int cnt = zero_cnt(temp, dig);
		if (cnt>= 1) {
			dig+= cnt;
			temp = 1;
		}
	}
	printf("%d", dig);
}
