#include <iostream>
#include <cstdio>

using namespace std;

// 全局变量的初始化
int map[1005][1005];
bool visted[1005];
int result[1005];                       // 要不从1开始吧
int n, m, k;

// 函数原型
int DFS_Graph(int map[][1005], int lost);
void DFS(int map[][1005], int source);
void InitVisited();

int main()
{
    int c1, c2;
    int lost;
    cin >> n >> m >> k;
    for(int i = 0; i < m ; i++)            /* 创建图 */
    {
        cin >> c1 >> c2;
        map[c1][c2] = 1;
        map[c2][c1] = 1;
    }
    for(int i = 1; i <= k; i++)
    {
        cin >> lost;
        InitVisited();
        result[lost] = DFS_Graph(map, lost) - 1;                 /* 假设i顶点缺失，返回连通集个数 */
        cout << result[lost] << endl;
    }            /* 巨坑，原打算使用数组存储输出的，可是忽略了并不一定是按1、2、3。。。的顺序存储的 */
                 /* 也就是lost可能是3 2 1的顺序，而动态输出数组则一定是1 2 3 */
//    for(int i = 1; i <= k; i++)
//        if(result[i] >= 0)
//
//        else
//            cout << "0" << endl;
    return 0;
}

void InitVisited()
{
    for(int i = 0; i < 1005; i++)
        visted[i] = false;
}

int DFS_Graph(int map[][1005], int lost)
{
    visted[lost] = true;
    int count = 0;                             /* 记录连通集个数 */
    for(int i = 1; i <= n; i++)
    {
        if(!visted[i])
        {
            count++;
//            cout << endl;
            DFS(map, i);
        }
    }
    return count;
}

void DFS(int map[][1005], int source)
{
    visted[source] = true;
//    printf("%d\t", source);
    for(int v = 1; v <= n; v++)
    {
        if(map[source][v] && !visted[v])
        {
            DFS(map, v);
        }
    }
}
