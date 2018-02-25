#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char a[50], b[50];
    double temp, sum = 0;
    int cnt = 0;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> a;
        sscanf(a, "%lf", &temp);                                   /* 字符串转数字 */
        sprintf(b, "%.2lf", temp);                                 /* 数字转字符串，前面都是自己造的轮子。。坑了 */
        bool flag = true;
        for(int i = 0; i < strlen(a); i++)
        {
            if(a[i] != b[i])
            {
                flag = false;
                break;
            }
        }
        if((temp <= 1000 && temp >= -1000) && flag)
        {
            sum += temp;
            cnt++;
        }
        else
            printf("ERROR: %s is not a legal number\n", a);
    }
    if(cnt == 1)                                                    /* 注意单数复数 */
        printf("The average of %d number is %.2lf", cnt, sum / cnt);
    else if(cnt > 1)
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}
