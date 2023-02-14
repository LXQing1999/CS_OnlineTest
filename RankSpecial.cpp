#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[1001];
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > max)
        {
            swap(a[i], max);
        }
    }
    return 0;
}
