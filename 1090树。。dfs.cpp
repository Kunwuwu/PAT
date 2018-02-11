#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, root;
double price, r;
vector<vector<int>> chain;
vector<double> weight;
double maxprice = -1.0;
int maxcnt = 0;

void dfs(int source, double tprice)                                  /* dfs就不多做解释了 */
{
    weight[source] = tprice;
    if(tprice > maxprice)
    {
        maxcnt = 1;
        maxprice = tprice;
    }
    else if(tprice == maxprice)
        maxcnt++;
    if(chain[source].size() == 0)
    {
        return ;
    }
    else
    {
        for(int i = 0; i < chain[source].size(); i++)
            dfs(chain[source][i], tprice * (1.0 + r));
    }
}

int main()
{
    cin >> n >> price >> r;
    r /= 100;
    chain.resize(n);
    weight.resize(n);
    for(int i = 0; i < n; i++)                                    /* 这里做一下说明 */
    {
        int temp;
        scanf("%d", &temp);
        if(temp != -1)                                            /* 这里temp代表的是供货商，i代表的是受供货的商家 */
            chain[temp].push_back(i);                             /* 所以temp在i的上一层 */
        else
        {
            weight[i] = price;
            root = i;                                             /* 其实weight没用，但是方便我用来调试，root记录根节点 */
        }
    }
    dfs(root, price);
    printf("%.2lf %d", maxprice, maxcnt);

    return 0;
}
