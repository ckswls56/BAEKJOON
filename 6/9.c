#include <stdio.h>
#include <string.h>

int cmp(char *s){
    int i=0;int len;
    char cro[8][4]={"c=","c-","dz=","d-","lj","nj","s=","z="};
    while(i<8){
        len = strlen(cro[i]);
        if(!strncmp(s,cro[i],len))
            return len;
        i++;
    }
    return 1;    
}

int main(){
    char s[101]={0};
    scanf("%s",s);
    int len = strlen(s); int i=0;
    int sum=0; int pos=0;
    while(i<len){
        pos = cmp(&s[i]);
        i += pos; sum ++;
    }
    printf("%d",sum);

}