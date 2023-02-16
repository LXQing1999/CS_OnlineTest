#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct num
{
    int x;
    int y;
};
const int N = 1001;
bool cmp(num a, num b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }
    else
    {
        return a.x < b.x;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    num a[N];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
        sort(a, a + n, cmp);
        cout << a[0].x << " " << a[0].y << endl;
    }

    return 0;
}
