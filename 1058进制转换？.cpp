#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int g1, s1, k1, g2, s2, k2, g, s, k;
    int overs = 0, overk = 0;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    if(k1 + k2 >= 29)
    {
        k = k1 + k2 - 29;
        overk = 1;
    }
    else
    {
        k = k1 + k2;
        overk = 0;
    }
    if(s1 + s2 + overk >= 17)
    {
        s = s1 + s2 + overk - 17;
        overs = (s1 + s2 + overk) / 17;
    }
    else
    {
        s = s1 + s2 + overk;
        overs = 0;
    }
    g = g1 + g2 + overs;
    printf("%d.%d.%d", g, s, k);
    return 0;
}
