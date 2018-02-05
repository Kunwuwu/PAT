#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    double ton;                                                        /* 这里为浮点数，整型的话有一个过不了 */
    double price;
}mooncake;

vector<mooncake> mks;

int n, m;

bool cmp(mooncake a, mooncake b)
{
    return a.price > b.price;
}

int main()
{
    double tprice;
    cin >> n >> m;
    mks.resize(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &mks[i].ton);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &tprice);
        mks[i].price = tprice / mks[i].ton;
    }
    sort(mks.begin(), mks.end(), cmp);
    double profit = 0.0;
    int i = 0;
    while(m > 0 && i < n)
    {
        if(mks[i].ton <= m)
        {
            profit += mks[i].ton * mks[i].price;
            m -= mks[i].ton;
        }
        else
        {
            profit += mks[i].price * m;
            m = 0;
            break;
        }
        i++;
    }
    printf("%.2lf", profit);
    return 0;
}
