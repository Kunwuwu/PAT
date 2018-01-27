#include <set>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, k;
vector<set<int>> clist(180000);

int encodeint(char name[])                                   /* 本打算用map的，可是速度慢，而且直接用字符串的话，更慢 */
{                                                            /* 所以用进行编码转换，可以唯一确定每个id */
    int a = name[0] - 'A';                                   /* 为毛越到后面越简单，可能是我厉害了 */
    int b = name[1] - 'A';
    int c = name[2] - 'A';
    int d = name[3] - '0';
    return (a * 26 * 26 + b * 26 + c) * 10 + d;
}

int main() {
    cin >> n >> k;
    int courceid, countstu;
    char tempname[5];
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &courceid, &countstu);
        for(int j = 0; j < countstu; j++)
        {
            scanf("%s", tempname);
            int id = encodeint(tempname);
            clist[id].insert(courceid);
        }
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%s", tempname);
        printf("%s", tempname);
        int id = encodeint(tempname);
        printf(" %d", clist[id].size());
        for(auto it = clist[id].begin(); it != clist[id].end(); it++)
            printf(" %d", (*it));
        printf("\n");
    }
    return 0;
}
