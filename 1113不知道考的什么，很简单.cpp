#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, n1, n2;
vector<int> s1, s2, s;

int main()
{
    cin >> n;
    s.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    sort(s.begin(), s.end());                             /* 集合s从大到小排序 */
    n2 = n / 2;                                           /* 拆成有n2个元素的s2，和有n1个元素的s1 */
    n1 = n - n2;                                          /* 要使得s1的和够大，s2的和够小，则让n2小于等于n的一半 */
    int sum2 = 0, sum1 = 0;
    for(int i = 0; i < n2; i++)
        sum2 += s[i];
    for(int i = n2; i < n; i++)
        sum1 += s[i];
    printf("%d %d", n1 - n2, sum1 - sum2);
    return 0;
}
