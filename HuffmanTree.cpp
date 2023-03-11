/* 迭代式求带权路径和
N的带权路径和=L的带权路径和+L的权重和+
             R的带权路径和+R的带权路径和
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int> pqueue;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int leaf; // 叶节点都是正整数，小于100
        cin >> leaf;
        pqueue.push(-leaf);
    }            // 默认大根堆，可以通过存入相反数，模拟小根堆
    int res = 0; // 用来存储带权路径和的中间结果
    while (pqueue.size() > 1)
    {
        int leaf1 = pqueue.top();
        pqueue.pop();
        int leaf2 = pqueue.top();
        pqueue.pop();
        // 计算带权路径和
        res = res + leaf1 + leaf2;
        // 把构成的新子树重新插回到集合K中
        pqueue.push(leaf1 + leaf2);
    }
    cout << -res << endl;
    // 当哈夫曼树构建完成后就输出结果
    return 0;
}
