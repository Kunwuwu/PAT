#include <cstdio>
#include <iostream>

using namespace std;

string orgstr, result, notok;
int k;
bool keyisok[128], aha[128];

int main()
{
    cin >> k >> orgstr;
    for(int i = 0; i < orgstr.length(); i++)              /* 两次遍历，第一次确定哪个字母是坏的 */
    {
        char ch = orgstr[i];
        int index = ch;
        if(!keyisok[index])
        {
            for(int j = 0; j < k; j++)
            {
                if(orgstr[i+j] != ch)
                {
                    keyisok[index] = true;
                    break;
                }
            }
        }
        if(!keyisok[index])
            i += (k - 1);
    }
    for(int i = 0; i < orgstr.length(); i++)              /* 第二次将字符串赋值到result中，根据字母是否是坏的 */
    {
        char ch = orgstr[i];
        int index = ch;
        if(!keyisok[index])
        {
            result.push_back(ch);
            i += (k - 1);
            if(!aha[index])
            {
                notok.push_back(ch);
                aha[index] = true;
            }
        }
        else
            result.push_back(ch);
    }
    cout << notok << endl;
    cout << result;
    return 0;
}
