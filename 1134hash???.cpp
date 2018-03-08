#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
int n, m, q, k;

int main()
{
    cin >> n >> m;
    g.resize(n);
    int v, w;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &v, &w);
        g[v].push_back(i);                                /* 这样的方法用过很多次了，一直不知道叫hash */
        g[w].push_back(i);                                /* 这样是唯一标记每条边，即与一个点相邻的边 */
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &k);
        int v;
        bool flag = true;
        vector<bool> hash(m, false);                      /* hash用于记录是否这条边是否被访问过了 */
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &v);
            for(int s = 0; s < g[v].size(); s++)          /* 表示这条边被访问过了 */
                hash[g[v][s]] = true;
        }
        for(int j = 0; j < m; j++)
        {
            if(!hash[j])                                  /* 如果存在没有被访问的边 */
            {
                flag = false;
                break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
