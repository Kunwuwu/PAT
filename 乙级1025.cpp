// 先放这摆个坑，有两个测试用例无法AC

#include <iostream>
#include <stack>
using namespace std;

typedef struct Node
{
    int pre;
    int next;
    int data;
}listnode;

listnode a[100001];

void show()
{
    int address, startads, num, from, tempads;
    int n;
    scanf("%d %d %d", &startads, &num, &from);
    n = num / from;
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &address);
        scanf("%d %d", &a[address].data, &a[address].next);
    }
    address = startads;
    for(int i = 0; i < num - 1; i++)
    {
        tempads = address;
        address = a[address].next;
        a[address].pre = tempads;
    }
    a[startads].pre = address;
    tempads = startads;
    address = startads;
    for(int i = 0; i < n - 1; i++)
    {
        if(i == 0) {
            for (int j = 0; j < 2 * from - 1; j++) {
                tempads = a[tempads].next;
            }
        }else{
            for (int j = 0; j < from; j++) {
                tempads = a[tempads].next;
            }
        }
        a[address].pre = tempads;
        for(int j = 0; j < from; j++)
        {
            address = a[address].next;
        }
    }
    if(n % from != 0)
    {
        for (int j = 0; j < 2 * from - 1; j++) {
            tempads = a[tempads].next;
        }
        a[address].pre = a[tempads].next;
    }
    address = startads;
    for(int i = 0; i < from - 1; i++)
    {
        address = a[address].next;
    }
    for(int i = 0; i < num - (num % from); i++)
    {
        if(i != num - 1)
        {
            printf("%05d %d %05d\n", address, a[address].data, a[address].pre);
            address = a[address].pre;
        }
        else
        {
            printf("%05d %d %d", address, a[address].data, -1);
        }
    }
    for(int i = 0; i < num % from; i++)
    {
        printf("%05d %d %d", address, a[address].data, a[address].next);
        address = a[address].next;
        if(i != num % from - 1)
            printf("\n");
    }
}
