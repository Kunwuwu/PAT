#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int d, n;

int main()
{
    cin >> d >> n;
    n--;                                                  /* 讲真我也不明白为毛要先减一，但是确实要减 */
    vector<int> v;
    v.push_back(d);
    while(n--)
    {
        int index = v[0];
        vector<int> t;                                    /* 根据v生成的t */
        int cnt = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] == index)                             /* 如果继续与前面的相同，则cnt++ */
                cnt++;
            else                                          /* 如果不同，将统计的index的数目加入t，并初始化*/
            {
                t.push_back(index);
                t.push_back(cnt);
                index = v[i];
                cnt = 1;
            }
            if(i == v.size() - 1)                         /* 如果到了v的末尾，将当前统计的放入t中 */
            {
                t.push_back(index);
                t.push_back(cnt);
            }
        }
        v = t;                                            /* 这个不能忘 */
    }
    for(int i = 0; i < v.size(); i++) printf("%d", v[i]);
    return 0;
}
