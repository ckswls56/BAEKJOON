#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct list
{
    int a;
    int b;
    int diff;
};

int abs(int n){
    if(n<0)
        return (-n);
    else
        return n;
}
int isprime(int n) {
	if (n < 2)
		return 0;
	int i = 2;
	while (i*i <= n) {
		if (n%i == 0)
			return 0;
		i++;
	}
	return 1;
}
int count_prime(int n){
    int i=2;
    int count =0;
    while(i<=n){
        if(isprime(i))
            count++;
        i++;
    }
    return count;
}
int *make_prime_arr(int n){
    int i=2;
    int * res;
    res= (int*)malloc(sizeof(int)*count_prime(n));
    int j=0;
    while(i<n){
        if(isprime(i))
            res[j++]=i;
        i++;
    }
    return res;
}

void print_min_list(struct list* arr,int k){
    int min;int index;
    if(k==1){
        printf("%d %d\n",arr->a,arr->b);
    }
    else{
        min =10000;
        while(k-->0){
            if(min>=arr[k].diff){
                min=arr[k].diff;
                index = k;
            }
        }
        printf("%d %d\n",arr[index].a,arr[index].b);
    }
}
int main() {
	int t;scanf("%d",&t);
    int n;int i,j,k,len;
    int *a,*b;
    a=make_prime_arr(10000);b=make_prime_arr(10000);
    struct list* arr;
    while(t>0){
        i=0;j=0;k=0;
        scanf("%d",&n);
        while((n<4||n%2!=0)){
            t--;
            if(t==0)
                return 0;
            scanf("%d",&n);
        }

        len = count_prime(n); arr=(struct list*)malloc(sizeof(arr)*len);
        while(i<=len){
            j=i;
            while(j<=len){
              if(a[i]+b[j]==n){
                arr[k].a=a[i];arr[k].b=b[j];arr[k].diff=abs(a[i]-b[j]);
                k++;
              }
                j++;
            }
            i++;
         }
          print_min_list(arr,k);
        t--;
    }
	
	return 0;
}
