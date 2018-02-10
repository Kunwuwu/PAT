#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
stack<int> s;
vector<int> pre, in, post;

void postorder(int startpre, int endpre, int startin, int endin)/* 分别是前序和中序序列的起点和终点 */
{
    if(startpre > endpre || startin > endin)
        return ;
    int root = 0;
    while(in[root] != pre[startpre]) root++;                /* 找到根节点在中序中的位置 */
    int left = root - startin;
    int right = endin - root;
    postorder(startpre + 1, endpre - right, startin, root - 1);
    postorder(startpre + 1 + left, endpre, root + 1, endin);
    post.push_back(pre[startpre]);
}

int main()
{
    string order;
    cin >> n;
    for(int i = 0; i < 2 * n; i++)
    {
        cin >> order;
        if(order[1] == 'u')
        {
            int temp;
            scanf("%d", &temp);
            s.push(temp);
            pre.push_back(temp);
        }
        else
        {
            int temp = s.top();
            in.push_back(temp);
            s.pop();
        }
    }
    postorder(0, n - 1, 0, n - 1);
    cout << post[0];
    for(int i = 1; i < post.size(); i++)
        cout << " " << post[i];
    return 0;
}
