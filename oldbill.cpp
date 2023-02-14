#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, x, y, z, price;
    int sum;
    bool flag = true;
    while (cin >> n >> x >> y >> z)
    {
        if (n == EOF)
            break;
        for (int i = 9; i > 0; i--)
        {
            for (int j = 9; j >= 0; j--)
            {
                sum = i * 10000 + x * 1000 + y * 100 + z * 10 + j;
                if (sum % n == 0)
                {
                    price = sum / n;
                    flag = false;
                    cout << i << " " << j << " " << price << endl;
                    break;
                }
            }
            if (sum % n == 0)
            {
                break;
            }
        }
        if (flag)
            cout << 0;
    }
    return 0;
}