#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int z, a, b, n;
char zs[20], as[20], bs[20];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> zs;
        int indexa = 0, indexb = 0;
        int sizez = strlen(zs);
        for(int i = 0; i < sizez; i++)                    /* 分割字符串 */
        {
            if(i < sizez / 2)
                as[indexa++] = zs[i];
            else
                bs[indexb++] = zs[i];
        }
        as[indexa] = '\0';
        bs[indexb] = '\0';
        sscanf(zs, "%d", &z);                             /* 字符串转数字（sscanf），数字转字符串（sprintf） */
        sscanf(as, "%d", &a);
        sscanf(bs, "%d", &b);
        if( a * b != 0 && z % (a * b) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
