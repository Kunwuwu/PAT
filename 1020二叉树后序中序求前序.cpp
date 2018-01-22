#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// 全局变量的定义及初始化
vector<int> post, in;
int n;

// 函数原型
void pre(int root, int start, int end);

int main()
{
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
    pre(post.size() - 1, 0, post.size() - 1);
    return 0;
}

void pre(int root, int start, int end)               /* 这里说明一下： */
{                                                    /* root是在根节点后序序列中确定的位置，i是根节点在中序的位置 */
    if(start > end)                                  /* end是在中序中的当前序列的结尾的位置 */
        return ;                                     /* start是在中序中的当前序列的起始的位置 */
    int i = start;
    while(i < end && in[i] != post[root])
        i++;
    cout << post[root] << "\t";
    pre(root - (end - i + 1), start, i - 1);
    pre(root - 1, i + 1, end);
}
