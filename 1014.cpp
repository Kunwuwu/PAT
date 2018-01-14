/*
 * 题目确实是有点难，很难去理解那个排队的机制，当然队列我肯定理解，算是更加熟悉队列了
 * 坑点就是那个17:00的时间限制其实是开始服务的时间，不是离开的时间，看文字翻译水平了
 * 重要的是参考了别人的思路。。。
 * 1.分为黄线外和黄线内的处理
 * 2.将时间线的变化用循环变量来表示
 * 找时间再自己做一下，2333
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

typedef struct CUS
{
    bool sorry;
    int time;
    int leaveTime;
}customer[1005];

typedef struct WIN
{
    int popTime;
    int endTime;
    queue<CUS> que;
}window;

// 全局变量的初始化
customer customers;
int n, m, k, q, index = 1;

// 函数原型
void timeToStr(int time);

int main()
{
    cin >> n >> m >> k >> q;
    vector<window> windows(n + 1);                          /* 定义窗口的向量，n个窗口 */
    for(int i = 1; i <= k; i++)                             /* 下标从1开始，表示对一个顾客，方便理解 */
    {
        cin >> customers[i].time;
        customers[i].sorry = false;                         /* 刚来的顾客都认为自己是能够被服务的 */
    }
    for(int i = 1; i <= m; i++)                             /* ---黄线以内---可以看作是n列m行 */
    {
        for(int j = 1; j <= n; j++)
        {
            if(index <= k)
            {
                if(windows[j].endTime >= 540)               /* 如果这个窗口的结束时间已经超过了17点 */
                    customers[index].sorry = true;          /* 则新来的这个顾客没法被服务了 */
                windows[j].endTime += customers[index].time;/* 窗口新的结束时间需要加上新来顾客的服务时间 */
                windows[j].que.push(customers[index]);      /* 将新来顾客加入本窗口的队列中 */
                if(i == 1)                                  /* 如果这是本窗口的第一个顾客 */
                    windows[j].popTime = windows[j].endTime;/* 可以得到窗口的第一次更新队列的时间 */
                customers[index].leaveTime = windows[j].endTime;/* 顾客的离开时间就是窗口的结束时间 */
                index++;                                    /* 下一个顾客 */
            }
        }
    }
    // 黄线以外的顾客
    while(index <= k)                 /* 如果顾客数(k)少于黄线内的空间数(index-1)，这个循环就不用进去了 */
    {
        int minWindowTime = windows[1].popTime;
        int minWindow = 1;                          /* 假设窗口1最先腾出位置 */
        for(int i = 2; i <= n; i++)
        {
            if(windows[i].popTime < minWindowTime)  /* 如果某个窗口能更快地腾出位置 */
            {
                minWindow = i;
                minWindowTime = windows[i].popTime;
            }
        }
        windows[minWindow].que.pop();                     /* 队伍第一个顾客离开队列 */
        windows[minWindow].que.push(customers[index]);    /* 将新顾客加入队列 */
        windows[minWindow].popTime += windows[minWindow].que.front().time;/* 更新窗口的poptime */
        if(windows[minWindow].endTime >= 540)
            customers[index].sorry = true;
        windows[minWindow].endTime += customers[index].time;  /* 窗口的结束时间要加上新加入顾客的服务时间 */
        customers[index].leaveTime = windows[minWindow].endTime;  /* 新顾客离开的时间 */
        index++;
    }
    for(int i = 1; i <= q; i++)
    {
        int query;
        cin >> query;
        if(!customers[query].sorry)
            timeToStr(customers[query].leaveTime);
        else
            cout << "Sorry" << endl;
    }
    return 0;
}

void timeToStr(int time)
{
    time += 8 * 60;
    int hh, mm;
    hh = time / 60;
    mm = time % 60;
    printf("%02d:%02d\n", hh, mm);
}
