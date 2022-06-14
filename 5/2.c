#include <stdio.h>
int	d(int n)
{
	int res = n;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
int main() {
	int i = 1;
	int arr[100000] = { 0 };

	while (i <= 10000) {
		arr[d(i)] = 1;
		i++;
	}
	i = 0;
	while (i < 10000) {
		if (arr[i] == 0)
			printf("%d\n", i);
		i++;
	}
}
