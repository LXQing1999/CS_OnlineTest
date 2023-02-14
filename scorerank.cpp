#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct student
{
    int number;
    int score;
};
const int N = 101;
bool compare(student x, student y)
{
    if (x.score == y.score)
    {
        // cout << (x.number < y.number) << endl;
        return x.number < y.number;
    }
    else
    {
        // cout << (x.score < y.score) << endl;
        return x.score < y.score;
    }
}
int n;
int main(int argc, char const *argv[])
{
    student a[N];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].number >> a[i].score;
    }
    sort(a, a + n, compare);
    // https://blog.csdn.net/weixin_42490152/article/details/100188778
    // sort中三个参数的用法
    //  当比较函数的返回值为true时，表示比较函数的第一个参数会排在第二个参数前面
    for (int i = 0; i < n; i++)
    {
        cout << a[i].number << " " << a[i].score << endl;
    }
    return 0;
}