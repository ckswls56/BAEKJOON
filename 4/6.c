#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int i,j,n, res, con;
	char a[80] = { 0 };
	scanf("%d", &n);
	i = 0;
	while (i < n) {
		res = 0;
		scanf("%s", a);
		j = strlen(a);
		con = 0;
		while (j > 0) {
			if (a[--j] == 79)
				con++;
			else
				con = 0;
			res += con;
		}
		printf("%d\n", res);
		i++;
	}	
}
