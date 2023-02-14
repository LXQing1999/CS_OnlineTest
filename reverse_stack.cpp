#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<int> mystack;
int main(int argc, char const *argv[])
{
    int n;
    long long a;
    while (cin >> n)
    {
        while (n--)
        {
            cin >> a;
            mystack.push(a);
        }
        while (!mystack.empty())
        {
            cout << mystack.top() << " ";
            mystack.pop(); // 之所以()里不用写是因为默认弹出栈顶
        }
        cout << endl;
    }
    return 0;
}