#include <iostream>
using namespace std;
#define MAXNODE 100000 + 1
int in[MAXNODE];
int post[MAXNODE];
int index[MAXNODE];

void preorder(int inStart, int inEnd, int postStart, int postEnd)
{ // postorder의 끝은 항상 root인 성질을 이용한다.

    if (inStart > inEnd || postStart > postEnd)
        return;

    int rootIndex = index[post[postEnd]];
    int leftSize = rootIndex - inStart;
    // int rightSize = inEnd - rootIndex;

    printf("%d ", in[rootIndex]);
    preorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    preorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &in[i]);
        index[in[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &post[i]);
    }

    preorder(1, n, 1, n);
}