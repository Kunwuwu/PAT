#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 常量的定义
const int MAX = 2000;

// 全局变量的定义及初始化
vector<int> post;
vector<int> in;
int n;
int level[MAX];

// 函数原型
void pre(int root, int start, int end, int index);

int main()
{
    fill(level, level + MAX, -1);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        post.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        in.push_back(temp);
    }
    pre(post.size() - 1, 0, post.size() - 1, 1);
    int count = 0;
    for(int i = 0; i < MAX; i++)
    {
        if(level[i] != -1 && count != n - 1)
        {
            cout << level[i] << " ";
            count++;
        }
        else if(count == n - 1 && level[i] != -1)
        {
            cout << level[i];
            break;
        }
    }
    return 0;
}

void pre(int root, int start, int end, int index)         /* 模拟前序遍历的过程 */
{
    int i = 0;
    if(start > end)
        return ;
    while(i < end && in[i] != post[root])                 /* 确定中序中root的位置 */
        i++;
    level[index] = post[root];                            /* 记录根节点在层序遍历中的顺序 */
    pre(root - (end - i + 1), start, i - 1, index * 2);   /* 二叉树左子树节点的index等于父节点2*index，右子树2*index+1 */
    pre(root - 1, i + 1, end, index * 2 + 1);
}
