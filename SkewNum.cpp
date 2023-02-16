#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    string n;
    while (cin >> n)
    {
        int len = n.size();
        int sum = 0;
        for (int i = 0; i < n.size(); i++)
        {
            // cout << len << endl;
            // cout << n[i] << " ";
            sum += (n[i] - '0') * (pow(2, len) - 1);
            // Math.pow(底数,几次方)   求幂
            len--;
        }
        cout << sum << endl;
    }
    return 0;
}