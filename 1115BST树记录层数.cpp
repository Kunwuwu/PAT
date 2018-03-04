#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tnode
{
    struct tnode *left, *right;
    int data;
    int height;
}*node;

int maxlevel = 0, n1, n2, n;

node insertx(node root, int x, int level)                 /* 创建BST */
{
    if(root == NULL)
    {
        root = new tnode;
        root->left = root->right = NULL;
        root->data = x;
        root->height = level;                             /* 记录节点的层数 */
        if(level > maxlevel)
            maxlevel = level;                             /* 更新最深的层数 */
    }
    else                                                  /* BST的带层数的插入操作 */
    {
        if(x <= root->data)
            root->left = insertx(root->left, x, level + 1);
        else
            root->right = insertx(root->right, x, level + 1);
    }
    return root;
}

void pre(node root)
{
    if(root == NULL)                                      /* 刚刚把这个忘了2333 */
        return ;
    if(root->height == maxlevel)                          /* 如果是倒数第一层或者倒数第二层，就记录一下 */
        n1++;
    else if(root->height == maxlevel - 1)
        n2++;
    pre(root->left);
    pre(root->right);
}

int main()
{
    cin >> n;
    node root = NULL;
    int x;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insertx(root, x, 1);
    }
    pre(root);
    printf("%d + %d = %d", n1, n2, n1 + n2);
    return 0;
}
