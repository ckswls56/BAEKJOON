#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,i,min,max;
    int *array;
    scanf("%d",&n);
    array = (int*)malloc(sizeof(int)*n);
    i=0;
    while(i<n){
        scanf("%d",&min);
        array[i++]=min;
    }
    max = min;
    i=0;
    while(i<n){
        if(array[i]>max)
            max = array[i];
        if(array[i]<min)    
            min = array[i];
        i++;
    }
    printf("%d %d",min,max);
}
