#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string pats;
    cin >> pats;
    long long pat = 0, p = 0, pa = 0;
    for(int i = 0; i < pats.size(); i++)
    {
        if(pats[i] == 'P')                              /* 从零到i这个位置，出现的p的个数 */
            p++;
        else if(pats[i] == 'A')   
            pa += p;                                    /* 到此位置，出现的pa个数等于p的个数加上之前pa的个数 */
        else
            pat += pa;                                  /* 同理 */
    }
    cout << pat % 1000000007;
    return 0;
}
