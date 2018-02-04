#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tnode
{
    int data;
    struct tnode *left, *right;
}*avl;

int getheight(avl root)                                       /* 递归求得树高 */
{
    if(root == NULL)                                          /* 空节点的高度为零 */
        return 0;
    else
        return max(getheight(root->left), getheight(root->right)) + 1;
}

avl rtleft(avl root)                                          /* LL旋转 */
{
    avl temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

avl rtright(avl root)                                        /* RR旋转 */
{
    avl temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

avl rtleftright(avl root)                                   /* LR旋转 */
{
    root->left = rtright(root->left);
    return rtleft(root);
}

avl rtrightleft(avl root)                                   /* RL旋转 */
{
    root->right = rtleft(root->right);
    return rtright(root);
}

avl insert(int x, avl root)
{
    if(root == NULL)                                        /* 新的结点 */
    {
        root = new tnode;
        root->data = x;
        root->left = root->right = NULL;                    /* 新的结点，自然左右子树都是空的 */
    }
    else
    {
        if(x < root->data)                                  /* x小，插入到左子树中 */
        {
            root->left = insert(x, root->left);             /* 插入到左子树中 */
            if(getheight(root->left) - getheight(root->right) == 2)  /* 如果root结点不平衡了 */
            {
                if(x < root->left->data)                    /* 如果x插入到了左子树的左子树中，需要LL旋转 */
                    root = rtleft(root);
                else
                    root = rtleftright(root);               /* 如果x插入到了左子树的右子树中，需要LR旋转 */
            }
        }
        else                                                /* x大，插入到右子树中 */
        {
            root->right = insert(x, root->right);           /* 插入到右子树中 */
            if(getheight(root->right) - getheight(root->left) == 2)  /* 如果root结点不平衡了 */
            {
                if(x < root->right->data)                   /* 如果x插入到了右子树的左子树中，需要RL旋转 */
                    root = rtrightleft(root);
                else
                    root = rtright(root);                   /* 如果x插入到了右子树的右子树中，需要RR旋转 */
            }
        }
    }
    return root;
}

int main()
{
    int n, x;
    cin >> n;
    avl root = NULL;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(x, root);
    }
    cout << root->data;
    return 0;
}
