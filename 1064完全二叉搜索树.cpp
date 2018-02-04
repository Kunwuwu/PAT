#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> od;
vector<int> lv;
int n, index = 1;

void treebuild(int root)                                  /* 模拟中序建树的过程 */
{
    if(root > n)
        return ;
    treebuild(root * 2);                                  /* 完全二叉树中左子树结点下标为根结点的两倍 */
    lv[root] = od[index++];
    treebuild(root * 2 + 1);                              /* 完全二叉树中右子树结点下标为根结点的两倍再加1 */
}

int main()
{
    cin >> n;
    od.resize(n + 1);
    lv.resize(n + 1);
    for(int i = 1; i <= n; i++)                           /* 读取的数据在sort后就是中序遍历序列 */
        scanf("%d", &od[i]);
    sort(od.begin(), od.end());
    treebuild(1);
    cout << lv[1];
    for(auto it = lv.begin() + 2; it != lv.end(); it++)
        cout << " " << *it;
    return 0;
}
