#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
// 过于精确的小数，连float和long long也无法处理时，只好用字符串来求解
int main(int argc, char const *argv[])
{
    string a, b;
    while (cin >> a >> b)
    {
        int point_a = a.find('.');
        int point_b = b.find('.');
        // b.find(a);这句代码的意思就是从b字符串中查找a字符串。
        // 返回值的类型为int类型，返回的是字符串的下标。
        // rfind() 就是倒着查找,后面的数字代表着就是从倒数第几个开始查找。
        // 如果计算机没有找到，就会返回npos
        if (point_a > point_b)
        {                                          // b的整数部分较少
                                                   // s.insert(pos,len,str)在s串下标pos的字符前插入len个字符串str
            b.insert(0, (point_a - point_b), '0'); // 在b的整数部分插入0，对齐
        }
        else
        {
            a.insert(0, (point_b - point_a), '0');
        }
        int len_a = a.size();
        int len_b = b.size();
        if (len_a > len_b)
        { // a的小数位比较多，在b后面补全0
            b.insert(len_b, (len_a - len_b), '0');
        }
        else
        {
            a.insert(len_a, (len_b - len_a), '0');
        }
        int carry = 0; // 用来暂存进位
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] == '.')
            {
                continue;
            }
            else
            {
                a[i] = a[i] + b[i] - '0' + carry;
                carry = (a[i] - '0') / 10;
                a[i] = (a[i] - '0') % 10 + '0';
                // 之所以不能用a[i]%10是因为a[i]是char类型的
                //(a[i] - '0')是int 类型的
                // 最后再+ '0'变成char类型，所以要转换来转换去
            }
        }               // for循环结束后，相当于两个数字逐位相加完毕
        if (carry == 0) // 检查一下有没有残余的高位进位位
        {
            cout << a << endl;
        }
        else
        {
            cout << carry << a << endl;
        }
    }
    return 0;
}
