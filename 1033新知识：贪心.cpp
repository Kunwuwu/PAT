#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

const double inf = 99999999;

using namespace std;

typedef struct
{
    double price;
    double dist;
}station;

vector<station> stas;

bool cmp(station a, station b)
{
    return a.dist < b.dist;
}

double c, d, avg;
int n;
double nowdist = 0.0, nowprice = 0.0, totalprice = 0.0, maxdist = 0.0;

int findnextstation(int nowsta)
{
    int min = -1;
    double minprice = inf;
    for(int i = nowsta + 1; i <= n; i++)
    {
        if(stas[i].dist <= (maxdist + stas[nowsta].dist))         /* 如果能到达这个站 */
        {
            if(stas[i].price < stas[nowsta].price)                /* 如果找到了比本站价格更低的站 */
            {
                min = i;
                break;
            }
            else                                                  /* 如果这个站油价没有比本站低 */
            {
                if(stas[i].price < minprice)                      /* 记录这个站油价，便于确定最低油价站 */
                {
                    min = i;
                    minprice = stas[i].price;
                }
            }
        }
    }
    return min;
}

int main()
{
    cin >> c >> d >> avg >> n;
    stas.resize(n + 1);
    stas[0] = {0.0, d};                              /* 将最便宜的点设置为最远，贪心算法 */
    for(int i = 1; i <= n; i++)
        cin >> stas[i].price >> stas[i].dist;
    sort(stas.begin(), stas.end(), cmp);
    if(stas[0].dist != 0)
    {
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    int nowsta = 0;
    double addtank = 0.0, tank = 0.0;                  /* 初始油量为零 */
    nowprice = stas[0].price;
    maxdist = c * avg;                           /* 能走的最大距离应该是不会变的 */
    while(nowdist < d)
    {
        nowsta = findnextstation(nowsta);        /* 在能到达的距离内找到更便宜的站 */
        if(stas[nowsta].price < nowprice)        /* 如果找的下一个站的油价更低，加到刚好能到下一站 */
        {
            addtank = (stas[nowsta].dist - nowdist) / avg - tank;      /* 用需要的油量减去剩下的，就是要加的 */
            tank = 0.0;                          /* 到下一站时，油量为零 */
        }
        else                                     /* 下一站的油价更高，将油加满 */
        {
            addtank = (c - tank);
            tank = c - (stas[nowsta].dist - nowdist) / avg;  /* 到下一站时，油量会有剩余 */
        }
        if(nowsta == -1)                         /* 如果找不到能到达的站了，则退出 */
        {
            break;
        }
        totalprice += addtank * nowprice;  /* 在当前站点计算总共价格 */
        nowdist = stas[nowsta].dist;                              /* 到达下一站，更新距离 */
        nowprice = stas[nowsta].price;                            /* 达到下一站，更新油价 */
    }
    if(nowsta == -1)
        printf("The maximum travel distance = %.2lf", nowdist + maxdist);
    else
        printf("%.2lf", totalprice);
    return 0;
}
