#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> coins;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    cin >> n >> m;
    int temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        coins.push_back(temp);
    }
    sort(coins.begin(), coins.end(), cmp);
    bool found = false;
    int v1, v2;
    for(int i = 0; i < n; i++)
    {
        v1 = coins[i];
        int low = i + 1, high = n - 1;                     /* 二分查找，我都快忘了，不然会超时的 */
        while(high >= low)                                 /* 这里应该是>=开始用了小于了 */
        {
            int mid = (high + low) / 2;
            if(v1 + coins[mid] < m)
            {
                low = mid + 1;
            }
            else if(v1 + coins[mid] > m)
            {
                high = mid - 1;
            }
            else
            {
                found = true;
                v2 = coins[mid];
                break;
            }
        }
        if(found)
            break;

    }
    if(found)
        cout << v1 << " " << v2;
    else
        cout << "No Solution";
    return 0;
}
