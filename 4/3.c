#include <stdio.h>
int main(){
    int a,b,c,res,i;
    int array[10]={0};
    scanf("%d %d %d",&a,&b,&c);
    res = a*b*c; i = 0;
    while(res>0){
        array[res%10]++;
        res/=10;
    }
    while(i<10)
        printf("%d ",array[i++]);
}
