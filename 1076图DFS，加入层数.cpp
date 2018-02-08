#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int inf = 999999999;
const int MAX = 1010;

int g[MAX][MAX];
bool visited[MAX];
int n, l, k;
vector<int> levels;

int bfs(int source)                                                /* 广度优先遍历 */
{
    queue<int> q;
    q.push(source);
    int cnt = 0;
    while(!q.empty())
    {
        int v = q.front();
        if(levels[v] <= l)                                         /* 如果有一个结点的层数大于l了，则不用遍历了 */
            cnt++;
        else
            break;
        visited[v] = true;                                         /* 标记计数过的结点 */
        q.pop();
        for(int w = 1; w <= n; w++)
        {
            if(!visited[w] && g[v][w] == 1)
            {
                q.push(w);
                visited[w] = true;
                levels[w] = levels[v] + 1;                         /* w结点肯定是从v结点出来的，层数正好比v高一层 */
            }
        }
    }
    return cnt;
}

int main()
{
    fill(g[0], g[0] + MAX * MAX, inf);
    cin >> n >> l;
    levels.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            int follower;
            scanf("%d", &follower);
            g[follower][i] = 1;                                  /* 这里是有向图，表示的是post传播的方向 */
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int query;
        scanf("%d", &query);
        printf("%d\n", bfs(query) - 1);
        fill(visited, visited + n + 1, false);                   /* 统计的结点数包括了source源结点，要减一 */
        for(int j = 1; j <= n; j++)
            levels[j] = 0;
    }
    return 0;
}
