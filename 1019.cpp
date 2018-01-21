/*
 * 题目比较容易，就没写注释了，唯一注意的地方就是零
 * */
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 全局变量
vector<int> result;

// 函数原型
bool convertToBase(int n, int base);

int main()
{
    long long  n, base;
    cin >> n >> base;
    bool ok = convertToBase(n, base);
    if(ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    if(n != 0)
        for(auto it = result.begin(); it != result.end(); it++)
        {
            if(it + 1 == result.end())
                cout << *it;
            else
                cout << *it << " ";
        }
    else
     cout << "0";
    return 0;
}

bool convertToBase(int n, int base)
{
    vector<int> convert;
    stack<int> s;
    while(n > 0)
    {
        convert.push_back(n % base);
        s.push(n % base);
        n /= base;
    }
    while(!s.empty())
    {
        int temp = s.top();
        result.push_back(temp);
        s.pop();
    }
    if(result == convert)
        return true;
    else
        return false;
}
