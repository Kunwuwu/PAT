#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int mul(int l, int u)
{
    int result = 1;
    for(int i = l; i <= u; i++)
        result *= i;
    return result;
}

int main()
{
    int n;
    cin >> n;
    int sqrtn = sqrt(n);                                                    /* 你懂的 */
    for(int result = 12; result >= 0; result--)                             /* 很机智，因为连续的因数，肯定是能被整除的 */
    {                                                                       /* 而12！就已经超过2^31了，肯定不会超过12个长度 */
        for(int start = 2; start <= sqrtn; start++)                         /* 剩下的就是从大到小寻找这个能被整除的串 */
        {
            if(n % mul(start, start + result) == 0)                         /* 如果这个连续的串能被整除 */
            {
                cout << result + 1 << endl;
                printf("%d", start);
                for(int i = start + 1; i <= start + result; i++)
                {
                    printf("*%d", i);
                }
                return 0;
            }
        }
    }
    printf("1\n%d", n);
    return 0;
}
