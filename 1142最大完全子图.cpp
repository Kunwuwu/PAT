/*
 * 考试的时候这个题是最坑的，因为有几个关键的词不认识，还有就是第一次见到最大完全图这个东西
 * 解释一下：首先完全图得是所有点都两两相邻，最大完全图就是加入其它的任意一个点，都不是最大完全图，所以得用二重循环来遍历验证
 * */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const int MAX = 205;

int nv, ne, m;
int g[MAX][MAX];


int main()
{
    cin >> nv >> ne;
    for(int i = 0; i < ne; i++)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        g[v][w] = g[w][v] = 1;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int size;
        vector<int> q;
        scanf("%d", &size);
        q.resize(size);
        for(int j = 0; j < size; j++)
            scanf("%d", &q[j]);
        bool isc = true;
        for(int j = 0; j < size; j++)
        {
            for(int k = 0; k < size; k++)
            {
                int v = q[j], w = q[k];
                if(v != w && g[v][w] != 1)                /* 子图中任意两点不相邻都是不是完全子图 */
                {
                    isc = false;
                    break;
                }
            }
            if(!isc)
                break;
        }
        if(!isc)
        {
            printf("Not a Clique\n");
            continue;
        }
        int cnt = 0;
        for(int j = 1; j <= nv; j++)
        {
            bool all = true;
            for(int k = 0; k < size; k++)
            {
                int v = q[k];
                if(j != v && g[j][v] != 1)                /* 统计是否这个点与子图中每个点都相邻 */
                {
                    all = false;
                    break;
                }
            }
            if(all)                                       /* 统计符合该相邻条件的点个数 */
                cnt++;
        }
        if(cnt == size)                                   /* 如果符合条件的点不止给的那几个，就不是最大图 */
            printf("Yes\n");
        else
            printf("Not Maximal\n");
    }
    return 0;
}
