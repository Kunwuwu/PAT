#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 105;
int n, m;
int maxdepth = -1;                                    // 定义最大层数

// 初始化
int tree[MAX][MAX];
int leaf[MAX], depth[MAX];                            // 两个数组，leaf记录当前层叶子节点数，depth记录当前节点所在的层数

// 函数原型
void BFS();

int main()
{
    int k;
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
    BFS();
    cout << leaf[0];
    for(int i = 1; i <= maxdepth; i++)
        cout << " " << leaf[i];
    return 0;
}

void BFS()
{
    queue<int> q;
    int temp;
    bool flag;
    q.push(1);
    depth[1] = 0;                                     // 1节点肯定是第零层
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        flag = true;                                  // 初始temp是叶子节点
        maxdepth = max(depth[temp], maxdepth);        // 更新最大层数
        for(int w = 1; w <= n; w++)
        {
            if(tree[temp][w] == 1)                     // 遍历temp的儿子，发现有儿子则更新队列，儿子的深度
            {
                q.push(w);
                flag = false;                         // 标记temp不是叶子节点
                depth[w] = depth[temp] + 1;           // temp必然是w的上一层
            }
        }
        if(flag)
            leaf[depth[temp]]++;                      // temp表示当前层，即将temp所在层的叶子节点加1
    }
}
