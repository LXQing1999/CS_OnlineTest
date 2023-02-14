#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    while (getline(cin, s))
    {
        if (s == "ENDOFINPUT")
            break;
        getline(cin, s);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = 'A' + (s[i] - 'A' + 21) % 26;
                // A加上s[i]在字母中的相对位置，基于ASCII码表的求解
            }
            else
            {
                continue;
            }
        }
        cout << s << endl;
    }
    cin >> s;

    return 0;
}
