#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[101];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n); // sort中的两个参数分别表示待排序序列的起始地址和结束地址
    // sort(first,last,cmp);             [first，last)（一定要注意这里的区间是左闭又开）
    // first是元素的起始地址，last是结束地址，cmp是排序的方式。对区间内数据根据cmp的方式进行排序。也可以不写第三个参数，此时按默认排序，从小到大进行排序。
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}