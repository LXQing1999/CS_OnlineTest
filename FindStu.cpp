#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
// 查找学术信息
struct Student
{
    string name;
    string gender;
    int age;
};
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    map<string, Student> infoMap;
    for (int i = 0; i < n; i++)
    {
        char num[30];
        // 这些字符数组都相当于string类型，只是方便限定长度
        char name[30];
        char gender[30];
        int age;
        scanf("%s%s%s%d", num, name, gender, &age);
        // key string
        string numstr = num; // C风格的字符数组变为C++风格的字符串
        // value student
        Student student;
        student.name = name;
        student.gender = gender;
        student.age = age;
        infoMap[numstr] = student;
        // 把numstr作为键，把student作为插入的值
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        char num[30];
        scanf("%s", num);
        string numstr = num; // C风格的字符数组变为C++风格的字符串
        if (infoMap.find(numstr) != infoMap.end())
        {
            // 找到了键值对
            printf("%s %s %s %d\n", numstr.c_str(),
                   infoMap[numstr].name.c_str(),
                   infoMap[numstr].gender.c_str(),
                   infoMap[numstr].age);
        }
        else
        {
            printf("No Answer!\n");
        }
    }
    return 0;
}
