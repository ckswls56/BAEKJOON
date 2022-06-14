#include <stdio.h>
#include <string.h>

void reverse(char *s) {
	char temp = s[0];
	s[0] = s[2];
	s[2] = temp;
}

int main(void) {
	char s1[4];
	char s2[4];
	int a1, a2;
	scanf("%s %s", s1, s2);
	reverse(&s1); reverse(&s2);
	a1 = atoi(s1); a2 = atoi(s2);
	if (a1 > a2)
		printf("%d", a1);
	else
		printf("%d", a2);

	return 0;
}
