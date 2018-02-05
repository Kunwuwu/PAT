#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int vectonum(vector<int> v)                                       /* 将vector转化成数字 */
{
    return v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
}

int rv(int num)                                                   /* 升序、降序、打印结果 */
{
    vector<int> v, t;
    int a, b;
    v.resize(4);
    for(int i = 0; i < 4; i++)
    {
        v[i] = num % 10;
        num /= 10;
    }
    sort(v.begin(), v.end(), cmp);
    t = v;
    a = vectonum(v);
    sort(t.begin(), t.end());
    b = vectonum(t);
    printf("%04d - %04d = %04d\n", a, b, a - b);
    return a - b;
}

int main()
{
    int n;
    cin >> n;
    while(1)
    {
        n = rv(n);
        if(n == 0 || n == 6174)
            break;
    }
    return 0;
}
