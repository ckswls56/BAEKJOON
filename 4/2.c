#include <stdio.h>
int main(){
    int i,max,max_i;
    int array[9];
    i=0;
    while(i<9)
        scanf("%d",&array[i++]);
    max = 0;
    while(i>=0){
        if(max<array[i]){
            max = array[i];
            max_i = i+1;
        }
        i--;
    }
}
