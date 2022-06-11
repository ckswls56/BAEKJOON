#include <stdio.h>

	int main() {
		int a;
		int b;
		int c;
		int tmp[3];
		int i=0;

		scanf("%d", &a);
		scanf("%d", &b);
		c = b;
		while (i < 3) {
			tmp[i++] = b % 10;
			b /= 10;
		}
		printf("%d\n", a*tmp[0]);
		printf("%d\n", a*tmp[1]);
		printf("%d\n", a*tmp[2]);
		printf("%d\n", a*c);
		return 0;
}
