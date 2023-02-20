#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    // 因为cin会自动忽略空格，所以遇到多个空格会无法处理，还是用getline
    int len = 0;
    while (getline(cin, s))
    {
        len = s.size();
        if (s[0] >= 'a' && s[0] <= 'z')
            s[0] = s[0] + 32;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n')
            {
                if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
                {
                    s[i + 1] = s[i + 1] + 32;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
/* while (cin >> s)
     {
         for (int i = 0; i <= s.size(); i++)
         {
             if (i == 0 && s[i] >= 97 && s[i] <= 122)
                 s[0] = s[0] - 32;
             if (i == s.size() && s[s.size()] != ' ')
             {
                 cout << s;
                 break;
             }
             else
             {
                 cout << s << " ";
                 break;
             }
         }
     }*/