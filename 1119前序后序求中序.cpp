#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> pre, post, in;
bool isdet = true;

void inorder(int startpre, int endpre, int startpost, int endpost)
{
    if(startpre == endpre)                                /* 因为插在右子树上，所以有这种情况 */
    {
        in.push_back(pre[startpre]);
        return ;
    }
    int leftroot = startpre + 1;
    int rightroot = endpost - 1;
    int rightpre = leftroot;
    while(rightpre <= endpre && pre[rightpre] != post[rightroot]) rightpre++;
    int leftnum = rightpre - startpre - 1;                /* 在前序序列中确定左子树元素的个数 */
    if(rightpre - startpre == 1)                          /* 不确定的时候，在后序中找到新根一定是在前序当前根的后面 */
        isdet = false;                                    /* 而前序当前根的下一个结点就是左子树的根 */
    else                                                  /* 考虑将最后这个元素插入到右子树中，就不再进行前序遍历了 */
        inorder(leftroot, rightpre - 1, startpost, startpost + leftnum - 1);
    in.push_back(pre[startpre]);
    inorder(rightpre, endpre, startpost + leftnum, rightroot);
}

int main()
{
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    inorder(0, n - 1, 0, n - 1);
    if(isdet) cout << "Yes" << endl;
    else cout << "No" << endl;
    printf("%d", in[0]);
    for(int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);                             /* 下次再遇到格式错误就空一行 */
    printf("\n");                                         /* 为什么一定需要空一行呢？题目好像没说明 */
}
