#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct                                             /* 树结点 */
{
    int data;
    int left, right;
}node;

vector<node> bst;                                          /* 二叉搜索树 */
vector<int> v, result;                                     /* v是中序序列 */
int n;
int index = 0;

void inorder(int root)                                     /* 中序遍历bst，生成bst */
{
    if(root == -1)
        return ;
    inorder(bst[root].left);
    bst[root].data = v[index++];
    inorder(bst[root].right);
}

void level(int root)                                       /* 层序遍历，得到结果 */
{
    queue<node> q;
    q.push(bst[root]);
    while(!q.empty())
    {
        node temp = q.front();
        q.pop();
        result.push_back(temp.data);
        if(temp.left != -1)
            q.push(bst[temp.left]);
        if(temp.right != -1)
            q.push(bst[temp.right]);
    }
}

int main()
{
    cin >> n;
    bst.resize(n);
    for(int i = 0; i < n; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        bst[i].left = left;
        bst[i].right = right;
    }
    for(int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        v.push_back(data);
    }
    sort(v.begin(), v.end());
    inorder(0);
    level(0);
    cout << result[0];
    for(int i = 1; i < n; i++)
        cout << " " << result[i];
    return 0;
}
