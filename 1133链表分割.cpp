#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

int start, n, k;

typedef struct tnode
{
    int data;
    int adr;
    int next;
}node[MAX];

node slist;
vector<tnode> lista, listb, listc;

int main()
{
    cin >> start >> n >> k;
    int adr;
    for(int i = 0; i < n; i++)                            /* 链表输入 */
    {
        scanf("%d", &adr);
        slist[adr].adr = adr;
        scanf("%d %d", &slist[adr].data, &slist[adr].next);
    }
    int ts = start;
    while(ts != -1)                                       /* 根据链表的顺序，将所有元素按条件放入到a，b，c中 */
    {
        if(slist[ts].data < 0)
            lista.push_back(slist[ts]);
        else if(slist[ts].data >= 0 && slist[ts].data <= k)
            listb.push_back(slist[ts]);
        else
            listc.push_back(slist[ts]);
        ts = slist[ts].next;
    }
    if(!lista.empty())                                    /* 找到链表新的根结点 */
        start = lista[0].adr;
    else if(!listb.empty())
        start = listb[0].adr;
    else
        start = listc[0].adr;
    int i;
    ts = start;
    for(i = 0; i < lista.size(); i++)                     /* 根据要求顺序，调整每个结点的next值 */
    {
        slist[ts].next = lista[i].adr;
        ts = lista[i].adr;                                /* 不要忘了ts也要移动 */
    }
    for(i = 0; i < listb.size(); i++)
    {
        slist[ts].next = listb[i].adr;
        ts = listb[i].adr;
    }
    for(i = 0; i < listc.size(); i++)
    {
        slist[ts].next = listc[i].adr;
        ts = listc[i].adr;
    }
    slist[ts].next = -1;
    while(start != -1)
    {
        if(slist[start].next != -1)
            printf("%05d %d %05d\n", start, slist[start].data, slist[start].next);
        else
            printf("%05d %d %d\n", start, slist[start].data, slist[start].next);
        start = slist[start].next;
    }
    return 0;
}
