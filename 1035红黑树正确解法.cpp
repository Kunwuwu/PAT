#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

typedef struct tnode {
    int data;
    struct tnode *left, *right;
} *bst;

vector<int> tpath;
bool ans = true;
int blacks = -1;

bst insertx(bst root, int x) {
    if (!root) {
        root = new tnode;
        root->left =  root->right = NULL;
        root->data = x;
    } else {
        if (abs(x) < abs(root->data)) root->left = insertx(root->left, x);
        else root->right = insertx(root->right, x);
    }
    return root;
}

void dfs(bst root, int cnt) {
    if (!root) {
        if (blacks != -1 && cnt != blacks)
            ans = false;
        else blacks = cnt;
        return ;
    }
    if (root->data >= 0) cnt++;
    else {
        if (root->left && root->left->data < 0) ans = false;
        if (root->right && root->right->data < 0) ans = false;
    }
    dfs(root->left, cnt);
    dfs(root->right, cnt);
}

int main() {
    int k, n, x;
    cin >> k;
    while (k--) {
        bst root = NULL;
        ans = true;
        blacks = -1;
        scanf("%d", &n);
        for (int i = 0; i < n ; i++) {
            scanf("%d", &x);
            root = insertx(root, x);
        }
        if (root->data >= 0) dfs(root, 0);
        else ans = false;
        if (!ans) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
