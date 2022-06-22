#include <stdio.h>
#include <math.h>

typedef struct ground
{
	int dir;
	int length;
}g;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int type(int *temp) {
	int count[4];
	for (int i = 0; i < 4; i++)
		count[i] = 0;
	for (int i = 0; i < 6; i++) {
		if (temp[i] == 1) 
			count[0]++;
		else if (temp[i] == 2)
			count[1]++;
		else if (temp[i] == 3)
			count[2]++;
		else
			count[3]++;
	}
	if (count[0] == 2 && count[2] == 2 )
		return 1;
	else if (count[0] == 2 && count[3] == 2)
		return 2;
	else if (count[1] == 2 && count[3] == 2)
		return 3;
	else
		return 4;
}

int main(){
	int k,t,x1,x2,y1,y2,h;
	scanf("%d", &k);
	g map[7];
	int temp[6];
	for (int i = 0; i < 6; i++) {
		scanf("%d %d", &map[i].dir, &map[i].length);
		temp[i] = map[i].dir;
	}
	t = type(temp);
	x1 = 0; x2 = 0; y1 = 0; y2 = 0;
	if (t == 1) {
		for (int i = 0; i < 6; i++) {
			if (map[i].dir == 1) {
				if (x1 == 0)
					x1 = map[i].length;
				else
					x2 = map[i].length;
			}
			else if (map[i].dir == 3) {
				if (y1 == 0)
					y1 = map[i].length;
				else
					y2 = map[i].length;
			}
			else if (map[i].dir == 4)
				h = map[i].length;
		}
		if ((map[0].dir == 3 && map[1].dir == 1 && map[2].dir == 4) || (map[0].dir == 1 && map[1].dir == 4 && map[2].dir == 2))
			swap(&x1, &x2);
		if ((map[0].dir == 1 && map[1].dir == 3 && map[2].dir == 1) || (map[0].dir == 3 && map[1].dir == 1 && map[2].dir == 4))
			swap(&y1, &y2);
		printf("%d", ((x2*h)+(x1*y1))*k);
	}
	else if (t == 2) {
		for (int i = 0; i < 6; i++) {
			if (map[i].dir == 1) {
				if (x1 == 0)
					x1 = map[i].length;
				else
					x2 = map[i].length;
			}
			else if (map[i].dir == 4) {
				if (y1 == 0)
					y1 = map[i].length;
				else
					y2 = map[i].length;
			}
			else if (map[i].dir == 3)
				h = map[i].length;
			
		}
		if ((map[0].dir == 4 && map[1].dir == 1 && map[2].dir == 4) || (map[0].dir == 1 && map[1].dir == 4 && map[2].dir == 2))
			swap(&x1, &x2);
		if ((map[0].dir == 1 && map[1].dir == 4 && map[2].dir == 2) || (map[0].dir == 4 && map[1].dir == 2 && map[2].dir == 3))
			swap(&y1, &y2);
		printf("%d", ((x1*h) + (x2*y2)) *k);
	}
	else if (t == 3) {

		for (int i = 0; i < 6; i++) {
			if (map[i].dir == 2) {
				if (x1 == 0)
					x1 = map[i].length;
				else
					x2 = map[i].length;
			}
			else if (map[i].dir == 4) {
				if (y1 == 0)
					y1 = map[i].length;
				else
					y2 = map[i].length;
			}
			else if (map[i].dir == 1)
				h = map[i].length;
		}
		if ((map[0].dir == 4 && map[1].dir == 2 && map[2].dir == 3) || (map[0].dir == 2 && map[1].dir == 3 && map[2].dir == 1))
			swap(&x1, &x2);
		if ((map[0].dir == 2 && map[1].dir == 4 && map[2].dir == 2) || (map[0].dir == 4 && map[1].dir == 2 && map[2].dir == 3))
			swap(&y1, &y2);

		printf("%d", ((y1*h) + (x2*y2))*k);

	}
	else {
		for (int i = 0; i < 6; i++) {
			if (map[i].dir == 2) {
				if (x1 == 0)
					x1 = map[i].length;
				else
					x2 = map[i].length;
			}
			else if (map[i].dir == 3) {
				if (y1 == 0)
					y1 = map[i].length;
				else
					y2 = map[i].length;
			}
			else if (map[i].dir == 1)
				h = map[i].length;
		}
		if ((map[0].dir == 3 && map[1].dir == 2 && map[2].dir == 3) || (map[0].dir == 2 && map[1].dir == 3 && map[2].dir == 1))
			swap(&x1, &x2);
		if ((map[0].dir == 2 && map[1].dir == 3 && map[2].dir == 1) || (map[0].dir == 3 && map[1].dir == 1 && map[2].dir == 4))
			swap(&y1, &y2);
		printf("%d", ((y2*h) + (x1*y1))*k);
	}

	return 0;
}
