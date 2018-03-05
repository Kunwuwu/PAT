#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 40;
int fid[MAX];
int n;

int sum(int num)                                          /* 计算每个数的数位和 */
{
    int r, result = 0;;
    while(num)
    {
        r = num % 10;
        result += r;
        num /= 10;
    }
    return result;
}

int main()                                                /* 郁闷的地方就是明明是 */
{
    cin >> n;
    int temp, cnt = 0;
    while(n--)                                            /* 输入数据 */
    {
        scanf("%d", &temp);
        int tsum = sum(temp);
        fid[tsum]++;
        if(fid[tsum] == 1)                                /* 一旦有个fid大于等于1，则cnt++ */
            cnt++;
    }
    cout << cnt << endl;
    int flag = true;
    for(int i = 0; i < MAX; i++)
    {
        if(fid[i] >= 1)
        {
            if(flag)
            {
                printf("%d", i);
                flag = false;
            }
            else
                printf(" %d", i);
        }
    }
    return 0;
}
