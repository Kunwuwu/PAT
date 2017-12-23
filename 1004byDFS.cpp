#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 105;
int n, m;
int maxdepth = -1;                                    // 定义最大层数
int tree[MAX][MAX];

// 初始化
int leaf[MAX];
vector<bool> visited(MAX, false);

// 函数原型
void DFS(int vertex, int depth);

int main()
{
    int k, depth = -1;
    int par, child;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)                        // 这个循环创建树
    {
        scanf("%d %d", &par, &k);
        for(int j = 1; j <= k; j++)
        {
            scanf("%d", &child);
            tree[par][child] = 1;
        }
    }
    DFS(1, depth);
    cout << leaf[0];
    for(int i = 1; i <= maxdepth; i++)
        cout << " " << leaf[i];
    return 0;
}

void DFS(int vertex, int depth)
{
    depth += 1;
    maxdepth = max(depth, maxdepth);
    bool flag = true;
    visited[vertex] = true;
    for(int i = 1; i <= n; i++)
    {
        if(tree[vertex][i] == 1 && !visited[i])
        {
            DFS(i, depth);
            flag = false;
        }
    }
    if(flag)
        leaf[depth] += 1;
}
