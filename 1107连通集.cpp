#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1005;

vector<vector<int>> hbs;                                  
int g[MAX][MAX];
int n;
int cnth = 0;
bool visited[MAX];
int cnt = 0;
vector<int> result;

void dfs(int v)
{
    visited[v] = true;
    cnt++;
    for(int w = 1; w <= n; w++)
    {
        if(!visited[w] && g[v][w] == 1)
            dfs(w);
    }
}

int main()
{
    cin >> n;
    hbs.resize(1002);
    for(int i = 1; i <= n; i++)                          /* 输入的处理 */
    {
        int k;
        scanf("%d:", &k);
        for(int j = 0; j < k; j++)                       /* 有同temp爱好的i压入temp的vector */
        {
            int temp;
            scanf("%d", &temp);
            if(temp > cnth) cnth = temp;
            if(!hbs[temp].empty())
            {
                int w = hbs[temp].front();
                g[w][i] = g[i][w] = 1;                   /* 同时由头到尾构成一条链表，生成图 */
            }
            hbs[temp].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++)                          /* 连通图的遍历 */
    {
        if(!visited[i])
        {
            cnt = 0;
            dfs(i);
            result.push_back(cnt);
        }
    }
    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for(int i = result.size() - 1; i >= 0 ; i--)
    {
        if(i != result.size() - 1)
            printf(" ");
        printf("%d", result[i]);
    }
    return 0;
}
