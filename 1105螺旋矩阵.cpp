#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> v;
int totalnum;
int m, n;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> totalnum;
    v.resize(totalnum);
    for(int i = 0; i < totalnum; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end(), cmp);
    n = sqrt(double(totalnum));
    m = totalnum / n;
    while(n > 1 && totalnum % n != 0)                      /* 寻找合适的行数m和列数n */
    {
        n--;
        m = totalnum / n;
    }
    int mt[m][n];
    fill(mt[0], mt[0] + m * n, -1);                        /* 矩阵的初始化 */
    int index = 0;
    int row = 0, col = 0;
    mt[row][col] = v[index++];
    while(index < totalnum)
    {
        while(col + 1 < n && mt[row][col+1] == -1)         /* 左->右 */
        {
            col++;
            mt[row][col] = v[index++];
            if(index >= totalnum)
                break;
        }
        while(row + 1 < m && mt[row+1][col] == -1)         /* 上->下 */
        {
            row++;
            mt[row][col] = v[index++];
            if(index >= totalnum)
                break;
        }
        while(col - 1 >= 0 && mt[row][col-1] == -1)         /* 右->左 */
        {
            col--;
            mt[row][col] = v[index++];
            if(index >= totalnum)
                break;
        }
        while(row - 1 >= 0 && mt[row-1][col] == -1)         /* 下->上 */
        {
            row--;
            mt[row][col] = v[index++];
            if(index >= totalnum)
                break;
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j != 0)
                printf(" ");
            printf("%d", mt[i][j]);
        }
        printf("\n");
    }
    return 0;
}
