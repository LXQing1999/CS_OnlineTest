#include <iostream>
#include <cstdio>
#include <string>
#include <map>
// map是一个将关键字key和映射值value形成一对映射后绑定存储的容器
using namespace std;
map<string, string> dict;
int main(int argc, char const *argv[])
{
    string str;
    // 构建词典
    while (getline(cin, str))
    {
        if (str == "@END@")
            b
            {
                break;
            }
        // 用find找到下标i，再用substr取出子串
        //  咒语从[0,i]长度i+1
        // 功能[i+2,end] ，剩余长度
        string word = str.substr(0, str.find(']') + 1);
        string info = str.substr(str.find(']') + 2);
        // substr默认取到结尾，end部分不用写
        // printf("word=%s,info=%s\n", word.c_str(), info.c_str());
        // 轮流互为键 值 插入进去，保证不管是搜咒语还是搜功能都可以查到
        dict[word] = info;
        dict[info] = word;
    }
    int n;
    cin >> n;
    getchar(); // 吃掉回车
    while (n--)
    {
        string key;
        getline(cin, key);
        string ans = dict[key];
        if (ans == "")
        {
            ans = "what?";
        }
        else if (ans[0] == '[')
        {
            ans = ans.substr(1, ans.size() - 2);
        }
        cout << ans << endl;
    }
    return 0;
}
