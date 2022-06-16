#include <stdio.h>
#include <math.h>
void hanoi(int n,int from,int to,int other) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(n - 1, from, other, to);
	printf("%d %d\n", from, to);
	hanoi(n - 1, other, to, from);
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)pow(2, n) - 1);
	hanoi(n,1,3,2);
	return 0;
}
