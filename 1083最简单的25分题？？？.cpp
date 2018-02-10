#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    char name[12];
    char id[12];
    int grade;
}stu;

vector<stu> stus, tstus;
int n, grade1, grade2;

bool cmp(stu a, stu b)
{
    return a.grade > b.grade;
}

int main()
{
    cin >> n;
    stu tstu;
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %d", tstu.name, tstu.id, &tstu.grade);
        tstus.push_back(tstu);
    }
    cin >> grade1 >> grade2;
    for(int i = 0; i < n; i++)
    {
        if(tstus[i].grade >= grade1 && tstus[i].grade <= grade2)
            stus.push_back(tstus[i]);
    }
    if(stus.size() > 0)
    {
        sort(stus.begin(), stus.end(), cmp);
        for(auto it = stus.begin(); it != stus.end(); it++)
        {
            printf("%s %s\n", (*it).name, (*it).id);
        }
    }
    else
        printf("NONE");
    return 0;
}
