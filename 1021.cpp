#include <vector>
#include <set>
#include <iostream>
#include <cstdio>

using namespace std;

// 常量的定义
const int MAX = 10005;

// 全局变量的定义
int map[MAX][MAX];
set<int> s;
int n;
int maxheight = 0, count = 0, tempheight;
bool visited[MAX];
vector<int> path;

// 函数原型
void dfs(int source);
void countDfs();

int main()
{
    cin >> n;
    int v, w;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> v >> w;
        map[v][w] = map[w][v] = 1;
    }
    countDfs();
    if(count == 1)
    {
        for(auto it = s.begin(); it != s.end(); it++)
        {
            cout << *it << endl;
        }
    }
    else if(count > 1)
    {
        printf("Error: %d components", count);
    }
    return 0;
}

void countDfs()
{
    for(int i = 1; i <= n; i++)                         /* 进行第一次dfs并记录连通集的个数 */
    {                                                   /* 第一次dfs可以得到从初始节点到各个边界点的路径长度，也就是树高 */
        if(!visited[i])
        {
            dfs(i);
            count++;
        }
    }
    if(count == 1)
    {
        fill(visited, visited + MAX, false);           /* 第二次dfs可以得到上次dfs中的最高树的根（可能多个） */
        int temp = *(s.begin());
        dfs(temp);
        fill(visited, visited + MAX, false);           /* 最后一次dfs为了防止第二次中使用的初始根节点没有被计算 */
        temp = *(s.begin());
        dfs(temp);
    }
}


void dfs(int source)                                        /* path用来记录树延伸的路径 */
{
    visited[source] = true;
    path.push_back(source);
    if(path.size() > maxheight)                             /* 用路径的长度来进行树高度的比较，我不要太聪明了哈哈 */
    {                                                       /* 感觉这个思路独到且受益终生嘛 */
        s.clear();                                          /* 更新集合set */
        maxheight = path.size();
        s.insert(source);
    }
    else if(path.size() == maxheight)
        s.insert(source);
    for(int w = 1; w <= n; w++)
    {
        if(!visited[w] && map[source][w] != 0)
            dfs(w);
    }
    path.pop_back();                                        /* 若这条路到头，退回上个节点访问下一条 */
}
