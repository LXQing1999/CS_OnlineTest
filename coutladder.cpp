#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = (n - i) * 2; j > 0; j--)
            cout << " ";
        for (int k = n + 2 * (i - 1); k > 0; k--)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}