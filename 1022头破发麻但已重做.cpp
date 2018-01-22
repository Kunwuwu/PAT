#include <cstdio>
#include <map>
#include <set>
#include <iostream>
#include <string>

using namespace std;

int n, m, num, id;

map<string, set<int>> title, author, kw, puber, years;

void PrintQuery(map<string, set<int>> &m, string &temp);

int main()
{
    string ttitle, tauthor, tkw, tpuber, tyears;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%d\n", &id);
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while(cin>>tkw)
        {
            kw[tkw].insert(id);
            char ch = getchar();
            if(ch == '\n')
                break;
        }
        getline(cin, tpuber);
        puber[tpuber].insert(id);
        getline(cin, tyears);
        years[tyears].insert(id);
    }
    cin >> m;
    string temp;
    for(int i = 1; i <= m; i++)
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
    if(!m[temp].empty())
    {
        for(auto it = m[temp].begin(); it != m[temp].end(); it++)
        {
            printf("%07d\n", *it);
        }
    }
    else
        cout << "Not Found" << endl;
}
