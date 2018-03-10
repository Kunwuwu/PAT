#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char a[9];

int main()
{
    int na, nb;
    cin >> na >> nb;
    int result = na + nb;
    sprintf(a, "%d", result);
    int len = strlen(a);
    for(int i = 0; i < len; i++)
    {
        if((len - i) % 3 == 0 && i != 0 && a[i-1] != '-')
            printf(",");
        printf("%c", a[i]);
    }
    return 0;
}
