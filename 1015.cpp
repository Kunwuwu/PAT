#include <stack>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 函数原型
bool isPrime(int revNum);
int convertToRadix(int n, int radix);

int main()
{
    int n, radix;
    while(cin >> n)
    {
        if(n < 0)
            break;
        cin >> radix;
        if(!isPrime(n))
        {
            cout << "No" << endl;
            continue;
        }
        int convNum = convertToRadix(n, radix);;
        if(isPrime(convNum))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

int convertToRadix(int n, int radix)
{
    int d[100], index = 0;
    int revNum = 0;
    while(n > 0)
    {
        d[index++] = n % radix;
        n /= radix;
    }
    for(int i = 0; i < index; i++)
    {
        revNum = revNum * radix + d[i];
    }
    return revNum;
}

bool isPrime(int revNum)
{
    if(revNum <= 1)                                     /* 记住1不是素数也不是合数 */
        return false;
    for(int i = 2; i <= int(sqrt(revNum * 1.0)); i++)   /* 这里是小于等于。。。因为小错误。。。不谈了 */
    {
        if(revNum % i == 0)
        {
            return false;
        }
    }
    return true;
}
