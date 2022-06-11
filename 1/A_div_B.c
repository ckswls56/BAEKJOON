#include <stdio.h>

int main()
{
	int a;
	int b;
	double res;

	scanf("%d", &a);
	scanf("%d", &b);

	if (a < 0 || b > 10)
		return 0;

	res = (double)a / (double)b;

	printf("%.10lf", res);

	return 0;
}
