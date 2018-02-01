#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    int age;
    int money;
    string name;                                /* string很可能会超时，因为重载的==和大于小于比strcmp慢 */
}person;

person tperson;
vector<person> richers;

int n, k;

bool cmp(person a, person b)                    /* 排序规则 */
{
    if(a.money != b.money)
        return a.money > b.money;
    else if(a.age != b.age)
        return a.age < b.age;
    else
        return a.name < b.name;
}


int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> tperson.name;
        scanf("%d %d", &tperson.age, &tperson.money);       /* 考虑到数据量可能会多的时候，就用scanf，不用cin了 */
        richers.push_back(tperson);
    }
    sort(richers.begin(), richers.end(), cmp);
    for(int i = 1; i <= k; i++)
    {
        int cnt, aged, ageu;
        bool isnone = true;
        scanf("%d %d %d", &cnt, &aged, &ageu);       /* 考虑到数据量可能会多的时候，就用scanf，不用cin了 */
        printf("Case #%d:\n", i);
        for(int j = 0; j < n; j++)
        {
            if(richers[j].age >= aged && richers[j].age <= ageu)
            {
                cout << richers[j].name;
                printf(" %d %d\n", richers[j].age, richers[j].money);
                cnt--;                               /* 我有点怀疑这个cnt最后减不到0。。。最后发现题目没考虑这个情况 */
                isnone = false;
            }
            if(cnt <= 0)                             /* 统计打印的个数 */
                break;
        }
        if(isnone)
            printf("None\n");
    }
    return 0;
}
