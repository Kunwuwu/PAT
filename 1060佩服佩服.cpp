#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
string numa, numb;
string resa, resb;

bool cmpstr(string a, string b)                             /* 比较两个字符串 */
{
    int i = 0, j = 0;
    while(a[i] == '0' || a[i] == '.')                       /* 跑到小数点后 */
        i++;
    while(b[j] == '0' || b[j] == '.')
        j++;
    for(int k = 0; k < n; k++)
    {
        if(i < a.length() && a[i] != '.')
            resa.push_back(a[i]);
        else if(i < a.length())
        {
            if(i + 1 < a.length())
            {
                resa.push_back(a[i+1]);
                i++;
            }
        }
        if(j < b.length() && b[j] != '.')
            resb.push_back(b[j]);
        else if(j < b.length())
        {
            if(j + 1 < b.length())
            {
                resb.push_back(b[j+1]);
                j++;
            }
        }
        i++;
        j++;
    }
    while(resa.size() < n)
    {
        resa.push_back('0');
    }
    while(resb.size() < n)
    {
        resb.push_back('0');
    }
    bool flag = false;
    if(resa == resb)
        flag = true;
    return flag;
}

int coefn(string num)                                   /* 计算得到指数 */
{
    int coef = num.length();
    for(int i = 0; i < num.length(); i++)               /* 找到小数点 */
    {
        if(num[i] == '.')
        {
            coef = i;
            break;
        }
    }
    if(num[0] == '0')                                   /* 如果数小于一 */
    {
        int i = coef + 1;
        while(num[i] == '0')
            i++;
        if(i < num.size())
            coef = -(i - coef - 1);
        else                                           /* 坑点：0.0000 */
            coef = 0;
    }
    return coef;
}

string strip0(string str)                              /* 坑点：去掉前面的零，比如00012这种情况 */
{
    int i = 0;
    string result;
    while(str[i] == '0' && str[i + 1] != '.')
        i++;
    for(;i < str.length(); i++)
        result.push_back(str[i]);
    return result;
}

int main()
{
    cin >> n >> numa >> numb;                           /* 首先判断两个数的数量级是否相等 */
    numa = strip0(numa), numb = strip0(numb);
    int coefa = coefn(numa), coefb = coefn(numb);
    if(cmpstr(numa, numb) && coefa == coefb)
    {
        cout << "YES ";
        printf("0.");
        cout << resa << "*" << 10 << "^" << coefa;
    }
    else
    {
        cout << "NO ";
        printf("0.");
        cout << resa << "*" << 10 << "^" << coefa << " ";
        printf("0.");
        cout << resb << "*" << 10 << "^" << coefb;
    }
    return 0;
}
