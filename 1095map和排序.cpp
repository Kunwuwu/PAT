#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

typedef struct
{
    string plateid;
    int time;
    bool empty;
}rec;                                                                       /* 停车记录的结构体 */

map<string, vector<rec>> plate;
vector<rec> recs;
vector<int> prs;
int n, m;
vector<string> result;
int maxtime = 0;

bool cmp1(rec a, rec b)                                                    /* 停车记录排序 */
{
    return a.time < b.time;
}


int main()
{
    cin >> n >> m;
    int hh, mm, ss;
    rec trec;
    for(int i = 0; i < n; i++)
    {
        string id;
        char ioro[5];
        cin >> id;
        scanf("%d:%d:%d %s", &hh, &mm, &ss, ioro);                        /* 尽量用char数组，会快一点 */
        trec.time = hh * 3600 + mm * 60 + ss;
        if(ioro[0] == 'i') trec.empty = false;                            /* 每条记录的empty属性 */
        else trec.empty = true;                                           /* true表示这个记录之后，车位就空了（车出来了） */
        trec.plateid = id;
        recs.push_back(trec);                                             /* 将这条记录加入到recs向量中 */
    }
    sort(recs.begin(), recs.end(), cmp1);                                 /* 所有记录按时间排序 */
    for(int i = 0; i < n; i++)
    {
        string id = recs[i].plateid;                                      /* 。。。 */
        if(plate[id].size() % 2 == 0 && !recs[i].empty)                   /* 如果这个车位是空的（size是2的倍数） */
            plate[id].push_back(recs[i]);                                 /* 如果这条记录是in，则进入车位 */
        else if(plate[id].size() % 2 == 1)                                /* 同上 */
        {
            if(recs[i].empty)
            {
                plate[id].push_back(recs[i]);
                int index = plate[id].size() - 1;
                prs.push_back(plate[id][index - 1].time);                 /* 将成对的两条记录放入prs向量中 */
                prs.push_back(plate[id][index].time);
            }
            else
            {
                plate[id].pop_back();
                plate[id].push_back(recs[i]);
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh * 3600 + mm * 60 + ss;
        int cnt = 0;
        int index = 1;
        int len = prs.size();
        bool flag = false;
        for(int j = index; j < len; j += 2)                               /* 防止超时的关键：prs中进入车位的时间是升序的 */
        {                                                                 /* 而查询序列也是升序的，index记录的作用防止超时 */
            if(time < prs[j] && time >= prs[j-1])
            {
                if(!flag)
                    index = j;
                flag = true;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    for(auto it = plate.begin(); it != plate.end(); it++)                 /* 遍历车位的每两条记录，计算停车最长的车位和时间 */
    {
        int tmaxtime = 0;
        int len = (*it).second.size();
        if(len > 0)
        {
            for(int j = 1; j < len; j += 2)
            {
                tmaxtime += (*it).second[j].time - (*it).second[j-1].time;
            }
        }
        if(tmaxtime > maxtime)
        {
            result.clear();
            maxtime = tmaxtime;
            result.push_back((*it).first);
        }
        else if(tmaxtime == maxtime)
            result.push_back(((*it).first));
    }
    for(auto it = result.begin(); it != result.end(); it++)
        cout << (*it) << " ";
    printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
    return 0;
}
