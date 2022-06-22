#include <stdio.h>

int main(){

    int x1,x2,x3;
    int y1,y2,y3;


    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    scanf("%d %d",&x3,&y3);

    if(x1==x2){
        if(y1==y2){
            printf("%d %d",x3,y3);
        }
        else if(y1==y3)
            printf("%d %d",x3,y2);
        else
            printf("%d %d",x3,y1);
    }
    else if(x1==x3){
        if(y1==y2)
            printf("%d %d",x2,y3);
        else if(y1==y3)
            printf("%d %d",x2,y2);
        else
            printf("%d %d",x2,y1);
        }
    else{
        if(y1==y2)
            printf("%d %d",x1,y3);    
        else if(y1==y3)
            printf("%d %d",x1,y2);
        else
            printf("%d %d",x1,y1);
    }   
    return 0;
}
