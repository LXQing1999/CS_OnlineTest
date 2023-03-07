#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
// 这个优先队列原理就是大根堆。
// Priority Queue in C++ Standard Template Library (STL)
// 借助数组表示的完全二叉树
int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 6, 1, 3, 5};
    priority_queue<int> myQueue;
    for (int i = 0; i < 6; ++i)
    {
        myQueue.push(arr[i]);
        cout << "push:" << arr[i] << " ";
        cout << "top:" << myQueue.top() << endl;
    }
    cout << endl;
    while (!myQueue.empty())
    {
        cout << "pop,top:" << myQueue.top() << " ";
        myQueue.pop();
    }
    cout << endl;
    return 0;
}