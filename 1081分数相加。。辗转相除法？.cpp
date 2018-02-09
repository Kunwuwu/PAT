#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n;

int gcd(long long a, long long b)                               /* 辗转相除法？？？ */
{
    if(b == 0)
        return abs(a);
    else
        return gcd(b, a % b);
}

int main()
{
    long long suma = 0, sumb = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        int gcdvalue = gcd(a, b);
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = suma * b + sumb * a;
        sumb = sumb * b;
        gcdvalue = gcd(suma, sumb);
        suma /= gcdvalue;
        sumb /= gcdvalue;
    }
    long long integer = suma / sumb;
    long long a = suma % sumb;
    int gcdvalue = gcd(a, sumb);
    a /= gcdvalue;
    sumb /= gcdvalue;
    if(integer == 0)
    {
        if(a != 0)
            printf("%lld/%lld", a, sumb);
    }
    else
    {
        printf("%lld", integer);
        if(a != 0)
            printf(" %lld/%lld", a, sumb);
    }
    if(integer == 0 && a == 0)
        printf("0");
    return 0;
}
