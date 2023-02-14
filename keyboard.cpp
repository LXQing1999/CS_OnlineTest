#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int keytab[26]{1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3,
               1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
int main(int argc, char const *argv[])
{
    string s;
    while (cin >> s)
    {
        int t = 0;
        for (int i = 0; i < s.size(); i++)
        {
            t += keytab[s[i] - 'a'];
            if (i != 0 && (s[i] - s[i - 1]) == (keytab[s[i] - 'a'] - keytab[s[i - 1] - 'a']))
            {
                // 如果两个字属于同一个按键，那么字母本身的间距等于它们按键次数的差
                t = t + 2; // 等待时间花费两个时间段
            }
        }
        cout << t << endl;
    }

    return 0;
}