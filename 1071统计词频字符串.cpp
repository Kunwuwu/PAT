#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string line;
map<string, int> dict;

int main()
{
    getline(cin, line);
    transform(line.begin(), line.end(), line.begin(), ::tolower);               /* 将所有大写转化成小写 */
    string temp;
    for(int i = 0; i < line.size(); i++)                                        /* 分词，统计词频 */
    {
        if(isalpha(line[i]) || isalnum(line[i]))                                /* 如果只有一个词，没有除数字字母之外的分割 */
            temp.push_back(line[i]);                                            /* 就会统计不到，比如a，一个字母 */
        else if(!temp.empty())
        {
            dict[temp]++;
            temp.clear();
        }
    }
    string word;
    int max = -1;                                                               /* 记录频率最高的词 */
    for(auto it = dict.begin(); it != dict.end(); it++)
    {
        if(dict[(*it).first] > max)
        {
            max = dict[(*it).first];
            word = (*it).first;
        }
    }
    if(max != -1)
        cout << word << " " << max;
    else
        cout << temp << " " << '1';                                            /* 防止单个字符或者单个单词的测试用例 */
    return 0;
}
