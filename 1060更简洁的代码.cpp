#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

string tran(string s, int &exp, int n) {                  /* 对每个数字进行处理 */
    while (*s.begin() == '0') s.erase(s.begin());         /* 除掉前导零 */
    if (s.length() == 0) s.push_back('0');                /* 如果全是零，加个零 */
    int dot = 0;
    for (; dot < s.length(); dot++) {                     /* 找到小数点的位置 */
        if (s[dot] == '.')
            break;
    }
    if (dot == s.length()) s.push_back('.');              /* 如果是整数，某尾加上小数点 */
    int start = 0;                                        /* 找到有效数字计算的起始点 */
    for (; start < s.length() && (s[start] == '.' || s[start] == '0'); start++);
    if (start < s.length())                               /* 防止全零 */
        exp = dot - start >= 0 ? dot - start : dot - start + 1;
    else
        exp = 0;
    string ans;
    int i = start;
    while (ans.length() < n && i < s.length()) {          
        if (s[i] != '.')
            ans.push_back(s[i]);
        i++;
    }
    for (; ans.length() < n; i++) ans.push_back('0');
    return ans;
}

int main() {
    int n;
    string a, b, A, B;
    cin >> n >> a >> b;
    int expa, expb;
    A = tran(a, expa, n);
    B = tran(b, expb, n);
    if (A == B && expa == expb) {
        printf("YES 0.");
        cout << A;
        printf("*10^%d", expa);
    } else {
        printf("NO 0.");
        cout << A;
        printf("*10^%d", expa);
        printf(" 0.");
        cout << B;
        printf("*10^%d", expb);
    }
    return 0;
}
