#include <iostream>
#include <cstdio>
using namespace std;

// exponents and coefficients 指数和系数

int main()
{
    double result[1001] = {0};                            //result数组的下标就是指数，值就是系数
    int exp, count = 0;                                   //count用来记录非零系数项的个数
    double coef;
    int a, b;
    cin >> a;
    for(int i = 0; i < a; i++)
    {
        cin >> exp >> coef;
        result[exp] += coef;
    }
    cin >> b;
    for(int i = 0; i < b; i++)
    {
        cin >> exp >> coef;
        result[exp] += coef;
    }
    for(int i = 0; i < 1001; i++)
    {
        if(result[i] != 0)                                //这里注意不能使用 > 0，因为系数有可能是负数
            count++;
    }
    cout << count;
    for(int i = 1000; i >= 0; i--)
    {
        if(result[i] != 0) {
            printf(" %d %.1lf", i, result[i]);
        }
    }
    return 0;
}
