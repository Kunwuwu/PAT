#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> nums;
int n;
string tnum;

bool cmp(string a, string b)
{
    return a + b < b + a;                                       /* 嘤嘤嘤，比较1234和4312与比较'1234'和'3412'是一样的啊 */
}

int main()
{
    cin >> n;
    string result;
    for(int i = 0; i < n; i++)
    {
        cin >> tnum;
        nums.push_back(tnum);
    }
    sort(nums.begin(), nums.end(), cmp);                        /* cmp简直神奇 */
    for(int i = 0; i < n; i++)
        result += nums[i];
    while(result[0] == '0' && result.length() != 0)             /* 移除前导零 */
        result.erase(result.begin());
    if(result.length() == 0)
        cout << "0";
    else
        cout << result;
    return 0;
}
