#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tnode
{
    int data;
    tnode *left, *right;
}*bst;

vector<int> tpre, pre1, pre2, post;
int n;

bst insertx1(bst root, int data)
{
    if(root == NULL)
    {
        root = new tnode;
        root->data = data;
        root->right = root->left = NULL;
    }
    else
    {
        if(data < root->data)
            root->left = insertx1(root->left, data);
        else
            root->right = insertx1(root->right, data);
    }
    return root;                                          /* 有两次因为这个忘了导致WA */
}

bst insertx2(bst root, int data)
{
    if(root == NULL)
    {
        root = new tnode;
        root->data = data;
        root->right = root->left = NULL;
    }
    else
    {
        if(data >= root->data)
            root->left = insertx2(root->left, data);
        else
            root->right = insertx2(root->right, data);
    }
    return root;                                          /* 有两次因为这个忘了导致WA */
}

void preorder(bst root, vector<int> &pre)                 /* 引用传递方便 */
{
    if(root == NULL)
        return ;
    pre.push_back(root->data);
    preorder(root->left, pre);
    preorder(root->right, pre);
}

void postorder(bst root)
{
    if(root == NULL)
        return ;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->data);
}

int main()
{
    cin >> n;
    tpre.resize(n);
    bst root1 = NULL, root2 = NULL;
    for(int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        root1 = insertx1(root1, data);                   
        root2 = insertx2(root2, data);                    /* 镜像bst */
        tpre[i] = data;
    }
    preorder(root1, pre1);                                /* 对普通bst生成的树生成前序序列 */
    preorder(root2, pre2);                                /* 对镜像bst生成的树生成前序序列 */
    if(pre1 == tpre)                                      /* 判断原前序序列和建成树之后的前序是否相等 */
    {
        printf("YES\n");
        postorder(root1);
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
                printf("%d", post[i]);
            else
                printf(" %d", post[i]);
        }
    }
    else if(pre2 == tpre)
    {
        printf("YES\n");
        postorder(root2);
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
                printf("%d", post[i]);
            else
                printf(" %d", post[i]);
        }
    }
    else
        printf("NO\n");
    return 0;
}
