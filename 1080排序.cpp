#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int id;
    int ge, gi;
    int rank;
    double final;
    vector<int> school;
}app;

typedef struct
{
    int quota, lastrank;
    vector<int> apps;                                          /* 原来用的不是int，而是app，会超时，估计是排序的锅 */
}school;

vector<school> schs;
vector<app> stus;
int n, m, k;

bool cmp1(app a, app b)
{
    if(a.final != b.final)
        return a.final > b.final;
    else
        return a.ge > b.ge;
}

int main()
{
    cin >> n >> m >> k;
    schs.resize(m);
    stus.resize(n);
    int tquota;
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &tquota);
        schs[i].quota = tquota;
        schs[i].lastrank = -1;
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &stus[i].ge, &stus[i].gi);
        stus[i].school.resize(k);
        for(int j = 0; j < k; j++)
            scanf("%d", &stus[i].school[j]);
        stus[i].id = i;
        stus[i].final = (stus[i].gi + stus[i].ge) / 2.0;
    }
    sort(stus.begin(), stus.end(), cmp1);
    stus[0].rank = 1;
    for(int i = 1; i < n; i++)
    {
        if(stus[i].ge == stus[i-1].ge && stus[i].final == stus[i-1].final)
            stus[i].rank = stus[i-1].rank;
        else
            stus[i].rank = i + 1;
    }
    for(int i = 0; i < n; i++)                              /* 开始是根据院校录取的，可是发现学生会被重复录取 */
    {                                                       /* 然后看了下柳婼的思路，可以根据排序后的学生录取，这样不会重复 */
        for(int j = 0; j < k; j++)
        {
            int tsch = stus[i].school[j];
            if(schs[tsch].apps.size() < schs[tsch].quota)   /* 分两种情况，第一种就是这个学校的名额是够的，可以直接录取 */
            {
                schs[tsch].apps.push_back(stus[i].id);
                schs[tsch].lastrank = stus[i].rank;
                break;                                      /* 如果录取了，则直接break，避免重复录取 */
            }
            else                                            /* 第二种就是学校名额满了，但是这个人排名和录取的最后一名排名一样 */
            {                                               /* 也要被录取 */
                if(schs[tsch].lastrank == stus[i].rank)
                {
                    schs[tsch].apps.push_back(stus[i].id);
                    break;
                }
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        sort(schs[i].apps.begin(), schs[i].apps.end());
        for(int j = 0; j < schs[i].apps.size(); j++)
        {
            if(j != 0)
                printf(" ");
            printf("%d", schs[i].apps[j]);
        }
        printf("\n");
    }
    return 0;
}
