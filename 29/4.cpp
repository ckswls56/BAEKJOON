#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef struct node
{
    char data;
    node *left_child;
    node *right_child;
} node;

node *tree;

void make_tree(char *s, node &t)
{
    char n, l, r;

    n = s[0];
    l = s[2];
    r = s[4];

    t.data = n;
    if (l != '.')
        t.left_child = &tree[l - 'A'];
    else
        t.left_child = NULL;

    if (r != '.')
        t.right_child = &tree[r - 'A'];
    else
        t.right_child = NULL;
}

void preorder(node *n)
{
    printf("%c", n->data);
    if (n->left_child)
        preorder(n->left_child);
    if (n->right_child)
        preorder(n->right_child);
}

void inorder(node *n)
{

    if (n->left_child)
        inorder(n->left_child);
    printf("%c", n->data);
    if (n->right_child)
        inorder(n->right_child);
}

void postorder(node *n)
{
    if (n->left_child)
        postorder(n->left_child);
    if (n->right_child)
        postorder(n->right_child);
    printf("%c", n->data);
}

int main()
{
    int n;
    char s[10];
    scanf("%d\n", &n);
    tree = new node[n];

    for (int i = 0; i < n; i++)
    {
        cin.getline(s, 10);
        make_tree(s, tree[s[0] - 'A']);
    }

    preorder(&tree[0]);
    printf("\n");
    inorder(&tree[0]);
    printf("\n");
    postorder(&tree[0]);
}