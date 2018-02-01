#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 16777220;

int n, m;
int color[MAX];

int main()
{
    cin >> n >> m;
    int temp;
    int max = 0, maxindex = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)                                /* 利用数组下标作为索引，简直超级快的好嘛 */
        {                                                         /* 统计所有颜色出现的次数就好了 */
            scanf("%d", &temp);
            color[temp]++;
            if(color[temp] > max)
            {
                maxindex = temp;
                max = color[temp];
            }
        }
    }
    cout << maxindex;
    return 0;
}
