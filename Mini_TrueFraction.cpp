#include <iostream>
#include <cstdio>

using namespace std;

/*int GCD(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return GCD(a - b, b);
    if (a < b)
        return GCD(b - a, a);
}//更相减损法
*/
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return GCD(b, a % b);
    }
} // 辗转相除法
int main(int argc, char const *argv[])
{
    int n;
    int a[600] = {-1};
    while (cin >> n)
    {
        int k = 0;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            // cout << a[i] << " ";
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i] < a[j])
                {
                    if (GCD(a[i], a[j]) == 1)
                        k++;
                }
            }
        }
        cout << k << endl;
        int a[600] = {-1};
    }
    return 0;
}
