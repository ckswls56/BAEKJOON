#include <stdio.h>
#include <stdlib.h>

long long int **arr;

long long int jegob(long long int n) {
	return n * n;
}

int main() {
	int t;
	scanf("%d", &t);
	arr = (long long int**)malloc(sizeof(long long int*) * 50);
	for(int i=0;i<50;i++)
		arr[i] = (long long int*)malloc(sizeof(long long int) * 3);
	while (t-- > 0) {
		long long int x1, y1, x2, y2;
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		
		int n;	int cnt = 0;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%lld %lld %lld", &arr[i][0], &arr[i][1], &arr[i][2]);
			int flag = -1; // start and end could not be entered in same circle
			if ( (jegob (arr[i][0] - x1) + jegob(arr[i][1] - y1) ) < jegob(arr[i][2]) ){
				flag *= -1;
			}
			if ( (jegob(arr[i][0] - x2) + jegob(arr[i][1] - y2) ) < jegob(arr[i][2]) ){
				flag *= -1;
			}
			if (flag == 1)
				cnt++;

		}
		if (x1 == x2 && y1 == y2) {
			printf("0\n");//start and end is same
			continue;
		}

		printf("%d\n", cnt);
	}

}
