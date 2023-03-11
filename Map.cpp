// Map底层是一棵二叉搜索树（红黑树）
// 数据插入map后，里面是有序的，时间复杂度O(lnN)
// 想要查找时间复杂度为O(1)时，底层使用散列hash
// 但hash要申请很大的空间，而且里面的数据是无序的
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, int> myMap; // 键值对：键是tring 值是map
    if (myMap.empty())
    { // 判空
        cout << "myMap is empty!" << endl;
    }
    cout << "Size of myMap =" << myMap.size() << endl;
    // 插入一对键值 1：运算符 2：insert方法
    myMap["Caixukun"] = 1;
    myMap.insert(pair<string, int>("Wuyifan", 2)); // 构建一个键值对
    cout << "Size of myMap =" << myMap.size() << endl;
    // 删除一对键值对 erase
    myMap.erase("Wuyifan");
    cout << "Size of myMap =" << myMap.size() << endl;
    return 0;
}
