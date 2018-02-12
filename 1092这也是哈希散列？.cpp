#include <iostream>
#include <cstdio>

using namespace std;

int a[130], b[130];

int main()
{
    string shop, need;
    cin >> shop >> need;
    int lenshop = shop.length();
    int lenneed = need.length();
    int cnt = 0;
    for(int i = 0; i < lenshop; i++)
        a[shop[i]]++;                                      /* 把店里串串的当前颜色数量++ */
    for(int i = 0; i < lenneed; i++)
        b[need[i]]++;                                      /* 把Eva需要的串串的当前颜色数量++ */
    bool flag = true;
    for(int i = 0; i < 130; i++)
    {
        if(a[i] < b[i])                                    /* 店里的串串必须包含所有需要的颜色和对应的数量 */
        {
            flag = false;
            cnt += (b[i] - a[i]);
        }
    }
    if(flag)
        printf("Yes %d", lenshop - lenneed);
    else
        printf("No %d", cnt);
    return 0;
}
