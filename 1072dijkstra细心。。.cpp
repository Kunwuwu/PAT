#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const int MAX = 1020;
const int inf = 999999999;
int edge[MAX][MAX];
bool collected[MAX];
int dist[MAX];
int n, m, k;
double ds;
map<string, int> gtonum;                                     /* 将加油站点转化成数字，便于求最短距离 */
map<int, string> numtog;                                     /* 将数字化的加油站点转化回G1、G2。。。 */
string stas[] = {"G1", "G2", "G3", "G4", "G5", "G6", "G7", "G8", "G9", "G10"};

void initmap()
{
    int index = 0;
    for(int i = 1001; i <= 1010; i++)
    {
        gtonum[stas[index]] = i;
        numtog[i] = stas[index];
        index++;
    }
}

int findmindist(int source)
{
    int min = -1, mindist = inf;
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] < mindist && !collected[i])
        {
            min = i;
            mindist = dist[i];
        }
    }
    for(int i = 1001; i <= m + 1000; i++)
    {
        if(dist[i] < mindist && !collected[i])
        {
            min = i;
            mindist = dist[i];
        }
    }
    return min;
}

double dijkstra(int source)
{
    fill(dist, dist + MAX, inf);
    fill(collected, collected + MAX, false);
    dist[source] = 0;
    double tminimum = inf;
    while(true)
    {
        int v = findmindist(source);
        if(v == -1)
            break;
        collected[v] = true;
        for(int w = 1; w <= n; w++)
        {
            if(!collected[w] && dist[w] > dist[v] + edge[v][w])
            {
                dist[w] = dist[v] + edge[v][w];
                if(dist[w] < tminimum)                                /* 直接在dijkstra里面取得的最小距离点的距离 */
                    tminimum = dist[w];
            }
        }
        for(int w = 1001; w <= 1000 + m; w++)
        {
            if(!collected[w] && dist[w] > dist[v] + edge[v][w])
            {
                dist[w] = dist[v] + edge[v][w];                      /* 遍历各个加油站候选址的时候，不用计算最小距离点 */
            }
        }
    }
    return tminimum;
}

int strtoindex(string num)                                                  /* 将数字字符串变成数字，好像有这么个函数 */
{                                                                           /* 可能是重复造轮子了，等会试试看 */
    int ans = 0;
    int len = num.length();
    for(int i = 0; i < len; i++)
    {
        ans += (num[i] - '0') * pow(10, len - i - 1);
    }
    return ans;
}

int main()
{
    cin >> n >> m >> k >> ds;                                                 /* 输入 */
    initmap();
    fill(dist, dist + MAX, inf);
    fill(edge[0], edge[0] + MAX * MAX, inf);                                  /* 初始化 */
    for(int i = 0; i < k; i++)                                                /* 输入图的各条边 */
    {
        string from, to;
        int a, b, dis;
        cin >> from >> to;
        scanf("%d", &dis);
        if(from[0] == 'G')
            a = gtonum[from];
        else
            a = strtoindex(from);
        if(isalpha(to[0]))
            b = gtonum[to];
        else
            b = strtoindex(to);
        edge[a][b] = edge[b][a] = dis;                                       
    }
    double minimum = -1;
    bool hassolution = false;
    int sta;
    double minavg = inf;
    for(int i = 1001; i <= 1000 + m; i++)
    {
        double tminimum = dijkstra(i);
        bool flag = true;
        for(int j = 1; j <= n; j++)                                           /* 求下最远距离点，判断是否在服务范围内 */
        {
            if(dist[j] > ds)
            {
                flag = false;
                break;
            }
        }
        double avg = 0.0;
        for(int j = 1; j <= n; j++)                                          /* 计算平均距离 */
        {
            avg += 1.0 * dist[j];
        }
        avg /= n;
        if(flag && tminimum > minimum)                                       /* 求得不同加油站点的最短距离中的最远距离 */
        {
            minimum = tminimum;
            hassolution = true;
            sta = i;
            minavg = avg;
        }
        else if(tminimum == minimum && flag)                                 /* 如果这个最远距离不止一个 */
        {
            if(avg < minavg)                                                 /* 求平均距离最小的一个 */
            {
                hassolution = true;
                minavg = avg;
                sta = i;
            }
        }
    }
    if(hassolution)                                                          /* 有解无解？ */
    {
        cout << numtog[sta] << endl;
        printf("%.1lf %.1lf", minimum, minavg);
    }
    else
        cout << "No Solution";
    return 0;
}
