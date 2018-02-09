#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

bool hashtable[10010];                                                  /* 哈希表 */
int msize, n;

bool isprime(int n)                                                     /* 判断是否是素数 */
{
    if(n == 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int findprime(int n)                                                  /* 寻找最近的素数 */
{
    while(!isprime(n))
    {
        n++;
    }
    return n;
}

int main()
{
    cin >> msize >> n;
    if(!isprime(msize))
        msize = findprime(msize);
    for(int i = 0; i < n; i++)
    {
        int key;
        scanf("%d", &key);
        int index = key % msize;
        if(!hashtable[index])                                        /* 哈希表的插入 */
        {
            if(i == 0)
                printf("%d", index);
            else
                printf(" %d", index);
            hashtable[index] = true;
        }
        else                                                        /* 哈希表解决冲突：二次方探查法 */
        {
            bool flag = false;
            for(int step = 1; step < msize; step++)
            {
                index = (key + step * step) % msize;
                if(!hashtable[index])
                {
                    flag = true;
                    if(i == 0)
                        printf("%d", index);
                    else
                        printf(" %d", index);
                    hashtable[index] = true;
                    break;
                }
            }
            if(!flag)
            {
                if(i != 0)
                    printf(" -");
                else
                    printf("-");
            }
        }
    }
    return 0;
}
