#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

// 全局变量的定义及初始化
string num;
int k;

// 函数原型
void paired(string tnum);

int main()
{
    cin >> num >> k;
    int step = -1;
    for(int i = 0; i < k; i++)
    {
        string tnum = num;
        reverse(tnum.begin(), tnum.end());                    /* 将tnum反转 */
        if(tnum == num)                                       /* 反转后相等，即为回文数 */
        {
            step = i;
            break;
        }
        paired(tnum);                                         /* 如果当前不是回文数，继续进行paired操作 */
    }
    if(step == -1)
        step = k;
    cout << num << endl;
    cout << step << endl;
    return 0;
}

void paired(string tnum)
{
    int len = num.length();
    int over = 0;
    for(int i = 0; i < len; i++)                                /* over表示进位的数 */
    {
        int carry = (num[i] - '0') + (tnum[i] - '0') + over;    /* carry表示当前数位相加后的结果 */
        if(carry < 10)                                          /* 不需要进位 */
        {
            num[i] = carry + '0';
            over = 0;
        }
        else                                                    /* 需要进位 */
        {
            num[i] = '0' + carry % 10;
            over = carry / 10;
        }
    }
    if(over > 0)                                                /* 注意最后一位的进位需要改变num字符串对象的大小 */
        num.insert(num.end(), over + '0');
    reverse(num.begin(), num.end());                            /* 得到的是一个反转的和，要倒过来 */
}
