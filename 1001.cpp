#include <iostream>
#include <cstdio>

//备注：字符串处理

using namespace std;

int main() {
    int a, b, count = 0, i = 0;        // count用于计数
    char str[20];
    cin >> a >> b;
    sprintf(str, "%d", (a+b));         // 将整型转化成字符数组，需要头文件cstdio
    string s = str;                    // 将字符数组转化成字符串类
    int len = s.length();              // 使用len变量储存字符串长度
    if(s[0] == '-')                    // 如果A+B和是负数，则输出‘-’，len记录数字的长度
    {
        len--;
        i = 1;                         // 使对字符串的遍历直接从数字开始
        cout << '-';                   // 输出‘-’，接下来直接处理数字就行
    }
    for (i; i < s.length(); i++) {        
        if((len - count) % 3 ==0 && count > 0)
            cout << ',';               // 如果从最后一个字符开始数，这个字符位置是3的的倍数，输出逗号
        cout << s[i];                         
        count++;
    }
    return 0;
}
