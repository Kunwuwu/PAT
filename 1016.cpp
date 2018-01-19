/*
 * 这道题目可以说是很有成就感了！！！使用类的话，确实代码量小很多，思路也清晰很多
 */

#include "vector"
#include "iostream"
#include "map"
#include "string"
#include "cstdio"
#include <algorithm>

using namespace std;

typedef struct REC                         /* 输入的每一条记录 */
{
    int time;
    bool isOnLine;
}record;

// 函数原型
bool cmp(const record &a, const record &b);                 /* 比较函数 */
void convertToTimeForm(int time);

// 全局变量的定义
string on = "on-line";
string off = "off-line";
double toll[24];

class Person {
public:
    bool isPair;
    double totalAmount;
    int month;
    vector<int> result;
    double callAmount[5000];
    int disTime[5000];
    vector<REC> call;             /* 储存一个人每条记录的向量 */
public:
    void match() {                /* 当成类来使用了 */
        bool flag = false;
        for (auto itP = call.begin(); itP != call.end(); itP++)   /* itP就是it的指针 */
        {
            auto it = *itP;
            if (it.isOnLine)               /* 如果这条记录是online */
            {
                if (flag)                  /* 如果这条记录是online而且前面也是online，将前一条记录pop */
                    result.pop_back();
                flag = true;
                result.push_back(it.time);/* 将这条记录加入result */
            } else if (flag && !it.isOnLine) /* 如果这条记录是offline而且前面出现过online */
            {
                result.push_back(it.time);/* 将这条记录加入result */
                flag = false;             /* 并且将flag重新置为false */
                isPair = true;
            }
        }
        if(flag)
            result.pop_back();             /* 如果前一条记录一直没匹配上，则pop() */
    }

    void cal()                            /* 计算费用的方法 */
    {
        totalAmount = 0.0;
        fill(callAmount, callAmount + 5000, 0.0);
        fill(disTime, disTime + 5000, 0);                /* 初始化 */
        if(isPair)
        {
            for(int i = 1; i < result.size(); i+=2)        /* 很可能会超时 */
            {
                for(int time = result[i-1]; time < result[i]; time++)   /* 计算两个匹配的时间，即每次通话记录的费用 */
                {
                    int hour = (time % (24 * 60)) / 60;                /* 注意hour和总时间（分钟）的关系 */
                    callAmount[i/2] += toll[hour] / 100;
                }
                disTime[i/2] = result[i] - result[i-1];
                totalAmount += callAmount[i/2];
            }
        }
    }
};


// 全局变量的定义
map<string, Person> dict;                /* 注意Person是一个类 */

int main()
{
    int n;                                /* 表示即将输入的n条记录 */
    int month, dd, hh, mm;
    vector<int> resultTemp;
    record recTemp;                       /* 临时的record结构体，存储每一条输入的记录 */
    string line;
    for (int i = 0; i < 24; i++)
        cin >> toll[i];
    cin >> n;                             /* 存入所有数据 */
    for (int i = 0; i < n; i++)           /* 将数据存储字典dict（类Person的call结构体）中 */
    {
        string name;
        cin >> name;
        scanf("%d:%d:%d:%d", &month, &dd, &hh, &mm);
        dict[name].month = month;
        recTemp.time = (dd - 1) * 24 * 60 + hh * 60 + mm;
        cin >> line;
        if (line == on)
            recTemp.isOnLine = true;
        else
            recTemp.isOnLine = false;
        dict[name].call.push_back(recTemp);
    }
    for (auto it = dict.begin(); it != dict.end(); it++)  /* 遍历字典，处理每个用户的通话记录 */
    {
        auto iter = (*it);
        sort(dict[iter.first].call.begin(), dict[iter.first].call.end(), cmp);  /* 将用户的每条记录按时间排序 */
        dict[iter.first].match();                         /* 将构成一次通话记录的两条数据匹配 */
        dict[iter.first].cal();                           /* 计算每次的费用和总费用 */
    }/* 最后只能通过使用返回值的方式进行赋值 */
    for (auto it = dict.begin(); it != dict.end(); it++)  /* 遍历字典，输出每个用户的通话记录和费用 */
    {
        auto iter =  *it;
        int count = 0;                                   /* 输出计数 */
        if(iter.second.result.size())                    /* 这句大概是没用的，我发现这个second很诡异 */
        {
            cout << iter.first;
            printf(" %02d\n", dict[iter.first].month);   /* 输出用户的名字，账单的月份 */
            for(auto i = dict[iter.first].result.begin(); i != dict[iter.first].result.end(); i++)
            {/* 输出用户每次的通话记录和费用 */
                convertToTimeForm(*i);           /* 将整数的时间转成dd:hh:mm的格式输出 */
                count++;
                if(count % 2 == 0)              /* 每输出两条记录 */
                {
                    printf("%d $%.02lf\n", dict[iter.first].disTime[count/2-1],dict[iter.first].callAmount[count/2-1]);
                }
            }
            printf("Total amount: $%.02lf\n", dict[iter.first].totalAmount);
        }
    }
    return 0;
}

bool cmp(const record &a, const record &b)                 /* 比较函数 */
{
    return a.time < b.time;                      /* 升序排列 */
}

void convertToTimeForm(int time)
{
    int dd = time / (24 * 60) + 1;
    int hh = (time % (24 * 60)) / 60;
    int mm = time % 60;
    printf("%02d:%02d:%02d ", dd, hh, mm);
}
