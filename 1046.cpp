#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int cycle[100001];
int n, m;

int main()
{
    cin >> n;
    int cl = 0, temp;
    cycle[1] = 0;
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &temp);
        cycle[i + 1] = temp + cycle[i];
        cl += temp;                                        /* 计算圈的整个长度 */
    }
    cin >> temp;
    cl += temp;
    cin >> m;
    int s, d, tdis;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &d);
        if(s < d)
        {
            tdis = cycle[d] - cycle[s];                   /* 其实就是从后往前减去就行 */
        }
        else
        {
            tdis = cycle[s] - cycle[d];
        }
        printf("%d\n", min(tdis, cl - tdis));             /* 和反方向的比较就行 */
    }
    return 0;
}
