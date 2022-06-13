#include <stdio.h>
#include <string.h>
int time(char dial[8][5],char c){
    int i=0;int len = 0;int j;
    while(i<8){
        len = strlen(dial[i]);
        j=0;
        while(j<len){
            if(dial[i][j] == c)
                return i+3;
            j++;
        }
        i++;
    }    
}

int main(){
    char dial[8][5]={"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    char s[16];int i=0,len =0,sum=0;
    scanf("%s",s);len = strlen(s);
    while(i<len)
        sum += time(dial,s[i++]);
    printf("%d",sum);
    return 0;
}