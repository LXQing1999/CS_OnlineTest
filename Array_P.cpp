#include <iostream>
using namespace std;
// 用指向指针的指针（二级指针）访问指针数组
int main(int argc, char const *argv[])
{
    int **a, i, j, k = 0;
    int m, n;
    cin >> m >> n;
    a = new int *[m];
    for (int i = 0; i < m; ++i)
    {
        a[i] = new int[n];
        // 用指针定义数组的好处就是数组的格式可以用户自己定义
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            k++;
            a[i][j] = k;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
        delete[] a[i]; // 用完后要删除多余指针
    // delete []表示删除的是a[i]那一行对应的n个数组元素，表示删除数组里一整行
    delete[] a; // 这个表示删除a定义的那m个行的指针
    return 0;
}