#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> v;

int MaxSubseqSum(vector<int> v, int N);
int IsAllZero(vector<int> v);
int in = 0;
int out = 0;

int main()
{
    int N, e, MaxSum;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &e);
        v.push_back(e);
    }
    MaxSum = MaxSubseqSum(v, N);
    if(MaxSum == 0 && IsAllZero(v))               // 判断是否所有的元素都为零的特殊情况
    {
        in = 0;
        out = v.size() - 1;
    }
    printf("%d %d %d", MaxSum, v[in], v[out]);
    return 0;
}

int MaxSubseqSum(vector<int> v, int N)
{
    int MaxSum, ThisSum;
    MaxSum = ThisSum =  0;
    int temp = 0;
    for(int i = 0; i < N; i++)
    {
        ThisSum += v[i];
        if(ThisSum > MaxSum || ( ThisSum == MaxSum && v[i - 1] < 0))
        {                                         // 防止类似于-1 0 0 -1的情况出现
            MaxSum = ThisSum;
            out = i;
            in = temp;                            // 如果出现了更大的子序列和，则更新序列的起止下标
        }
        else if(ThisSum < 0)
        {
            ThisSum = 0;                          // 如果当前子序列的和小于零了，则意味着后面数能够成更大的子序列
            temp = i + 1;                         // 将新子序列的始下标更新
        }
    }
    return MaxSum;
}

int IsAllZero(vector<int> v)
{
    bool flag = true;
    for(auto it = v.cbegin(); it != v.cend(); it++)
    {
        if(*it >= 0)
            flag = false;
    }
    return flag;
}
