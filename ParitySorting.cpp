#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int a;
    int odd[10] = {0};
    int even[10] = {0};
    int t1 = 0;
    int t2 = 0;

    for (int i = 0; i < 10; i++)
    {
        cin >> a;
        if (a % 2 == 1)
        {
            odd[t1] = a;
            t1++;
        }
        else
        {
            even[t2] = a;
            t2++;
        }
    }
    sort(odd, odd + t1, greater<int>()); // 大的放前面，所以是降序
    sort(even, even + t2, less<int>());  // 小的放前面，所以是升序
    for (int i = 0; i < t1; i++)
    {
        cout << odd[i] << " ";
    }
    for (int i = 0; i < t2; i++)
    {
        cout << even[i] << " ";
    }

    return 0;
}
