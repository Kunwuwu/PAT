#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s1, s2, s3, s4;

string week[] = {"MON", "TUE",  "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    cin >> s1 >> s2 >> s3 >> s4;
    int len1 = s1.length(), len2 = s2.length(), len3 = s3.length(), len4 = s4.length();
    int index1 = 0, index2 = 0, index3 = 0, index4 = 0;
    bool istime = false;
    int weekindex = 0, hourindex = 0;
    while(index1 < len1 && index2 < len2)                                    /* 前两个字符串中找星期和小时 */
    {
        if(!istime && s1[index1] == s2[index2] && s1[index1] >= 'A' && s1[index1] <= 'G')   /* 找星期 */
        {
            weekindex = s1[index1] - 'A';
            istime = true;
            index1++;
            index2++;
            continue;
        }
        if(istime && s1[index1] == s2[index2])                              /* 找小时（几点） */
        {
            if(s1[index1] >= '0' && s1[index1] <= '9')
            {
                hourindex = s1[index1] - '0';
                break;
            }
            else if(s1[index1] >= 'A' && s1[index1] <= 'N')
            {
                hourindex = s1[index1] - 'A' + 10;
                break;
            }
        }
        index1++;
        index2++;
    }
    int min = 0;
    while(index3 < len3 && index4 < len4)                                           /* 找分钟 */
    {
        if(s3[index3] <= 'z' && s3[index3] >= 'a' || s3[index3] <= 'Z' && s3[index3] >= 'A')
        {
            if(s4[index4] <= 'z' && s4[index4] >= 'a' || s4[index4] <= 'Z' && s4[index4] >= 'A')
            {
                if(s3[index3] == s4[index4])
                {
                    break;
                }
            }
        }
        index3++;
        index4++;
    }
    min = index3;
    cout << week[weekindex];
    printf(" %02d:%02d", hourindex, min);
    return 0;
}
