#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    int address;
    int value;
    int next;
}node;

vector<node> v, input;

bool cmp(node a, node b)
{
    return a.value < b.value;
}

int main()
{
    int n, head, addr;
    cin >> n >> head;
    if(head == -1)                                                 /* 2333超级大坑点，第一个直接来空节点 */
    {
        cout << "0 -1";
        return 0;
    }
    input.resize(100005);
    for(int i = 0; i < n; i++)                                     /* 录入数据 */
    {
        scanf("%d", &addr);
        scanf("%d %d", &input[addr].value, &input[addr].next);
        input[addr].address = addr;
    }
    while(head != -1)                                               /* 确定有效数据 */
    {
        v.push_back(input[head]);
        head = input[head].next;
    }
    sort(v.begin(), v.end(), cmp);
    int len = v.size();
    for(int i = 0; i < len - 1; i++)
    {
        v[i].next = v[i+1].address;
    }
    v[len-1].next = -1;
    printf("%d %05d\n", len, v[0].address);
    for(int i = 0; i < len; i++)
    {
        if(v[i].next != -1)
            printf("%05d %d %05d\n", v[i].address, v[i].value, v[i].next);
        else
            printf("%05d %d %d\n", v[i].address, v[i].value, v[i].next);
    }
    return 0;
}
