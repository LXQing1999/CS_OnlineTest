#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    int n = i * 1000 + j * 100 + k * 10 + l;
                    int b = l * 1000 + k * 100 + j * 10 + i;
                    if (n != 0)
                    {
                        if (n * 9 == b)
                        {
                            cout << i << endl;
                            cout << j << endl;
                            cout << k << endl;
                            cout << l << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")