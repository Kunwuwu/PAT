#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> post, in, level;
int n;

void pre(int startpost, int endpost, int startin, int endin, int index)
{
    if(startpost > endpost || startin > endin)
    {
        return ;
    }
    int root = 0;
    while(in[root] != post[endpost]) root++;           /* 在中序中查找根节点的位置 */
    int left = root - startin;                         /* 在中序中找到左节点和右节点的数量 */
    int right = endin - root;
    level[index] = post[endpost];
    pre(startpost, endpost - right - 1, startin, root - 1, index * 2 + 1);
    pre(startpost + left, endpost - 1, root + 1, endin, index * 2 + 2);
}

int main()
{
    cin >> n;
    int temp;
    level.resize(1000001, 0);                         /* 层序遍历的范围要足够大，2^depth */
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        post.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        in.push_back(temp);
    }
    pre(0, n - 1, 0, n - 1, 0);
    cout << level[0];
    for(int i = 1; i < 1000001; i++)
        if(level[i] != 0)
            cout << " " << level[i];
    return 0;
}
