#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 202;
int g[MAX][MAX];
int visited[MAX];
int n, m, q, k;

int main()
{
    cin >> n >> m;
    int v, w;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &v, &w);
        g[v][w] = g[w][v] = 1;
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        bool flag = true;
        fill(visited + 1, visited + n + 1, 0);
        scanf("%d", &k);
        int start, next;
        scanf("%d", &start);
        next = start;
        int pre = start;
        visited[pre]++;
        for(int j = 2; j <= k; j++)
        {
            scanf("%d", &next);
            if(g[pre][next] == 0)                         /* 如果不是邻边的跨越 */
                flag = false;
            visited[next]++;
            pre = next;
        }
        if(start != next)                                 /* 如果终点起点不一致 */
        {
            printf("NO\n");
            continue;
        }
        for(int j = 1; j <= n; j++)
        {
            if(j != start && visited[j] != 1)             /* 注意这里，start是被计算两次的，因为最后一圈要回到起点 */
            {
                flag = false;                             /* 判断是否所有的点都是经过一次，起点除外 */
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
