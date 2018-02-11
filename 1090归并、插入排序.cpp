#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int a[105], b[105];
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    int i, j;
    for(i = 0; b[i] <= b[i+1] && i < n - 1; i++);
    for(j = i + 1; a[j] == b[j] && j < n; j++);
    if(j == n)
    {
        cout << "Insertion Sort" << endl;                             /* 注意插入排序的特点 */
        sort(a, a + i + 2);                                           /* 插入排序的下一步就是将后两个元素插入排好的序列中排序 */
    }
    else
    {
        cout << "Merge Sort" << endl;
        int flag = 1, k = 1;
        while(flag)                                                   /* 归并排序就是每（2、4、6。。）个元素排序 */
        {
            flag = 0;
            for(int i = 0; i < n; i++)
            {
                if(a[i] != b[i])                                      /* 一直不知道这个循环是干嘛的，想了一下 */
                    flag = 1;                                         /* 好像是比较b序列和正在排序的a序列 */
            }                                                         /* 如果a序列排序后和b序列相等，则说明下次就得到目标序列了 */
            k *= 2;
            for(int i = 0; i < n / k; i++)                            /* 归并排序：每k（2、4、6...）个元素进行排序 */
                sort(a + i * k, a + (i + 1) * k);
            sort(a + n / k * k, a + n);                               /* 如果n不是k的倍数，会剩下部分序列没排序，将其排序 */
        }
    }
    cout << a[0];
    for(int i = 1; i < n; i++)
        cout << " " << a[i];
    return 0;
}
