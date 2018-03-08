#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct                                            /* 树结点 */
{
    int left, right;
    string data;
}node;

vector<node> v;
vector<bool> roots;                                       /* 记录下有哪个结点是别人的子结点 */
int n;

void in(int root)                                         /* 可以看到示例中，结点信息是中序输出的 */
{
    if(root == -1)
        return ;
    bool left = false, right = false;
    if(v[root].left != -1 && (v[v[root].left].left != -1 || v[v[root].left].right != -1))
    {                                                     /* 判断这个结点的左子树是否还有子结点，有的话就可以给他加括号 */
        printf("(");
        left = true;
    }
    in(v[root].left);
    if(left)
        printf(")");
    cout << v[root].data;
    if(v[root].right != -1 && (v[v[root].right].left != -1 || v[v[root].right].right != -1))
    {                                                     /* 判断这个结点的右子树是否还有子结点，有的话就可以给他加括号 */
        printf("(");
        right = true;
    }
    in(v[root].right);
    if(right)
        printf(")");
}

int main()
{
    cin >> n;
    v.resize(n + 1);
    roots.resize(n + 1, true);
    int root;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i].data;
        scanf("%d %d", &v[i].left, &v[i].right);
        if(v[i].left != -1)
            roots[v[i].left] = false;
        if(v[i].right != -1)
            roots[v[i].right] = false;
    }
    for(int i = 1; i <= n; i++)                           /* 找根结点 */
    {
        if(roots[i])
        {
            root = i;
            break;
        }
    }
    in(root);
    return 0;
}
