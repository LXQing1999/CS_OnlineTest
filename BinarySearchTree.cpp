// 二叉搜索树的左子树小于根结点，右子树大于根结点
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *leftChild;
    TreeNode *rightChild;
};
void insertBST(TreeNode *&root, int data)
{
    TreeNode *pNewNode = new TreeNode;
    pNewNode->data = data;
    pNewNode->leftChild = NULL;
    pNewNode->rightChild = NULL; // 初始化为空
    if (root == NULL)
    {
        root = pNewNode; // 指向新结点
        printf("-1\n");
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
                    printf("%d\n", pPre->data);
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
                    printf("%d\n", pPre->data);
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
int main()
{
    int n;
    scanf("%d", &n);
    TreeNode *root = NULL;
    // int array[] = {2, 3, 5, 1, 4};
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        insertBST(root, num);
    }
}