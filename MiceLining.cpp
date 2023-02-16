#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct mouse
{
    int weight;
    string color;
};
const int N = 101;
bool cmp(mouse x, mouse y)
{
    return x.weight > y.weight;
} // 这个返回值应该是排序的判断条件
int main(int argc, char const *argv[])
{
    int n;
    mouse a[N];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].weight >> a[i].color;
            // 注意，如果a是指针，用a->sth  ;如果a[i]是结构体，用a[i].sth
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < n; i++)
        {
            cout << a[i].color << endl;
        }
    }
    return 0;
}
