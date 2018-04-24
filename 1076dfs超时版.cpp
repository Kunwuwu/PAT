#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> g;
int n, maxlevel, m;
int cnt = 0;
bool visited[1002];

void dfs(int root, int depth, vector<bool> &collected) {
    if(depth <= maxlevel) {
        if(!collected[root]) {
            collected[root] = true;
            cnt++;
        }
    }
    else
        return ;
    for (int i = 0; i < g[root].size(); i++) {
        if(!visited[g[root][i]]) {
            visited[g[root][i]] = true;
            dfs(g[root][i], depth + 1, collected);
            visited[g[root][i]] = false;
        }
    }
}

int main() {
    cin >> n >> maxlevel;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int temp;
            scanf("%d", &temp);
            g[temp].push_back(i);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cnt = 0;
        scanf("%d", &q);
        visited[q] = true;
        vector<bool> collected(n + 1);
        dfs(q, 0, collected);
        visited[q] = false;
        printf("%d\n", cnt - 1) ;
    }
    return 0;
}
