#include <iostream>
#include <cstdio>
using namespace std;

const int L = 10001;
bool array[L] = {0};
int main(int argc, char const *argv[])
{
    int len, m;
    int l, r;
    cin >> len;
    for (int i = 0; i <= len; i++)
    {
        array[i] = 1; // 每个端点都有一棵树，包括头尾端点
    }
    int sum = len + 1;
    cin >> m;
    while (m--)
    {
        cin >> l >> r;
        for (int i = l; i <= r; i++)
        {
            // if (array[i] == 1)
            if (array[i] >= 1 && array[i] <= 1)
            {
                array[i] = 0;
                sum--;
            }
        }
    }
    cout << sum << endl;

    return 0;
}