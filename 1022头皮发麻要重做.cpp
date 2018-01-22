#include <iostream>
#include <map>
#include <set>
#include <cstdio>
#include <string>

using namespace std;

// 全局变量的定义
int n, m, id;
map<string, set<int>> title, author, kw, puber, years;

// 函数原型
void PrintQuery(map<string, set<int>> &m, string &temp);

int main()
{
    cin >> n;
    string ttitle, tauthor, tkw, tpuber, tyear;
    for(int i = 0; i < n ; i++)
    {
        scanf("%d\n", &id);
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while(cin >> tkw)
        {
            kw[tkw].insert(id);
            char ch = getchar();
            if(ch == '\n')
                break;
        }
        getline(cin, tpuber);
        puber[tpuber].insert(id);
        getline(cin, tyear);
        years[tyear].insert(id);
    }
    cin >> m;
    int num;
    string temp;
    for(int i = 0; i < m; i++)
    {
        scanf("%d: ", &num);
        getline(cin, temp);
        cout << num << ": " << temp << endl;
        if(num == 1)
            PrintQuery(title, temp);
        else if(num == 2)
            PrintQuery(author, temp);
        else if(num == 3)
            PrintQuery(kw, temp);
        else if(num == 4)
            PrintQuery(puber, temp);
        else if(num == 5)
            PrintQuery(years, temp);
    }
    return 0;
}

void PrintQuery(map<string, set<int>> &m, string &temp)
{
    if(m[temp].size() > 0)
    {
        for(auto it = m[temp].begin(); it != m[temp].end(); it++)
            printf("%07d\n", *it);
    }
    else
        cout << "Not Found" << endl;
}
