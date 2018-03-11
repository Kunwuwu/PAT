#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> pre, in, po;

void post(int leftpre, int rightpre, int leftin, int rightin)
{                                                         /* 根据前序和中序确定后序 */
    if(leftpre > rightpre)
        return ;
    int rootin = leftin;
    while(in[rootin] != pre[leftpre] && rootin <= rightin) rootin++;
    int left = rootin - leftin;                           /* 左儿子的个数 */
    post(leftpre + 1, leftpre + left, leftin, rootin - 1);
    post(leftpre + 1 + left, rightpre, rootin + 1, rightin);
    po.push_back(pre[leftpre]);
}

int main()
{
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    post(0, n - 1, 0, n - 1);
    cout << po[0];
    return 0;
}
