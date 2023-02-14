#include <iostream>
#include <cstdio>
using namespace std;

char a[7][7]; // 原始图形
char b[3005][3005];
for (int i = 0; i < 3005; i++)
{
    for (int j = 0; j < 3005; j++)
    {
        b[i][j] = " "; // 初始化
    }
}

int main(int argc, char const *argv[])
{
    int n, q;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        cin >> q;
    }
    return 0;
}