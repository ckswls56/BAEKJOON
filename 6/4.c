#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void t(int repeat,char *c) {
	int i = 0;
	int j;
	while (i < strlen(c)) {
		j = 0;
		while (j < repeat) {
			printf("%c", c[i]);
			j++;
		}
		i++;
	}
	printf("\n");
}

int main() {
	char *c;
	int repeat,i,T;
	c = (char*)malloc(sizeof(char)*20);
	i = 0;
	scanf("%d", &T);
	while (i < T) {
		scanf("%d %s", &repeat, c);
		t(repeat,c);
		i++;
	}
}
