#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n;

int main()
{
    cin >> n;
    v.resize(n + 1);
    v[0] = 0;
    int time = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
    for(int i = 0; i < n; i++)
    {
        if(v[i+1] < v[i])
            time += (v[i] - v[i+1]) * 4;
        else
            time += (v[i+1] - v[i]) * 6;
        time += 5;
    }
    cout << time;
    return 0;
}
