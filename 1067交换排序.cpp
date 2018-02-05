#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int cnt = 0;
int index = 0;

bool issort()
{
    for(int i = index; i < n; i++)              /* 这里用index记录上次调整的位置，防止每次从头开始找，会超时 */
    {
        if(v[i] != i)
        {
            index = i;
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    v.resize(n);
    int temp;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        v[temp] = i;
    }
    while(1)
    {
        if(v[0] == 0)                       /* 当0出现在0位置时，序列不一定顺序排列，此时需要将0与最前的非顺序排列的数字交换 */
        {
            if(issort())                    /* 当0出现在0位置且所有数字顺序排列时 */
            {
                break;
            }
            else
            {
                swap(v[0], v[index]);      /* 当0出现在0位置，而index所在位置的数字不是顺序排列时，将他与0交换 */
                cnt++;
            }
        }
        swap(v[0], v[v[0]]);
        cnt++;
    }
    cout << cnt;
    return 0;
}
