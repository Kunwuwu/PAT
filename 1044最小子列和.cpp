#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    int left, right;
}node;

int n, m;
vector<int> chain;
vector<int> sumchain;
vector<node> tlists;

int main()
{
    cin >> n >> m;
    chain.resize(n + 1);
    sumchain.resize(n + 1);
    int sum = 0;
    int maxm = 999999999;
    for(int i = 1; i <= n; i++)
    {
        int money;
        scanf("%d", &money);
        sum += money;
        chain[i] = money;
        sumchain[i] = sum;                                /* 记录的是到i的子列和 */
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int tsum = sumchain[j] - sumchain[i] + chain[i];  /* 不用累加，直接可以计算出连续子列的和 */
            if(tsum < maxm && tsum >= m)
            {
                maxm = tsum;
                tlists.clear();
                tlists.push_back(node{i, j});
                break;
            }
            else if(tsum == maxm && tsum >= m)
            {
                tlists.push_back(node{i, j});
                break;
            }
            else if(tsum > maxm)                              /* 当前子列的和已经大于最大值的时候就可以break了，防止超时 */
                break;
        }
        if(sumchain[n] - sumchain[i] + chain[i] < m)          /* 当剩下子列的和已经小于m时，直接break，防止超时 */
            break;
    }
    for(int i = 0; i < tlists.size(); i++)
        printf("%d-%d\n", tlists[i].left, tlists[i].right);
    return 0;
}
