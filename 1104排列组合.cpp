#include <cstdio>
#include <iostream>

using namespace std;

int n;
double result = 0.0;

int main()
{
    cin >> n;
    double temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &temp);
        result += temp * ( n - i) * (i + 1);               /* 排列组合，第i个数出现的次数是(n-i-1)*i */
    }
    printf("%.2lf", result);
    return 0;
}
