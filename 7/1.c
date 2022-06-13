#include <stdio.h>

int calc(int a , int b, int c){
    if (b >= c)
        return (-1);
    return ((a/(c-b))+1);
    
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d",calc(a,b,c));
}