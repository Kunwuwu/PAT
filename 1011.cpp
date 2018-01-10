#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char sign[] = {'W', 'T', 'L'};
    double max;
    int index[3];
    double result = 1;
    for(int i = 0; i < 3; i++)                              /* 循环进行输入和计算 */
    {
        max = 0.0;
        for(int j = 0; j < 3; j++)                          /* 计算最大值 */
        {
            double temp;
            cin >> temp;
            if(temp > max)
            {
                max = temp;
                index[i] = j;
            }
        }
        result *= max;
    }
    result = (result * 0.65 - 1) * 2;
    printf("%c %c %c %.2lf", sign[index[0]], sign[index[1]], sign[index[2]], result);
    return 0;
}
