#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;

    while (cin >> a >> b)
    // scanf("%s", str);不用加& 因为数组名是一个指针，代表数组头的地址
    {
        int result = 0;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                result += (a[i] - '0') * (b[j] - '0');
                //-'0'是ASCII码的原理
                // 这里利用string类型替换int型简化问题
            }
        }
        cout << result << endl;
    }

    return 0;
}
