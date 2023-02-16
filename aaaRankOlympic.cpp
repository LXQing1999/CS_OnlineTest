#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct country
{
    int golden;
    int Awards;
    int population;
    int num; // 国家号
};
const int N = 101;
bool cmp(country x, country y)
{

} // 这个返回值应该是排序的判断条件
int main(int argc, char const *argv[])
{
    int n, m;
    country a[N];
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].golden >> a[i].Awards >> a[i].population;
            // 注意，如果a是指针，用a->sth  ;如果a[i]是结构体，用a[i].sth
        }
        for (int i = 0; i < m; i++)
        {
            cin >> a[i].num;
        }
        sort(a, a + m, cmp);

        for (int i = 0; i < n; i++)
        {
            cout << a[i].num << endl;
        }
    }
    return 0;
}
