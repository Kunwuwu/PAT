#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int getexp(string exp)
{
    string ans;
    int result = 0;
    int i = 0;
    while(exp[i] == 0)
        i++;
    for(; i < exp.length(); i++)
        ans.push_back(exp[i]);
    int len = ans.length();
    for(int i = 0; i < len; i++)
    {
        result += (ans[i] - '0') * pow(10, len - i - 1);
    }
    return result;
}

int main()
{
    bool ispstv, ispexp;
    string base, exp;
    int expint;
    string num;
    cin >> num;
    if(num[0] == '+')                                                /* 记录整个数的正负 */
        ispstv = true;
    else
        ispstv = false;
    int i;
    for(i = 1; num[i] != 'E'; i++)                                   /* 将E之前的数字放入base（底数）中 */
    {
        if(num[i] != '.')                                            /* 小数点不放入base中 */
            base.push_back(num[i]);
    }
    i++;                                                             /* 跳过'E' */
    if(num[i] == '+')                                                /* 判断指数正负 */
        ispexp = true;
    else
        ispexp = false;
    i++;                                                             /* 跳过指数的正负号 */
    for(; i < num.length(); i++)                                     /* 得到指数字符串（包括前导零） */
        exp.push_back(num[i]);
    expint = getexp(exp);                                            /* 得到整数的字符串 */
    string ans;
    if(ispexp)                                                       /* 如果指数是正的 */
    {
        int i = 0;                                                   /* 两种情况，通过指数大小移动小数点 */
        for(; i < base.length() && i <= expint; i++)                 /* 将base按照指数expint进行处理 */
        {
            ans.push_back(base[i]);
        }
        if(i == base.length())                                       /* 第一种：base不够长（得到的是整数），需要添加尾部的零 */
        {
            for(; i <= expint; i++)
                ans.push_back('0');
        }
        else                                                         /* 第二种：base够长（得到的是小数） */
        {
            ans.push_back('.');                                      /* 添加小数点后，还需要把后面的数作为小数加上去 */
            for(; i < base.length(); i++)
                ans.push_back(base[i]);
        }
    }
    else                                                             /* 如果指数是负的，得到的是绝对值小于1的数 */
    {
        ans = "0.";                                                  /* 你懂的 */
        for(int i = 1; i < expint; i++)                              /* 在小数点后加零，类似于0.0000X。。。这种 */
            ans.push_back('0');
        ans = ans + base;
    }
    if(!ispstv)
        cout << "-";
    cout << ans;
    return 0;
}
