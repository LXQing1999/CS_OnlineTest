#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void progress(long long n, int m)
{
    vector<int> ans;
    if (m == 0)
    {
        return;
    }
    else
    {
        while (n != 0)
        {
            ans.push_back(n % m);
            n = n / m;
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
    return;
}
int main(int argc, char const *argv[])
{
    int m;
    long long a, b;
    while (scanf("%d %lld %lld", &m, &a, &b) != EOF)
    {
        if (m == 0)
            return 0;
        if ((a + b) == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            progress(a + b, m);
        }
    }
    return 0;
}