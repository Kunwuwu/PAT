#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s1, s2, ans;
bool cnt[128];

int main()
{
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++)
    {
        bool have = false;
        for(int j = 0; j < s2.length(); j++)
        {
            if(isalpha(s1[i]) && isalpha(s2[j]))
            {
                if(tolower(s1[i]) == tolower(s2[j]))
                {
                    have = true;
                    break;
                }
            }
            else if(s1[i] == s2[j])
            {
                have = true;
                break;
            }
        }
        if(!have)
        {
            int index = toupper(s1[i]);
            if(!cnt[index])
            {
                ans.push_back(toupper(s1[i]));
                cnt[index] = true;
            }
        }
    }
    cout << ans;
    return 0;
}
