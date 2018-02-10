#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

string shuzi[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string shuwei[] = {"", "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian"};
string orgstr;
bool isfu;

string stripzero(string num)
{
    int i = 0;
    string ans;
    while(num[i] == '0')
        i++;
    for(; i < num.length(); i++)
        ans.push_back(num[i]);
    return ans;
}

int main()
{
    string num;
    vector<string> ans;
    cin >> orgstr;
    if(orgstr[0] == '-')
    {
        for(int i = 1; i < orgstr.length(); i++)
            num.push_back(orgstr[i]);
        isfu = true;
    }
    else
        num = orgstr;
    num = stripzero(num);
    if(num.size() == 0)
    {
        printf("ling");
        return 0;
    }
    if(isfu)
        ans.push_back("Fu");
    int wei = num[0] - '0';
    ans.push_back(shuzi[wei]);
    if(num.length() == 9)
        ans.push_back("Yi");
    else
        ans.push_back(shuwei[num.length()]);
    for(int i = 1; i < num.length(); i++)
    {
        int index = num.length() - i;
        if(num[i] != '0')
        {
            int wei = num[i] - '0';
            ans.push_back(shuzi[wei]);
            ans.push_back(shuwei[index]);
        }
        else                                               /* 观察后面有没有非零的数字 */
        {
            int j = i + 1;
            bool flag = false;                             /* true表示后面有非零的数字 */
            while(j < num.length())
            {
                if(num[j] != '0')
                {
                    flag = true;
                    break;
                }
                j++;
            }
            if(flag)
            {
                if(index >= 5 && (num.length() - j) <= 4)
                {
                    int len = num.length();
                    if(len == 9 && (num[1] == '0' && num[2] == '0' && num[3] == '0' && num[4] == '0'))
                        printf("");
                    else
                        ans.push_back("Wan");
                }
                ans.push_back("ling");
                i = j - 1;
            }
            else
                break;
        }
    }
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++)
    {
        if(ans[i].length() != 0)                /* 发现了一个PAT的bug，当输入的字符串即使为空，也会判错，巨诡异 */
            cout << " " << ans[i];
    }
    return 0;
}
