#include <stdio.h>
#define maxsize 10000

int main(){
	int n,i,j,x;
	scanf("%d", &n);
	int count[maxsize] = { 0 };
	i = 0;
	while (i++ < n) {
		scanf("%d", &x);
		count[x-1]++;
	}
	i = 0;
	while (i < maxsize) {
		j = count[i];
		while (j-- > 0) {
			printf("%d\n", i+1);
			}
		i++;
	}
	return 0;
}
