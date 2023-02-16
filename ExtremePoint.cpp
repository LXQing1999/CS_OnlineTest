#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    vector<int> index;
    index.clear();
    int a[80];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (a[0] != a[1])
            index.push_back(0);

        for (int i = 1; i <= n - 2; i++)
        {
            if (((a[i] > a[i - 1]) && (a[i] > a[i + 1])) || ((a[i] < a[i - 1]) && (a[i] < a[i + 1])))
            {
                index.push_back(i);
            }
            else
            {
                continue;
            }
        }
        if (a[n - 1] != a[n - 2])
            index.push_back(n - 1);
        for (int i = 0; i < index.size(); i++)
        {
            cout << index[i] << " ";
        }
        cout << endl;
        index.clear();
    }
    return 0;
}
