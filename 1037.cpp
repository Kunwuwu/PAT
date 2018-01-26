#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nc, np;
vector<int> coup, prod;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> nc;
    int temp;
    for(int i = 0; i < nc; i++)
    {
        cin >> temp;
        coup.push_back(temp);
    }
    sort(coup.begin(), coup.end(), cmp);
    cin >> np;
    for(int i = 0; i < np; i++)
    {
        cin >> temp;
        prod.push_back(temp);
    }
    sort(prod.begin(), prod.end(), cmp);
    int result = 0, cpindex = 0, pdindex = 0, cpcnt = 0, pdcnt = 0;     /* 两个index变量是作为下标移动的 */
    int lencp = coup.size(), lenpd = prod.size();                       /* 两个cnt变量是分别统计移动次数的，用于最后退出 */
    bool havechanged = false;                                /* 如果其中有负数的话，两个下标会直接退到最后一个，记录一下 */
    while(cpcnt < lencp && pdcnt < lenpd)
    {
        if (coup[cpindex] >= 0 && prod[pdindex] >= 0)        /* 如果两个都是正的，直接加，往后移动 */
        {
            result += coup[cpindex] * prod[pdindex];
            cpindex++;
            pdindex++;
            cpcnt++;
            pdcnt++;
        }                                                   /* 如果任何一个是负的，则从后往前移动 */
        else if(!havechanged)
        {
            havechanged = true;                             /* 表示下标已经到了最后一个了，往后就不再变了 */
            cpindex = lencp - 1;
            pdindex = lenpd - 1;
        }
        else                                                 /* 到这个分支的时候，cpindex和pdindex肯定是倒转过的 */
        {
            if(coup[cpindex] < 0 && prod[pdindex] >= 0)
                break;
            else if(coup[cpindex] >= 0 && prod[pdindex] < 0)
                break;
            else                                             /* 两个都为负 */
            {
                result += coup[cpindex] * prod[pdindex];     /* 则更新结果，并将两个索引往前移动 */
                cpindex--;
                pdindex--;
                cpcnt++;
                pdcnt++;
            }
        }
    }
    cout << result;
    return 0;
}
