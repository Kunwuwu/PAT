#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 10001;                               

vector<vector<int>> g(MAX);                               /* 一开始想用邻接表，然后dijkstra求，但是越做越感觉会超时 */
vector<int> tpath, result;                                /* 其实邻接表的话，明明dfs更合适啊，dijkstra肯定超时 */
int line[MAX][MAX];                                       /* 我明明记得以前开500*500的二维数组就会爆栈的 */
int n;                                                    /* 这个line的操作是参考柳婼小姐姐的，真的很棒 */
int s, d, q;
int minlines, minstas;
bool visited[MAX];
int getlines(vector<int> v)                               /* 这个的话是根据前面那个line二维数组，求换乘的站个数 */
{
    set<int> s;
    for(int i = 1; i < v.size(); i++)
    {
        int tline = line[v[i]][v[i-1]];
        s.insert(tline);
    }
    return s.size();
}

void dfs(int v)                                           /* dfs的回溯剪枝 */
{
    tpath.push_back(v);
    if(v == d)
    {
        int tstas = tpath.size(), tlines = getlines(tpath);
        if(tstas < minstas)                               /* 条件一：经过点最少的路径 */
        {
            minstas = tpath.size();
            result = tpath;
            minlines = tlines;
        }
        else if(tstas == minstas)                         /* 条件二：换乘最少的路径 */
        {
            if(tlines < minlines)
            {
                result = tpath;
                minlines = tlines;
            }
        }
        tpath.pop_back();
        return ;
    }
    for(int i = 0; i < g[v].size(); i++)
    {
        int w = g[v][i];
        if(!visited[w])
        {
            visited[w] = true;                            /* 这个也是参考柳婼的，简直递归神技能，可以避免每次fill的耗时啊 */
            dfs(w);
            visited[w] = false;                           /* 如果每次求都对visited初始化，可能会超时 */
        }
    }
    tpath.pop_back();
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int start, next, k;
        scanf("%d %d", &k, &start);
        for(int j = 2; j <= k; j++)
        {
            scanf("%d", &next);
            line[start][next] = line[next][start] = i;    /* 记录相邻两个点间的线路，简直神技，困扰我好久，一直不知道怎么唯一确定地铁线路 */
            g[start].push_back(next);                     /* 邻接表啊邻接表 */
            g[next].push_back(start);
            start = next;
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &s, &d);
        minlines = MAX, minstas = MAX;        
        dfs(s);
        printf("%d\n", result.size() - 1);                                
        int preline = line[result[0]][result[1]];
        printf("Take Line#%d from %04d to", preline, result[0]);        /* 这有点坑，最后点一直过不了，才发现忘了四位输出格式了 */
        for(int j = 0; j < result.size() - 1; j++)
        {
            if(line[result[j]][result[j+1]] != preline)
            {
                printf(" %04d.\n", result[j]);            /* 这有个点. */
                preline = line[result[j]][result[j+1]];
                printf("Take Line#%d from %04d to", preline, result[j]); 
            }
        }
        printf(" %04d.\n", d);
    }
    return 0;
}
