#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 0;
const int MAX = 3000;

int graph[MAX][MAX];
int calltime[MAX];
int n, k;
int idnumber = 1;
int bang[MAX];
bool visited[MAX];
int countbang = 0;
int bangweight[MAX];
int bangnumer[MAX];
int banghead[MAX];
int maxcalltime;
map<int, string> numtostr;
map<string, int> strtonum;

typedef struct
{
    string name;
    int weight;
}person;

vector<person> v;

int StringToint(string name)
{
    if(strtonum[name] == 0)
    {
        strtonum[name] = idnumber;
        numtostr[idnumber] = name;
        return idnumber++;
    }
    else
        return strtonum[name];
}

void dfs(int v)
{
    visited[v] = true;
    bangnumer[countbang]++;
    if(calltime[v] > maxcalltime)          /* 如果这个人的电话时间大于之前的，则更新maxcalltime */
    {
        maxcalltime = calltime[v];
        banghead[countbang] = v;           /* 其实就是寻找head */
    }
    for(int w = 1; w < idnumber; w++)
    {
        if(graph[v][w] != inf)                               /* 因为是有向图，而且当v-w和w-v都有效时，默认只能遍历v-w */
        {                                                    /* 所以当w-v也有效时，则这个bang的权重需要加上w-v */
            bangweight[countbang] += graph[v][w];
            if(!visited[w])
                dfs(w);
        }
    }
}

void dfscnt()
{
    for(int i = 1; i < idnumber; i++)
    {
        maxcalltime = 0;                                 /* 遍历一个新的bang（连通集时），更新maxcalltime */
        if(!visited[i])
        {
            dfs(i);
            if(bangweight[countbang] <= k || bangnumer[countbang] <= 2) /* 如果这个bang的权重小于阈值k，则这个bang失效 */
            {
                bangweight[countbang] = 0;                            /* 因为bang数目没有增加，这个bang会被覆盖 */
                bangnumer[countbang] = 0;
            }
            else
                countbang++;
        }
    }
}

bool cmp(person a, person b)
{
    return a.name < b.name;
}

int main()
{
    cin >> n >> k;
    string person1, person2;
    int weight;
    fill(graph[0], graph[0] + MAX * MAX, inf);
    fill(calltime, calltime + MAX, inf);
    fill(bang, bang + MAX, 0);
    fill(bangweight, bangweight + MAX, 0);
    fill(bangnumer, bangnumer + MAX, 0);
    fill(banghead, banghead + MAX, -1);
    for(int i = 0; i < n; i++)
    {
        cin >> person1 >> person2 >> weight;
        int v = StringToint(person1), w = StringToint(person2);
        graph[v][w] += weight;                                             /* 有向图 */
        calltime[v] += weight;
        calltime[w] += weight;
    }
    dfscnt();
    cout << countbang << endl;
    person temp;
    for(int i = 0; i < countbang; i++)
    {
        temp.name = numtostr[banghead[i]];
        temp.weight = bangnumer[i];
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);                                   /* 这个得考虑一下，按字母排序输出 */
    for(auto it = v.begin(); it != v.end(); it++)
        cout << (*it).name << " " << (*it).weight << endl;
    return 0;
}
