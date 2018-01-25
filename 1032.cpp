#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100005;

typedef struct
{
    vector<int> pre;                                     /* 有两个pre的结点就是目标结点啦 */
    int next;
    char letter;
}Node[MAX];

Node letters;
int begin1, begin2, n;

int main()                                                /* 突然想到一种情况就是中间会出现一些相同的字母干扰答案 */
{                                                         /* 所以给每个字符加上pre，从后面开始遍历，如果某点出现两个pre */
    cin >> begin1 >> begin2 >> n;                         /* 防止两个单词全相等的情况 */
    int b1 = begin1, b2 = begin2;
    letters[begin1].pre.push_back(-1);
    letters[begin1].pre.push_back(-1);
    int address, result = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> address;
        cin >> letters[address].letter >> letters[address].next;
    }
    int temp1;
    while(begin1 != -1)
    {
        temp1 = begin1;
        begin1 = letters[begin1].next;
        if(begin1 != -1)                                   /* 出循环的时候，temp代表的就是最后的位置 */
            letters[begin1].pre.push_back(temp1);
    }
    int temp2;
    while(begin2 != -1)
    {
        temp2 = begin2;
        begin2 = letters[begin2].next;
        if(begin2 != -1)                                   /* 出循环的时候，temp代表的就是最后的位置 */
            letters[begin2].pre.push_back(temp2);
    }
    if(b1 == b2)
    {
        printf("%05d", b1);
    }
    else if(temp1 == temp2 && temp1 != -1)
    {
        while(temp1 != -1)                                     /* 找出存在两个pre的结点 */
        {
            if(letters[temp1].pre.size() == 1)
                break;
            temp1 = letters[temp1].pre[0];
        }
        printf("%05d", letters[temp1].next);
    }
    else
    {
        printf("-1");
    }
    return 0;
}
