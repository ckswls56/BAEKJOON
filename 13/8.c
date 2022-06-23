#include <stdio.h>

int in_link(int w, int h, int x, int y, int px, int py,int r) {

	int left, right;
	left = (px - x)*(px - x) + (py - (y + r))*(py - (y + r));
	right = (px - (x+w))*(px - (x+w)) + (py - (y + r))*(py - (y + r));
	if (px >= x && px <= x+w && py >= y && py <= y+h)
		return 1;
	else if (left <= r*r || right <= r*r)
		return 1;
	
	return 0;
}

int main(){
	
	int w, h, x, y, p,count;
	scanf("%d %d %d %d %d", &w, &h, &x, &y, &p);
	int r = h / 2;
	count = 0;
	while (p-- > 0) {
		int px, py;
		scanf("%d %d", &px, &py);
		if (in_link(w, h, x, y, px, py,r))
			count++;

	}
	printf("%d\n", count);
	return 0;
}
