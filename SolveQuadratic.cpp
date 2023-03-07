#include <iostream>
#include <cmath>
using namespace std;
// 间接访问，利用指针解二元一次方程
int SolveQuadratic(double a, double b, double c, double *px1, double *px2)
{
    double disc, sqrtDisc;
    if (a == 0)
        return 3; // 不是二元一次方程
    disc = b * b - 4 * a * c;
    if (disc < 0)
        return 2; // 无根
    if (disc == 0)
    {
        *px1 = -b / (2 * a);
        return 1; // 等根
    }
    sqrtDisc = sqrt(disc);
    *px1 = (-b + sqrtDisc) / (2 * a);
    *px2 = (-b - sqrtDisc) / (2 * a);
    return 0;
}
int main()
{
    double a, b, c, x1, x2;
    // abc是方程的系数
    int result;
    cout << "请输入a,b,c:";
    cin >> a >> b >> c;
    result = SolveQuadratic(a, b, c, &x1, &x2);
    switch (result)
    {
    case 0:
        cout << "方程有两个不同的解：" << x1 << " " << x2;
        break;
    case 1:
        cout << "方程有两个等解：" << x1;
        break;
    case 2:
        cout << "方程无实根";
        break;
    case 3:
        cout << "不是二元一次方程";
        break;
    }
    return 0;
}