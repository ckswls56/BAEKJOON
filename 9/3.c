#include <stdio.h>
int i=0;
void print_underbar(int n){
    while(n-->0){
        printf("____");
    }
}
void    jaegi(int n){
    if(n==0){
        print_underbar(i);printf("\"¿¿¿¿¿ ¿¿¿?\"\n");
        print_underbar(i);printf("\"¿¿¿¿¿ ¿¿ ¿¿¿ ¿¿¿¿ ¿¿¿¿\"\n");
        print_underbar(i);printf("¿¿ ¿¿¿¿¿.\n");
        i--;
        return ;
    }
    
    print_underbar(i);printf("\"¿¿¿¿¿ ¿¿¿?\"\n");
    print_underbar(i);printf("\"¿ ¿¿¿¿. ¿¿¿¿ ¿ ¿ ¿¿¿¿ ¿¿¿ ¿¿ ¿¿¿ ¿¿¿ ¿¿¿ ¿¿¿.\n");
    print_underbar(i);printf("¿¿ ¿¿¿¿ ¿¿ ¿ ¿¿¿¿ ¿¿¿ ¿¿¿ ¿¿, ¿¿ ¿¿¿¿ ¿¿¿ ¿¿¿.\n");
    print_underbar(i);printf("¿¿ ¿¿ ¿¿¿ ¿¿¿¿ ¿¿. ¿¿¿ ¿¿ ¿, ¿ ¿¿¿¿ ¿ ¿¿¿ ¿¿¿¿ ¿¿¿.\"\n");
    i++;
    jaegi(n-1);
    print_underbar(i);printf("¿¿ ¿¿¿¿¿.\n");
    i--;
    return ;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("¿¿ ¿ ¿¿¿¿¿¿ ¿¿¿ ¿¿¿ ¿¿¿¿ ¿¿¿ ¿¿¿.\n");
    jaegi(n);
}
