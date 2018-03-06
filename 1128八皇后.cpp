#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1005;
int k, n;
int q[MAX];

int main()
{
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &n);
        vector<int> cntraw(n + 1, 0);
        vector<int> cntx(2 * n + 1, 0), cntfx(2 * n + 1, 0); /* 反斜，正斜 */
        bool flag = true;                                 /* 其实就是统计某一行出现的个数是多少 */
        for(int j = 1; j <= n; j++)                       /* 某一45度斜线上出现的个数有多少 */
        {                                                 /* 某一135度斜线上出现的个数有多少 */
            scanf("%d", &q[j]);
            cntraw[q[j]]++;
            int xie = j - q[j] + n;
            int fxie = j + q[j];
            cntx[xie]++;
            cntfx[fxie]++;
            if(cntraw[q[j]] > 1 || cntx[xie] > 1 || cntfx[fxie] > 1)
                flag = false;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
