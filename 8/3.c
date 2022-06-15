#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int i=2;

    while(i<=n){
        if(n%i==0){
            printf("%d\n",i);
            n/=i;
            i=1;
        }
        i++;
    }
}