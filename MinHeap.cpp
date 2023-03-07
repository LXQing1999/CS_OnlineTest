#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
// 重建小根堆
/*方案一：如果传入的参数都是正整数，直接取负，
相当于把绝对值存进priority_queue中。
方案二：运算符重载（只有自定义的类，才支持运算符重载）。
像int这种内置类型都是不支持重载的。
*/
struct Element
{
    int value;
}; // 只有自定义的类，才支持运算符重载
bool operator<(Element lhs, Element rhs)
{
    // return true;
    //  默认情况下，是构建一个大根堆 lhs<rhs为真，触发交换
    //  重新解释<的含义
    return lhs.value > rhs.value;
    // 当父>子，触发交换
} // 运算符重载
int main(int argc, char const *argv[])
{
    priority_queue<Element> pqueue;
    int arr[] = {6, 4, 2, 5, 3, 1};
    for (int i = 0; i < 6; ++i)
    {
        Element e;
        e.value = arr[i];
        pqueue.push(e);
    }
    return 0;
}