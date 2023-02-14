#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        string a[1000];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; // 一维字符串数组    // a[i]这个数组里装了许多字符串
        }
        cout << endl;
        cout << endl;
        cout << endl;
        sort(a, a + n); // sort(begin, end, cmp)，其中begin为指向待sort()的数组的第一个元素的指针，// end为指向待sort()的数组的最后一个元素的下一个位置的指针，cmp参数为排序准则，cmp参数可以不写，如果不写的话，默认从小到大进行排序。
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < a[i].size(); j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
        int k = 0; // k表示递归深度
        for (int i = 0; i < a[0].size(); i++)
        { // 输入的第一个字符串
            if (a[0][i] == '\\')
            {
                cout << "  " << endl;
            }
            else
            {
                cout << a[0][i];
            } // 因为a[0]是一个字符串,a[0][i]是要遍历一个这个字符串里的char
        }
        cout << endl;
        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] != a[i - 1][j] && a[i][j] != '\\')
                {
                    cout << a[0][i];
                }
                else
                {
                    cout << "  "; // 如果目录在上一层已经出现过了
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

/*

5
a\d\e
b\cst
d\
a\b\c
a\f\k\i
0

*/