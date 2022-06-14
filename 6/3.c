#include <stdio.h>
#include <stdlib.h>
int main() {
	char *c;
	int arr[26];
	c = (char*)malloc(sizeof(char)*100);
	scanf("%s", c);
	int i = 0;
	while (i < 26)
		arr[i++] = -1;
	i = 0;
	while (i < 100) {
		if( arr[c[i]-'a'] == -1)
			arr[c[i]-'a'] = i;
		i++;
	}
	i = 0;
	while (i < 26) {
		printf("%d ", arr[i]);
		i++;
	}
}
