#include<stdio.h>

int main() {

	int T;
	scanf("%d", &T);

	for (int j = 0; T > j; j++) {
		int x1, x2, y1, y2, r1, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		int radd = (r1 + r2)*(r1 + r2);
		int rsub = (r1 - r2)*(r1 - r2);
		if (d == 0 && rsub == 0) printf("-1\n"); // 같은 원일경우
		else if (d == radd || d == rsub) printf("1\n"); // 한점
		else if (rsub< d && d < radd) printf("2\n"); // 두점.
		else printf("0\n"); //만나지 않는 경우
	}
}
