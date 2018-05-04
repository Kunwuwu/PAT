#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct tnode {
    int data;
    struct tnode *left, *right;
} *tree;

vector<int> pre, in, sortpre;
bool flag = true;
int k, n, index = 0;

tree insertx(tree root, int x) {                          /* bst建树 */
    if (root == NULL) {
        root = new tnode;
        root->left = root->right = NULL;
        root->data = x;
    } else {
        if (abs(x) < abs(root->data))
            root->left = insertx(root->left, x);
        else
            root->right = insertx(root->right, x);
    }
    return root;
}

void inorder(tree root) {                                 /* 得到中序序列 */
    if (root == NULL)
        return;
    if (root->data < 0) {
        if (root->left && root->left->data < 0)
            flag = false;
        if (root->right && root->right->data < 0)
            flag = false;
    }
    inorder(root->left);
    in[index++] = abs(root->data);
    inorder(root->right);
}

int geth(tree root) {                                     /* 获得某个根节点的树高 */
    if (root == NULL)
        return 0;
    if (root->data > 0)
        return max(geth(root->left), geth(root->right)) + 1;
    else
        return max(geth(root->left), geth(root->right));
}

void isbl(tree root) {                                    /* 根据左右子树树高，递归判断是否平衡 */
    if (root == NULL)
        return;
    if (geth(root->left) != geth(root->right))
        flag = false;
    isbl(root->left);
    isbl(root->right);
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        tree root = NULL;
        flag = true;
        pre.resize(n);
        in.resize(n);
        vector<int> t;
        t.resize(n);
        index = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &pre[j]);
            root = insertx(root, pre[j]);
            t[j] = abs(pre[j]);
        }
        inorder(root);
        isbl(root);                                       /* 首先判断是否平衡 */
        sort(t.begin(), t.end());
        if (t != in || pre[0] < 0)                        /* 如果根节点不是黑色的，则不是红黑树 */
            flag = false;                                 /* 如果得到的中序序列不是有序的，也不是红黑树 */
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
