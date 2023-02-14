#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    int j;
    while (getline(cin, s))
    {
        // if (s == EOF)
        //     break;
        int alphabet[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                j = (s[i] - 'A');
                alphabet[j]++;
            }
        }
        for (int j = 0; j < 26; j++)
        {
            char c = 'A' + j;
            cout << c << ":" << alphabet[j] << endl;
        }
    }
    return 0;
}