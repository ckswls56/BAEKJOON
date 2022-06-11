#include <stdio.h>

int main()
{
	int a;
	int b;
	int res;

	scanf("%d", &a);
	scanf("%d", &b);

	if (a < 2 || b > 10001)
		return 0;
	res = a + b;

	printf("%d\n", res);

	res = a - b;

        printf("%d\n", res);
        res = a * b;

        printf("%d\n", res);
        res = a / b;

        printf("%d\n", res);

        res = a % b;

        printf("%d\n", res);


	return 0;
}
