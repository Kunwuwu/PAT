#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string nums[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};

string hnum[] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int strtonum(string num)
{
    int ans = 0;
    int len = num.length();
    for(int i = 0; i < len; i++)
    {
        int temp = num[i] - '0';
        int mi = len - i - 1;
        int pw =  pow(10, mi);
        ans += pw * temp;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    string num;
    for(int i = 0; i < n; i++)
    {
        getline(cin, num);
        if(isalpha(num[0]))
        {
            int ans = 0;
            if(num.length() > 4)
            {
                string t1, t2;
                int j = 0;
                while(num[j] != ' ')
                {
                    t1.push_back(num[j]);
                    j++;
                }
                j++;
                for(; j < num.length(); j++)
                {
                    t2.push_back(num[j]);
                }
                for(int j = 1; j < 13; j++)
                {
                    if(hnum[j] == t1)
                    {
                        ans += j * 13;
                        break;
                    }
                }
                for(int j = 1; j < 13; j++)
                {
                    if(nums[j] == t2)
                    {
                        ans += j;
                        break;
                    }
                }
            }
            else
            {
                for(int j = 1; j < 13; j++)
                {
                    if(hnum[j] == num)
                    {
                        ans += j * 13;
                        break;
                    }
                }
                for(int j = 1; j < 13; j++)
                {
                    if(nums[j] == num)
                    {
                        ans += j;
                        break;
                    }
                }
            }
            printf("%d\n", ans);
        }
        else
        {
            int data = strtonum(num);
            int a = data / 13;
            int b = data % 13;
            if(a != 0 && b != 0)
                cout << hnum[a] << " " << nums[b] << endl;
            else if(b == 0)
                cout << hnum[a] << endl;
            else
                cout << nums[b] << endl;
        }
    }
    return 0;
}
