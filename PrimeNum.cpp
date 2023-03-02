#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> prime;
int judge(int x)
{
    int limit = sqrt(x);
    for (int i = 2; i <= limit; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    for (int i = 2; i < 120000; i++)
    {
        if (judge(i) == 1)
        {
            // cout << i << " ";
            prime.push_back(i);
        }
    }
    // cout << endl;
    // for (int i = 0; i < prime.size(); i++)
    // {
    //     cout << prime[i] << " ";
    // }
    int k;
    while (cin >> k) // 第k个质数，序号是k-1
    {
        cout << prime[k - 1] << endl;
    }
    return 0;
}
