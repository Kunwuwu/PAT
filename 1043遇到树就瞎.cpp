#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> pre;
vector<int> post;
bool isMirror = false;

void posord(int root, int end)
{
    if(root > end)
        return ;
    int i = root + 1, endleft = end;
    if(!isMirror)
    {
        while(pre[i] < pre[root] && i <= end) i++;            /* 找到右子树根结点的位置 */
        while(pre[endleft] >= pre[root] && endleft > root)  endleft--; /* 左子树的右边界 */
    }
    else
    {
        while(pre[i] >= pre[root] && i <= end) i++;           /* 同上，不过是镜像过的 */
        while(pre[endleft] < pre[root] && endleft > root)  endleft--; /* 左子树的右边界 */
    }
    if(i - endleft != 1)
        return ;
    posord(root + 1, endleft);
    posord(i, end);
    post.push_back(pre[root]);
}

int main()
{
    int temp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        pre.push_back(temp);
    }
    posord(0, n - 1);
    if(post.size() != n)
        isMirror = true;
    if(isMirror)
    {
        post.clear();
        posord(0, n - 1);
    }
    if(post.size() == n)
    {
        cout << "YES" << endl;
        cout << post[0];
        for(int i = 1; i < n; i++)
            cout << " " << post[i];
    }
    else
        cout << "NO";
    return 0;
}
