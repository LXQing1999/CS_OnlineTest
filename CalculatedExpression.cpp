#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int priority(char c)
{
    if (c == '#')
    {
        return 0;
    }
    else if (c == '$')
    {
        return 1;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
double calculate(double x, double y, char op)
{
    double result = 0;
    if (op == '+')
    {
        result = x + y;
    }
    else if (op == '-')
    {
        result = x - y;
    }
    else if (op == '*')
    {
        result = x * y;
    }
    else if (op == '/')
    {
        result = x / y;
    }
    return result;
}
double getnum(string s, int &i)
{
    double data = 0;
    while (isdigit(s[i]))
    {
        data = data * 10 + s[i] - '0';
        i++;
    }
    return data;
}
int main(int argc, char const *argv[])
{
    string s;
    while (getline(cin, s))
    {
        if (s == "0")
        {
            break;
        }
        int i = 0;             // 表示扫描表达式时的下标
        stack<char> operation; // 运算符栈
        stack<double> num;     // 运算数栈
        s += '$';              // 字符串末尾增加一个字符标志
        operation.push('#');
        while (i < s.size())
        {
            if (s[i] == ' ')
            {
                i++;
            }
            else if (isdigit(s[i]))
            {
                // cout << s[i] << " ";
                num.push(getnum(s, i));
            }
            else
            { // 扫描到的是字符,且比栈顶的优先级高
                if (priority(s[i]) > priority(operation.top()))
                {
                    operation.push(s[i]); // 扫描到的字符优先级高，压入栈中
                    i++;                  // 继续扫描
                }
                else
                { // 弹出栈顶元素，并和运算数栈顶的两个数字进行运算
                    double y = num.top();
                    num.pop();
                    double x = num.top();
                    num.pop();
                    num.push(calculate(x, y, operation.top()));
                    // 将运算结果压入栈顶
                    operation.pop();
                }
            }
        }
        cout << num.top() << endl;
        // printf("%.2f\n", num.top());
    }
    return 0;
}