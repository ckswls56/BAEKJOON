#include <stdio.h>

int star(int x, int y) {
	if ((x % 3 == 1) && (y % 3) == 1)
		return 0;
	else if (x == 0 || y == 0)
		return 1;
	return(star(x / 3, y / 3));
}

int main(){
	int n,x,y;
	scanf("%d", &n);
	y = 0;
	while (y < n) {
		x = 0;
		while (x < n) {
			if (star(x, y))
				printf("*");
			else
				printf(" ");
			x++;
		}
		y++;
		printf("\n");
	}
	return 0;
}
