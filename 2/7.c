#include <stdio.h>
int main() {

	int d1,d2,d3;
	int price=0;
	scanf("%d %d %d", &d1, &d2, &d3);
	if (d1 == d2 && d1 == d3)
		price = 10000 + d1 * 1000;
	else if (d1 == d2 || d1 == d3 || d2 == d3)
		if (d1 == d2)
			price = 1000 + d1 * 100;
		else
			price = 1000 + d3 * 100;
	else
		if (d1 > d2 && d1 > d3)
			price = d1 * 100;
		else if (d2 > d1 && d2 > d3)
			price = d2 * 100;
		else
			price = d3 * 100;

	printf("%d", price);
	return 0;
}
