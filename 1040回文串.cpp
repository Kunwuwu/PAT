#include <cstdio>
#include <iostream>

using namespace std;

string org;                                               /* 不知道为毛这个题没传到github */

int main()
{
    getline(cin, org);                                    /* 接受一整行的字符串 */
    int maxsub = 1;
    int len = org.length();
    for(int i = 0; i < len; i++)
    {
        if(i < len - 1 && org[i] == org[i+1])             /* 如果是相邻字符对称（AA）的回文串 */
        {
            int left = i, right = i + 1;
            while(left >= 0 && right < len && org[left] == org[right])
            {
                if(right - left + 1 > maxsub)
                    maxsub = right - left + 1;
                left--;
                right++;
            }
        }
        else if(i < len - 2 && org[i] == org[i+2])        /* 如果是ABA样式的回文串 */
        {
            int left = i, right = i + 2;
            while(left >= 0 && right < len && org[left] == org[right])
            {
                if(right - left + 1 > maxsub)
                    maxsub = right - left + 1;
                left--;
                right++;
            }
        }
    }
    cout << maxsub;
    return 0;
}
