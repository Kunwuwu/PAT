#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;

typedef struct
{
    int cp = -1;
    bool iscome;
}guest[MAX];

guest guests;
int n, m;
vector<int> result;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);                           /* 记录每个人cp的id */
        guests[a].cp = b;
        guests[b].cp = a;
    }
    cin >> m;
    int one;
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &one);
        guests[one].iscome = true;                        /* 记录这个人来没来 */
    }
    for(int i = 0; i < MAX; i++)                          /* 如果这个人来了，但是他没有cp或者是cp没来，则放入result */
    {
        if(guests[i].iscome)
        {
            int id = guests[i].cp;
            if(id == -1 || !guests[id].iscome)
            {
                result.push_back(i);
            }
        }
    }
    cout << result.size() << endl;
    for(auto it = result.begin(); it < result.end(); it++)
    {
        if(it != result.begin())
            printf(" %05d", *it);
        else
            printf("%05d", *it);
    }
    return 0;
}
