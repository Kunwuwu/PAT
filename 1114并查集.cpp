#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10000;

typedef struct
{
    int id, fid, mid, me, area;
    vector<int> cid;
}data[MAX];                                               /* 输入数据源结构体 */

typedef struct
{
    int id, people;
    double avgsets, avgarea;
    bool flag;
}ans;                                                     /* 输出数据结构体 */

data datas;
vector<ans> anss(MAX);
int n, cnt = 0;
int father[MAX];
bool visited[MAX];

int tfind(int x)                                         /* 找到集合中的老大 */
{
    while(x != father[x])
        x = father[x];
    return x;
}

void tunion(int a, int b)                               /* 找到各自的老大，比较id大小后合并 */
{
    int fa = tfind(a);
    int fb = tfind(b);
    if(fa < fb)
        father[fb] = fa;
    else if(fa > fb)
        father[fa] = fb;
}

bool cmp(ans a, ans b)
{
    if(a.avgarea != b.avgarea)
        return a.avgarea > b.avgarea;
    else
        return a.id < b.id;
}

int main()
{
    cin >> n;
    int k;
    for(int i = 0; i < MAX; i++)
        father[i] = i;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &datas[i].id, &datas[i].fid, &datas[i].mid, &k);
        visited[datas[i].id] = true;                      /* visited数组可以计算是否需要统计这个人people */
        datas[i].cid.resize(k);
        if(datas[i].fid != -1)
        {
            visited[datas[i].fid] = true;
            tunion(datas[i].fid, datas[i].id);            /* 将两人合并（连接老大的方式） */
        }
        if(datas[i].mid != -1)
        {
            visited[datas[i].mid] = true;
            tunion(datas[i].mid, datas[i].id);
        }
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &datas[i].cid[j]);
            visited[datas[i].cid[j]] = true;
            tunion(datas[i].cid[j], datas[i].id);
        }
        scanf("%d %d", &datas[i].me, &datas[i].area);     /* 记录数据 */
    }
    for(int i = 0; i < n; i++)
    {
        if(visited[datas[i].id])                          /* 对于标记访问过的id */
        {
            int fa = tfind(datas[i].id);                  /* 找到老大，将其房产加在老大那 */
            anss[fa].avgsets += (double)datas[i].me;
            anss[fa].id = fa;
            anss[fa].avgarea += (double)datas[i].area;
            anss[fa].flag = true;
        }
    }
    for(int i = 0; i < MAX; i++)
    {
        if(visited[i])                                    /* 对于每个标记过的id，找到老大，老大的小弟数++ */
        {
            int fa = tfind(i);
            anss[fa].people++;
        }
        if(anss[i].flag)                                  /* 记录家庭的个数 */
            cnt++;
    }
    for(int i = 0; i < MAX; i++)
    {
        if(anss[i].flag)
        {
            anss[i].avgsets = anss[i].avgsets / anss[i].people;
            anss[i].avgarea = anss[i].avgarea / anss[i].people;
        }
    }
    sort(anss.begin(), anss.end(), cmp);
    cout << cnt << endl;
    for(int i = 0; i < MAX; i++)
    {
        if(anss[i].flag)
            printf("%04d %d %.3lf %.3lf\n", anss[i].id, anss[i].people, anss[i].avgsets, anss[i].avgarea);
    }
    return 0;
}
