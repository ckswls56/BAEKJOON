#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Max(int *arr) {
	int i = 0;
	int max = 0;
	while (i < 26) {
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return max;
}
int overlap(int *arr, int max) {
	int i = 0;
	int count = 0;
	while (i < 26) {
		if (arr[i] == max)
			count++;
		i++;
	}
	if (count >= 2)
		return 1;
	return 0;
}
int index(int *arr, int max) {
	int i = 0;
	int count = 0;
	while (i < 26) {
		if (arr[i] == max)
			return i;
		i++;
	}

	return 0;
}
int main() {
	char *c;
	int i, max,len;
	int arr[26] = { 0 };
	char alpha[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	c = (char*)malloc(sizeof(char) * 1000000);
	scanf("%s", c);
	i = 0; len = strlen(c);
	while (i < len) {
		if (c[i] >= 'a'&&c[i] <= 'z')
			arr[c[i] - 'a'] += 1;
		else
			arr[c[i] - 'A'] += 1;
		i++;
	}
	max = Max(arr);
	if (overlap(arr, max))
		printf("?");
	else
		printf("%c", alpha[index(arr, max)]);
	return 0;
}
