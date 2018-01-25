#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int inf = 99999999;
const int MAX = 505;

int n, m, s, d;
int dist[MAX];
int edge[MAX][MAX];
int cost[MAX][MAX];
vector<int> paths[MAX];
bool collected[MAX];
vector<int> result, temppath;
int mincost = inf;

int findmindist(int source)
{
    int min = source, mindist = inf;
    for(int i = 0; i < n; i++)
    {
        if(!collected[i] && dist[i] < mindist)
        {
            min = i;
            mindist = dist[i];
        }
    }
    return min;
}


void dijkstra(int source)
{
    dist[source] = 0;
    for(int i = 0; i < n; i++)
    {
        int min = findmindist(source);
        collected[min] = true;
        for(int w = 0; w < n; w++)
        {
            if(!collected[w] && edge[min][w] < inf)
            {
                if(dist[w] > dist[min] + edge[min][w])                    /* 生成多条路径paths，感觉像棵树 */
                {
                    dist[w] = dist[min] + edge[min][w];
                    paths[w].clear();                                     /* 细节，如果有更短的路径，重置改点的path */
                    paths[w].push_back(min);
                }
                else if(dist[w] == dist[min] + edge[min][w])
                {
                    paths[w].push_back(min);
                }
            }
        }
    }
}

void dfs(int source)
{
    temppath.push_back(source);
    if(source == s)                                /* 整个路径是从d往回到s的 */
    {
        int tempcost = 0;
        for(int i = 0; i < temppath.size() - 1; i++)         /* 计算整个路径的花费，与最少花费比较 */
        {
            tempcost += cost[temppath[i]][temppath[i+1]];
        }
        if(tempcost < mincost)
        {
            mincost = tempcost;
            result = temppath;
        }
        temppath.pop_back();                                /* 这里的pop和return都不能少呢 */
        return ;
    }
    for(int w = 0; w < paths[source].size(); w++)
        dfs(paths[source][w]);
    temppath.pop_back();                                    /* 与上面的pop类似，既然这条路走到头，自然返回上个点 */
}


int main()
{
    cin >> n >> m >> s >> d;
    int v, w;
    fill(edge[0], edge[0] + MAX * MAX, inf);
    fill(cost[0], cost[0] + MAX * MAX, inf);
    fill(dist, dist + MAX, inf);
    for(int i = 0; i < m; i++)
    {
        cin >> v >> w;
        cin >> edge[v][w] >> cost[v][w];
        edge[w][v] = edge[v][w];
        cost[w][v] = cost[v][w];
    }
    dijkstra(s);                                     /* dijkstra都是老套路了 */
    dfs(d);                                          /* dfs+dijkstra，30分题的老套路 */
    for(int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";
    cout << dist[d] << " ";
    cout << mincost;
    return 0;
}
