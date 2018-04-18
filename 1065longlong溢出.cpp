#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        long long a, b, c;
        string ans;
        cin >> a >> b >> c;
        long long sum = a + b;                          /* c不可能溢出 */
        if(a > 0 && b > 0 && sum < 0)                   /* 如果a,b都大于零，而sum溢出的话，肯定大于c，sum的值为负 */
            ans = "true";
        else if(a < 0 && b < 0 && sum >= 0)             /* a,b为负，sum溢出，sum应该小于c，sum实际为非负数， */
            ans = "false";
        else if(sum > c)                                /* 比较有意思的是这里的sum直接用a+b的话只能过一个测点 */
            ans = "true";
        else
            ans = "false";
        printf("Case #%d: ", i);
        cout << ans << endl;
    }
    return 0;
}
