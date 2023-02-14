#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        string a[1000]; // string类型的数组，里面每个数组元素都是一个字符串
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int k = 0;
        for (int i = 0; i < a[0].size(); ++i)
        {
            if (a[0][i] == '\\')
            {
                if (i < a[0].size() - 1)
                {
                    cout << endl;
                    k++;
                    for (int j = 0; j < k; ++j)
                    {
                        cout << "  ";
                    }
                }
            }
            else
            {
                cout << a[0][i];
            }
        }
        cout << endl;
        for (int i = 1; i < n; ++i)
        {
            int k = 0;
            int j;
            int flag = false;
            for (j = 0; j < a[i].size(); ++j)
            {
                if (a[i - 1][j] == a[i][j])
                {
                    if (a[i][j] == '\\')
                    {
                        k++;
                        flag = true;
                    }
                }
                else
                {
                    break;
                }
            } // 找与上一个字符串不同的位置
            for (; j < a[i].size(); ++j)
            {
                if (flag)
                {
                    // cout << endl;
                    for (int l = 0; l < k; ++l)
                    {
                        cout << "  ";
                    }
                    flag = false;
                }
                if (a[i][j] == '\\')
                {
                    if (j < a[i].size() - 1)
                    {
                        cout << endl;
                        k++;
                        for (int l = 0; l < k; ++l)
                        {
                            cout << "  ";
                        }
                    }
                }
                else
                {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}