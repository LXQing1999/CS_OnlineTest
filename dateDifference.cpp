#include <iostream>
#include <cstdio>
using namespace std;

int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
bool leap(int x)
{
    return (x % 4 == 0 && x % 100 != 0 || (x % 400 == 0));
} // 是闰年的话，return 1；不是闰年的话，会return 0；
int numofyear(int y)
{
    if (leap(y) == 1)
    {
        return 366;
    }
    else
    {
        return 365;
    }
}
int Sum(int y, int m, int d)
{
    int sum = 0;
    for (int i = 1; i < y; i++)
    {
        if (leap(i) == 1)
        {
            sum += 366;
        }
        else
        {
            sum += 365;
        }
    }
    int row = leap(y);
    for (int j = 0; j < m; j++)
    {
        sum += daytab[row][j];
    }
    sum += d;
    return sum;
}
int main(int argc, char const *argv[])
{
    // int a, b;
    // while (cin >> a >> b)
    // {
    //     if (a == EOF || b == EOF)
    //         break;
    //     // int y1 = a / 10000;
    //     // int m1 = (a / 100) % 100;
    //     // int d1 = a % 100;
    //     // int y2 = b / 10000;
    //     // int m2 = (b / 100) % 100;
    //     // int d2 = b % 100;
    // }
    int y, m, d;
    while (scanf("%4d%2d%2d", &y, &m, &d) != EOF)
    {
        int sum1, sum2;
        sum1 = Sum(y, m, d);
        scanf("%4d%2d%2d", &y, &m, &d);
        sum2 = Sum(y, m, d);
        int difference = abs(sum1 - sum2) + 1;
        cout << difference << endl;
    }
    return 0;
}