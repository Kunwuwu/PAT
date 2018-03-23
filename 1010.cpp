#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long map[256];                                       // 这个应该是不用那么大的
char n1[20], n2[20];

// 二分查找对应的进制
long long binarySearch(char n2[], long long low, long long high, long long deOfn1);
// 将字符转化成十进制
long long convertToTen(char num[], long long radix);
// 比较函数
int cmp(char n2[], long long radix, long long deOfn1);
int findMaxDigit(char n2[]);


int main()
{
    int tag;
    long long radix;
    cin >> n1 >> n2 >> tag >> radix;
    for(char c = '0'; c <= '9'; c++)
    {
        map[c] = c - '0';
    }
    for(char c = 'a'; c <= 'z'; c++)
    {
        map[c] = c - 'a' + 10;
    }
    if(tag == 2)
        swap(n1, n2);
    long long deOfn1 = convertToTen(n1, radix);
    long long low = findMaxDigit(n2);                     // 进制最小应该大于所有数位中最大的数字
    long long high = max(low, deOfn1) + 1;                // 进制最大不会大于数字n1的十进制值+1
    long long ans = binarySearch(n2, low, high, deOfn1);
    if(ans == -1)
        cout << "Impossible";
    else
        cout << ans;
    return 0;
}

long long convertToTen(char num[], long long radix)
{
    long long result = 0;
    for(int i = 0; i < strlen(num); i++)
    {
        result = result * radix + map[num[i]];
    }
    return result;
}

int findMaxDigit(char n2[])
{
    int ans = -1;
    for(int i = 0; i < strlen(n2); i++)
    {
        if(map[n2[i]] > ans)
        {
            ans = map[n2[i]];
        }
    }
    return ans + 1;
}

int cmp(char n2[], long long radix, long long deOfn1)
{
    long long deOfn2 = convertToTen(n2, radix);
    if(deOfn2 < 0)                                        // 这里主要考虑的是longlong溢出的时候为负数，即这时deOfn2肯定大于deOfn1
        return 1;
    if(deOfn2 < deOfn1)                                   // 表示进制在radix的右边
        return -1;
    else
        return (deOfn2 == deOfn1) ? 0 : 1;                // 找到了进制返回零，否则就是传入的radix过大了
}

long long binarySearch(char n2[], long long low, long long high, long long deOfn1)
{
    long long mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        int flag = cmp(n2, mid, deOfn1);
        if(flag == 1)
            high = mid - 1;
        else if(flag == -1)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
