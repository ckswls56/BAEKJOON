#include <stdio.h>
#include <string.h>


int main(){
    int N; scanf("%d",&N); 
    int i=0;int j ;int group = 0;
    char s[101];int len;
    while(i<N){
        char alpha[26]={0};
        scanf("%s",s);len=strlen(s);
        j=1;alpha[s[0]-'a']=1;
        while(j<len){
            if (alpha[s[j]-'a']==1 && (s[j]!=s[j-1])){
                group--;
                break;
            }
            alpha[s[j++]-'a'] = 1;
        }
        group++;
        i++;
    }
    printf("%d",group);
    return 0;
}