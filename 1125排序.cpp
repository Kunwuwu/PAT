#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());                             /* 为了让长度更长，应该让长的绳子尽量少的被折叠 */
    double sum = (double)v[0];
    for(int i = 1; i < n; i++)                            /* 模拟折叠的过程 */
    {
        sum += (double)v[i];
        sum /= 2;
    }
    printf("%d", int(sum));
    return 0;
}
