// Plural set复数集合
// 复数由实部和虚部构成
#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
struct Complex
{
    int real;
    int img; // imaginary number虚数
};
bool operator<(Complex lhs, Complex rhs)
{
    // lhs左边的模小于右边rhs的模
    return (lhs.real * lhs.real + lhs.img * lhs.img) < (rhs.real * rhs.real + rhs.img * rhs.img);
}
int main(int argc, char const *argv[])
{
    int n;
    string action;
    cin >> n;
    priority_queue<Complex> pqueue;
    for (int i = 0; i < n; i++)
    {
        cin >> action;
        string actionstr = action;
        if (action == "Pop")
        {
            if (pqueue.empty())
            {
                cout << "empty" << endl;
                // cout << "SIZE = " << pqueue.size() << endl;
            }
            else
            {
                cout << pqueue.top().real << '+' << 'i' << pqueue.top().img << endl;
                pqueue.pop();
                cout << "SIZE = " << pqueue.size() << endl;
            }
        }
        else if (actionstr == "Insert")
        {
            int real, img;
            scanf("%d+i%d\n", &real, &img);
            Complex c;
            c.real = real;
            c.img = img;
            pqueue.push(c);
            cout << "SIZE = " << pqueue.size() << endl;
        }
    }
    return 0;
}
