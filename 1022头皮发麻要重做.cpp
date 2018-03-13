#include <cstdio>
#include <iostream>
#include <map>
#include <set>

using namespace std;

map<string, set<int>> dict;

int n, m;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string temp;
        int id;                                           /* id */
        scanf("%d\n", &id);
        getline(cin , temp);                              /* title */
        dict[temp].insert(id);
        getline(cin , temp);                              /* author */
        dict[temp].insert(id);
        getline(cin , temp);                              /* keywords */
        string s;
        for(int i = 0; i < temp.length(); i++)            /* 分割keywords */
        {
            if(temp[i] == ' ')
            {
                dict[s].insert(id);
                s.clear();
            }
            else
                s.push_back(temp[i]);
        }
        dict[s].insert(id);                               /* 注意最后的keywords */
        getline(cin , temp);                              /* 出版社 */
        dict[temp].insert(id);
        getline(cin , temp);                              /* 年份 */
        dict[temp].insert(id);                            /* 放入到对应的set中 */
    }
    cin >> m;
    for(int i = 0; i < m; i++)                            /* 查询操作 */
    {
        int num;
        string temp;
        scanf("%d: ", &num);
        getline(cin, temp);
        printf("%d: ", num);
        cout << temp << "\n";
        if(dict[temp].size() > 0)
        {
            for(auto it = dict[temp].begin(); it != dict[temp].end(); it++)
                printf("%07d\n", *it);
        }
        else
            printf("Not Found\n");
    }
    return 0;
}
