#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 全局变量的定义及初始化
typedef struct
{
    int arrivetime;
    int playtime;
    bool isvip;
    int starttime;
}player;

typedef struct
{
    int poptime = 8 * 3600, servenum = 0;
    bool isvip;
}table;

vector<player> players;
vector<table> tbs;

int n, k, m;

// 函数原型
bool cmp1(player a, player b);
bool cmp2(player a, player b);
int mintb();                     /* 查找最先空出来的桌子 */
int findnextvip(int vipid);
void alloctable(int playerid, int tableid);
int minviptb();

int main()
{
    cin >> n;
    player tplayer;
    int hh, mm, ss, tstime, isvip;
    for(int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> tstime >> isvip;
        tplayer.arrivetime = hh * 3600 + mm * 60 + ss;
        tplayer.playtime = tstime > 120 ? 7200 : 60 * tstime;  /* 大于两个小时按两个小时算 */
        tplayer.isvip = ((isvip == 1) ? true : false);
        tplayer.starttime = 3600 * 21;                    /* 标记某些无法等到桌子的用户 */
        if(tplayer.arrivetime < 21 * 3600)      /* 坑点：题目说open...while..8:00-21:00。。。不包括21点，为了这个纠结了一天 */
            players.push_back(tplayer);
    }
    cin >> k >> m;
    tbs.resize(k + 1);
    int viptable;
    for(int i = 0; i < m; i++)
    {
        cin >> viptable;
        tbs[viptable].isvip = true;
    }
    sort(players.begin(), players.end(), cmp1);         /* 将所有玩家排序 */
    int index = 0, vipid = -1;
    vipid = findnextvip(vipid);
    while(index < players.size())                          /* 遍历队列中的每个人 */
    {
        int min = mintb();                             /* 找出最先空闲的桌子 */
        if(tbs[min].poptime >= 21 * 3600)              /* 如果最先空闲的桌子空闲时间已经过了21:00，则直接退出 */
            break;
        if(players[index].isvip && index < vipid)      /* 这里考虑了很久。。如果这个vip用户前面已经分配过桌子了，就跳过 */
        {                                              /* players[index].isvip&&index < vipid 表示这个vip已经玩过了 */
            index++;
            continue;
        }
        if(tbs[min].isvip)                             /* 如果最先空闲的桌子是vip桌 */
        {
            if(players[index].isvip)                   /* 如果队首的就是vip */
            {
                alloctable(index, min);
                if(vipid == index)
                    vipid = findnextvip(vipid);
                index++;
            }                                          /* 如果队首的不是vip */
            else
            {
                if(vipid < players.size() && players[vipid].arrivetime <= tbs[min].poptime)
                {                                      /* （vip桌）如果这个vip在等待的队列中 */
                    if(players[vipid].isvip)
                        alloctable(vipid, min);            /* 给vip分配桌子 */
                    else
                        alloctable(index, min);
                    vipid = findnextvip(vipid);        /* 更新vip */
                }
                else                                   /* 如果等待的队列中没有vip，直接把VIP桌子分配给index用户 */
                {
                    alloctable(index, min);
                    index++;
                }
            }
        }
        else                                           /* 如果最先空闲的桌子不是vip桌子 */
        {
            if(players[index].isvip)                   /* 如果这个用户是vip用户 */
            {
                int vipmin = minviptb();               /* 查找最先空闲的vip桌 */
                if(vipmin != -1 && players[index].arrivetime >= tbs[vipmin].poptime)
                {                                      /* 如果有vip桌空闲 */
                    alloctable(index, vipmin);
                    if(index == vipid)
                        vipid = findnextvip(vipid);
                    index++;
                }
                else                                   /* 如果没有vip桌空闲，直接分配给最先空闲的桌子 */
                {
                    alloctable(index, min);
                    if(vipid == index)
                        vipid = findnextvip(vipid);
                    index++;
                }
            }
            else                                       /* 如果队首不是vip */
            {
                alloctable(index, min);                /* 直接分配给最先空闲的桌子 */
                index++;
            }
        }
    }
    sort(players.begin(), players.end(), cmp2);
    for(int i = 0; i < players.size() && players[i].starttime < 3600 * 21; i++)
    {
        printf("%02d:%02d:%02d ", players[i].arrivetime / 3600, (players[i].arrivetime % 3600) / 60, players[i].arrivetime % 60 );
        printf("%02d:%02d:%02d ", players[i].starttime / 3600, (players[i].starttime % 3600) / 60, players[i].starttime % 60 );
        printf("%.0f\n", round((players[i].starttime - players[i].arrivetime) / 60.0));  /* 注意round其实返回的是浮点数 */
    }
    for(int i = 1; i <= k; i++)
    {
        if(i != 1)
            cout << " ";
        printf("%d", tbs[i].servenum);
    }
    return 0;
}

bool cmp1(player a, player b)    /* 降序排列，让最先来的在队的尾部，方便pop */
{
    return a.arrivetime < b.arrivetime;
}

int mintb()
{
    int min = -1, mintime = 999999999;
    for(int i = 1; i <= k; i++)
    {
        if(tbs[i].poptime < mintime)
        {
            min = i;
            mintime = tbs[i].poptime;
        }
    }
    return min;
}

int findnextvip(int vipid)
{
    vipid++;
    while(vipid < players.size() && !players[vipid].isvip)
        vipid++;
    return vipid;
}

void alloctable(int playerid, int tableid)
{
    if(players[playerid].arrivetime > tbs[tableid].poptime)      /* 分两种情况，桌子先空闲，人再到 */
    {
        players[playerid].starttime = players[playerid].arrivetime;
    }
    else                                                        /* 人到了，但桌子不空闲，需要等 */
    {
        players[playerid].starttime = tbs[tableid].poptime;
    }
    tbs[tableid].poptime = players[playerid].starttime + players[playerid].playtime;
    tbs[tableid].servenum++;
}

int minviptb()
{
    int min = -1, minviptime = 999999999;
    for(int i = 1; i <= k; i++)
    {
        if(tbs[i].poptime < minviptime && tbs[i].isvip)
        {
            min = i;
            minviptime = tbs[i].poptime;
        }
    }
    return min;
}

bool cmp2(player a, player b)
{
    return a.starttime < b.starttime;
}
