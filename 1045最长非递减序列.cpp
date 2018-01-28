/*
 * 新知识：
 * 最大非递减序列
 * 其实转化一下就是非递减序列了
 * 最喜欢的颜色: 2 3 1 5 6
 *        下标: 1 2 3 4 5              JB家所有的软件都对不齐中文
 *
 *
 * 要处理的颜色数据: 2 2 4 1 5 5 6 3 1 1 5 6
 *   颜色对应的下标：1 1 0 3 4 4 5 2 3 3 4 6
 * 看到上面就知道了，从前往后，如果有递减的序列，如5 2，那非递减的序列就暂停了，不计数了，表示中间这段递减的就是不符合要求的颜色带
 * 就这样，一个半小时理解这个东西
 * */

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fvt[201];
int colors[10001];
int n, m, l;

int main()
{
    cin >> n >> m;
    int temp;
    fill(fvt, fvt + 201, 0);
    for(int i = 1; i <= m; i++)
    {
        cin >> temp;
        fvt[temp] = i;                                     /* 记录喜欢的颜色及其应该在的位置，不喜欢的颜色值为零 */
    }
    cin >> l;
    for(int i = 0; i < l; i++)
    {
        cin >> temp;
        if(fvt[temp] >= 1)                                 /* 如果这个颜色是喜欢的颜色之一 */
            colors[i] = fvt[temp];                         /* 记录下这个颜色的位置 */
    }
    int maxlen = 1, templen = 0, tempmax = 0;
    for(int i = 0; i < l; i++)
    {
        tempmax = colors[i];
        templen = 0;
        for(int j = i; j < l; j++)
        {
            if(colors[j] >= tempmax)                      /* 如果是非递减关系，如果不是非递减关系则继续 */
            {
                tempmax = colors[j];                      /* 则更新临时大值和长度 */
                templen++;
            }
        }
        maxlen = max(maxlen, templen);                    /* 更新最大值 */
    }
    cout << maxlen;
    return 0;
}
