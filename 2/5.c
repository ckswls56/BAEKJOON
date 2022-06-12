#include <stdio.h>
int main(){
    
    int hour,min;
    scanf("%d",&hour);
    scanf("%d",&min);
    if(min>=45)
        min-=45;
    else{
       hour--;
       min=min+15;
    }
    if(hour<0)
        hour=23;
    printf("%d %d",hour,min);
    return 0;
}
