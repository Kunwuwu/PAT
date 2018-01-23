#include <cstdio>
#include <iostream>
#include <string>
#include <set>

using namespace std;

string nums;
char dbnums[25];
set<char> s1, s2;

int main()
{
    cin >> nums;
    int index = 0,count = 0;
    fill(dbnums, dbnums + 25, '0');
    for(int i = nums.length() - 1; i >= 0; i--)
    {
        if((dbnums[index] + 2 * (nums[i] - '0') - '0') < 10)            /* 判断的时候也要抓化成数字 */
        {
            dbnums[index] += 2 * (nums[i] - '0');          /* 必须转化为数字相加 */
            if(i == 0)
                count = nums.length();
        }
        else
        {
            dbnums[index] += (2 * (nums[i] - '0')) % 10;
            dbnums[index+1] += (2 * (nums[i] - '0')) / 10;
            if(i == 0)                                   /* 如果在最后一位数进位了，则说明double后变长了 */
                count = nums.length() + 1;
        }
        index++;
    }
    for(auto it = nums.begin(); it != nums.end(); it++)             /* 使用set的去重性来判断是否相等 */
    {
        s1.insert(*it);
    }
    for(int i = 0; i < count; i++)
    {
        s2.insert(dbnums[i]);
    }
    if(s1 == s2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for(int i = count - 1; i >= 0; i--)
        cout << dbnums[i];
    return 0;
}
