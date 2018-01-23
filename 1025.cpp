#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//全局变量的初始化设置
int n;
typedef struct
{
    long long id;
    int score;
    int finalrank;
    int localnumber;
    int localrank;
}student;

vector<student> stu;

// 函数原型
bool cmp(student a, student b);

int main() {
    cin >> n;
    int k;
    student tstu;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        vector<student> temp;
        for(int j = 0; j < k; j++)
        {
            cin >> tstu.id >> tstu.score;
            tstu.localnumber = i;
            temp.push_back(tstu);
        }
        sort(temp.begin(), temp.end(), cmp);           /* 地区排序 */
        temp[0].localrank = 1;
        stu.push_back(temp[0]);
        for(int j = 1; j < k; j++)                     /* 对地区每个考生进行排序标记 */
        {
            if(temp[j].score == temp[j-1].score)
                temp[j].localrank = temp[j-1].localrank;
            else
                temp[j].localrank = j + 1;
            stu.push_back(temp[j]);
        }
    }
    sort(stu.begin(), stu.end(), cmp);
    stu[0].finalrank = 1;
    for(int i = 1; i < stu.size(); i++)
    {
        if(stu[i].score == stu[i-1].score)
            stu[i].finalrank = stu[i-1].finalrank;
        else
            stu[i].finalrank = i + 1;
    }
    cout << stu.size() << endl;
    for(auto it = stu.begin(); it != stu.end(); it++)
    {
        printf("%013lld %d %d %d\n", (*it).id, (*it).finalrank, (*it).localnumber, (*it).localrank);
    }
    return 0;
}

bool cmp(student a, student b)
{
    if(a.score == b.score)
    {
        return a.id < b.id;
    }
    else
        return a.score > b.score;
}
