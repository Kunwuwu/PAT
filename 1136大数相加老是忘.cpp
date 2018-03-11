#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

string add(string a, string b)                            /* 大数相加 */
{
    int high = 0;
    string ans;
    for(int i = 0; i < a.length(); i++)
    {
        int sum = a[i] - '0' + b[i] - '0' + high;
        if(sum < 10)
        {
            char ch = sum + '0';
            ans.push_back(ch);
            high = 0;
        }
        else
        {
            char ch = sum % 10 + '0';
            ans.push_back(ch);
            high = 1;
        }
    }
    if(high == 1)
        ans.push_back('0' + high);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a, b;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    int cnt = 0;
    while(a != b && cnt != 10)                            /* 终止条件 */
    {
        string c = add(a, b);
        cout << a << " + " << b << " = " << c << endl;
        a = c;
        b = a;
        cnt++;
        reverse(b.begin(), b.end());
    }
    if(cnt == 10 && a != b)
        printf("Not found in 10 iterations.");
    else
        cout << a << " is a palindromic number.";
    return 0;
}
