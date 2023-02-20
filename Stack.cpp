#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
    stack<int> mystack;
    int n;
    char c;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            if (c == 'P')
            {
                int i;
                cin >> i;
                mystack.push(i);
            }
            else if (c == 'O')
            {
                if (!mystack.empty())
                {
                    mystack.pop();
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (!mystack.empty())
                {
                    int temp = mystack.top();
                    cout << temp << endl;
                }
                else
                {
                    cout << 'E' << endl;
                }
            }
        }
    }
    return 0;
}
