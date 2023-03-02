#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;

int approximation(int x)
{
    int k = 0;
    int i = 1;
    for (; i * i < x; i++)
    {
        if (x % i == 0)
        {
            k = k + 2;
        }
    } // 在跳出for循环时，i++，情况好时，正好i * i == x
    if (i * i == x)
        k++;
    cout << k << endl;
    return 0;
}
int main(int argc, char const *argv[])
{
    int n;
    int a[1001] = {-1};
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            approximation(a[i]);
        }
    }
    return 0;
}
