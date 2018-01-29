#include <cstdio>                           /* 因为超时，讲真，思路有点难理解，这种题目还是只能拿22分 */
#include <iostream>                         /* 感觉这个规律让直接推导出来也是件不简单的事情 */

using namespace std;

int main()
{
    int n;
    cin >> n;
    int now, left, right, a = 1, ans = 0;
    while(n / a)
    {
        left = n / (a * 10), now = (n / a) % 10, right = n % a;        /* 注意这now的计算方法 */
        if(now == 0)
            ans += left * a;
        else if(now == 1)
            ans += (left * a + right + 1);
        else
            ans += (left + 1) * a;
        a *= 10;
    }
    cout << ans;
    return 0;
}
