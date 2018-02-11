#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef struct
{
    int x, y, z;
}node;

const int MAX_x = 1300, MAX_y = 130, MAX_z = 65;             /* 各维度上的边界 */

int map[MAX_x][MAX_y][MAX_z];
bool visited[MAX_x][MAX_y][MAX_z];
int m, n, l, t;
int dx[] = {1, -1, 0, 0, 0, 0};                              /* 非常巧妙的一个地方，便于每次往六个方向上任意一个方向前进一个单位 */
int dy[] = {0, 0, 1, -1, 0, 0};                              /* 注意一列上只能有一个1或-1 */
int dz[] = {0, 0, 0, 0, 1, -1};

bool issuite(int x, int y, int z)                            /* 判断这个点是否在边界内，为肿瘤的一个点或者已经被统计过 */
{
    if(0 <= x && x < m)
        if(0 <= y && y < n)
            if(0 <= z && z < l)
                if(map[x][y][z] == 1 && !visited[x][y][z])
                    return true;
    return false;
}

int bfs(int x, int y, int z)                                 /* bfs遍历整个连通区域 */
{
    node temp;
    int cnt = 0;
    temp.x = x;
    temp.y = y;
    temp.z = z;
    queue<node> q;
    q.push(temp);
    while(!q.empty())
    {
        node v = q.front();
        q.pop();
        visited[v.x][v.y][v.z] = true;
        cnt++;                                               /* 计数 */
        for(int i = 0; i < 6; i++)                           /* 循环遍历任何一个点的周围六个点（六个方向） */
        {
            int tx = v.x + dx[i];                            /* 很巧妙的地方，循环往任意方向上前进一个单位，然后判断这点是否合适 */
            int ty = v.y + dy[i];
            int tz = v.z + dz[i];
            if(issuite(tx, ty, tz))
            {
                temp.x = tx;
                temp.y = ty;
                temp.z = tz;
                visited[tx][ty][tz] = true;
                q.push(temp);
            }
        }
    }
    if(cnt >= t)
        return cnt;
    else
        return 0;
}

int main()
{
    cin >> m >> n >> l >> t;
    int ans = 0;
    for(int i = 0; i < l; i++)                               /* 注意了l, m, n和 i, j, k的关系 */
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                scanf("%d", &map[j][k][i]);                  /* 构造图 */
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                if(!visited[j][k][i] && map[j][k][i] == 1)   /* 遍历每个连通区域 */
                    ans += bfs(j, k, i);
    cout << ans;
    return 0;
}
