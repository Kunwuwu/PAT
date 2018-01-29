#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string oristr;
int asc[128];
string no;
string result;

int main()                              /* 思路就是转化成ascii码，详见asc数组，这个数组记录当前的字符是否应该删除 */
{
    fill(asc, asc + 128, 0);
    getline(cin, oristr);
    getline(cin, no);
    int count = 0;
    result.resize(oristr.size());        /* 开始用的oristr.size()-no.size()，系统判定异常退出，估计大小不够 */
    for(int i = 0; i < no.size(); i++)   /* 考虑是出现要减去的字符在原字符串中重复出现 */
    {
        int index = no[i];
        asc[index] = -1;
    }
    for(int i = 0; i < oristr.size(); i++)
    {
        int index = oristr[i];
        if(asc[index] != -1)
            result[count++] = oristr[i];
    }
    cout << result;
    return 0;
}
