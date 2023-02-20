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
    else if (islower(c))
    {
        return ((c - 'a') + 10);
    }
    else
    {
        return ((c - 'A') + 10);
    }
}
int conver(int decimal, int b)
{
    vector<int> ans;
    if (decimal == 0)
    {
        cout << '0' << endl;
    }
    else
    {
        while (decimal != 0)
        {
            ans.push_back(decimal % b);
            decimal = decimal / b;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] < 10)
        {
            cout << ans[i];
        }
        else
        {
            char t = ans[i] - 10 + 'A'; // 强制类型转换
            cout << t;
        }
    }
    cout << endl;
    return 0;
}
int main(int argc, char const *argv[])
{
    int a, b;
    string n;
    while (cin >> a >> n >> b)
    /*输入参数是已经定义好的“字符数组名”, 不用加 &, 因为在C语言中数组名就代表该数组的起始地址 */
    {
        int sum = 0;
        int k = 0; // 方
        for (int i = n.size() - 1; i >= 0; i--)
        {
            sum += (getnum(n[i])) * (pow(a, k));
            k++;
        } // 结束后的到n的十进制数值
        // cout << sum << endl;
        conver(sum, b);
    }
    return 0;
}