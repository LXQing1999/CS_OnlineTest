#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    while (getline(cin, s))
    {
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] <= 'y' && s[i] >= 'a') || (s[i] <= 'Y' && s[i] >= 'A'))
            {
                s[i] = s[i] + 1;
            }
            else if (s[i] == 'z' || s[i] == 'Z')
            {
                s[i] = s[i] - 25;
            }
            else
            {
                continue;
            }
        }
        // cout << s << endl;
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
