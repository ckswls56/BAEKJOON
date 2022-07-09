#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char s[200001];
	scanf("%s", s);
	
	int len;
	len = strlen(s);

	int **alpha;
	alpha = (int**)malloc(sizeof(int*)*26);

	for (int i = 0; i < 26; i++) {
		alpha[i] = (int*)malloc(sizeof(int)*(len+1));
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 1; j++) {
			alpha[i][j] = 0;
		}
	}

	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		for (int j = 1; j <= len; j++) {
			alpha[i][j] = alpha[i][j - 1];
			if (c == s[j - 1])
				alpha[i][j]++;
		}
	}

	int q;
	scanf("%d\n", &q);
	char c;
	int l, r;

	while (q-- > 0) {
		scanf("%c %d %d\n", &c, &l,&r);
		printf("%d\n", alpha[c - 'a'][r+1] - alpha[c - 'a'][l]);
	}

}
