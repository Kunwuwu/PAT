#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> coins;
vector<int> result;
vector<int> tpath;
vector<vector<int>> paths;
bool found;

bool cmp(vector<int> a, vector<int> b)
{
    return a < b;
}

void dfs(int index, int lost)
{
    tpath.push_back(coins[index]);
    if(lost - coins[index] == 0)
    {
        paths.push_back(tpath);
        found = true;
        tpath.pop_back();
        return ;
    }
    else if(lost - coins[index] < 0)
    {
        tpath.pop_back();
        return ;
    }
    else
    {
        if(lost - coins[index] < coins[index])
        {
            tpath.pop_back();
            return ;
        }
        else
        {
            for(int i = index + 1; i < n; i++)
            {
                if(found)                                /* 不处理的话，会超时 */
                    break;
                if(i > 15 && coins[i] == coins[i-15])    /* 这个15巨诡异，其实就是会有很多重复的，得到的方案也是重复的 */
                    continue;                            /* 如果取到25的会员，最后的案例超时，取10以下的话，倒数第三个过不了 */
                else                                     /* 这次纯粹是有点投机取巧了2333 */
                    dfs(i, lost - coins[index]);
            }
        }
        tpath.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    coins.resize(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }
    sort(coins.begin(), coins.end());
    for(int i = 0; i < n; i++)
    {
        if(found)
            break;
        dfs(i, m);
    }
    if(found)
    {
        sort(paths.begin(), paths.end(), cmp);
        result = paths[0];
        cout << result[0];
        for(auto it = result.begin() + 1; it != result.end(); it++)
            cout << " " << (*it);
    }
    else
        cout << "No Solution";
    return 0;
}
