#include <stdio.h>
int main() {
	int i, t, a, b;
	scanf("%d", &t);
	i = 0;
	while (i++ < t) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n",i, a + b);
	}

	return 0;
}
