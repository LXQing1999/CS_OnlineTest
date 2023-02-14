#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int y, n;
    bool flag = 0;
    int m = 1;
    int d;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 普通年
    int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 闰年

    while (cin >> y >> n)
    {
        if (y == EOF)
            break;
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) // 闰年要求能被4整除的同时，不被100整除，或者能被400整除，也属于闰年
        {
            flag = 1; // 闰年
        }
        if (flag == 0)
        {
            for (int i = 1; i < 13; i++)
            {
                if ((n / a[i]) != 0)
                {
                    m++;
                    n = n - a[i];
                }
                else
                {
                    continue;
                }
            }
            if (n == 0)
            {
                d = a[m - 1];
                m--;
            }
            else
            {
                d = n;
            }
        }
        else
        {
            for (int i = 1; i < 13; i++)
            {
                if ((n / b[i]) != 0)
                {
                    m++;
                    n = n - b[i];
                }
                else
                {
                    continue;
                }
            }
            if (n == 0)
            {
                d = b[m - 1];
                m--;
            }
            else
            {
                d = n;
            }
        }

        cout << y << "-";
        printf("%02d-%02d\n", m, d);
        // 如果输出的整型数不足两位，左侧用0补齐。
        m = 1;
        flag = 0;
    }
    return 0;
}
