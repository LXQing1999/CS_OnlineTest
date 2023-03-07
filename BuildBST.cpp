#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *leftChild;
    TreeNode *rightChild;
};
void insertBST(TreeNode *&root, char data)
{
    TreeNode *pNewNode = new TreeNode;
    pNewNode->data = data;
    pNewNode->leftChild = NULL;
    pNewNode->rightChild = NULL;
    if (root == NULL)
    {
        root = pNewNode;
    }
    else
    {
        TreeNode *pPre = root;
        TreeNode *pCur; // 不设初值，因为不知道是左是右
        while (true)
        {
            if (data < pPre->data)
            {
                pCur = pPre->leftChild;
                if (pCur == NULL)
                { // 左子不存在
                    pPre->leftChild = pNewNode;
                    // pPre左子的位置放上新结点
                    break;
                }
                else
                {
                    pPre = pCur;
                    // 有左子的话，转移指针
                }
            }
            else
            {
                pCur = pPre->rightChild;
                if (pCur == NULL)
                {
                    pPre->rightChild = pNewNode;
                    break;
                }
                else
                {
                    pPre = pCur; // 往右走
                }
            }
        }
    }
}
string InOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    return (InOrder(root->leftChild) + root->data + InOrder(root->rightChild));
} // 返回一个字符串
string PreOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    return (root->data + PreOrder(root->leftChild) + PreOrder(root->rightChild))
}
int main()
{
    int n;
    cin >> n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            break;
        }
        char str1[100];
        scanf("%s", str1);
        TreeNode *root1 = NULL;
        /*for (int i = 0; str1[i] != '\0'; ++i)
        {
            insertBST(root1, str1[i]);
        }*/
        for (auto i : str1)
        {
            insertBST(root1, i);
        }
        string PreOrder1 = PreOrder(root1);
        string InOrder1 = InOrder(root1);
        printf("%s %s\n", PreOrder.c_str(), InOrder1.c_str());
        char str2[100];
        for (int idx = 0; idx < n; ++idx)
        {
            scanf("%s", str2);
            TreeNode *root2 = NULL;
            for (int i = 0; str2[i] != '\0'; ++i)
            {
                insertBST(root2, str2[i]);
            }
            string PreOrder2 = PreOrder(root2);
            string InOrder2 = InOrder(root2);
            if (PreOrder1 == PreOrder2 && InOrder1 == InOrder2)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}