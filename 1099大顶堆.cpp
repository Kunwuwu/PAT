#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
vector<int> a, b, t;

void update(int end)
{
    int parent = 1, child = parent * 2;
    while(child <= end)                                          /* 该节点的孩子必须要小于end */
    {
        if(child + 1 <= end && b[child] < b[child + 1])          /* 在该节点的两个孩子中找一个最大的 */
            child += 1;
        if(b[child] > b[parent])                                 /* 如果有孩子比父亲大，两个交换 */
        {
            swap(b[child], b[parent]);                           /* 父亲孩子交换值 */
            parent = child;                                      /* 父亲孩子交换位置 */
            child *= 2;                                          /* 新的孩子 */
        }
        else
            break;
    }
}

int main()
{
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
    int i, j;
    for(i = 1; b[i] <= b[i + 1] && i < n; i++);
    for(j = i + 1; a[j] == b[j] && j <= n; j++);
    if(j > n)
    {
        cout << "Insertion Sort" << endl;
        sort(a.begin() + 1, a.begin() + i + 2);
        cout << a[1];
        for(int i = 2; i <= n; i++)
            cout << " " << a[i];
        return 0;
    }
    else
    {
        cout << "Heap Sort" << endl;
        t = a;
        sort(t.begin() + 1, t.end());
        int k = n;
        for(; t[k] == b[k] && k >= 1; k--);
        swap(b[1], b[k]);
        update(k - 1);
        cout << b[1];
        for(int j = 2; j <= n; j++)
            cout << " " << b[j];
        return 0;
    }
}
