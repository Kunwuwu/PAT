#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> chain;
int n, result = 0;
double minprice = 99999999999;
double r, price;

void dfs(int root, double tprice)                                /* dfs带层数 */
{
    if(chain[root].size() == 0)
    {
        if(tprice < minprice)
        {
            minprice = tprice;
            result = 1;
        }
        else if(tprice == minprice)
            result++;
    }
    else
    {
        for(int i = 0; i < chain[root].size(); i++)
            dfs(chain[root][i], tprice * (1 + r));
    }
}

int main()
{
    cin >> n >> price >> r;
    r /= 100;
    int k;
    chain.resize(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        for(int j = 0; j < k; j++)
        {
            int temp;
            scanf("%d", &temp);
            chain[i].push_back(temp);
        }
    }
    dfs(0, price);
    printf("%.4lf %d", minprice, result);
    return 0;
}
