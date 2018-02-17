#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v, v1, v2;
vector<int> result;

int main()
{
    cin >> n;
    v.resize(n);
    int max = -1, min = 999999999;
    for(int i = 0; i < n; i++)            /* 将数据保存，并把符合（到该数为止，该数一定是最大数）的数保存 */
    {
        scanf("%d", &v[i]);
        if(v[i] >= max)
        {
            v1.push_back(v[i]);
            max = v[i];
        }
    }
    for(int i = n - 1; i >= 0; i--)      /* 从后往前，并把符合（到该数为止，该数一定是最小数）的数保存 */
    {
        if(v[i] <= min)
        {
            v2.push_back(v[i]);
            min = v[i];
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int size = v1.size(), index = 0;
    for(int i = 0; i < size; i++)       /* 把v1、v2共有的数保存 */
    {
        for(int j = index;v2[j] <= v1[i] && j < v2.size(); j++)
        {
            if(v1[i] == v2[j])
            {
                result.push_back(v1[i]);
                index = j;
                break;
            }
        }
    }
    cout << result.size() << endl;
    if(result.size() > 0)
    {
        cout << result[0];
        for(int i = 1; i < result.size(); i++)
            printf(" %d", result[i]);
    }
    else                                 /* 题目输出的意思应该是必须要两行，第二行没有数的话，也要空一行 */
        cout << endl;                    /* 好像第三个测试点，result是0个 */
    return 0;
}
