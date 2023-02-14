#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
    float p, t, g1, g2, g3, gj, result;
    cin >> p >> t >> g1 >> g2 >> g3 >> gj;
    if (abs(g1 - g2) <= t) // case1
    {
        result = (g1 + g2) / 2;
        printf("%.1f\n", result);
    }
    else
    {
        if ((abs(g1 - g3) < t || abs(g2 - g3) < t) && (t - abs(g1 - g3)) * (t - abs(g1 - g2)) < 0)
        { // 有一个在公差范围内
            result = min((g1 + g3) / 2, (g2 + g3) / 2);
            printf("%.1f\n", result);
        }
        if (abs(g1 - g3) < t && abs(g2 - g3) < t)
        {
            result = max(max(g1, g2), max(g2, g3));
            printf("%.1f\n", result);
        }
        if (abs(g1 - g3) > t && abs(g2 - g3) > t)
        {
            result = gj;
            printf("%.1f\n", result);
        }
    }

    return 0;
}