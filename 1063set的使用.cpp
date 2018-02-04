#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

vector<set<int>> v;
int n, k;

double sml(set<int> s1, set<int> s2)
{
    int nc = 0, nt = s2.size();
    for(auto it = s1.begin(); it != s1.end(); it++)
    {
        if(s2.find(*it) == s2.end())        /* 遍历s1，从s2中找到相同的，如果找到了，nc++，没找到就是nt++ */
            nt++;                           /* 没找到就说明是s2中没有这个，最后总的元素个数就是s2加上s2没有的而s1有的 */
        else
            nc++;
    }
    return double(nc) / nt;
}

int main()
{
    cin >> n;
    v.resize(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int m, temp;
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &temp);
            v[i].insert(temp);
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int set1, set2;
        scanf("%d %d", &set1, &set2);
        double result = sml(v[set1], v[set2]);
        printf("%.01lf%c\n", result * 100, 37);
    }
}
