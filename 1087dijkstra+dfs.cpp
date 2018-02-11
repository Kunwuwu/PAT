#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, string> numtostr;
map<string, int> strtonum;
const int MAX = 205;
const int inf = 999999999;
int g[MAX][MAX];
int dist[MAX];
bool collected[MAX];
int weight[MAX];
int n, k;
string startcity;
vector<vector<int>> paths;
int startcityid, romeid;
vector<int> tpath, resultpath;
int maxhappy = -1;
int maxavghappy = -1;
int id = 0;
int mincostcnt = 0;

int convert(string city)                                       /* 将城市名称转化成相应的代号，使用map */
{
    int cityid = id;
    id++;
    numtostr[cityid] = city;
    strtonum[city] = cityid;
    return cityid;
}

int findmindist()
{
    int min = -1, mindist = inf;
    for(int i = 0; i < n; i++)
    {
        if(dist[i] < mindist && !collected[i])               /* 忘了验证是否collected */
        {
            min = i;
            mindist = dist[i];
        }
    }
    return min;
}

void dijkstra(int source)                                    /* 这个没什么好说的 */
{
    dist[source] = 0;
    while(1)
    {
        int v = findmindist();
        if(v == -1)
            break;
        collected[v] = true;
        for(int w = 0; w < n; w++)
        {
            if(!collected[w] && g[v][w] != inf)
            {
                if(dist[w] > dist[v] + g[v][w])
                {
                    dist[w] = dist[v] + g[v][w];
                    paths[w].clear();                      /* 如果有更短的路径，清空以前的路径 */
                    paths[w].push_back(v);                 /* 你懂的 */
                }
                else if(dist[w] == dist[v] + g[v][w])      /* 相同最短路径 */
                    paths[w].push_back(v);
            }
        }
    }
}

void dfs(int source)
{
    tpath.push_back(source);
    if(source == startcityid)
    {
        mincostcnt++;                                     /* 统计起点到终点最短路径的数量 */
        int num = tpath.size();
        int thappy = 0;
        int tavghappy = 0;
        for(int i = 0; i < num; i++)
        {
            thappy += weight[tpath[i]];                   /* 记住这是tpath[i]，而不是直接用i，犯了点错误 */
        }
        tavghappy = thappy / (num - 1);                   /* 这里注意num-1，因为起点不算入weight */
        if(thappy > maxhappy)
        {
            maxhappy = thappy;
            resultpath = tpath;
            maxavghappy = tavghappy;
        }
        else if(thappy == maxhappy && tavghappy > maxavghappy)
        {
            maxavghappy = tavghappy;
            resultpath = tpath;
        }
        tpath.pop_back();                                 /* 这个每次都不能忘了 */
        return ;
    }
    for(int i = 0; i < paths[source].size(); i++)
    {
        dfs(paths[source][i]);
    }
    tpath.pop_back();
}

int main()
{
    fill(g[0], g[0] + MAX * MAX, inf);
    fill(dist, dist + MAX, inf);
    paths.resize(MAX);
    cin >> n >> k >> startcity;
    startcityid = convert(startcity);
    for(int i = 0; i < n - 1; i++)
    {
        string tcity;
        int w;
        cin >> tcity >> w;
        int v = convert(tcity);
        weight[v] = w;
    }
    for(int i = 0; i < k; i++)
    {
        int v, w;
        string vv, ww;
        cin >> vv >> ww;
        v = strtonum[vv];
        w = strtonum[ww];
        scanf("%d", &g[v][w]);
        g[w][v] = g[v][w];
    }
    romeid = strtonum["ROM"];
    dijkstra(startcityid);
    dfs(romeid);
    printf("%d %d %d %d\n", mincostcnt, dist[romeid], maxhappy, maxavghappy);
    int size = resultpath.size();
    cout << numtostr[resultpath[size-1]];
    for(int i = size - 2; i >= 0; i--)
    {
        cout << "->" << numtostr[resultpath[i]];
    }
    return 0;
}
