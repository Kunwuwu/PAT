#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;

bool cmp(int c, int d)
{
    return c > d;
}

int main()
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end(), cmp);
    int index = 0;
    while(a[index] > index + 1 && index < n)              /* 找到一个最大数，让a[i] > i就行（结果是i-1） */
        index++;                                          /* 实际上下标i（从1开始）就是天数 */
    cout << index;                                        /* 天数和E就是i，但是骑的距离a[i]要比i大 */
    return 0;
}
