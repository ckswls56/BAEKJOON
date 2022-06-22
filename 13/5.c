#include <stdio.h>
#define M_PI       3.14159265358979323846
#include <math.h>
int main() {
	double r;
	scanf("%lf", &r);

	printf("%lf\n", M_PI*r*r);
	printf("%lf", r*r*2);
}
