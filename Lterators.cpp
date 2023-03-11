// 迭代器可以看作指向内部的指针
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string, int> myMap;
int main(int argc, char const *argv[])
{
    map<string, int> myMap = {
        {"Caixukun,1"},
        {"Wuyifan,2"},
        {"Liyifeng,3"},
    };
    map<string, int>::iterator it; // 定义一个迭代器
    // myMap.begin() 第一个成员的位置
    // myMap.end() 尾后的位置
    for (it = myMap.begin(); it != myMap.end(); ++it)
    {
        // 对于Map而言，++it移动迭代器的指向(unorder_map不支持这个操作)
        printf("it->first=%s,it->second=%d\n", it->first.c_str(), it->second);
        // map里面是按照键的大小来存储的，C L W的字典序
    }                            // find方法，某个键是否存在
    it = myMap.find("caixukun"); // 返回的是一个迭代器类型
    // 查找的时候区分字母大小写
    if (it != myMap.end())
    {
        printf("Found,it->first=%s,it->second=%d\n", it->first.c_str(), it->second);
    }
    else
    {
        printf("Not Found.\n");
    }
    return 0;
}
