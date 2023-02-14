#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, x;
    int a[201] = {0};
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> x;
        int pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                pos = i;
                break; // 找到了，跳出本轮循环，直接打印
            }
        }
        cout << pos << endl;
    }
    return 0;
}