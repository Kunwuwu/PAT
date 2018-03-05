#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct tnode
{
    int data;
    struct tnode *left, *right;
}*avl;

const int inf = 999999999;
int n;
int level[1000];
bool iscmpt = true;

int geth(avl root)
{
    if(root == NULL)
        return 0;
    else
        return max(geth(root->left), geth(root->right)) + 1;
}

avl rtleft(avl root)
{
    avl temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

avl rtright(avl root)
{
    avl temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

avl rtleftright(avl root)
{
    root->left = rtright(root->left);
    return rtleft(root);
}

avl rtrightleft(avl root)
{
    root->right = rtleft(root->right);
    return rtright(root);
}

avl insertx(avl root, int x)
{
    if(root == NULL)
    {
        root = new tnode;
        root->left = root->right = NULL;
        root->data = x;
    }
    else
    {
        if(x < root->data)
        {
            root->left = insertx(root->left, x);
            if(geth(root->left) - geth(root->right) == 2)
            {
                if(x < root->left->data)
                    root = rtleft(root);
                else
                    root = rtleftright(root);
            }
        }
        else
        {
            root->right = insertx(root->right, x);
            if(geth(root->right) - geth(root->left) == 2)
            {
                if(x < root->right->data)
                    root = rtrightleft(root);
                else
                    root = rtright(root);
            }
        }
        return root;
    }
}

void pre(avl root, int index)
{
    if(root == NULL)
        return ;
    level[index] = root->data;
    pre(root->left, 2 * index);
    pre(root->right, 2 * index + 1);
}

int main()
{
    cin >> n;
    int x;
    avl root = NULL;
    fill(level, level + 1000, inf);
    for(int i = 0; i < n; i++)                            /* AVL那些基本操作就不谈了 */
    {
        scanf("%d", &x);
        root = insertx(root, x);
    }
    pre(root, 1);                                         /* 这里是进行一次带层数的前序遍历，生成层序序列 */
    for(int i = 1; i < 1000; i++)
    {
        if(level[i] == inf)                               /* 如果是完全二叉树，则满足序列的长度正好要为n */
        {
            if(i <= n)
                iscmpt = false;
        }
        else
        {
            if(i > n)
                iscmpt == false;
            if(i == 1)
                printf("%d", level[i]);
            else
                printf(" %d", level[i]);
        }
    }
    if(iscmpt)
        printf("\nYES");
    else
        printf("\nNO");
    return 0;
}
