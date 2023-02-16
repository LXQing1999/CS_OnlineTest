#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> result;
    int n, t;
    result.clear();
    while (cin >> n)
    {
        while (n != 0)
        {
            t = n % 2;
            result.push_back(t);
            n = n / 2;
        }
        for (int i = result.size() - 1; i >= 0; i--)
        {
            cout << result[i];
        }
        cout << endl;
        result.clear();
        // vector有两个参数:size表示当前vector容器内存储的元素个数;
        // capacity，表示当前vector在内存中申请的这片区域所能容纳的元素个数。
        // 通常capacity会比size大，如果往vector中push_back数据，这样就不用重新申请内存和拷贝元素到新内存区域了，便于节省时间
        // vector.clear() 的真正作用是：把size设置成0，capacity不变。
    }
    return 0;
}