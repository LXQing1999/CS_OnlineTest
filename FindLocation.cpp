#include <iostream>
#include <cstdio>
using namespace std;

void Print(string s, int i, int temp)
{
    char c;
    c = i;
    for (int i = 0; i < s.size(); i++)
    {
        if (c == s[i])
        {
            cout << c << ':' << i;
            temp--;
            if (temp >= 1)
                cout << ',';
            if (temp == 0)
                cout << endl;
        }
    }

    return;
}
int main(int argc, char const *argv[])
{
    int a[123] = {0}; // 用ASCII码表暂存位置
    string s;
    unsigned int t = 0;
    while (cin >> s)
    {
        for (char i : s)
        {
            t = i; // 强制类型转换
            a[t]++;
        }
        for (char j : s)
        {
            t = j;           // t表示j在ASCII码表的位置
            int temp = a[t]; // 出现的次数
            if (a[t] > 1)
            {
                Print(s, t, temp);
                a[t] = 0;
            }
            /*for (int i = 48; i < 123; i++)
            {
                if (a[i] > 1 && t == i)
                {
                    Print(s, i, temp);
                    a[i] = 0;
                }
                else
                {
                    continue;
                }
            }*/
        }
    }
    return 0;
}