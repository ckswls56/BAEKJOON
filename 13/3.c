#include <stdio.h>
#include <math.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	while (a != 0 && b != 0 && c != 0) {
		a *= a; b *= b; c *= c;
		if (a + b <= c) {
			if (a + b == c)
				printf("right");
			else
				printf("wrong");
		}
		else if (a + c <= b) {
			if (a + c == b)
				printf("right");
			else
				printf("wrong");
		}
		else if (b + c <= a) {
			if (b + c == a)
				printf("right");
			else
				printf("wrong");
		}
		else // equilateral triangle
			printf("wrong");
		printf("\n");
		
		scanf("%d %d %d", &a, &b, &c);
	}
	return 0;
}
