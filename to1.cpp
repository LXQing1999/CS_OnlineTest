#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int t = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
                t++;
            }
            else
            {
                n = 3 * n + 1;
                n = n / 2;
                t++;
            }
        }
        cout << t << endl;
    }
    return 0;
}