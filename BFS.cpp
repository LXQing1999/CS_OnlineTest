// 搜索是枚举的升级，枚举列出所有的状态
// 采用高效的策略，访问树中的所有结点
// BFS广度优先搜索
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct Info
{
    int pos;
    int time;
};
queue<Info> posQueue; // 建立一个Info类型的队列
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;

    bool isvisit[10001] = {false};
    // 把起始点加入队列
    Info root;
    root.pos = n; // 起始位置
    root.time = 0;
    posQueue.push(root);
    while (!posQueue.empty())
    {
        Info cur = posQueue.front();
        posQueue.pop();
        if (cur.pos == k)
        {
            cout << cur.time << endl;
            break;
        }
        isvisit[cur.pos] = true;
        // 把邻居加入到队列当中
        Info neighbour;
        if ((cur.pos - 1) >= 0 && (cur.pos - 1) <= 100000 && (!isvisit[cur.pos - 1]))
        {
            neighbour.pos = cur.pos - 1;
            neighbour.time = cur.time - 1;
            posQueue.push(neighbour);
        }
        if ((cur.pos + 1) >= 0 && (cur.pos + 1) <= 100000 && (!isvisit[cur.pos + 1]))
        {
            neighbour.pos = cur.pos + 1;
            neighbour.time = cur.time + 1;
            posQueue.push(neighbour);
        }
        if ((cur.pos * 2) >= 0 && (cur.pos * 2) <= 100000 && (!isvisit[cur.pos * 2]))
        {
            neighbour.pos = cur.pos * 2;
            neighbour.time = cur.time * 2;
            posQueue.push(neighbour);
        }
    }

    return 0;
}
