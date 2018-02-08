#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<string> v;

int main()
{
    cin >> n;
    getchar();                                                     /* 接收掉回车，这个很重要 */
    int minlen = 300;
    string temp;
    for(int i = 0; i < n; i++)
    {
        getline(cin, temp);
        v.push_back(temp);
        if(temp.length() < minlen)                                 /* 记录字符串的最小长度 */
            minlen = temp.length();
    }
    int cnt = 1;
    string ans;
    while(cnt <= minlen)                                           /* 从每个字符串的最后一个字符开始比较，直到不相同 */
    {
        char ch = v[0][v[0].length() - cnt];
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(v[i][v[i].length() - cnt] != ch)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            ans.push_back(ch);
        }
        else
            break;
        cnt++;
    }
    if(ans.size() > 0)
    {
        for(int i = ans.length() - 1; i >= 0; i--)
            printf("%c", ans[i]);
    }
    else
        cout << "nai";
    return 0;
}
