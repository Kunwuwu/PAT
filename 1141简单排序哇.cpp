#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

typedef struct
{
    double score;                                        /* 总成绩 */
    string name;
    int rank;
    int tws;                                             /* 取整后的成绩 */
    int ns;
}sch;

vector<sch> schs(1);
int n;
map<string, int> dict;

bool cmp(sch a, sch b)                                    /* 排序规则 */
{
    if(a.tws != b.tws)
        return a.tws > b.tws;
    else if(a.ns != b.ns)
        return a.ns < b.ns;
    else
        return a.name < b.name;
}

int main()
{
    cin >> n;
    int index = 1;
    for(int i = 0; i < n; i++)
    {
        string km, name;
        double score;
        cin >> km >> score >> name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(dict[name] == 0)                               /* 如果这个学校首次出现，则插入schs后 */
        {
            dict[name] = index;
            sch tsch;
            tsch.name = name;
            tsch.ns = 1;
            if(km[0] == 'A')
                tsch.score = score;
            else if(km[0] == 'B')
                tsch.score = score / 1.5;
            else
                tsch.score = score * 1.5;
            schs.push_back(tsch);
            index++;
        }
        else                                              /* 如果以前出现过，修改各项数据 */
        {
            int id = dict[name];
            schs[id].ns++;
            if(km[0] == 'A')
                schs[id].score += score;
            else if(km[0] == 'B')
                schs[id].score += score / 1.5;
            else
                schs[id].score += score * 1.5;
        }
    }
    for(int i = 1; i < index; i++)
        schs[i].tws = (int)schs[i].score;                 /* 这里是坑点，不这样的话最后的测点过不了 */
    sort(schs.begin() + 1, schs.end(), cmp);              /*  "TWS" is the total weighted score which is defined to be the integer part of "ScoreB/1.5 + ScoreA + ScoreT*1.5" */
    for(int i = 1; i < index; i++)
    {
        if(i > 1 && schs[i].tws == schs[i-1].tws)         /* 排名 */
            schs[i].rank = schs[i-1].rank;
        else
            schs[i].rank = i;
    }
    cout << index - 1 << endl;
    for(int i = 1; i < index; i++)
    {
        printf("%d ", schs[i].rank);
        cout << schs[i].name;
        printf(" %d %d\n", schs[i].tws, schs[i].ns);
    }
    return 0;
}
