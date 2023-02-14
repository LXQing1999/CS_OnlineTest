#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
// vector 可用于邻接表，尤其擅长处理数据量不确定的情况
vector<int> numE;
vector<int> numG;
int judge(int x)
{
    int sum = 0;
    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
        {
            sum += i;
        }
    }
    if (sum == x)
    { // 完数
        numE.push_back(x);
    }
    else if (sum > x)
    { // 盈数
        numG.push_back(x);
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    for (int i = 2; i <= 60; i++)
    {
        judge(i);
    }
    cout << "E:";
    for (int k = 0; k < numE.size(); k++)
    {
        if (k == numE.size() - 1)
        {
            cout << numE[k];
        }
        cout << " " << numE[k];
    }
    cout << endl;
    cout << "G:";
    for (int k = 0; k < numG.size(); k++)
    {
        cout << " " << numG[k];
    }
    cout << endl;
    return 0;
}
