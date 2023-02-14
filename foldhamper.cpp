#include <iostream>
#include <cstdio>
using namespace std;

char matrix[80][80];
int main()
{
    int n;
    char a, b; // a是中心字符  b是外框字符
    bool first = true;
    while (cin >> n >> a >> b)
    {
        if (n == EOF || a == EOF || b == EOF)
        {
            break;
        }
        if (first == true)
        {
            first = false;
        }
        else
        {
            cout << endl;
        }
        for (int i = 0; i < n / 2 + 1; i++)
        {                           //(i,i)是每圈左上角坐标
            int j = n - i - 1;      // 矩阵下标是从0开始的，所以-1；(j,j)是每圈右下角坐标
            int length = n - 2 * i; // 表示当前圈的边长
            char c;
            if ((n / 2 - i) % 2 == 0) // 用奇偶数沿着中间的横线判断应该填充的字符
            {
                c = a;
            }
            else
            {
                c = b;
            }
            for (int k = 0; k < length; k++)
            {
                matrix[i][i + k] = c; // 上侧赋值
                matrix[i + k][i] = c; // 下侧赋值
                matrix[j][j - k] = c; // 右侧赋值
                matrix[j - k][j] = c; // 左侧赋值
            }
        }
        if (n != 1)
        {
            matrix[0][0] = ' ';
            matrix[0][n - 1] = ' ';
            matrix[n - 1][0] = ' '; //' '单引号是char  " "双引号是字符串
            matrix[n - 1][n - 1] = ' ';
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
