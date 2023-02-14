#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int a[1001];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << a[n - 1] << endl;
        for (int i = 0; i < n - 1; i++)
        {
            cout << a[i] << " ";
        }
        if (n == 1)
            cout << "-1";
        cout << endl;
    }
    return 0;
}
