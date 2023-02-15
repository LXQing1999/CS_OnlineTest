#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
// 设立运算符和运算数两个栈，一个用来存储运算符，另一个用来存储运算数
// 在运算符栈放置特殊字符#，其优先级最低
// 在表达式尾部添加一个特殊符号￥，其优先级次低
// 从左向右依次遍历字符串，并将其与栈顶元素做比较
// 如果扫描到的字符优先级高，将其压入栈中
// 如果扫描到的“字符优先级小于等于栈顶元素，弹出栈顶元素”
// 同时在运算数栈中弹出两个运算数进行运算，并将结果压入栈中
// 遍历到运算数时，直接压入运算数栈
// 若运算符栈中仅剩#和￥，则表达式运算结束，此时运算数栈中唯一的数字就是表达式的值

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
        // cout << num.top() << endl;
        printf("%.2f\n", num.top());
    }
    return 0;
}