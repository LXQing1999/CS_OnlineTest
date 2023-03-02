#include <iostream>
#include <cstdio>
#include <math.h>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    unsigned long long n;
    stack<int> binary;
    // binary.clear();
    while (cin >> n)
    {
        if (n == 0)
        {
            cout << 0;
        }
        while (n != 0)
        {
            binary.push(n % 2);
            n = n / 2;
        }
        while (!binary.empty())
        {
            cout << binary.top();
            binary.pop();
        }
        cout << endl;
        // binary.clear();
    }
    return 0;
}
