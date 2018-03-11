#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n;

int main()
{
    int maxsum = -1;                                      /* 这个一定要小于零，不然会有一个测点过不了，如-1 -1 0 -1 */
    int tempsum = 0;
    cin >> n;
    v.resize(n);
    int left = 0, right = n - 1, tleft = 0, tright = 0;   /* 如果是全负的情况，则left和right不会更新，这样代表整个序列 */
    bool flag = false;
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 0;i < n; i++)
    {
        tempsum += v[i];
        tright = i;
        if(tempsum > maxsum)
        {
            maxsum = tempsum;
            left = tleft;
            right = tright;
        }
        if(tempsum < 0)
        {
            tempsum = 0;
            tleft = i + 1;
        }
    }
    if(maxsum < 0) maxsum = 0;
    printf("%d %d %d", maxsum, v[left], v[right]);
}
