#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

map<int, bool> dict;                                      /* 记录是否存在 */

int main()
{
    int m, n, u, v, a;
    cin >> m >> n;
    vector<int> pre;
    pre.resize(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
        dict[pre[i]] = true;                              /* 前序，这个点存在 */
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        for(int j = 0; j < n; j++)
        {
            a = pre[j];                                   /* 遍历前序序列，如果某个点大小在uv之间，则满足条件 */
            if((u < a && v > a) || (v < a && u > a) || (a == u) || (a == v))
                break;
        }
        if(!dict[u] && !dict[v])
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if(!dict[u] && dict[v])
            printf("ERROR: %d is not found.\n", u);
        else if(dict[u] && !dict[v])
            printf("ERROR: %d is not found.\n", v);
        else
        {
            if(a == u)
                printf("%d is an ancestor of %d.\n", u, v);
            else if(a == v)
                printf("%d is an ancestor of %d.\n", v, u);
            else
                printf("LCA of %d and %d is %d.\n", u, v, a);
        }
    }
    return 0;
}
