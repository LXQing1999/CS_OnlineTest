#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct student
{
    string name;
    int num;
    int k; // 输入顺序
    int t;
};
bool cmp(student x, student y)
{
    if (x.num == y.num)
    {
        return x.k < y.k;
    }
    else
    {
        if (x.t == 0)
        {
            return x.num > y.num;
        }
        if (x.t == 1)
        {
            return x.num < y.num;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int n, t; // t 为 0（降序）或者1（升序）
    while (scanf("%d%d", &n, &t) != EOF)
    {
        student a[1000];
        // if (n == EOF || t == EOF)
        //     break;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].name >> a[i].num;
            a[i].k = i;
            a[i].t = t;
        }
        sort(a, a + n, cmp);
        for (int i = 0; i < n; i++)
        {
            cout << a[i].name << " " << a[i].num << endl;
            // printf("%c %d\n", &a[i].name, &a[i].num);
        }
    }

    return 0;
}

/*
3
1
fang 90
yang 50
ning 70
3
0
moolgouua 43
aebjag 87
b 67
*/