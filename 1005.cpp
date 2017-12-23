#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

// 初始化定义

stack<char> s;
stack<int> index;
char out[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
    char ch;
    int sum = 0;
    int num;
    bool is_zero = false;
    while((ch = getchar()) != '\n')
    {
        s.push(ch);
    }
    while(!s.empty())                                 // 使用栈的特性
    {
        num = s.top() - '0';
        sum += num;
        s.pop();
    }
    if(!sum)
        is_zero = true;
    while(sum > 0)
    {
        index.push(sum % 10);
        sum /= 10;
    }
    if(!index.empty())                                // 如果栈是空的，会发生段错误，所以先判断
    {
        cout << out[index.top()];
        index.pop();
    }
    if(!is_zero)
    {
        while(!index.empty())
        {
            cout << " " << out[index.top()];
            index.pop();
        }
    }
    else
        cout << "zero";
    return 0;
}
