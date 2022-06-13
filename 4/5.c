#include <stdio.h>
#include<stdlib.h>
int main() {
	int m,i,max;
	int  *array;
	double res;
	max = 0; i = 0;
	scanf("%d", &m);
	array = (int*)malloc(sizeof(int)*m);
	if (!array)
		return 0;
	while (i < m) {
		scanf("%d", &array[i]);
		if (max < array[i])
			max = array[i];
		i++;
	}
	i = 0; res = 0;
	while (i < m) {
		res += (array[i] /(double) max) * 100;
		i++;
	}
		
	printf("%lf", res/m);
	
}
