#include <cstdio>
#include <queue>
using namespace std;

struct TreeNode
{
    char data;
    TreeNode *leftChild;
    TreeNode *rightChild;
};

struct QueueNode // 队列里的结点格式
{
    TreeNode parent;
    bool isLeftIn;
};

void insertTreeNode(TreeNode *&root, queue<QueueNode> &myQueue, char data)
{
    if (data != '#')
    {
        TreeNode *pTreeNode = new TreeNode;
        pTreeNode->data = data;
        QueueNode pQueueNode; // 新建一个队列结点
        pQueueNode.parent = *pTreeNode;
        // pTreeNode是前面定义的指针，*表示取出内容，这样等号两边就都是TreeNode类型了
        //*在定义时，表示指针，在其他地方表示取出内容
        pQueueNode.isLeftIn = false;
        myQueue.push(pQueueNode);
        if (root == NULL)
        {
            root = pTreeNode;
        }
        else
        {
            QueueNode pParent = myQueue.front();
            if (pParent.isLeftIn == false)
            {
                pParent.parent.leftChild = pTreeNode;
                pParent.isLeftIn = true;
            }
            else
            {
                pParent.parent.rightChild = pTreeNode;
                myQueue.pop();
            }
        }
    }
    else
    {
        if (root != NULL)
        {
            QueueNode pParent = myQueue.front();
            if (pParent.isLeftIn == false)
            {
                pParent.parent.leftChild = NULL;
                pParent.isLeftIn = true;
            }
            else
            {
                pParent.parent.rightChild = NULL;
                myQueue.pop();
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    TreeNode *root = NULL;
    char charList[] = "abc##de#g##f###";
    queue<QueueNode> myQueue;
    for (int i = 0; charList[i] != '\0'; i++)
    {
        insertTreeNode(root, myQueue, charList[i]);
    }
    LevelOrder(root);
    return 0;
}
