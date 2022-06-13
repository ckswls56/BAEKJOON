#include <stdio.h>
int main() {
	int i = 0;
	int j, count;
	int array[10];
	int res[42] = { 0 };

	while (i < 10) {
		scanf("%d", &array[i]);
		array[i++] %= 42;
	}
	count = 0; i = 0;
	while (i <10 ){
		res[array[i]] = 1;
		i++;
	}
	i = 0;
	while (i < 42) {
		if (res[i++] == 1)
			count++;
	}
		
	printf("%d", count);
}
