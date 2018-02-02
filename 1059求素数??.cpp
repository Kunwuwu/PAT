#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 100000;
vector<int> factors(100000, 0);
long n;

bool isprime(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

void find(long num)
{
    for(int i = int(round(sqrt(num))); i >= 2; i--)
    {
        if(num % i == 0 && isprime(i))
        {
            factors[i]++;
            if(isprime(num / i))
                factors[num / i]++;
            find(num / i);
            return ;
        }
    }
}

int main()
{
    cin >> n;
    find(n);
    cout << n <<"=";
    int count = 0;
    if(isprime(n))                                           /* 如果这个数本身就是素数，那唯一的因数就是自己 */
    {
        cout << n;
        return 0;
    }
    for(int i = 0; i < MAX; i++)
    {
        if(factors[i] == 1 && count > 0)
            printf("*%d", i);
        else if(factors[i] > 1 && count > 0)
            printf("*%d^%d", i, factors[i]);
        else if(factors[i] == 1 && count == 0)
        {
            printf("%d", i);
            count++;
        }
        else if(factors[i] > 1 && count == 0)
        {
            printf("%d^%d", i, factors[i]);
            count++;
        }
    }
    return 0;
}
