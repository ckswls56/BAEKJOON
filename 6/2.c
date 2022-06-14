#include <stdio.h>
#include <stdlib.h>
int main() {
	int len;
	scanf("%d", &len);
	char *c;
	c = (char*)malloc(sizeof(char)*len + 1);
	scanf("%s", c);
	int i = 0;
	int sum = 0;
	while (i < len)
		sum += c[i++] - '0';
	printf("%d", sum);
}
