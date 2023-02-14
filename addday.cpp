#include <iostream>
#include <cstdio>
using namespace std;

int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
bool leap(int x)
{
    return (x % 4 == 0 && x % 100 != 0 || (x % 400 == 0));
}
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
int main(int argc, char const *argv[])
{
    int n, y, m, d, add;
    cin >> n;
    while (n--)
    {
        cin >> y >> m >> d >> add;

        int row = leap(y); // 0是false 普通年；1是true 闰年
        for (int i = 1; i < m; i++)
        {
            add += daytab[row][i];
            // cout << a[i] << " ";
        }
        add += d;
        while (add > numofyear(y)) // 超过了一年
        {
            add = add - numofyear(y);
            y++;
        }
        m = 0;
        row = leap(y);
        while (add > daytab[row][m])
        {
            add = add - daytab[row][m];
            m++;
        }
        d = add;
        printf("%04d-%02d-%02d\n", y, m, d);
    }
    return 0;
}