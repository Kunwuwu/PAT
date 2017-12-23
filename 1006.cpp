#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;


// 初始化定义


int main()
{
    int h1, h2, m1, m2, s1, s2;
    int n;
    int tin, tout;
    int min = INT_MAX, max = INT_MIN;
    scanf("%d", &n);
    string unlock, locked;
    for(int i = 0; i < n ; i++)
    {
        string tmp;
        cin >> tmp;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        tin = h1 * 3600 + m1 * 60 + s1;
        tout = h2 * 3600 + m2 * 60 + s2;
        if(tout > max)
        {
            max = tout;
            locked = tmp;
        }
        if(tin < min)
        {
            min = tin;
            unlock = tmp;
        }
    }
    cout << unlock << " " << locked;
    return 0;
}
