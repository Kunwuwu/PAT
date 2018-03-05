#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 10001;
int father[MAX];
int cnt = 0, cntfa;
bool isfather[MAX];
bool visited[MAX];
int n, q;

int tfind(int x)                                          /* 并查集的find操作 */
{
    while(x != father[x])
        x = father[x];
    return x;
}

void tunion(int a, int b)                                 /* 并查集的union操作 */
{
    int fa = tfind(a);
    int fb = tfind(b);
    if(fa < fb)
        father[fb] = fa;
    else if(fa > fb)
        father[fa] = fb;
}

int main()
{
    cin >> n;
    for(int i = 0; i < MAX; i++)                          /* 并查集 */
        father[i] = i;
    int k;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if(k > 1)
        {
            int fa, cd;
            scanf("%d", &fa);
            if(fa > cnt) cnt = fa;                        /* 记录最大下标的鸟 */
            for(int j = 1; j < k; j++)
            {
                scanf("%d", &cd);
                if(cd > cnt) cnt = cd;
                tunion(fa, cd);
            }
        }
        else if(k == 1)                                   /* 开始把这个忘了，倒是有些测点通不过，要考虑k=1的情况 */
        {
            int fa;
            scanf("%d", &fa);
            if(fa > cnt)
                cnt = fa;
        }
    }
    for(int i = 1; i <= cnt; i++)                         /* 找到每颗树上的老大，标记一个老大就标记一棵树 */
    {
        int fa;
        fa = tfind(i);
        isfather[fa] = true;
    }
    for(int i =1; i <= cnt; i++)                          /* 统计老大的数量 */
    {
        if(isfather[i])
            cntfa++;
    }
    cout << cntfa << " " << cnt << endl;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int b1, b2;
        scanf("%d %d", &b1, &b2);
        if(tfind(b1) == tfind(b2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
