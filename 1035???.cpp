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

bool converpwd(string &pwd)
{
    bool flag = false;
    for(int i = 0; i < pwd.size(); i++)
    {
        if(pwd[i] == '1')
        {
            pwd[i] = '@';
            flag = true;
        }
        else if(pwd[i] == '0')
        {
            pwd[i] = '%';
            flag = true;
        }
        else if(pwd[i] == 'l')
        {
            pwd[i] = 'L';
            flag = true;
        }
        else if(pwd[i] == 'O')
        {
            pwd[i] = 'o';
            flag = true;
        }
    }
    return flag;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tacc.id >> tacc.pwd;
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
