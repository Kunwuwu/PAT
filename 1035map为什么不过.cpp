#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct
{
    string id;
    string pwd;
}account;

account tacc;
vector<account> accounts;
int n;
map<string, string> res;

bool converpwd(string &pwd)
{
    bool flag = false;
    for(auto it = res.begin(); it != res.end(); it++)
    {
        string key = (*it).first;
        int pos = pwd.find(key);
        if(pos != -1)
        {
            pwd.replace(pos, 1, res[key]);
            flag = true;
        }
    }
    return flag;
}

int main()
{
    cin >> n;
    res["1"] = "@";
    res["0"] = "%", res["l"] = "L", res["O"] = "o";
    for(int i = 0; i < n; i++)
    {
        cin >> tacc.id 

 >> tacc.pwd;
        if(converpwd(tacc.pwd))
            accounts.push_back(tacc);
    }
    if(accounts.empty())
    {
        if(n == 1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified", n);
    }
    else
    {
        cout << accounts.size() << endl;
        for(auto it = accounts.begin(); it != accounts.end(); it++)
            cout << (*it).id << " " << (*it).pwd <<endl;
    }
    return 0;
}
