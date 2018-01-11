/* 可以说是很痛苦了，第二个测试用例一直通不过，估计就是因为我省了一个循环，但是找不出思路的错误在哪 */
/* 立下flag，有时间一定找出不过的原因 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Student
{
public:
    int id;
    int score[4];
    int rank;
    char lesson;
    void ave()
    {    /* 这里计算平均值记得四舍五入 */
        score[0] = (score[1] + score[2] + score[3]) / 3.0 + 0.5;
    }
}Stu[2005];

Stu stu;

int flag = -1;

bool cmp(Student s1, Student s2)
{
    return s1.score[flag] > s2.score[flag];
}

int exist[1000000] = {0};

int main()
{
    int n, m, ID[2001];
    cin >> n >> m;
    char lesson[] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < n; i++)
    {
        cin >> stu[i].id;
        cin >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        stu[i].ave();
    }
//    cout << stu[0].score[0] << endl;                           /* 测试输入 */
    for(int i = 0; i < m; i++)
    {
        cin >> ID[i];
    }
    for(flag = 0; flag < 4; flag++)
    {
        sort(stu, stu + n, cmp);           // 按科目A C M E的顺序给学生排序
        for(int i = 0; i < n; i++)
        {                                  // 一旦发现排名可以更小，则更新排名和对应的排名种类
            if(stu[i].rank <= 0 || (stu[i].rank > i + 1))
            {
                stu[i].rank = i + 1;
                stu[i].lesson = lesson[flag];
                if(i > 0 && stu[i].score[flag] == stu[i-1].score[flag])  // 如果出现并列的情况
                    stu[i].rank = stu[i-1].rank;                         // 则排名与前一名相同
            }
            exist[stu[i].id] = i + 1;                                    // 记录是否存在这个id并且存储这个id最后的位置
        }
    }
    for(int i = 0; i < m; i++)
    {
        int temp = exist[ID[i]];
        if(temp)
            printf("%d %c\n", stu[temp-1].rank, stu[temp-1].lesson);
        else
            printf("N/A\n");
    }
    return 0;
}
