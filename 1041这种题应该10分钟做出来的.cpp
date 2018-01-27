#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int index;
    int count = 0;
    int value;
}num;

vector<num> nums(10005);
int n;
vector<int> v;

int main()
{
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++)                               /* 其实就是结构体数组记录自己出现的次数和值 */
    {                                                        /* 向量v记录从前往后记录每个数出现的顺序 */
        scanf("%d", &temp);
        v.push_back(temp);
        if(nums[temp].count == 0)
        {
            nums[temp].count = 1;
            nums[temp].value = temp;
        }
        else
            nums[temp].count++;
    }
    bool isNone = true;
    for(auto it = v.begin(); it != v.end(); it++)
    {
        if(nums[*it].count == 1)
        {
            cout << nums[*it].value;
            isNone = false;
            break;
        }
    }
    if(isNone)
        cout << "None";
    return 0;
}
