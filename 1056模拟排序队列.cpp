#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct
{
    int weight;
    int idnum;
    int index;
    int rank;
}mouse;

vector<mouse> ms;
int n, m;

bool cmp(mouse a, mouse b)
{
    return a.idnum < b.idnum;
}

int main()
{
    cin >> n >> m;
    ms.resize(n);
    vector<int> w(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    int idnum;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &idnum);
        ms[i].idnum = idnum;
        ms[i].weight = w[idnum];
        ms[i].index = i;
    }
    queue<mouse> qm;
    for(int i = 0; i < n; i++)
    {
        qm.push(ms[i]);
    }
    while(!qm.empty())
    {
        int groups = qm.size()/ m;        /* 计算可以组成多少个队 */
        int plus = qm.size() - groups * m;
        if(plus == 0)
            plus = m;
        else
            groups += 1;                 /* 整除嘛，你懂的 */
        for(int i = 0; i < groups; i++)    /* 遍历处理每个组 */
        {
            int cnt = 0;                             /* 计数，多少人组成一个队 */
            int maxweight = -1;
            int maxindex = -1;
            while(cnt < m)                           /* 找到每个组最重的老鼠 */
            {
                if(i == groups - 1 && cnt >= plus)  /* 最后一个组的时候注意 */
                    break;
                mouse temp =  qm.front();
                ms[temp.index].rank = groups + 1;             /* 每个鼠的排名进行更新哇 */
                qm.pop();
                cnt++;
                if(temp.weight > maxweight)
                {
                    maxweight = temp.weight;
                    maxindex = temp.index;
                }
            }
            if(qm.empty())                        /* 最后一组的话，计算出来的max就是第一，就不同push啦 */
            {
                ms[maxindex].rank = 1;
                break;
            }
            qm.push(ms[maxindex]);               /* 将每个组最重的拿个鼠push进队列 */
        }
    }
    sort(ms.begin(), ms.end(), cmp);
    cout << ms[0].rank;
    for(int i = 1; i < n; i++)
        printf(" %d", ms[i].rank);
    return 0;
}
