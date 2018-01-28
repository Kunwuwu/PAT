/*
 * 讲真，我觉得这道题要考虑m = 0的，但是题目没考虑这种情况。。。
 * */

#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct
{
    int start;
    int end;
}cut;

vector<int> chains;
int n, m;
const int inf = 999999999;         /* 莫不是有毒？？？99999999不行，要999999999？？？？ */
vector<cut> result;

int main() {
    cin >> n >> m;
    cut tcut;
    chains.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &chains[i]);
    }
    int fwdindex, thissum, minsum = inf;
    for(int i = 1; i <= n; i++)
    {
        fwdindex = i;
        thissum = 0;
        while(fwdindex <= n && thissum < m)
        {
            thissum += chains[fwdindex];
            fwdindex++;
        }
        tcut.start = i;
        tcut.end = fwdindex - 1;                          /* 因为fwdindex更新是在计算thissum之后的，所以要减1的 */
        if(thissum < m)                                   /* 如果最后的diamond的和不够钱了，就不用继续了 */
            break;
        if(minsum == m)
        {
            if(thissum == minsum)
                result.push_back(tcut);
        }
        else
        {
            if(thissum < minsum)
            {
                minsum = thissum;
                result.clear();
                result.push_back(tcut);
            }
            else if(thissum == minsum)
                result.push_back(tcut);
        }
    }
    for(auto it = result.begin(); it != result.end(); it++)
        printf("%d-%d\n", (*it).start, (*it).end);
    return 0;
}
