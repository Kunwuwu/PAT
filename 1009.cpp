#include <cstdio>
#include <iostream>

using  namespace std;

int main()
{
    double poly1[1005] = {0}, poly2[1005] = {0}, poly3[2010] = {0};
    int n, m;
    double coef;
    int exp, count = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> exp >> coef;
        poly1[exp] = coef;
    }
    cin >> m;
    for(int i = 0; i < m;i++)
    {
        cin >> exp >> coef;
        poly2[exp] = coef;
        for(int j = 0; j < 1005; j++)                 // 注意这里是1005，因为这个最高次方可能比n大
        {
            poly3[j+exp] += coef * poly1[j];
        }
    }
    for(int i = 0; i < 2010; i++)
    {
        if(poly3[i] != 0.0)                           // 这里是必须0.0，每次都忘哎
        {
            count++;
        }
    }
    cout << count;
    for(int i = 2009; i >= 0; i--)
    {
        if(poly3[i] != 0.0)                           // 这里是必须0.0，每次都忘哎
            printf(" %d %.1lf", i, poly3[i]);
    }
    return 0;
}
