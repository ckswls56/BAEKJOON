#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cashe[21][21][21] = { 0 };

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	if (a < b && b < c)
		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else
		return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int w2(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else {
		if (a > 20 || b > 20 || c > 20)
			return (int)pow(2, 20);
		else {
			if (a < b && b < c || (a == b && b == c))
				return (int)pow(2, a);

			for (int i = 0; i <= a; i++) {
				for (int j = 0; j <= b; j++) {
					for (int k = 0; k <= c; k++) {
						cashe[i][j][k] = 1;
					}
				}
			}

			for (int i = 1; i <= a; i++) {
				for (int j = 1; j <= b; j++) {
					for (int k = 1; k <= c; k++) {
						cashe[i][j][k] = cashe[i - 1][j][k] + cashe[i - 1][j - 1][k] + cashe[i - 1][j][k - 1] - cashe[i - 1][j - 1][k - 1];
					}
				}
			}
			return cashe[a][b][c];

		}
	}
}


int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);


	while (a != -1 || b != -1 || c != -1) {
		printf("w(%d, %d, %d) = %d\n", a, b, c, w2(a, b, c));
		scanf("%d %d %d", &a, &b, &c);
	}

}
