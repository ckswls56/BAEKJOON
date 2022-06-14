#include <stdio.h>
#include <math.h>
int main(void) {
	double a, b, v;
	a = 0; b = 0; v = 0;
	scanf("%d %d %d", &a, &b, &v);
	
	printf("%.0lf", ceil((v-b)/(a-b)));
}
