#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

vector<vector<int>> tree;                                 /* 生成树 */
vector<bool> root;                                        /* 判断是否是根的数组 */
vector<int> level(25, -1);                                /* 先序遍历生成的层序数组 */
int n, realroot;
bool iscpl = true;                                        /* 判断是否是完全二叉树 */

void pre(int rt, int index)                               /* 带index的先序遍历 */
{
    if(index >= n)                                        /* 完全二叉树的元素下标，只可能比n小 */
    {
        iscpl = false;
        return ;
    }
    level[index] = rt;                                    /* 先序遍历 */
    if(tree[rt][0] != -1)
        pre(tree[rt][0], 2 * index + 1);
    if(tree[rt][1] != -1)
        pre(tree[rt][1], 2 * index + 2);
}

int main()
{
    cin >> n;
    char num1[3], num2[3];
    int left, right;
    tree.resize(n);
    root.resize(n, true);
    for(int i = 0; i < n ; i++)                           /* 建立树（数组表示） */
    {
        tree[i].resize(2, -1);
        scanf("%s %s", num1, num2);
        if(num1[0] != '-')
        {
            sscanf(num1, "%d", &left);
            tree[i][0] = left;
            root[left] = false;
        }
        if(num2[0] != '-')
        {
            sscanf(num2, "%d", &right);
            tree[i][1] = right;
            root[right] = false;
        }
    }
    for(int i = 0; i < n; i++)                            /* 找树根 */
    {
        if(root[i])
            realroot = i;
    }
    pre(realroot, 0);
    if(iscpl)
    {
        for(int i = 0; i < n; i++)
        {
            if(level[i] == -1)                            /* 如果level数组中出现过没有被先序遍历到的元素，说明不是完全二叉树 */
            {
                iscpl = false;
                break;
            }
        }
    }
    if(iscpl)
        cout << "YES" << " " << level[n-1];
    else
        cout << "NO" << " " << realroot;
    return 0;
}
