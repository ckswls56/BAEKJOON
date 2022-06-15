#include <stdio.h>

int isprime(int n) {
	if (n < 2)
		return -1;
	int i = 2;
	while (i*i <= n) {
		if (n%i == 0)
			return -1;
		i++;
	}
	return 1;
}
int main() {
	int n,count,n2;
    scanf("%d", &n);
    while(n>0){
        count=0;n2=n*2;
	    while (++n <= n2) {
		    if (isprime(n) == 1) {
			    count++;
            }
	    }
        printf("%d\n",count);
        scanf("%d", &n);
    }
	
	return 0;
}
