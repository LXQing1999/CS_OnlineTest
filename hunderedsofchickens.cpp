#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        if (n == EOF)
            break;
        for (int x = 0; x < n / 5 + 1; x++)
        {
            for (int y = 0; y < n / 3 + 1; y++)
            {
                for (float z = 0; z < n * 3; z++)
                {
                    float sum = x * 5 + y * 3 + z / 3; // 一共花了sum元  //注意数据类型，用Int会丢掉小数点
                    if (sum <= n && (x + y + z) == 100)
                    {
                        cout << "x=" << x << ",";
                        cout << "y=" << y << ",";
                        cout << "z=" << z << endl;
                    }
                }
            }
        }
    }
    return 0;
}