#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> in, post;

const int MAX = 50000;                                    /* 这个是层序遍历的数组的大小，反正弄5000是没过的，干脆50000 */

typedef struct
{
    int level, data;
}node[MAX];                                               /* 得到的层序遍历序列既有值，又有层数 */

node levels;                                 

int n;

vector<vector<int>> result(35);

void pre(int leftin, int rightin, int leftpost, int rightpost, int index, int level)
{                                                         /* 前序遍历，中序后序求层序就不谈了，带了层数和下标 */
    if(leftin > rightin) 
        return ;
    int rootin = leftin;
    levels[index].data = post[rightpost];
    levels[index].level = level;
    while(in[rootin] != post[rightpost]) rootin++;
    int leftnum = rootin - leftin;
    int rightnum = rightin - rootin;
    pre(leftin, rootin - 1, leftpost, rightpost - rightnum - 1, 2 * index + 1, level + 1);
    pre(rootin + 1, rightin, rightpost - rightnum, rightpost - 1, 2 * index + 2, level + 1);
}

int main()
{
    cin >> n;
    in.resize(n);
    post.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    pre(0, n -1 , 0, n -1, 0, 1);
    for(int i = 0; i < MAX; i++)
    {
        if(levels[i].level > 0)
        {
            int tlevel = levels[i].level;
            result[tlevel].push_back(levels[i].data);     /* result的行是层数，列就是元素啦 */
        }
    }
    printf("%d", result[1][0]);
    for(int i = 2; i < 35; i++)
    {
        if(i % 2 == 0)
        {
            for(auto it = result[i].begin(); it != result[i].end(); it++)
                printf(" %d", *it);
        }
        else
        {
            for(int j = result[i].size() - 1; j >= 0; j--)
                printf(" %d", result[i][j]);
        }
    }
    return 0;
}
