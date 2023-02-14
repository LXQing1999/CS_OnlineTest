#include <iostream>
using namespace std;

int main()
{
    int a, b;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                int abc = i * 100 + j * 10 + k;
                int bbc = j * 100 + k * 10 + k;
                if ((abc + bbc) == 532)
                {
                    cout << i << " ";
                    cout << j << " ";
                    cout << k << " ";
                }
            }
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")