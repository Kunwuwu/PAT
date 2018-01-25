#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

string line;
int a, b;

int main()
{
    cin >> line;
    int cy = line.size() + 2;
    for(b = cy / 3; b <= cy - 2; b++)
        if((cy - b) % 2 == 0 && b >= 3 && (cy - b) / 2 <= b)
            break;
    a = (cy - b) / 2;
    int i;
    for(i = 0; i < a; i++)
    {
        printf("%c", line[i]);
        for(int j = 0; j < b - 2; j++)
        {
            if(i < a - 1)
                printf(" ");
            else
                printf("%c", line[a + j]);
        }
        printf("%c\n", line[cy-3-i]);
    }
    return 0;
}
