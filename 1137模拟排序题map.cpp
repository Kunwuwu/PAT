#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

class stu
{
public:
    string id;
    int mscore = -1;                                      /* 开始没注意到这需要初始化为-1，一直输出不正确 */
    int fscore = -1;
    int pscore = -1;
    int grade = -1;
    bool show = false;

public:
    void cal()
    {
        if(pscore >= 200)                                 /* struct或者class使用方法，一直很少看到人用，但是我用过两次了，还好 */
        {
            if(fscore >= mscore)
                grade = (double)fscore;
            else
                grade = (int)((double)mscore * 0.4 + (double)fscore * 0.6 + 0.5);    /* 取整 */
            if(grade >= 60)
                show = true;                              /* 符合条件的数据 */
        }
    }
};

map<string, int> idtonum;                               
vector<stu> stus(1);
int p, m, n;

bool cmp(stu a, stu b)                                    /* 排序规则 */
{
    if(a.grade != b.grade)
        return a.grade > b.grade;
    else
        return a.id < b.id;
}

int main()
{
    cin >> p >> m >> n;
    string tid;
    int index = 1;
    for(int i = 0; i < p; i++)
    {
        stu tstu;
        cin >> tstu.id >> tstu.pscore;
        if(idtonum[tstu.id] == 0)
        {
            idtonum[tstu.id] = index++;
            stus.push_back(tstu);
        }
        else
            stus[idtonum[tstu.id]].pscore = tstu.pscore;
    }
    for(int i = 0; i < m; i++)                            /* 利用map将id和数字的下标对应 */
    {
        stu tstu;
        cin >> tstu.id >> tstu.mscore;
        if(idtonum[tstu.id] == 0)
        {
            idtonum[tstu.id] = index++;
            stus.push_back(tstu);
        }
        else
            stus[idtonum[tstu.id]].mscore = tstu.mscore;  /* 开始的时候tstu.id搞错了成index了，一直有错误 */
    }
    for(int i = 0; i < n; i++)
    {
        stu tstu;
        cin >> tstu.id >> tstu.fscore;
        if(idtonum[tstu.id] == 0)
        {
            idtonum[tstu.id] = index++;
            stus.push_back(tstu);
        }
        else
            stus[idtonum[tstu.id]].fscore = tstu.fscore;
    }
    for(int i = 1; i < stus.size(); i++)
        stus[i].cal();                                    /* 对每个人计算成绩和排名的资格 */
    sort(stus.begin() + 1, stus.end(), cmp);
    for(int i = 1; i < stus.size(); i++)
    {
        if(stus[i].show)
        {
            cout << stus[i].id;
            printf(" %d %d %d %d\n", stus[i].pscore, stus[i].mscore, stus[i].fscore, stus[i].grade);
        }
    }
    return 0;
}
