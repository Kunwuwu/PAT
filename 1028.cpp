#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct STU
{
    int id;
    char name[10];
    int score;
}student[100010];

student stu;
int n, c;

bool cmp(STU a, STU b)
{
    if(c == 1)
        return a.id < b.id;
    else if(c == 2)
    {
        return strcmp(a.name, b.name) <= 0;             /* char数组的strcmp好像比==要快是吗 */
    }
    else if(c == 3)
    {
        return a.score <= b.score;
    }
}

int main()
{
    cin >> n >> c;
    for(int i = 0; i < n; i++)
        cin >> stu[i].id >> stu[i].name >> stu[i].score;
    sort(stu, stu + n, cmp);
    for(int i = 0; i < n; i++)
    {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);         /* 好像printf也比cout快？ */
    }
    return 0;
}
