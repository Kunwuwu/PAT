#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> paths[101];                         /* 生成树 */
vector<int> weight;
bool visited[101];
vector<int> temppath;
vector<int> result[101];

int n, m, w, cnt = 0;

void dfs(int s)                                /* 每一个条path就是从根节点到叶节点所经过的所有结点 */
{
    visited[s] = true;
    temppath.push_back(s);                     /* 当前的路径 */
    if(paths[s].size() == 0)                   /* 如果是叶节点，则开始计算权重和值 */
    {
        int sum = 0;                           /* 计算整个路径的权重之和 */
        for(int i = 0; i < temppath.size(); i++)
        {
            sum += weight[temppath[i]];
        }
        if(sum == w)
            result[cnt++] = temppath;          /* 向量数组存储每条符合条件的路径（已经经过排序） */
        temppath.pop_back();                   /* 这个pop和return不能忘，理解，其实就是退回到上个结点 */
        return ;
    }
    for(int v = 0; v < paths[s].size(); v++)
    {
        dfs(paths[s][v]);
    }
    temppath.pop_back();                       /* 退回上一个结点 */
}

bool cmp(int a, int b)
{
    return weight[a] > weight[b];              /* 进行降序排列 */
}

int main()
{
    cin >> n >> m >> w;
    weight.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    int root, k;
    for(int i = 0; i < m; i++)                                     /* 对生成树进行赋值 */
    {
        scanf("%d %d", &root, &k);
        int temp;
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &temp);
            paths[root].push_back(temp);
        }
        sort(paths[root].begin(), paths[root].end(), cmp);        /* 对根节点的每个子节点根据权重值进行排序（降序） */
    }
    dfs(0);                                                       /* 对生成树进行dfs遍历，并进行处理 */
    for(int i = 0; i < cnt; i++)
    {
        printf("%d", weight[result[i][0]]);
        for(int j = 1; j < result[i].size(); j++)
        {
            printf(" %d", weight[result[i][j]]);
        }
        printf("\n");
    }
    return 0;
}
