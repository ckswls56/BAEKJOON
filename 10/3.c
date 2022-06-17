#include <stdio.h>
#include <stdlib.h>
typedef struct person {
	int x;
	int y;
	int dungci;
}person;

int main(){
	int n,i,j;
	scanf("%d", &n);
	person * arr;
	arr = (person*)malloc(sizeof(person)*n);
	i = 0;
	while(i<n){
		scanf("%d %d", &arr[i].x, &arr[i].y);
		arr[i].dungci = n+1;
		i++;
	}
	i = 0;
	while (i < n) {
		j = 0;
		while (j < n) {
			if ((arr[i].x >= arr[j].x) || (arr[i].y >= arr[j].y))
				arr[i].dungci--;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
		printf("%d ", arr[i++].dungci);

	free(arr);
	return 0;
}
