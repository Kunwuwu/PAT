#include <vector>
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct
{
    int arriveTime;
    int serveTime;
    int waitTime;
}customer;

// 全局变量的初始化定义
int n, k;
queue<customer> cus;

// 函数原型
bool cmp(customer a, customer b);

int main()
{
    int hh, mm, ss;
    cin >> n >> k;
    vector<int> window(k, 28800);           /* 每个窗口开始的时间都是早上八点 */
    vector<customer> v;
    vector<int> time;                       /* 记录等待时间的向量 */
    int count = 0;
    double result = 0.0;
    for(int i = 0; i < n; i++)
    {
        customer temp;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> temp.serveTime;
        if(temp.serveTime > 60)
            temp.serveTime = 60;
        temp.serveTime *= 60;               /* 转化成秒 */
        temp.arriveTime = hh * 3600 + mm * 60 + ss;
        if(temp.arriveTime <= 17 * 3600)
            v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cus.push((*it));                        /* 用户进队列 */
    }
    while(!cus.empty())                        /* 队列不为空则。。。你懂的 */
    {
        int minWindow = 0, minTime = window[minWindow];
        for(int it = 0; it != window.size(); it++)      /* 找到当前最早空位的window */
        {
            if(window[it] < minTime)
            {
                minWindow = it;
                minTime = window[it];
            }
        }/* 队列第一个人的等待时间就是当前窗口的时间减去他来的时间 */
        cus.front().waitTime = max(window[minWindow] - cus.front().arriveTime, 0);
        time.push_back(cus.front().waitTime);
        if(window[minWindow] - cus.front().arriveTime > 0)         /* 如果用户来的时候窗口有人 */
            window[minWindow] += cus.front().serveTime;  /* 窗口的服务结束时间+=该用户的服务时间 */
        else                                                       /* 如果用户来的时候窗口没人 */
            window[minWindow] = cus.front().serveTime + cus.front().arriveTime; /* 注意窗口的服务结束时间需从当前用户开始计算 */
        cus.pop();                                   /* 当前队伍的第一人出队 */
    }
    for(auto it = time.begin(); it != time.end(); it++)
    {
        result += (double)(*it);
    }
    if(result > 0)
        printf("%.01lf", result / (v.size() * 60));
    else
        printf("0.0");
    return 0;
}

bool cmp(customer a, customer b)
{
    return a.arriveTime < b.arriveTime;   /* 升序排列 */
}
