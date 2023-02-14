#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    int a[101] = {0};
    int b[101] = {0};
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        int j = 0;
        while (m--)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[j] && j <= m)
                {
                    cout << "YES" << endl;
                    j++;
                    break;
                }
                if (j > m)
                    break;
            }
            cout << "NO" << endl;
        }
    }
    return 0;
}