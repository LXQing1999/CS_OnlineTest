#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int y, m, d;
    bool flag = 0;
    while (cin >> y >> m >> d)
    {
        if (y == EOF)
            break;
        int sum = 0;
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) // 闰年要求能被4整除的同时，不被100整除，或者能被400整除，也属于闰年
        {
            flag = 1;
        }
        int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 普通年
        int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 闰年
        if (flag == 1)
        {
            for (int i = 1; i < m; i++)
            {
                sum += b[i];
                // cout << a[i] << " ";
            }
            sum += d;
        }
        else
        {
            for (int i = 1; i < m; i++)
            {
                sum += a[i];
            }
            sum += d;
        }
        cout << sum << endl;
    }
    return 0;
}