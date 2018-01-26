#include <cstdio>
#include <iostream>

using namespace std;

int n;

typedef struct
{
    string id;
    char gender;
    string name;
    int grade;
}student;

student fhest, mlest, temp;

int main()
{
    cin >> n;
    int mingrade = 101, maxgrade = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> temp.name >> temp.gender >> temp.id >> temp.grade;
        if(temp.gender == 'M')
        {
            if(temp.grade < mingrade)
            {
                mingrade = temp.grade;
                mlest = temp;
            }
        }
        else if(temp.gender == 'F')
        {
            if(temp.grade > maxgrade)
            {
                maxgrade = temp.grade;
                fhest = temp;
            }
        }
    }
    if(maxgrade != -1)
        cout << fhest.name << ' ' << fhest.id << endl;
    else
        cout << "Absent" << endl;
    if(mingrade != 101)
        cout << mlest.name << ' ' << mlest.id << endl;
    else
        cout << "Absent" << endl;
    if(maxgrade != -1 && mingrade != 101)
        cout << fhest.grade - mlest.grade;
    else
        cout << "NA";
    return 0;
}
