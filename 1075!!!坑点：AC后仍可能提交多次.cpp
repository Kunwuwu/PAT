#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class stu
{
public:
    int id;
    vector<int> scores;
    int totalscore;
    bool passcmp;
    int rank;
    int passnum;

public:
    void cal()
    {
        for(auto it = scores.begin(); it != scores.end(); it++ )
        {
            if((*it) != -1 && (*it) != -2)
            {
                totalscore += *it;                                  /* 计算总分 */
                passcmp = true;                                     /* 判断这个人是否成功编译了至少一个题目 */
            }
        }
    }
};

vector<stu> tstus, stus;
vector<int> p;
int n, k, m;

bool cmp(stu a, stu b)                                            /* 排序规则 */
{
    if(a.totalscore != b.totalscore)
    {
        return a.totalscore > b.totalscore;
    }
    else if(a.passnum != b.passnum)
    {
        return a.passnum > b.passnum;
    }
    return a.id < b.id;
}

int main()
{
    cin >> n >> k >> m;
    p.resize(k);
    tstus.resize(n);
    for(int tid = 0; tid < n; tid++)
    {
        tstus[tid].scores.resize(k);
        for(int pid = 0; pid < k; pid++)
            tstus[tid].scores[pid] = -2;                                /* 所有选手的题目分数默认为-2，表示没有提交过 */
    }
    for(int i = 0; i < k; i++)
        scanf("%d", &p[i]);
    for(int i = 0; i < m; i++)
    {
        int tid, pid, score;
        scanf("%d %d %d", &tid, &pid, &score);
        if(score == p[pid-1] && tstus[tid-1].scores[pid-1] != p[pid-1]) /* 这个题目最大的坑点，满分后仍然可能提交多次!!!!! */
            tstus[tid-1].passnum++;                                     /* 如果这道题第一次!!!!第一次啊得满分，passnum++ */
        if(score > tstus[tid-1].scores[pid-1])                          /* 每道题目取的是最高分，-2提交没编译通过也是-1 */
            tstus[tid-1].scores[pid-1] = score;
        tstus[tid-1].id = tid;                                          /* 记录id */
    }
    for(auto it = tstus.begin(); it != tstus.end(); it++)
    {
        (*it).cal();                                                    /* 计算总分和统计未编译过(未通过)的题目数量 */
        if((*it).passcmp)                                               /* 如果没编译过(未通过)的题目数量比k少 */
            stus.push_back(*it);                                        /* 这位同学就算进总数了 */
    }
    sort(stus.begin(), stus.end(), cmp);                                /* 按照排序规则排序 */
    stus[0].rank = 1;                                                   /* 第一名排名为1 */
    for(int i = 1; i < stus.size(); i++)                                /* 记录排序后的排名 */
    {
        if(stus[i].totalscore == stus[i-1].totalscore)                  /* 如果这个人分数与前面的人相同，则排名也相同 */
            stus[i].rank = stus[i-1].rank;
        else
            stus[i].rank = i + 1;
    }
    for(auto it = stus.begin(); it != stus.end(); it++)
    {
        printf("%d %05d %d", (*it).rank, (*it).id, (*it).totalscore);
        for(int i = 0; i < k; i++)
        {
            if((*it).scores[i] != -2 && (*it).scores[i] != -1)
                printf(" %d", (*it).scores[i]);
            else if((*it).scores[i] == -2)
                printf(" -");
            else
                printf(" 0");
        }
        printf("\n");
    }
    return 0;
}
