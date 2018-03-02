#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct
{
    int h;
    char name[10];
}stu;                                                     /* 定义每个学生的结构体，包括身高属性和姓名属性 */

vector<stu> v;
int n, k, m;

bool cmp(stu a, stu b)                                    /* 确定排序规则 */
{
    if(a.h != b.h)
        return a.h > b.h;
    else
        return strcmp(a.name, b.name) < 0;                /* 注意这里如果是小于的话就是升序 */
}

int main()
{
    cin >> n >> k;
    v.resize(n);
    vector<stu> tcol;
    int vindex = 0;
    for(int i = 0; i < n; i++)
        scanf("%s %d", v[i].name, &v[i].h);               /* 用字符数组更快 */     
    sort(v.begin(), v.end(), cmp);
    while(n)                                              /* 主循环 */
    {
        if(n % k == 0)                                    /* 确定每行的人数 */
            m = n / k;
        else
            m = n / k + 1;
        n -= m;
        k--;                                              /* 每排好一行，则少一行，同样总人数n也在减少的 */
        int maxindex = m / 2;
        tcol.resize(m);
        tcol[maxindex] = v[vindex++];
        for(int i = 1; i < m; i++)                        /* 每一个行的排列，中间高，两边低，左边高于右边 */
        {
            if(maxindex - i >= 0)
                tcol[maxindex - i] = v[vindex++];
            else
                break;
            if(maxindex + i < m)
                tcol[maxindex + i] = v[vindex++];
            else
                break;
        }
        for(int i = 0; i < m; i++)
        {
            if(i != 0)
                printf(" %s", tcol[i].name);
            else
                printf("%s", tcol[i].name);
        }
        printf("\n");
    }
    return 0;
}
