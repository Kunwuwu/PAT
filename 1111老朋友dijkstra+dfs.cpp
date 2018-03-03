#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int inf = 999999999;
const int MAX = 505;

int gdist[MAX][MAX];
int gtime[MAX][MAX];
int dist[MAX];
int times[MAX];
bool collected[MAX];
vector<vector<int>> timetree;
vector<vector<int>> disttree;
vector<int> tpath, timepath, distpath;
int mintime = inf;
int mindot = inf;

int s, d, n, m;

int findmindist()
{
    int v = -1, mindist = inf;
    for(int i = 0; i < n; i++)
    {
        if(!collected[i] && dist[i] < mindist)
        {
            mindist = dist[i];
            v = i;
        }
    }
    return v;
}

void dijkstradist(int source)
{
    dist[source] = 0;
    while(true)
    {
        int v = findmindist();
        if(v == -1)
            break;
        collected[v] = true;
        for(int w = 0; w < n; w++)
        {
            if(!collected[w] && gdist[v][w] != inf)
            {
                if(dist[w] > dist[v] + gdist[v][w])
                {
                    dist[w] = dist[v] + gdist[v][w];
                    disttree[w].clear();
                    disttree[w].push_back(v);
                }
                else if(dist[w] == dist[v] + gdist[v][w])
                    disttree[w].push_back(v);
            }
        }
    }
}

int findmintime()
{
    int v = -1, mintime = inf;
    for(int i = 0; i < n; i++)
    {
        if(!collected[i] && times[i] < mintime)
        {
            mintime = times[i];
            v = i;
        }
    }
    return v;
}

void dijkstratime(int source)
{
    times[source] = 0;
    while(true)
    {
        int v = findmintime();
        if(v == -1)
            break;
        collected[v] = true;
        for(int w = 0; w < n; w++)
        {
            if(!collected[w] && gtime[v][w] != inf)
            {
                if(times[w] > times[v] + gtime[v][w])
                {
                    times[w] = times[v] + gtime[v][w];
                    timetree[w].clear();
                    timetree[w].push_back(v);
                }
                else if(times[w] == times[v] + gtime[v][w])
                    timetree[w].push_back(v);
            }
        }
    }
}

void dfsdist(int source)
{
    tpath.push_back(source);
    if(source == s)
    {
        int totaltime = 0;
        for(int i = 1; i < tpath.size() ; i += 1)
            totaltime += gtime[tpath[i]][tpath[i-1]];     /* 计算总时间，记得tpath是倒序的 */
        if(totaltime < mintime)
        {
            mintime = totaltime;
            distpath = tpath;
        }
        tpath.pop_back();
        return ;
    }
    else
    {
        for(int i = 0; i < disttree[source].size(); i++)
            dfsdist(disttree[source][i]);
    }
    tpath.pop_back();
}

void dfstime(int source)
{
    tpath.push_back(source);
    if(source == s)
    {
        if(tpath.size() < mindot && !tpath.empty())
        {
            mindot = tpath.size();
            timepath = tpath;
        }
        tpath.pop_back();
        return ;
    }
    else
    {
        for(int i = 0; i < timetree[source].size(); i++)
            dfstime(timetree[source][i]);
    }
    tpath.pop_back();
}

int main()
{
    fill(dist, dist + MAX, inf);
    fill(times, times + MAX, inf);
    fill(gdist[0], gdist[0] + MAX * MAX, inf);
    fill(gtime[0], gtime[0] + MAX * MAX, inf);            /* 初始化就不谈了 */
    cin >> n >> m;
    disttree.resize(n);
    timetree.resize(n);
    int v, w, oneway, length, ttime;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d %d", &v, &w, &oneway, &length, &ttime);
        if(oneway == 1)                                   /* one-way一开始我就觉得是单向，果然是哈哈 */
        {
            gdist[v][w] = length;
            gtime[v][w] = ttime;
        }
        else
        {
            gdist[v][w] = gdist[w][v] = length;
            gtime[w][v] = gtime[v][w] = ttime;
        }
    }
    cin >> s >> d;
    dijkstradist(s);                                      /* 首先利用dijkstra求最短路径，会生成一棵树（disttree） */
    fill(collected, collected + MAX, false);
    dijkstratime(s);                                      /* 再用dijkstra求最短时间，也会生成一棵树（timetree） */
    dfsdist(d);                                           /* 对生成树disttree深搜，找到最短路径中时间最少的 */
    tpath.clear();
    dfstime(d);                                           /* 对生成树timetree深搜，找到最短时间路径中，经过点最少的 */
    printf("Distance = %d", dist[d]);
    if(timepath != distpath)
    {
        int last = distpath.size() - 1;
        printf(": %d", distpath[last]);
        for(int i = last - 1; i >= 0; i--)
            printf(" -> %d", distpath[i]);
        printf("\n");
    }
    else
        printf("; ");
    int last = timepath.size() - 1;
    printf("Time = %d: %d", times[d], timepath[last]);
    for(int i = last - 1; i >= 0; i--)
        printf(" -> %d", timepath[i]);
    return 0;
}
