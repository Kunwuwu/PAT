#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, largestp = 0, largestlevel = -1;
vector<vector<int>> family;
int levels[100];

void dfs(int root, int level)                                          /* 带层数的dfs */
{
    levels[level]++;
    if(levels[level] > largestp)
    {
        largestlevel = level + 1;
        largestp = levels[level];
    }
    if(family[root].size() == 0)
        return ;
    else
    {
        for(int i = 0; i < family[root].size(); i++)
            dfs(family[root][i], level + 1);
    }
}

int main()
{
    cin >> n >> m;
    family.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
        int temp, tsize;
        scanf("%d %d", &temp, &tsize);
        family[temp].resize(tsize);
        for(int i = 0; i < tsize; i++)
            scanf("%d", &family[temp][i]);
    }
    dfs(1, 0);
    cout << largestp << " " << largestlevel;
    return 0;
}
