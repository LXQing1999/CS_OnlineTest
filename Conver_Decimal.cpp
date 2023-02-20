#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <math.h>
using namespace std;
// 十六进制转换成十进制
int getnum(char c)
{
    if (isdigit(c))
    {
        return (c - '0');
    }
    else
    {
        return (c - 'A' + 10);
    }
}

int main(int argc, char const *argv[])
{
    string s;
    while (cin >> s)
    {
        int sum = 0;
        int k = 0; // 方
        for (int i = s.size() - 1; i >= 2; i--)
        {
            sum += (getnum(s[i])) * (pow(16, k));
            k++;
        }
        cout << sum << endl;
    }
    return 0;
}