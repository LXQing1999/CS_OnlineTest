#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
// 由已知的先序和中序字符串，还原出二叉树
struct TreeNode
{
    char data;
    TreeNode *leftChild;
    TreeNode *rightChild;
};
TreeNode *rebuild(string preOrder, string inOrder)
{
    if (preOrder.size() == 0)
    {
        return NULL; // 空树
    }
    else
    { // 不为空树，从先序确定根
        char rootdata = preOrder[0];
        // 取到的这个元素为根节点
        TreeNode *pNewNode = new TreeNode;
        // 指向新结点的指针，在堆上申请了一个新的结点
        pNewNode->data = rootdata;
        // 拿根去切割中序
        int pos = inOrder.find(rootdata);
        // 返回一个整数，rootdata在中序序列中出现的位置
        //(0,pos-1)是左子树的;(pos+1,end)是右子树的
        /* preOrder.substr(1, pos); // 0在preOrder里面是根
         // 切割子串preOrder.substr(起始位置，切割长度)
         preOrder.substr(pos + 1);
         // 切割子串preOrder.substr(起始位置)默认切割到结束位置
         inOrder.substr(0, pos);
         inOrder.substr(pos + 1);*/
        pNewNode->leftChild = rebuild(preOrder.substr(1, pos), inOrder.substr(0, pos));
        pNewNode->rightChild = rebuild(preOrder.substr(pos + 1), inOrder.substr(pos + 1));
        return pNewNode;
    }
}
void postOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->leftChild);
    // 指针用-> 类用.
    postOrder(root->rightChild);
    printf("%c", root->data);
}
// 返回一个结点的指针类型，比如根节点的地址
// 返回值表示子树的根节点的地址
int main(int argc, char const *argv[])
{
    char inOrder[30];
    char preOrder[30];
    while (scanf("%s%s", preOrder, inOrder) != EOF)
    {
        TreeNode *root;
        root = rebuild(preOrder, inOrder);
        postOrder(root);
        printf("\n");
    }

    return 0;
}
// 缺少输出
