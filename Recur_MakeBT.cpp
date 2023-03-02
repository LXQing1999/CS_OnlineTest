#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
// 递归调用建立二叉树
// 从先序序列中还原二叉树
struct TreeNode
{
    char data;
    TreeNode *leftChild;
    TreeNode *rightChild;
};
TreeNode *RecursiveBuildTree(int &i, string str)
{ // 返回的是本棵子树的根结点的地址
    char c = str[i];
    ++i;
    if (c == '#')
    {
        return NULL; // 返回空树
    }
    else
    {
        TreeNode *pNewNode = new TreeNode;
        pNewNode->data = c;
        pNewNode->leftChild = RecursiveBuildTree(i, str);
        pNewNode->rightChild = RecursiveBuildTree(i, str);
        return pNewNode;
    }
}
void InOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        InOrder(root->leftChild);
        printf("%c ", root->data);
        InOrder(root->rightChild);
    }
}
int main()
{
    // string str = "ab##cd#gf###e##";
    char str[1001];
    while (scanf("%s", str) != EOF)
    {
        int i = 0;
        TreeNode *root = RecursiveBuildTree(i, str);
        InOrder(root);
        printf("\n");
    }
}