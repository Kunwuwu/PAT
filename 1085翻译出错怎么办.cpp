#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> num;

int main()
{
    long n, p;                                                   /* 这个long很重要 */
    cin >> n >> p;
    for(int i = 0; i < n; i++)
    {
        long temp;
        scanf("%ld", &temp);
        num.push_back(temp);
    }
    sort(num.begin(), num.end());
    int result = 0, temp = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = result + i; j < n; j++)                     /* 不解释了 */
        {
            if(num[j] <= num[i] * p)
            {
                temp = j - i + 1;
            }
            else
                break;
        }
        result = temp;
    }
    cout << result;
    return 0;
}
