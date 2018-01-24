#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long int> s;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    long int temp;
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%ld", &temp);
        s.push_back(temp);
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        scanf("%ld", &temp);
        s.push_back(temp);
    }
    sort(s.begin(), s.end(), cmp);
    cout << s[(m + n - 1)/2];
    return 0;
}
