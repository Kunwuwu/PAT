#include  <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> tree;
int n;
vector<int> in, level, roots;
int cntin = 0;

int strtoint(string tree)                                         /* 将字符串数字转成数字 */
{
    int sum = 0, len = tree.length();
    for(int i = 0; i < len; i++)
    {
        sum *= 10;
        sum += (tree[i] - '0');
    }
    return sum;
}

void inorder(int root, int index)                                 /* 带层序的中序遍历 */
{
    if(root == -1)
        return ;
    level[index] = root;
    inorder(tree[root][0], 2 * index + 1);
    in[cntin++] = root;
    inorder(tree[root][1], 2 * index + 2);
}

int main()
{
    cin >> n;
    tree.resize(n);
    in.resize(n);
    roots.resize(n);
    level.resize(1000, -1);
    string left, right;
    int leftint, rightint, root = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> left >> right;
        tree[i].resize(2);
        if(left != "-")
        {
            rightint = strtoint(left);
            roots[rightint]++;
            tree[i][1] = rightint;
        }
        else
            tree[i][1] = -1;
        if(right != "-")
        {
            leftint = strtoint(right);
            roots[leftint]++;
            tree[i][0] = leftint;
        }
        else
            tree[i][0] = -1;
    }
    for(int i = 0; i < n; i++)
    {
        if(roots[i] == 0)
        {
            root = i;
            break;
        }
    }
    inorder(root, 0);
    cout << level[0];
    for(int i = 1; i < 1000; i++)
        if(level[i] != -1)
            printf(" %d", level[i]);
    printf("\n%d", in[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", in[i]);
    return 0;
}
