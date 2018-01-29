#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef struct
{
    vector<int> stus;
}course;

int n, m, k;
vector<course> courses;

int strtoint(char name[])                                            /* string会超时，直接改成int和char数组进行转换吧 */
{
    int a = (name[0] - 'A') * 26 * 26;
    int b = (name[1] - 'A') * 26;
    int c = name[2] - 'A';
    int d = name[3] - '0';
    return (a + b + c) * 10 + d;
}

void inttostr(int id)
{
    char name[5];
    name[0] = (id / 10) / (26 * 26) + 'A';
    name[1] = ((id / 10) % (26 * 26)) / 26 + 'A';
    name[2] = (id / 10) % 26 + 'A';
    name[3] = id % 10 + '0';
    name[4] = '\0';
    printf("%s\n", name);
}

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    cin >> n >> m;
    char name[4];
    int tempid;
    int stuid;
    courses.resize(m + 1);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d", name, &k);
        stuid = strtoint(name);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &tempid);
            courses[tempid].stus.push_back(stuid);
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int l = courses[i].stus.size();
        sort(courses[i].stus.begin(), courses[i].stus.end(), cmp);
        printf("%d %d\n", i, l);
        for(auto it = courses[i].stus.begin(); it != courses[i].stus.end(); it++)
        {
            inttostr(*it);
        }
    }
    return 0;
}
