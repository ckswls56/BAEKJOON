#include <stdio.h>
int main() {
	int i,t,a,b;
	scanf("%d", &t);
	i = 0;
	while (i++ < t){
		scanf("%d %d",&a,&b);
		printf("%d\n", a + b);
	}

	return 0;
}
