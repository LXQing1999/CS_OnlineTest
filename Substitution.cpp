#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    string result;
    getline(cin, s);

    string a, b;
    cin >> a >> b;
    int index = 0;                      // 暂存单词起始位置
    string compare;                     // 用来比较的，主串中的单个单词
    for (int i = 0; i <= s.size(); i++) // 扫描主串
    // 这里必须有“=”号，因为\n在string下标为 s.size()的位置
    {
        if (s[i] == ' ' || s[i] == '\0') // 每一个单词的结尾
        {
            compare = s.substr(index, i - index);
            // s.substr(pos, len);   提取子串，位置和串长
            if (compare == a)
            {
                result = result + b + ' ';
            }
            else
            {
                result = result + compare + ' ';
            }
            index = i + 1; // 跳到下一个单词那里去
        }
    }
    cout << result << endl;

    return 0;
}