#include <stdio.h>
int i=0;
void print_underbar(int n){
    while(n-->0){
        printf("____");
    }
}
void    jaegi(int n){
    if(n==0){
        print_underbar(i);printf("\"����Լ��� ������?\"\n");
        print_underbar(i);printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
        print_underbar(i);printf("��� �亯�Ͽ���.\n");
        i--;
        return ;
    }
    
    print_underbar(i);printf("\"����Լ��� ������?\"\n");
    print_underbar(i);printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
    print_underbar(i);printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
    print_underbar(i);printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
    i++;
    jaegi(n-1);
    print_underbar(i);printf("��� �亯�Ͽ���.\n");
    i--;
    return ;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    jaegi(n);
}