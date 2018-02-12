#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct
{
    double data;
    vector<int> child;
}node;

vector<node> chain;                                                       /* 其实就是一颗树 */
int n;
double r, p, total = 0.0;

void dfs(int source, int depth)                                           /* dfs，带深度的dfs遍历 */
{
    if(chain[source].child.size() == 0)
    {
        total += chain[source].data * pow(1 + r, depth);
        return ;
    }
    else
    {
        for(int i = 0; i < chain[source].child.size(); i++)
        {
            dfs(chain[source].child[i], depth + 1);
        }
    }
}

int main() {
    cin >> n >> p >> r;
    chain.resize(n);
    r /= 100;
    for(int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        if(k != 0)
        {
            for(int j = 0; j < k; j++)
            {
                int temp;
                scanf("%d", &temp);
                chain[i].child.push_back(temp);
            }
        }
        else
        {
            double amount;
            scanf("%lf", &amount);
            chain[i].data = amount;
        }
    }
    dfs(0, 0);
    printf("%.1lf", p * total);
    return 0;
}
