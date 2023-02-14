#include <iostream>
using namespace std;

int reverse(int x)
{
    int n = 0;
    while (x != 0)
    {
        n = n * 10;       // 提高位次
        n = n + (x % 10); // 取得个位
        x = x / 10;       // 去掉最低位
    }
    return n;
}
int main()
{
    for (int i = 0; i < 257; i++)
    {
        if (i * i <= 256 && i * i == reverse(i * i))
        {
            cout << i << endl;
        }
    }
    return 0;
}

// 64 位输出请用 printf("%lld")