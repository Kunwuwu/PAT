#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;                                   /* 主要一开始题目没搞懂，居然忘了度（degree）的意思是什么 */
vector<bool> visited;                                    /* 看了一眼别人的解释，马上就明白了 */
int n, m;
bool flag = true;
int cnt = 0;

void dfs(int v)                                           /* 一个坑点，如果图不连通的话，也是Non-Eulerian */
{
    visited[v] = true;
    for(int w = 0; w < g[v].size(); w++)
    {
        if(!visited[g[v][w]])
            dfs(g[v][w]);
    }
}

int main()
{
    cin >> n >> m;
    int v, w;
    g.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 0; i < m; i++)                            /* 邻接表的形式存储图，便于统计度（degree） */
    {
        scanf("%d %d", &v, &w);
        g[v].push_back(w);
        g[w].push_back(v);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cnt++;
            if(cnt > 1)
                flag = false;
        }
    }
    int cntodd = 0;
    for(int i = 1; i <= n; i++)
    {
        int degree = g[i].size();
        if(degree % 2 != 0)
            cntodd++;
        if(i != 1)
            printf(" %d", degree);
        else
            printf("%d", degree);
    }
    if(cntodd == 0 && flag)
        printf("\nEulerian");
    else if(cntodd == 2 && flag)
        printf("\nSemi-Eulerian");
    else
        printf("\nNon-Eulerian");
    return 0;
}
