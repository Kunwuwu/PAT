#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

// 全局变量的定义
int c, n, s, m;
int capacity[505];
int map[505][505];
const int MAX = 99999999;
int dist[505];
vector<int> path[505];
vector<int> tempPath, minPath;
bool vistied[505];
int minBack = MAX, minNeed = MAX;


// 函数原型
int FindMinDist();
void Dijkstra(int source);
void dfs(int source);

int main()
{
    cin >> c >> n >> s >> m;
    fill(capacity, capacity + 505, 0);                              /* 全局变量的初始化 */
    fill(map[0], map[0] + 505 * 505, MAX);
    fill(vistied, vistied + 505, false);
    fill(dist, dist + 505, MAX);
    for(int i = 1; i <= n; i++)
    {
        int weight;
        cin >> weight;
        capacity[i] = weight - c / 2;
    }
    for(int i = 0; i < m; i++)
    {
        int v, w, weight;
        cin >> v >> w >> weight;
        map[v][w] = weight;
        map[w][v] = weight;
    }
    Dijkstra(0);
    dfs(s);
    printf("%d 0", minNeed);
    for(int i = minPath.size() - 2; i >= 0; i--)
    {
        cout << "->" << minPath[i];
    }
    cout << " " << minBack << endl;
    return 0;
}

int FindMinDist()
{
    int minDist = MAX;
    int min = -1;
    for(int i = 0; i <= n; i++)
    {
        if(!vistied[i] && dist[i] < minDist)
        {
            min = i;
            minDist = dist[i];
        }
    }
    return min;
}

void Dijkstra(int source)
{
    dist[source] = 0;
    for(int i = 0; i < n; i++)
    {
        int v = FindMinDist();
        if(v == -1)                              /* 如果不存在这样的最小距离点，则退出 */
            break;
        vistied[v] = true;
        for(int w = 0; w <= n; w++)
        {
            if(!vistied[w] && map[v][w] != MAX)
            {
                if( dist[v] + map[v][w] < dist[w])
                {
                    dist[w] = dist[v] + map[v][w];
                    path[w].clear();
                    path[w].push_back(v);
                }
                else if(dist[v] + map[v][w] == dist[w])     /* 这个是解决这个问题的主要办法，等会再看 */
                {
                    path[w].push_back(v);
                }
            }
        }
    }
}

void dfs(int source)                           /* 其实就是树的dfs遍历（先序遍历） */
{
    tempPath.push_back(source);
    if(source == 0)
    {
        int back = 0, need = 0;
        for(int i = tempPath.size() - 1; i >= 0; i--)  /* 思路就是模拟从pbmc开始从0点往前走，所以是i-- */
        {     /* 因为只能往前走，所以capcity < 0的点只能依靠从pbmc带出来进行补充，capacity > 0 的点只能从该点再带出来 */
            int id = tempPath[i];
            if(capacity[id] > 0)           /* 如果这个点的自行车数量高于最佳状态 */
                back += capacity[id];      /* 则pbmc需要收回的自行车数量增加 */
            else          /* 如果这个点的自行车数量低于或者等于最佳状态 */
            {
                if (back > (0 - capacity[id]))   /* 如果前面点多余的车辆能够补上这个点缺少的 */
                {
                    back += capacity[id];        /* 继续更新back */
                }
                else                             /* 如果补不上，则要need增加，将back即能够带回去的置零 */
                {
                    need += (0 - (capacity[tempPath[i]] + back));      /* 更新need */
                    back = 0;                                /* back置零 */
                }
            }
        }
        if(need < minNeed)               /* 注意minNeed和minBack同时更新，最后更新最短路径minPath */
        {
            minNeed = need;
            minBack = back;
            minPath = tempPath;
        }
        else if(need == minNeed && back < minBack)
        {
            minBack = back;
            minNeed = need;
            minPath = tempPath;
        }
        tempPath.pop_back();            /* 因为是递归深度优先遍历，所以将路径退回到上一个点 */
        return ;
    }
    for(int v = 0; v < path[source].size(); v++)
    {
        dfs(path[source][v]);
    }
    tempPath.pop_back();            /* 因为是递归深度优先遍历，所以将路径退回到上一个点 */
}
