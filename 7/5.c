#include <stdio.h>

int main(void) {
	int t; scanf("%d", &t);
	int h, w, n,i,x;
	while (t > 0) {
		scanf("%d %d %d", &h, &w, &n);
		i = 0; x = 1;
		while (n > 0) {
			if (n <= h)
				i += n;
			else {
				x++;
			}
			n -= h;
		}
		printf("%d\n", i*100+x);
		t--;
	}
}
