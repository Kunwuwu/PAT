#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    string id;
    int virtue;
    int talent;
    int total;
}person;

int n, l, h;
vector<person> sage, nobleman, foolman, smallman;

bool cmp(person a, person b)                                           /* 排序规则 */
{
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.virtue != b.virtue)
        return a.virtue > b.virtue;
    else
        return a.id < b.id;
}

int main()
{
    cin >> n >> l >> h;
    person temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp.id;
        scanf("%d %d", &temp.virtue, &temp.talent);
        temp.total = temp.virtue + temp.talent;
        if(temp.virtue >= l && temp.talent >= l)
        {
            if(temp.talent >= h && temp.virtue >= h)
                sage.push_back(temp);
            else if(temp.talent < h && temp.talent >= l && temp.virtue >= h)
                nobleman.push_back(temp);
            else if(temp.talent <= temp.virtue && temp.talent >= l && temp.virtue < h)
                foolman.push_back(temp);
            else
                smallman.push_back(temp);
        }
    }
    sort(sage.begin(), sage.end(), cmp);
    sort(nobleman.begin(), nobleman.end(), cmp);
    sort(foolman.begin(), foolman.end(), cmp);
    sort(smallman.begin(), smallman.end(), cmp);
    int num = sage.size() + nobleman.size() + foolman.size() + smallman.size();
    cout << num << endl;
    for(auto it = sage.begin(); it != sage.end(); it++)
    {
        cout << (*it).id;
        printf(" %d %d\n", (*it).virtue, (*it).talent);
    }
    for(auto it = nobleman.begin(); it != nobleman.end(); it++)
    {
        cout << (*it).id;
        printf(" %d %d\n", (*it).virtue, (*it).talent);
    }
    for(auto it = foolman.begin(); it != foolman.end(); it++)
    {
        cout << (*it).id;
        printf(" %d %d\n", (*it).virtue, (*it).talent);
    }
    for(auto it = smallman.begin(); it != smallman.end(); it++)
    {
        cout << (*it).id;
        printf(" %d %d\n", (*it).virtue, (*it).talent);
    }
    return 0;
}
