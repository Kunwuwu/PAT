#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10002;

typedef struct
{
    int c, d;
}ans;

vector<vector<int>> tree(MAX);                            /* 邻接表，存储每个人的朋友，当数据量大的时候用邻接表 */  
vector<ans> anss;                                         /* 存储查询结果的 */
ans tans;
char gender[MAX];                                         /* 记录性别 */
bool visited[MAX];
int n, m, q;
int a, b;
vector<int> tpath;                                        /* 每次深搜的记录 */

bool cmp(ans r, ans s)                                    /* 排序规则 */
{
    if(r.c != s.c)
        return r.c < s.c;
    else
        return r.d < s.d;
}

void dfs(int one, int level)                              /* dfs，剪枝 */
{
    tpath.push_back(one);
    if(level == 4 && one == b)                            /* 如果最后联系上了对方 */
    {
        tans.c = tpath[1];                                /* 处理 */
        tans.d = tpath[2];
        anss.push_back(tans);
        tpath.pop_back();
        return ;
    }
    for(int i = 0; i < tree[one].size(); i++)             /* 这里比较巧妙，总共经过四个人，前两人性别必须相同，后两人也是的 */
    {
        int two = tree[one][i];
        if(!visited[two])                                 /* 开始的时候这个忘判断了，只能得22分 */
        {
            if(level == 1 && gender[one] == gender[two])
            {
                visited[two] = true;
                dfs(two, level + 1);
                visited[two] = false;
            }
            else if(level == 2 && gender[b] == gender[two])
            {
                visited[two] = true;
                dfs(two, level + 1);
                visited[two] = false;
            }
            else if(level == 3 && two == b)               /* 到第三个人的时候可以直接找对象b了 */
            {
                visited[two] = true;
                dfs(two, level + 1);
                visited[two] = false;
            }
        }
    }
    tpath.pop_back();
}


int main()
{
    cin >> n >> m;
    char as[6], bs[6];
    for(int i = 0; i < m; i++)
    {
        scanf("%s %s", as, bs);
        sscanf(as, "%d", &a);                             /* 这里参考柳婼，因为对于整数输入，-0和0都是0，没有符号 */
        sscanf(bs, "%d", &b);
        if(a < 0 || as[0] == '-')
        {
            a = abs(a);
            gender[a] = 'f';
        }
        else
            gender[a] = 'm';
        if(b < 0 || bs[0] == '-')
        {
            b = abs(b);
            gender[b] = 'f';
        }
        else
            gender[b] = 'm';
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        scanf("%d %d", &a, &b);
        a = abs(a);
        b = abs(b);
        visited[a] = true;
        dfs(a, 1);
        sort(anss.begin(), anss.end(), cmp);
        visited[a] = false;                               /* 第一个点的访问记录 */
        printf("%d\n", anss.size());
        for(int i = 0; i < anss.size(); i++)
        {
            printf("%04d %04d\n", anss[i].c, anss[i].d);
        }
        tpath.clear();
        anss.clear();
    }
    return 0;
}
