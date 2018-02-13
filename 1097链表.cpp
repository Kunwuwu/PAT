#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef struct
{
    int data;
    int next, address;
}node;

const int MAX = 100005;

vector<node> orgllist(MAX);
int n, start;
int dup[MAX];
node save[MAX], del[MAX];
vector<node> t1, t2;

int main()
{
    cin >> start >> n;
    int address, data, next;
    for(int i = 0; i < n; i++)                                           /* 将数据存入org列表 */
    {
        scanf("%d %d %d", &address, &data, &next);
        orgllist[address].data = data;
        orgllist[address].address = address;
        orgllist[address].next = next;
    }
    int temp = start;
    bool isfirst = true;
    int startdel = -1;
    while(temp != -1)
    {
        data = abs(orgllist[temp].data);                                 /* data是经过绝对值的 */
        if(dup[data] != 0)                                               /* 如果这个data不是第一次出现 */
        {
            t2.push_back(orgllist[temp]);                                /* 压入t2数组 */
            if(isfirst)
            {
                startdel = temp;
                isfirst = false;
            }
        }
        else
        {
            t1.push_back(orgllist[temp]);                                /* 否则压入t1数组 */
            dup[data]++;
        }
        temp = orgllist[temp].next;                                      /* 链表上移动 */
    }
    for(int i = 0; i < t1.size(); i++)                                   /* t1链表上是需要留下的数据 */
    {
        int ads = t1[i].address;
        if(i < t1.size() - 1)
        {
            save[ads].next = t1[i+1].address;
            save[ads].data = t1[i].data;
        }
        else
        {
            save[ads].next = -1;
            save[ads].data = t1[i].data;
        }
    }
    for(int i = 0; i < t2.size(); i++)                                   /* t2链表上是需要删除的数据 */
    {
        int ads = t2[i].address;
        if(i < t2.size() - 1)
        {
            del[ads].next = t2[i+1].address;
            del[ads].data = t2[i].data;
        }
        else
        {
            del[ads].next = -1;
            del[ads].data = t2[i].data;
        }
    }
    while(start != -1)
    {
        if(save[start].next != -1)
            printf("%05d %d %05d\n", start, save[start].data, save[start].next);
        else
            printf("%05d %d %d\n", start, save[start].data, save[start].next);
        start = save[start].next;
    }
    while(startdel != -1)
    {
        if(del[startdel].next != -1)
            printf("%05d %d %05d\n", startdel, del[startdel].data, del[startdel].next);
        else
            printf("%05d %d %d\n", startdel, del[startdel].data, del[startdel].next);
        startdel = del[startdel].next;
    }
    return 0;
}
