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
        sort(a, a + n);                       // sort(begin, end, cmp)，其中begin为指向待sort()的数组的第一个元素的指针，// end为指向待sort()的数组的最后一个元素的下一个位置的指针，cmp参数为排序准则，cmp参数可以不写，如果不写的话，默认从小到大进行排序。
        int k = 0;                            // k表示递归深度
        for (int i = 0; i < a[0].size(); i++) // 输入的第一个字符串
        {
            if (a[0][i] == '\\')
            {
                if (i < a[0].size() - 1)
                {
                    cout << endl;
                    k++;
                    for (int j = 0; j < k; j++)
                    {
                        cout << "  ";
                    }
                }
            }
            else
            {
                cout << a[0][i];
            } // 因为a[0]是一个字符串,a[0][i]是要遍历一个这个字符串里的char
        }
        cout << endl;
        for (int i = 1; i < n; ++i)
        {
            int k = 0;
            int flag = false;
            for (int j = 0; j < a[i].size(); ++j)
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
            for (int j = 0; j < a[i].size(); ++j)
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
/*    for (int i = 1; i < n; i++)
     {
         int k = 0;
         bool flag = false;
         for (int j = 0; j < a[i].size(); j++)
         {
             if (a[i - 1][j] == a[i][j]) // 如果目录在上一层已经出现过了
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
         for (int j = 0; j < a[i].size(); j++)
         {
             if (flag)
             {
                 for (int l = 0; l < k; l++)
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
                     for (int l = 0; l < k; l++)
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
 return 0;
}*/