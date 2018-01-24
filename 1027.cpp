#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;



// 全局变量的定义
int r, g, b;
char color[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
vector<int> Red, Green, Blue;

void convert(int rgb, vector<int> &RGB)
{
    while(rgb > 0)
    {
        RGB.push_back(rgb % 13);
        rgb /= 13;
    }
}

int main()
{
    cin >> r >> g >> b;
    convert(r, Red);
    convert(g, Green);
    convert(b, Blue);
    cout << "#";
    if(Red.size() == 1)
    {
        cout << "0";
        cout << color[Red[0]];
    }
    else if(Red.empty())
        cout << "00";
    else
    {
        while(!Red.empty())
        {
            cout << color[Red.back()];
            Red.pop_back();
        }
    }
    if(Green.size() == 1)
    {
        cout << "0";
        cout << color[Green[0]];
    }
    else if(Blue.empty())
        cout << "00";
    else
    {
        while(!Green.empty())
        {
            cout << color[Green.back()];
            Green.pop_back();
        }
    }
    if(Blue.size() == 1)
    {
        cout << "0";
        cout << color[Blue[0]];
    }
    else if(Blue.empty())
        cout << "00";
    else
    {
        while(!Blue.empty())
        {
            cout << color[Blue.back()];
            Blue.pop_back();
        }
    }
    return 0;
}
