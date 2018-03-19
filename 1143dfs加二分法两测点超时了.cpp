#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct tnode
{
    int data;
    struct tnode * left, *right;
}*bst;

int m, n, a, b;
int f = -1;
bool founda, foundb;
vector<int> v;

bst insert(bst root, int x)
{
    if (root == NULL)
    {
        root = new tnode;
        root->data = x;
        root->left = root->right = NULL;
    }
    else
    {
        if (x < root->data)
            root->left = insert(root->left, x);
        else
            root->right = insert(root->right, x);
    }
    return root;
}

void dfs(bst root, int x, int y)
{
    if (root == NULL || f != -1)
        return;
    if (x < root->data && y < root->data)
        dfs(root->left, x, y);
    else if (x > root->data && y > root->data)
        dfs(root->right, x, y);
    else
        f = root->data;
}

bool bs(int x)
{
    int left = 0, right = v.size() - 1;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(x < v[mid])
            right = mid - 1;
        else if(x > v[mid])
            left = mid + 1;
        else
            left = right = mid;
    }
    if(v[left] == x)
        return true;
    else
        return false;
}

int main()
{
    cin >> m >> n;
    bst root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        f = -1;
        founda = bs(a), foundb = bs(b);
        if(founda && foundb)
        {
            dfs(root, a, b);
            if(a == f)
                printf("%d is an ancestor of %d.\n", a, b);
            else if(b == f)
                printf("%d is an ancestor of %d.\n", b, a);
            else
                printf("LCA of %d and %d is %d.\n", a, b, f);
        }
        else if(founda && !foundb)
            printf("ERROR: %d is not found.\n", b);
        else if(!founda && foundb)
            printf("ERROR: %d is not found.\n", a);
        else
            printf("ERROR: %d and %d are not found.\n", a, b);
    }
    return 0;
}
