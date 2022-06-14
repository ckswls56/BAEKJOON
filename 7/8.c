#include <stdio.h>

int main() {
	char *res;
	char a[10002] = { 0 };
	char b[10002] = { 0 };
	int len1, len2, len3, temp1, temp2, temp3;
	scanf("%s %s", a, b);
	len1 = strlen(a); len2 = strlen(b);
	if (len1 > len2)
		len3 = len1;
	else
		len3 = len2;
	res = (char*)malloc(sizeof(char)*len3 + 1);
	memset(res, '0', len3 + 1); res[len3 + 1] = 0;
	while (len1 > 0 && len2 > 0) {
		temp1 = a[--len1] - '0';
		temp2 = b[--len2] - '0';
		temp3 = temp1 + temp2 ;
		res[len3] += temp3;
		if (res[len3] > '9') {
			res[len3] -= 10;
			res[len3 - 1]++;
		}
		len3--;
	}
	while (len3 > 0) {
		if (len1 == 0)
			temp3 = b[--len2] - '0';
		else
			temp3 = a[--len1] - '0';
		res[len3] += temp3;
		if (res[len3] > '9') {
			res[len3] -= 10;
			res[len3 - 1]++;
		}
		len3--;
	}
	while (*res == '0')//skip '0'
		res++;
	printf("%s", res);

	return 0;
}
