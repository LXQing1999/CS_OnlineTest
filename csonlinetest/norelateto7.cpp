#include <iostream>
using namespace std;
bool judge(int x)
{
    bool flag = false;
    while (x != 0)
    {
        if (x % 10 == 7) // 与7有关
        {
            flag = true;
        }
        x = x / 10;
    }
    return flag;
}
int main()
{
    int n;
    int sum = 0;
    while (cin >> n)
    {
        if (n == EOF)
        {
            break;
        }
        for (int i = 1; i < n + 1; ++i)
        {
            if ((i % 7) != 0 && judge(i) == false)
            {
                sum += i * i;
            }
        }
        cout << sum;
    }
    return 0;
}