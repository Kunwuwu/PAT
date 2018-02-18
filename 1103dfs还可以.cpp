#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> path, tpath;
int n, k, p;
int maxsum = -1;

void dfs(int sum, int fac, int cnt)                      /* dfs遍历，老同志了 */
{
    sum -= int(pow(fac, p));
    tpath.push_back(fac);
    if(sum == 0 && cnt == 1)
    {
        int tsum = 0;
        for(int i = 0; i < tpath.size(); i++)
        {
            tsum += tpath[i];
        }
        if(tsum > maxsum)
        {
            maxsum = tsum;
            path = tpath;
        }
        tpath.pop_back();
        return ;
    }
    else if(sum > 0 && cnt > 1)                          /* 剪枝 */
    {
        for(int i = fac; i >= 1; i-- )
            dfs(sum, i, cnt - 1);
    }
    else                                                 /* 剪枝 */
    {
        tpath.pop_back();
        return ;
    }
    tpath.pop_back();
}

int main()
{
    cin >> n >> k >> p;
    for(int i = sqrt(n); i >= 1; i--)
    {
        tpath.clear();                                   /* 这里初始化的时候踩了个坑，加了句maxsum = -1，导致错误，巨尴尬 */
        dfs(n, i, k);
    }
    if(!path.empty())
    {
        printf("%d = %d^%d", n, path[0], p);
        for(int i = 1; i < path.size(); i++)
            printf(" + %d^%d", path[i], p);
    }
    else
        printf("Impossible");
    return 0;
}
