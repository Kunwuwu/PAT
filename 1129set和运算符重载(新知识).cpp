#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef struct tnode
{
    int index;                                            /* 用排序碰到两个超时，不玩了，改用set */
    int cnt;
    tnode(int a, int b) : index(a), cnt(b){}              /* 第一次接触到运算符重载，才发现可以改变set的排序规则 */
    bool operator < (const tnode &a) const
    {
        if(cnt != a.cnt)
            return cnt > a.cnt;
        else
            return index < a.index;
    }
}node;

int n, k;
vector<int> book;
set<node> s;

int main()
{
    cin >> n >> k;
    book.resize(n + 1);
    int index;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &index);
        if(i > 1)                                         /* 因为第一个时，前面没有统计过，不输出 */
        {
            printf("%d:", index);
            int tcnt = 0;
            for(auto it = s.begin(); it != s.end() && tcnt < k; it++)  /* set的输出 */
            {
                printf(" %d", (*it).index);
                tcnt++;
            }
            printf("\n");
        }
        auto it = s.find(node(index, book[index]));       /* 找到index所在的结点位置 */
        if(it != s.end())                                 /* 如果找到了，就删掉 */
            s.erase(node(index, book[index]));
        book[index]++;
        s.insert(node(index, book[index]));               /* 然后将新的插入 */
    }
    return 0;
}
