#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int m, n, k, current;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)            /* 模拟元素入栈和出栈的过程 */
    {
        stack<int> s;                      /* 。。。。 */
        vector<int> v(n + 1);
        bool isover = false;
        for(int j = 1; j <= n; j++)        /* 为什么弄这个看上去多余的循环输入？ */
        cin >> v[j];                       /* 直接在下面的循环里面输入的话，有个上个循环没读玩的数据会在下次继续读，造成错误 */
        int index = 1;
        s.push(1);                         /* 第一个元素肯定是1嘛 */
        for(int j = 1; j <= n; j++)
        {
            current = v[j];                /* 当前检查的元素 */
            while(s.empty() || s.top() != current)      
            {
                index++;
                s.push(index);
                if(s.size() > m)
                {
                    isover = true;         /* isover一旦为真，说明有的序列不符合栈的输入输出规定 */
                    break;
                }
            }
            s.pop();
            if(isover)
                break;
        }
        if(index == n && !isover)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
