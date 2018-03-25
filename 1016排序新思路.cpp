#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct
{
    string id;
    int t;
    int month;
    bool status;
    int d;
    int h;
    int m;
}node;

int toll[] = {10, 10, 10, 10, 10, 10, 20, 20, 20, 15, 15, 15, 15, 15, 15, 15, 20, 30, 20, 15, 15, 10, 10, 10};
int n;

vector<node> datas;

bool cmp(node a, node b)                                  /* 先按名字排序，再按时间 */
{                                                         /* 保证一个人的记录都在一起 */
    return a.id != b.id ? a.id < b.id : a.t < b.t;
}

int main() {
    for(int i = 0; i < 24; i++) scanf("%d", &toll[i]);
    cin >> n;
    datas.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> datas[i].id;
        scanf("%d:%d:%d:%d", &datas[i].month, &datas[i].d, &datas[i].h, &datas[i].m);
        char status[10];
        scanf("%s", status);
        datas[i].t = datas[i].d * 24 * 60 + datas[i].h * 60 + datas[i].m;
        datas[i].status = status[1] == 'n' ? true : false;
     }
    sort(datas.begin(), datas.end(), cmp);
    map<string, vector<node>> dict;
    for(int i = 0; i < n - 1; i++)
    {
        if(datas[i].id == datas[i+1].id)
        {
            if(datas[i].status && !datas[i+1].status)
            {
                dict[datas[i].id].push_back(datas[i]);
                dict[datas[i].id].push_back(datas[i+1]);
            }
        }
    }
    for(auto it : dict)
    {
        string name = it.first;
        vector<node> v = it.second;
        double total = 0;
        if(v.size() > 0)
        {
            cout << name;
            printf(" %02d\n", v[0].month);
            for(int i = 1; i < v.size(); i += 2)
            {
                printf("%02d:%02d:%02d %02d:%02d:%02d", v[i-1].d, v[i-1].h, v[i-1].m, v[i].d, v[i].h, v[i].m);
                printf(" %d ", v[i].t - v[i-1].t);
                double now = 0;
                for(int j = v[i-1].t; j < v[i].t; j++)
                {
                    int h = (j % (24 * 60)) / 60;
                    now += (double)toll[h];
                }
                printf("$%.2lf\n", now / 100);
                total += now / 100;
            }
        }
        printf("Total amount: $%.2lf\n", total);
    }
    return 0;
}
