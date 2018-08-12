#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    vector<int> dp(m + 1), w(n + 1), ans;
    bool choice[110][10010];
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    sort(w.begin() + 1, w.end());
    reverse(w.begin() + 1, w.end());
    for (int i = 1; i <= n; i++) {/* 为了满足1 2 4 < 1 3 3 这种设定，使得背包从重的开始选，最终会选到最轻的物体 */
        for (int j = m; j >= w[i]; j--) {
            if (dp[j] <= dp[j - w[i]] + w[i]) { /* 如果装下这个物体获得的收益等于或大于之前同等重量的收益 */
                dp[j] = dp[j-w[i]] + w[i];
                choice[j][i] = true;            /* 表示选择当包内j重的物体时，获得最大收益的情况下最轻 */
            }
        }
    }
    if (dp[m] == m) {
        for (int i = n; i >= 1; i--) {
            if (choice[m][i]) {
                ans.push_back(w[i]);
                m -= w[i];
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", ans[i]);
        }
    } else printf("No Solution");
    return 0;
}

/******************思路*********************/
/* 1、01背包的思路就是：背包内背满m重量物体获得最大收益一定是建立在载重为0,1,2,3...m取得最大收益的情况下的，
 * 2、本题的不同之处在于，选取物体的质量序列要最小，比如选取9重量的物体，则1,3,5会比1,4,4更符合要求，这样就要求
 * 物体的质量选取要从大到小选，这样就使得最后选取到的物体质量总是最少；
 * 3、题目的思路是：质量m选取的众多物体中，choice要选一个最小的（假设质量为p），然后根据（1）中说到的背包原则，质量(m-p)选取的（m-p）质量物体一定也能获得最大收益，且它也一定选了一个最小质量物体。。。
 * */
