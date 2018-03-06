#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int m, n, s;

vector<string> names;
map<string, int> dict;

int main()
{
    cin >> m >> n >> s;
    string temp;
    names.resize(m + 1);
    for(int i = 1; i <= m; i++)
    {
        cin >> temp;
        dict[temp] = 0;                                   /* dict记录每个id中奖被点名的次数，首先置为0 */
        names[i] = temp;
    }
    bool flag = false;
    while(s <= m)
    {
        while(dict[names[s]] != 0)                        /* 如果这个id之前中过奖，则跳过 */
            s++;
        if(s > m)
            break;
        cout << names[s] << "\n";
        dict[names[s]]++;                                 /* 中奖的id记录其中奖 */
        flag = true;
        s += n;
    }
    if(!flag)
        cout << "Keep going..." << endl;
    return 0;
}
