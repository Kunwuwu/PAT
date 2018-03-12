#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef struct
{
    int id;
    int course[4];
    int ranklist[4];
}stu;

vector<stu> v;
int index, n, q;
char course[] = {'A', 'C', 'M', 'E'};                     /* 每门课按顺序排列，方便计算和排序 */
map<int, int> dict;                                       /* 记录最后一次排序时学生的位置 */

bool cmp(stu a, stu b)                                    /* 讲真用数组表示课程的方法简直就是神作，简化好多 */
{
    return a.course[index] > b.course[index]; 
}

int main()
{
    cin >> n >> q;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d %d %d", &v[i].id, &v[i].course[1], &v[i].course[2], &v[i].course[3]);
        v[i].course[0] = (v[i].course[1] + v[i].course[2] + v[i].course[3]) / 3;
    }
    for(index = 0; index < 4; index++)
    {
        sort(v.begin() + 1, v.end(), cmp);
        for(int i = 1; i <= n; i++)
        {
            if(v[i].course[index] == v[i-1].course[index])/* 考虑并列的情况 */
                v[i].ranklist[index] = v[i-1].ranklist[index];
            else
                v[i].ranklist[index] = i;
            dict[v[i].id] = i;                            /* 记录下最后一次排序后学生的位置 */
        }
    }
    int id;
    for(int i = 0; i < q; i++)
    {
        scanf("%d", &id);
        int ti = dict[id];
        if(ti)
        {
            int minrank = 9999999999, minindex = -1;
            for(int j = 0; j < 4; j++)                    /* 找到排名最高的课程 */
            {
                if(v[ti].ranklist[j] < minrank)
                {
                    minindex = j;
                    minrank = v[ti].ranklist[j];
                }
            }
            printf("%d %c\n", minrank, course[minindex]);
        }
        else
            printf("N/A\n");
    }
    return 0;
}
