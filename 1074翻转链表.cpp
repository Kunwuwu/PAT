#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    int adr;
    int data;
    int next;
}node;

vector<node> slist(100000);
int tlist[100000];
int start, n, r;

int main()
{
    cin >> start >> n >> r;
    for(int i = 0; i < n; i++)
    {
        int adr, data, next;
        scanf("%d %d %d", &adr, &data, &next);
        slist[adr].data = data;
        slist[adr].adr = adr;
        slist[adr].next = next;
    }
    int cnt = 0;
    while(start != -1)
    {
        tlist[cnt++] = start;
        start = slist[start].next;
    }
    int index = 0;
    while(index + r <= cnt)
    {
        reverse(tlist + index, tlist + index + r);
        index += r;
    }
    for(int i = 0; i < cnt; i++)
    {
        if(i != cnt - 1)
            printf("%05d %d %05d\n", tlist[i], slist[tlist[i]].data, tlist[i+1]);
        else
            printf("%05d %d %d\n", tlist[i], slist[tlist[i]].data, -1);
    }
    return 0;
}
