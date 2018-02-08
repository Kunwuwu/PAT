#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    int data;
    int next;
    int pre;
    int reverse;
}node;

vector<node> list(100005);
int start, n, k;

int main()
{
    cin >> start >> n >> k;
    int totalnum = 1;
    for(int i = 0; i < n; i++)
    {
        int address;
        scanf("%d", &address);
        scanf("%d %d", &list[address].data, &list[address].next);
    }
    int temp = -1, tstart = start;
    while(tstart != -1)
    {
        list[tstart].pre = temp;
        temp = tstart;
        tstart = list[tstart].next;
        totalnum++;                                            /* 不一定所有结点都有用，加个计数器 */
    }
    int cnt = 1;
    int begin;
    while(start != -1)                                        /* start模拟指针从前往后移动 */
    {
        if(cnt % k == 0)                                      /* 每移动k个结点 */
        {
            if(cnt == k)                                      /* 如果是第k个结点，则是翻转的起点 */
                begin = start;
            int right = list[start].next, left = start;       /* right负责从第k个结点右移，left则是左移 */
            int index = k - 1;
            int rightcnt = 0;                                 /* 记录right移动的次数 */
            while(index--)                                    /* index是记录left移动的次数，倒计数 */
            {
                list[left].reverse = list[left].pre;          /* 标记每个节点翻转够的下一个节点，如果是翻转的话则为left结点 */
                left = list[left].pre;                        /* 移动left结点 */
                if(list[right].next != -1 && right != -1)     /* 标记right最后的位置，有可能到了第cnt+k个位置，有可能不到 */
                {
                    right = list[right].next;
                    rightcnt++;
                }
            }
            if(rightcnt == k - 1)                             /* 如果right到了cnt+k个位置，则正常翻转 */
            {
                list[left].reverse = right;
            }
            else
            {
                list[left].reverse = list[start].next;        /* start后的结点不能完成翻转，需要next结点标记翻转 */
                int temp = list[start].next;                  /* temp记录start的下个结点 */
                while(temp != -1)
                {
                    list[temp].reverse = list[temp].next;
                    temp = list[temp].next;
                }
            }
        }
        start = list[start].next;
        cnt++;
    }
    for(int i = 0; i < totalnum && begin != -1; i++)
    {
        if(list[begin].reverse != -1)
            printf("%05d %d %05d\n", begin, list[begin].data, list[begin].reverse);
        else
            printf("%05d %d %d\n", begin, list[begin].data, list[begin].reverse);          /* -1不用添加前置零 */
        begin = list[begin].reverse;
    }
    return 0;
}
