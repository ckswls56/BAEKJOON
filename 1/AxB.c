#include <stdio.h>

int main()
{
	int a;
	int b;
	int res;

	scanf("%d", &a);
	scanf("%d", &b);

	if (a < 0 || b > 10)
		return 0;
	res = a * b;

	printf("%d", res);

	return 0;
}
