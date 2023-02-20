#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void octal(int n)
{
    vector<int> ans;
    if (n == 0)
    {
        ans.push_back(0);
    }
    else
    {
        while (n != 0)
        {
            ans.push_back(n % 8);
            n = n / 8;
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
    int n;
    while (scanf("%d", &n) != EOF)
    {
        octal(n);
    }
    return 0;
}