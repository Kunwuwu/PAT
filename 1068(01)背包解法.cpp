#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

const int MAX = 10002;

int dp[MAX];
bool choice[MAX][MAX];
int n, m;
vector<int> w;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n >> m;
    w.resize(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    sort(w.begin() + 1, w.end(), cmp);
    for(int i = 1; i <= n; i++) {
        for(int v = m; v >= w[i]; v--) {
            if(dp[v] <= dp[v-w[i]] + w[i]) {
                dp[v] = dp[v-w[i]] + w[i];
                choice[i][v] = true;
            }
        }
    }
    if (dp[m] != m)
        printf("No Solution");
    else {
        vector<int> ans;
        int v = m, index = n;
        for (; v > 0;) {
            if(choice[index][v]) {
                ans.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for (int i = 0; i < ans.size(); i++) {
            if(i != 0)
                printf(" ");
            printf("%d", ans[i]);
        }
    }
    return 0;
}
