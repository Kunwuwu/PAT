#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cmath>
#define lowbit(i) ((i) & (-i))

using namespace std;

const int MAX = 100010;

vector<int> treear(MAX, 0);
stack<int> s;
int n;

void update(int key, int v)
{
    for(int i = key; i < MAX; i += lowbit(i))
        treear[i] += v;
}

int getsum(int mid)
{
    int sum = 0;
    for(int i = mid; i >= 1; i -= lowbit(i))
        sum += treear[i];
    return sum;
}

int binarryres()
{
    int low = 1, high = MAX, k = (s.size() + 1) / 2;
    while(low < high)
    {
        int mid = (high + low) / 2;
        if(getsum(mid) >= k)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    cin >> n;
    char order[15];
    while(n--)
    {
        scanf("%s", order);
        if(order[1] == 'o')
        {
            if(s.empty())
                printf("Invalid\n");
            else
            {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            }
        }
        else if(order[1] == 'u')
        {
            int key;
            scanf("%d", &key);
            update(key, 1);
            s.push(key);
        }
        else
        {
            if(!s.empty())
                printf("%d\n", binarryres());
            else
                printf("Invalid\n");
        }
    }
    return 0;
}
