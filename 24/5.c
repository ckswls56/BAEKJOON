#include <stdio.h>
#include<string.h>

int dp[40001];
int arr[30];

int abs(int x){
    if(x<0)
        return -x;
    return x;
}

void    scale(int x){
    int temp[40001]={0};

        for(int i=1;i<40001;i++){
            if(dp[i]){
                temp[i]=1;
                temp[abs(x-i)]=1;
                temp[x+i]=1;
            }
        }
        temp[x]=1;
        memcpy(dp,temp,sizeof(int)*40001);
}

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        scale(arr[i]);
    }

    scanf("%d",&n);
    while(n--){
        int w;
        scanf("%d",&w);
        if(dp[w]==1){
            printf("Y ");
        }
        else
            printf("N ");
    }
   
}