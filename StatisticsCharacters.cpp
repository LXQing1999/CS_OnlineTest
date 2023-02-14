#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;
    while (getline(cin, a))
    {
        if (a == "#")
            break;
        getline(cin, b);
        for (int i = 0; i < a.size(); i++)
        {
            int t = 0;
            for (int j = 0; j < b.size(); j++)
            {
                if (a[i] == b[j])
                    t++;
            }
            cout << a[i] << " " << t << endl;
        }
    }
    return 0;
}