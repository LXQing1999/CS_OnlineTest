#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
queue<int> person;
int main(int argc, char const *argv[])
{
    int n, k, m;
    while (cin >> n >> k >> m)
    {
        if (n == 0 && k == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            person.push(i); // 给n个人逐个编号
        }
        for (int i = 0; i <= k - 1; i++)
        // 为了把编号为k的放在队列首
        {
            person.push(person.front()); // 队首元素入队尾
            person.pop();                // 出队
            // 先入队再出队是为了防止数据丢失
        } // 当跳出for循环时，队头已经定位在编号k的位置了
        while (!person.empty())
        {
            for (int i = 0; i < m - 1; i++)
            {
                person.push(person.front());
                person.pop();
            } // 前m-1个人排到队尾去
            // 每一轮for循环都是一次叫号
            person.pop(); // 数到m的出队
            if (person.size() == 1)
            {
                cout << person.front() << endl;
            }
            // else
            // {
            //     cout << " " << person.front();
            // }
        }
    }
    return 0;
}