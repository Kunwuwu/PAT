#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 10000;

typedef struct
{
    int rank = -1;
    bool checked;
}stu[MAX];

string award[] = {"Mystery Award", "Minion", "Chocolate", "Checked", "Are you kidding?"};
int n, k;
stu stus;

bool isprime(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    int id;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &id);
        stus[id].rank = i;
    }
    cin >> k;
    for(int i = 0; i < k; i++)                            /* 查询id，根据排名和是否checked来打印结果 */
    {
        scanf("%d", &id);
        int trank = stus[id].rank;
        if(trank == 1 && !stus[id].checked)
        {
            printf("%04d: ", id);
            stus[id].checked = true;
            cout << award[0] << "\n";
        }
        else if(trank == -1)
        {
            printf("%04d: ", id);
            cout << award[4] << "\n";
        }
        else if(isprime(trank) && !stus[id].checked)
        {
            printf("%04d: ", id);
            stus[id].checked = true;
            cout << award[1] << "\n";
        }
        else if(stus[id].checked)
        {
            printf("%04d: ", id);
            stus[id].checked = true;
            cout << award[3] << "\n";
        }
        else
        {
            printf("%04d: ", id);
            cout << award[2] << "\n";
            stus[id].checked = true;
        }
    }
    return 0;
}
